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
std::string server_prj_dir =  "/u/hongcez/rv32i-inv-syn/";

/// run verification one-by-one
std::vector<std::string> props ;

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

bool analyze_failed_property_and_time(const std::string & vcd_file_name,
  std::string & failed_prop, double & time, double & start_time, const std::string& the_scope,
  const std::string & start_signal, // "inst_begin_cond"
  const std::string & expect_start_signal_value // "1'b1"
  ) {

  VCDFileParser parser;
  VCDFile * trace = parser.parse_file(vcd_file_name);

  if (not trace) {
    ILA_ERROR << "Error while reading waveform from: "<< vcd_file_name; return false; }
  ILA_NOT_NULL(trace -> get_scope("$root"));
  ILA_NOT_NULL(trace -> get_scope(the_scope));

  // determine the failing property time
  std::string starting_sig_hash;
  std::map<std::string,std::string> sig_hash_map;
  for (VCDSignal* root_sig : trace -> get_scope(the_scope) -> signals ) {
    // find the hash of it
    auto signame = root_sig -> reference;
    if (signame.size() >= 1 && signame.at(0)=='\\')
      signame = signame.substr(1);
    if ( std::find(props.begin(),props.end(), signame) != props.end() ) {
      // if it is a signal name
      sig_hash_map.insert(std::make_pair(signame, root_sig -> hash));
    }
    if ( signame == start_signal )
      starting_sig_hash = root_sig -> hash;
  }

  // determine the start signal time
  if (not starting_sig_hash.empty()) {
    VCDSignalValues * prop_sig_vals = trace -> get_signal_value(starting_sig_hash);
    for (VCDTimedValue * tv : *prop_sig_vals) {
      if ( val2vlgstr( *(tv -> value) ) == expect_start_signal_value ) {
        start_time = tv -> time;
        std::cout << "Found starting time: @ " << start_time << std::endl; break;
      }
    }
    ILA_WARN << "starting_sig_hash not found. Use given starting time: " <<start_time;
  }
  //

  ILA_ASSERT(not sig_hash_map.empty()) << "No properties in the vcd!";

  time = -1;
  for (auto && sig_hash_pair : sig_hash_map) {
    VCDSignalValues * prop_sig_vals = trace -> get_signal_value(sig_hash_pair.second);

    for (VCDTimedValue * tv : *prop_sig_vals) {
      if ( val2vlgstr( *(tv -> value) ) == "1'b0" && (tv -> time >= start_time) ) {
        time = tv -> time;
        failed_prop = sig_hash_pair.first;
        std::cout << "Found property:" << failed_prop << " failed @ " << time << std::endl;
        return true;
      }
    }
  }
  ILA_ERROR << "Cannot find failing signals in the following presenting signals:";
  for(auto && sig_hash_pair : sig_hash_map ) {
    ILA_ERROR <<sig_hash_pair.first;
  }
  return false;
}


/// now let's make the expect pattern
bool get_why(const std::string &prop_signal, double failtime, double starttime,
  std::set<std::string> & whysig  )  {

  { // generate why expect
    std::ifstream fin("nobelwhy.expect.tpl");
    std::ofstream fout("nobelwhy.expect");
    std::stringstream sbuf;

    ILA_ASSERT(fin.is_open());
    ILA_ASSERT(fout.is_open());

    sbuf << fin.rdbuf();

    auto expect =
      ReplaceAll(
      ReplaceAll(
      ReplaceAll(sbuf.str(), 
        "%server%", server_name),
        "%path%", server_prj_dir),
        "%prop%", '"'+prop_signal+'"');
    
    fout << expect << std::endl;
  }

  { // generate why tcl
    std::ifstream fin("why.tcl.tpl");
    std::ofstream fout("why.tcl");
    std::stringstream sbuf;

    ILA_ASSERT(fin.is_open());
    ILA_ASSERT(fout.is_open());

    sbuf << fin.rdbuf();

    auto why =
      ReplaceAll(
      ReplaceAll(sbuf.str(), 
        "%cycle%", std::to_string((int)(failtime/10)+1)),
        "%prop%", prop_signal);
    
    fout << why << std::endl;

  }
  { // push why tcl
    const static std::string cmd = "scp why.tcl %server%:%dir%";
    auto syscmd = 
      ReplaceAll(
      ReplaceAll(cmd,
        "%server%", server_name),
        "%dir%", server_prj_dir);
    auto ret = std::system( syscmd.c_str() );
    if (ret != 0) {
      ILA_ERROR << "Push why.tcl to server failed!";
      return false;
    }
  }
  // run expect
  std::system("expect nobelwhy.expect");

  { // fetch why.result
    const static std::string cmd = "scp %server%:%dir%why.result ./";
    auto syscmd = 
      ReplaceAll(
      ReplaceAll(cmd,
        "%server%", server_name),
        "%dir%", server_prj_dir);
    auto ret = std::system( syscmd.c_str() );
    if (ret != 0) {
      ILA_ERROR << "Pull why.result from server failed!";
      return false;
    }
  } // end -- fetch why.result

  { // Parse why.result
    std::ifstream fin("why.result");
    if (not fin.is_open()) {
      ILA_ERROR << "Open why.result failed!";
      return false;
    }

    std::string line;
    bool start = false;
    while (std::getline(fin,line)) {
      if(!start && line.find("Cycle: " + std::to_string(starttime == 0 ? 0 : (int)(starttime/10) + 1 )) == 0) {
        start = true;
      } else if (start) {
        if (line.find("-----------------") == 0) {
          break; // Done -- we are good
        } // else
        auto varnames = SplitSpaceTabEnter(line);
        if (varnames.empty()) {
          ILA_ERROR << "no var on this line:" << line;
          continue;
        }
        ILA_ERROR_IF(varnames.size() > 1) << "multi var:" << line;
        auto varname = varnames[0];
        auto sep = varname.find('[');
        if (sep != varname.npos)
          varname = varname.substr(0,sep);
        whysig.insert(varname);
      } // end of start
    } // end of while get line
  } // end of Parsing why.result
  return true;
}

void filter_sigs(const std::set<std::string> & in, std::set<std::string> &out, const std::string & beg) {
  for (auto && n : in) {
    if (n.find(beg) == 0)
      out.insert(n);
  }
}

void get_signal_value_list(
  const std::string & vcd_file_name,
  const std::string & top_module_name, // "eq_top"
  const std::string & scope, // "hls_U"
  std::set<std::string> & whysig, double starttime,
  CexExtractor::cex_t & cex) {
  
  std::set<std::string> local_why(whysig);

  VCDFileParser parser;
  VCDFile * trace = parser.parse_file(vcd_file_name);

  std::vector<VCDSignal*>* sigs = trace -> get_signals();

  for ( VCDSignal * sig: *sigs) {
    // check scope
    auto scopes = collect_scope(sig->scope);

    // check scope -- only the top level
    if ( not ( scopes.find("$root."+top_module_name+"." +  scope + ".") == 0 ) )
      continue;

    auto vlg_name = ReplaceAll(
      scopes + sig->reference, "$root."+top_module_name+".", "");
    std::string check_name = vlg_name;
    {
      auto pos = check_name.find('[');
      if (pos != std::string::npos)
        check_name = check_name.substr(0,pos);
    }

    if (not IN(check_name, whysig))
      continue;
    local_why.erase(check_name);
    
    // ensure it is only register
    // if (sig->type != VCDVarType::VCD_VAR_REG)
    //   continue;

    auto vlg_val_ptr = trace->get_signal_value_at( sig->hash, starttime);

    if (vlg_val_ptr == nullptr) {
      ILA_WARN << "Parsing VCD: " << vlg_name << " gets Xs. Ignored.";
      continue;
    }
    std::string val = 
      val2vlgstr(
        * vlg_val_ptr );
    
    cex.insert( std::make_pair( vlg_name, val) ); 
  } // end for signals 
  if (not local_why.empty()) {
    std::cout << "These signals are not found in vcd: ";
    for (auto && n : local_why)
      std::cout << n << ' ';
    std::cout <<"\n";
  }
}

bool load_why(std::set<std::string> & whysig, const std::string & fn) {
  std::ifstream fin(fn);
  if (!fin.is_open()) { ILA_ERROR << "unable to read from " << fn; return false;}

  std::string sig;
  while(std::getline(fin,sig)) {
    if (!sig.empty())
      whysig.insert(sig);
  }
  return true;
}

void suggest_remove(const std::set<std::string> & provided_why_sig,
  const std::set<std::string> & jg_why_sig) {
  
  std::set<std::string> suggestion;
  for (auto && n : provided_why_sig) {
    if (not IN(n, jg_why_sig ))
      suggestion.insert(n);
  }
  std::cout << "Suggest remove of #" << suggestion.size() << std::endl;
  std::ofstream fout("suggest_remove.txt");
  if (!fout.is_open()) {
    std::cout << "cannot write to suggest_remove.txt\n"; return;
  }
  fout << suggestion.size() << std::endl;
  for (auto && n : suggestion) {
    fout << n << std::endl;
  }
}

int main(int argc, char **argv) {

  const std::string vardef = "vardef.v";
  const std::string assumefile = "assume.tcl";
  const std::string cexfile = "cex.sigs";
  const std::string propfile = "prop.txt";

  if (argc < 3) {
    std::cout << "Usage : " << argv[0] << " server path\n";
    return 7;
  }

  bool deduce_why = argc == 3;

  server_name = argv[1];
  server_prj_dir = argv[2];

  load_property_name(propfile);

  if (not push_assume_to_server(assumefile) || not push_assume_to_server(vardef) )
    return 1; // failed connection
  bool has_cex = run_jg_till_fail(assumefile);
  if (!has_cex)
    return 5; // i like 5
  
  std::string prop; double starttime = 0.0, failtime;
  if(!analyze_failed_property_and_time("cex.vcd",prop,failtime,starttime,"\\jasper::tcl_properties",
      "inst_begin_cond", "1'b0")) {
    return 1; // failed to extract
  }

  std::set<std::string> whysig, dutsigs;
  if (deduce_why) {
    get_why(prop,failtime, starttime,whysig);
    filter_sigs(whysig, dutsigs, "hls_U.");
  } else {
    std::set<std::string> jg_info_whysig, after_fileter;
    if (not load_why(dutsigs,argv[3]) ) return 2;
    get_why(prop,failtime, starttime,jg_info_whysig);
    filter_sigs(jg_info_whysig, after_fileter, "hls_U.");
    suggest_remove(dutsigs, after_fileter); // dutsigs will be the one used
  }

  ilang::CexExtractor::cex_t cex;
  get_signal_value_list("cex.vcd","eq_top","hls_U",dutsigs,starttime, cex);

  CexExtractor::StoreCexToFile(cexfile, cex);

  return 0; // it has done its job
}

