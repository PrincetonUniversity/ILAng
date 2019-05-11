#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/util/fs.h>
#include <ilang/vtarget-out/inv-syn/cex_extract.h>

#include <vcdparser/VCDFileParser.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace ilang;

std::string server_name = "nobel";
std::string server_prj_dir =  "/u/hongcez/fmcad19-exp/rv-inv-check/";

/// run verification one-by-one
std::vector<std::string> props;

// --------------------------- HELPERS ------------------------------ //

static std::string val2vlgstr(const VCDValue & v) {
  std::stringstream ret;

  switch(v.get_type()) {
    case (VCD_SCALAR): 
      ret << "1'b" << VCDValue::VCDBit2Char(v.get_value_bit());
      break;
    case (VCD_VECTOR):
      {
        const VCDBitVector * vecval = v.get_value_vector();
        ret << std::to_string(vecval->size())<< "'b";
        for(auto it = vecval -> begin();
                it != vecval -> end();
                ++it)
          ret << VCDValue::VCDBit2Char(*it);
      }
      break;
    case (VCD_REAL):
      ret << v.get_value_real();
      break;
    default:
      ILA_ERROR<<"Unknown value type!";
  }
  return ret.str();
}

static std::string collect_scope(VCDScope * sc) {
  std::string ret;
  while(sc) {
    ret = sc->name + "." + ret;
    sc = sc->parent;
  }
  return ret;
}
// ------------------------- STEPS -------------------------- //

bool push_assume_to_server(const std::string & assumefile) {
  const static std::string cmd = "scp %localName% %server%:%dir%";
  auto syscmd = 
    ReplaceAll(
    ReplaceAll(
    ReplaceAll(cmd,
      "%localName%", assumefile),
      "%server%", server_name),
      "%dir%", server_prj_dir);
  auto ret = std::system( syscmd.c_str() );
  ILA_ERROR_IF( ret != 0 )
    << "Push to server failed!";
  return ret == 0;
}

bool run_jg_till_fail(const std::string & assumefile) {

  std::string propstr = "{\"" + Join(props, "\" \"") + "\"}";

  bool has_cex;
  std::system("rm -f cex.vcd");
  { // generate template
    std::ifstream fin("nobel.expect.tpl");
    std::ofstream fout("nobel.expect");
    std::stringstream sbuf;

    ILA_ASSERT(fin.is_open());
    ILA_ASSERT(fout.is_open());

    sbuf << fin.rdbuf();

    auto expect =
      ReplaceAll(
      ReplaceAll(
      ReplaceAll(
      ReplaceAll(sbuf.str(), 
        "%server%", server_name),
        "%path%", server_prj_dir),
        "%assume%",  os_portable_file_name_from_path(assumefile) ),
        "%properties%", propstr);
    
    fout << expect << std::endl;
  }
  { // remove the old counterexample
    auto rm_cmd = "ssh %server% rm -f %dir%cex.vcd";
    std::string rmcmd = 
      ReplaceAll(
      ReplaceAll(rm_cmd,
        "%server%", server_name),
        "%dir%", server_prj_dir);
    std::system(rmcmd.c_str());
  }

  { // remove the old data
    auto rm_cmd = "ssh  %server% rm -rf %dir%db  %dir%jgproject";
    std::string rmcmd = 
      ReplaceAll(
      ReplaceAll(rm_cmd,
        "%server%", server_name),
        "%dir%", server_prj_dir);
    std::system(rmcmd.c_str());
  }
  // run till the end (either fail or succeeded)
  std::system("expect nobel.expect");

  {
    const std::string cmd = "scp %server%:%dir%cex.vcd ./";
    std::string fetch_cmd = 
      ReplaceAll(
      ReplaceAll(cmd,
        "%server%", server_name),
        "%dir%", server_prj_dir);
    int ret = std::system(fetch_cmd.c_str());
    if (ret == 0)
      has_cex = true;
    else
      has_cex = false;
  }
  return has_cex;
}

void analyze_failed_property_and_time(const std::string & vcd_file_name,
  std::string & failed_prop, double & time, const std::string & scope,
  CexExtractor::cex_t & cex, const std::set<std::string>  &required_sigs, bool allow_wire) {
  
  std::set<std::string>  local_required_sigs(required_sigs);

  VCDFileParser parser;
  VCDFile * trace = parser.parse_file(vcd_file_name);

  if (not trace) {
    ILA_ERROR << "Error while reading waveform from: "<< vcd_file_name; return; }
  ILA_NOT_NULL(trace -> get_scope("$root"));
  ILA_NOT_NULL(trace -> get_scope("wrapper"));

  // determine the failing property time
  std::map<std::string,std::string> sig_hash_map;
  for (VCDSignal* root_sig : trace -> get_scope("jasper::tcl_properties") -> signals ) {
    // find the hash of it
    auto signame = root_sig -> reference;
    if ( std::find(props.begin(),props.end(), signame) != props.end() ) {
      // if it is a signal name
      sig_hash_map.insert(std::make_pair(signame, root_sig -> hash));
    }
  }


  ILA_ASSERT(not sig_hash_map.empty()) << "No properties in the vcd!";

  time = -1;
  for (auto && sig_hash_pair : sig_hash_map) {
    VCDSignalValues * prop_sig_vals = trace -> get_signal_value(sig_hash_pair.second);

    for (VCDTimedValue * tv : *prop_sig_vals) {
      if ( val2vlgstr( *(tv -> value) ) == "1'b0"  ) {
        time = tv -> time;
        failed_prop = sig_hash_pair.first;
        std::cout << "Found property:" << failed_prop << " failed @ " << time << std::endl;
      }
    }
  } // sig_hash_map

  ILA_ASSERT(time != -1) << "Unable to find failing time.";

  std::vector<VCDSignal*>* sigs = trace -> get_signals();

  for ( VCDSignal * sig: *sigs) {
    // check scope
    auto scopes = collect_scope(sig->scope);

    // check scope -- only the top level
    if ( not ( scopes.find("$root.wrapper." +  scope + ".") == 0 ) )
      continue;

    auto vlg_name = ReplaceAll(
      scopes + sig->reference, "$root.wrapper.", "");
    std::string check_name = vlg_name;
    {
      auto pos = check_name.find('[');
      if (pos != std::string::npos)
        check_name = check_name.substr(0,pos);
    }

    if (not IN(check_name, required_sigs))
      continue;
    local_required_sigs.erase(check_name);
    
    // ensure it is only register
    if (! allow_wire && sig->type != VCDVarType::VCD_VAR_REG)
      continue;

    auto vlg_val_ptr = trace->get_signal_value_at( sig->hash, time);

    if (vlg_val_ptr == nullptr) {
      ILA_WARN << "Parsing VCD: " << vlg_name << " gets Xs. Ignored.";
      continue;
    }
    std::string val = 
      val2vlgstr(
        * vlg_val_ptr );
    
    cex.insert( std::make_pair( vlg_name, val) ); 
  } // end for signals 

  if (not local_required_sigs.empty()) {
    std::cout << "These signals are not found in vcd: ";
    for (auto && n : local_required_sigs)
      std::cout << n << ' ';
    std::cout <<"\n";
  }
}

void load_property_name(const std::string &fn) {
  std::ifstream fin(fn);
  if (not fin.is_open()) {
    ILA_ERROR << "Unable to read from:" << fn;
    return;
  }
  std::string prop;
  while(std::getline(fin,prop))
    props.push_back(prop);
}


bool load_sig_list(std::set<std::string> & siglist, const std::string & fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) { ILA_ERROR << "unable to read from " << fn; return false;}

  std::string sig;
  while(std::getline(fin,sig)) {
    if (!sig.empty())
      siglist.insert(sig);
  }
  return true;
}

int main(int argc, char **argv) {

  const std::string vardef = "vardef.v";
  const std::string assumefile = "assert.tcl";
  const std::string cexfile = "cex.sigs";
  const std::string propfile = "prop.txt";

  if (argc < 3) {
    std::cout << "Usage : " << argv[0] << " server path\n";
    return 7;
  }

  server_name = argv[1];
  server_prj_dir = argv[2];

  load_property_name(propfile);

  if (not push_assume_to_server(assumefile) || not push_assume_to_server(vardef) )
    return 1; // failed connection
  bool has_cex = run_jg_till_fail(assumefile);
  if (!has_cex)
    return 5; // i like 5
  
  std::string prop;
  double failtime;
  ilang::CexExtractor::cex_t cex;
  std::set<std::string>  siglist;
  bool do_load_sig_list = argc >=  4;
  if (do_load_sig_list)
    load_sig_list(siglist, argv[3]);
  analyze_failed_property_and_time("cex.vcd",prop,failtime, "dut", cex, siglist, do_load_sig_list);

  CexExtractor::StoreCexToFile(cexfile, cex);

  // store failing property --- propfile
  {
    std::ofstream fout(propfile);
    if (not fout.is_open()) {
      ILA_ERROR << "Unable to write to " << propfile;
    } else
      fout << prop << std::endl;
  }

  return 0; // it has done its job
}

