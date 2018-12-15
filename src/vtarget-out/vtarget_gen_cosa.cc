/// \file Source of generating CoSA accepted problem, vlg, mem, script
// --- Hongce Zhang

#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/vtarget_gen_cosa.h>
#include <ilang/util/fs.h>
#include <algorithm>
#include <iostream>
#include <fstream>

namespace ilang {

    VlgSglTgtGen_Cosa::VlgSglTgtGen_Cosa(
    const std::string              & output_path, // will be a sub directory of the output_path of its parent
    const InstrPtr                 & instr_ptr, // which could be an empty pointer, and it will be used to verify invariants
    const VerilogGenerator::VlgGenConfig & config,
    nlohmann::json                 & _rf_vmap,
    nlohmann::json                 & _rf_cond,
    VerilogInfo      *               _vlg_info_ptr,
    const std::string              & vlg_mod_inst_name,
    const std::string              & ila_mod_inst_name,
    const std::string              & wrapper_name,
    const std::vector<std::string> & implementation_srcs
  ):VlgSglTgtGen(
      output_path, instr_ptr, config, _rf_vmap, _rf_cond,
      _vlg_info_ptr, vlg_mod_inst_name, ila_mod_inst_name,
      wrapper_name, implementation_srcs )
  {

  }


  /// Add an assumption
  void VlgSglTgtGen_Cosa::add_an_assumption(const std::string & aspt, const std::string & dspt) {
    auto assumption_wire_name = vlg_wrapper.sanitizeName(dspt);
    vlg_wrapper.add_wire( assumption_wire_name , 1 );
    vlg_wrapper.add_assign_stmt( assumption_wire_name,  aspt );
    _problems.assumptions.push_back(assumption_wire_name);
  }
  /// Add an assertion
  void VlgSglTgtGen_Cosa::add_an_assertion (const std::string & asst, const std::string & dspt)  {
    auto assrt_wire_name = vlg_wrapper.sanitizeName(dspt);
    vlg_wrapper.add_wire( assrt_wire_name , 1 );
    vlg_wrapper.add_assign_stmt( assrt_wire_name,  asst );

    _problems.probitem[dspt].assertions.push_back(assrt_wire_name);
  }

  /// export the script to run the verification
  void VlgSglTgtGen_Cosa::Export_script(const std::string & script_name) {
    auto fname = os_portable_append_dir(_output_path, script_name);
    std::ofstream fout(fname);
    if(! fout.is_open() ) {
      ILA_ERROR << "Error writing to file:"<<fname;
      return;
    }
    fout << "#!/bin/bash" << std::endl;
    if (cosa_prob_fname != "") 
      fout << "CoSA -i " << cosa_prob_fname << std::endl;
    else
      fout << "echo 'Nothing to check!'" << std::endl;
  }
  /// export extra things (problem)
  void VlgSglTgtGen_Cosa::Export_problem(const std::string & extra_name) {
    if(_problems.probitem.size() == 0) {
      ILA_ERROR << "Nothing to prove, no assertions inserted!";
      return;
    }

    cosa_prob_fname = extra_name;

    std::ofstream rstf( os_portable_append_dir( _output_path ,"rst.ets") );
    if(! rstf.is_open() ) {
      ILA_ERROR << "Error writing file: " << os_portable_append_dir(_output_path,"rst.ets");
      return;
    }    
    rstf<< "I: rst = 0_1" << std::endl;
    rstf<< "I: reset_done = False" << std::endl;
    rstf<< "S1: rst = 1_1" << std::endl;
    rstf<< "S1: reset_done = False" << std::endl;
    rstf<< "S2: rst = 0_1" << std::endl;
    rstf<< "S2: reset_done = True" << std::endl;
    rstf<< "# TRANS" << std::endl;
    rstf<< "I -> S1" << std::endl;
    rstf<< "S1 -> S2" << std::endl;
    rstf<< "S2 -> S2" << std::endl;

    std::ofstream fout( os_portable_append_dir(_output_path,extra_name) );
    if(! fout.is_open() ) {
      ILA_ERROR << "Error writing file: " << os_portable_append_dir(_output_path, extra_name);
      return;
    }    

    fout<<"[GENERAL]"<<std::endl;
    fout<<"model_file:";// 
    fout << top_file_name << "[" << top_mod_name << "]," << ila_file_name  ;
    fout << ",rst.ets";
    for(auto && fn : vlg_design_files)
    fout << "," << fn;
    fout << std::endl;

    fout<<"assume_if_true: True"<<std::endl;
    fout<<"abstract_clock: True"<<std::endl;
    fout<<"[DEFAULT]"<<std::endl;
    fout<<"bmc_length: " << std::to_string(max_bound) <<std::endl;
    fout<<"precondition: reset_done"<<std::endl;
    fout<<std::endl;

    std::string assmpt = Join(_problems.assumptions, "&");
    for ( auto && pbname_prob_pair : _problems.probitem ) {
      const auto & prbname = pbname_prob_pair.first;
      const auto & prob    = pbname_prob_pair.second;
      auto asst = Join(prob.assertions, "&" );
      auto prob_name = vlg_wrapper.sanitizeName(prbname);
      fout << "["<<prob_name<<"]" <<std::endl;
      fout << "description:\"" << prbname <<"\""  <<std::endl;
      fout << "formula:" << asst << std::endl;
      if(assmpt != "")
        fout << "assumptions:" << assmpt << std::endl;
      fout << "prove: True" << std::endl;
      fout << "verification: safety" << std::endl;
      fout << "strategy: ALL" << std::endl;
      fout << "expected: True" << std::endl;

    }


  }  // only for cosa

  /// export the memory abstraction (implementation)
  /// Yes, this is also implementation specific, (jasper may use a different one)
  void VlgSglTgtGen_Cosa::Export_mem(const std::string & mem_name) {

  }

  /// For jasper, this means do nothing, for yosys, you need to add (*keep*)
  void VlgSglTgtGen_Cosa::Export_modify_verilog()  {
    // collect all locations: filename -> lineno
    // open, read, count and write
    // if it is a port name, we will ask user to specify its upper level 
    // signal name
    
    // filename -> (lineno, varname, portsig?) vec
    fn_l_map_t fn_l_map;

    for (auto && vlg_sig_name : _all_referred_vlg_names) {
      auto vlg_sig_info = vlg_info_ptr->get_signal(vlg_sig_name);
      auto loc = vlg_info_ptr->name2loc(vlg_sig_name);
      fn_l_map[loc.first].push_back (
        info_t (
          loc.second, // lineno
          vlg_sig_info.get_signal_name(), // variable name
          vlg_sig_info.no_internal_def()  // is it a port
          ));
    }

    // sort it according to lineno
    for( auto && fn_tp_pair : fn_l_map) {
      auto & vec = fn_tp_pair.second;
      std::sort(begin(vec), end(vec), 
          [](info_t const &t1, info_t const &t2) {
              return std::get<0>(t1) < std::get<0>(t2); // or use a custom compare function
          } );
    }

    // now let's do the job
    for (auto && fn : vlg_design_files) {
      auto outfn = os_portable_append_dir( _output_path , os_portable_file_name_from_path(fn) );
      std::ifstream fin(fn);
      std::ofstream fout(outfn);
      if(!fin.is_open()) {
        ILA_ERROR<<"Cannot read file:"<<fn;
        continue;
      }
      if(!fout.is_open()) {
        ILA_ERROR<<"Cannot open file for write:"<<outfn;
        continue;
      }
      if(not IN(fn, fn_l_map) ) {
        // no need to modify, just copy
        fout << fin.rdbuf();
        continue;
      }
      rmw(fin,fout, fn_l_map[fn]);
    } // for (auto && fn : vlg_design_files)
    // .. (copy all the verilog file in the folder), this has to be os dependent
    ILA_WARN << "Not copying includes.";
    // maybe in the script
  } // Export_modify_verilog

  /// helper to read-modify-write a file
  /// I just don't want to make the above function too long
  void VlgSglTgtGen_Cosa::rmw(std::ifstream & fin, std::ofstream & fout, std::vector<info_t> & info ) {
    // really we need to deal with it
    long lineno = 0;
    std::string line;
    auto vec_it = info.begin(); // what if it is end
    while (std::getline(fin, line) ) {
      while(vec_it != info.end() and lineno == get<0>(*vec_it)) {
        // process it
        auto vname = get<1>(*vec_it);
        auto is_port = get<2>(*vec_it);

        if(!is_port)
          line = "(* keep *)" + line;
        else {
          line = add_keep_to_port(line, vname);
        }
        // move to the next item on the same line
        vec_it ++;
      }
      fout << line << std::endl;
      lineno ++;
    }
  }
  

  std::string VlgSglTgtGen_Cosa::add_keep_to_port(const std::string & line_in, const std::string & vname) {
    size_t left = 0;
    if( line_in.find(vname) == std::string::npos ) {
      ILA_ERROR<<"Implementation bug: not able to add keep to line:"
        << line_in << " required varname:" << vname;
      return line_in;
    }
    if(line_in.find("(") != std::string::npos) 
      left = line_in.find("(") + 1;
    if(line_in.find(",") == std::string::npos)  
      return line_in.substr(0,left) +" (* keep *) " + line_in.substr(left);
    // not handline port case
    ILA_WARN << vname << "@"<< line_in << " is a port name, please use the upper level signal name.";
    return line_in;
    /*    
    unsigned idx = left;
    auto var_pos = line_in.find(vname);
    
    while(idx < var_pos ) {
      idx = line_in.find(",",left);
      left = idx + 1;
    }
    ILA_ASSERT(idx  < line_in.size() ) << "Implementation bug.";
    ILA_ASSERT(left < line_in.size() ) << "Implementation bug.";



    for(unsigned idx = left; idx < line_in.size() ; ++ idx) {
      auto c = line_in[idx];
      if(c == ',')
        left = idx + 1;
      auto rest = line_in.substr(left);
      auto var_pos = rest.find(vname);
      if(  == std::string::npos )
        ILA_ASSERT(false) << "Implementation bug.";
      rest.find()
    }*/
  }

}; // namespace ilang