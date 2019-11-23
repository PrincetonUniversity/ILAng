/// \file Invariant Synthesis -- CHC FreqHorn
/// to work with FreqHorn (bv branch)
/// to parse the sythesize result -- need to do the similar thing
///
// Hongce Zhang

#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/inv-syn/freqhorn_inv_parse.h>

#include <sstream>
#include <fstream>

namespace ilang{
namespace smt {


FreqHornInvariantParser::FreqHornInvariantParser(YosysSmtParser * yosys_smt_info, 
  const std::string & dut_instance_name,
  bool discourage_outside_var,
  bool outside_var_to_freevar) : // dt hier flattened , INV name should not be used
  SmtlibInvariantParser(yosys_smt_info, true, true,  {}, dut_instance_name, discourage_outside_var),
  convert_out_var_to_free_var(outside_var_to_freevar) {
  // this should be the only layer  
  quantifier_def_stack.push_back(quantifier_temp_def_t());

}

FreqHornInvariantParser::~FreqHornInvariantParser() {
  // quantifier_def_stack.pop_back(); no neede
}


// ------------------------- INTERFACE --------------------------------------------------------------------
// parse from a file, we will add something there to make
// if sat --> failed (return false)
// if unsat --> add the (assert ...)
bool FreqHornInvariantParser::ParseInvResultFromFile(const std::string & fname) {
  std::ifstream fin(fname);
  if (not fin.is_open()) {
    ILA_ERROR << "Unable to read from : " << fname;
    return false;
  }
/*
  std::string result;
  if (not std::getline(fin,result) ) {
    ILA_ASSERT(false) << "No output from the synthesizer!" << result;
    return false; // unknown result, possibly failed
  }
  do {
    if (S_IN("unknown", result))
      return false; // failed
    if (S_IN("proved", result)) {
      getline(fin,result); // the iter line, the rest are the invs
      break;
    }
  } while (getline(fin,result));
*/
  std::stringstream sbuf;
  sbuf << fin.rdbuf(); // different from original, it starts (define-fun)
  raw_string = sbuf.str();

  ParseSmtResultFromString(raw_string); // but the raw string are multiline and it should not be prune...
  return true;
}

// -------------------------CALL BACK FUNS--------------------------------------------------------------------

/// call back function to create a sort
var_type * FreqHornInvariantParser::make_sort(const std::string &name, const std::vector<int> & idx) {
  //ILA_ASSERT(not quantifier_def_stack.empty());
  //ILA_ASSERT(not quantifier_var_def_idx_stack.empty());
  
  // should should only be BitVec or Bool
  if (name == "Bool") {
    if (not IN("Bool", sort_container))
      sort_container.insert(std::make_pair(std::string("Bool"),
        var_type(var_type::tp::Bool, 1, "")));
    return & (sort_container["Bool"]);
  }
  else if (name == "BitVec") {
    ILA_ASSERT(idx.size() == 1);
    ILA_ASSERT(idx[0] > 0);
    std::string sortIdxName = "BV"+std::to_string(idx[0]);
    if (not IN(sortIdxName, sort_container))
      sort_container.insert(std::make_pair(sortIdxName,
        var_type(var_type::tp::BV, idx[0], "")));
    return & (sort_container[sortIdxName]);
  }
  ILA_ASSERT(false) << "Unknown sort:" << name << " in flattened smt.";
    return nullptr; // should not be reachable
} // make_sort


/// this is actually declare variables
void FreqHornInvariantParser::declare_function(const std::string &name, var_type * sort) {
  ILA_ASSERT(quantifier_def_stack.size() == 1) << "There should only be a global quantified var list";
  // we need to extract the name from verilog
  auto top_module = design_smt_info_ptr->get_module_def_orders().back();
  /// we need to check the format
  std::string vlg_name = name;
  if (name.front() == '|' and name.back() == '|') {
    ILA_ASSERT(name.size() > 2) << "Unexpected empty name: " << name;
    vlg_name = name.substr(1,name.length()-2) ; // verilog-name should be extracted from the name part
  }
  if (vlg_name.find("S_") == 0) {
    ILA_ASSERT(vlg_name.size() > 2) << "Unexpected empty name: " << name;
    vlg_name = vlg_name.substr(2,name.length()-2);
  }
  std::string converted_name;
  if (vlg_name.find(dut_verilog_instance_name+".") == 0) {  
    converted_name = vlg_name;
  } else {
    // it is an outside name
    ILA_ERROR_IF(no_outside_var_refer) << "Invariant refers to outside var:" << vlg_name;
    if (convert_out_var_to_free_var) {
      if (S_IN('.', vlg_name)){
        converted_name = ReplaceAll(vlg_name,".","_dot_");
      } else {
        converted_name = "__TOP_dot_"+vlg_name+"__";
      }
      free_vars.insert(std::make_pair(converted_name, sort->GetBoolBvWidth()));
    } else // else do not convert
      converted_name = vlg_name;
  }

  // save it
  quantifier_def_stack.back().insert(std::make_pair(name,
    SmtTermInfoVerilog(converted_name,*sort,this)));
} 

// --------------------- DISABLE THESE FUNCTIONS ------------------------ //
/// call back function to handle (forall
SmtTermInfoVlgPtr FreqHornInvariantParser::push_quantifier_scope() {
  ILA_ASSERT(false) << "push_quantifier_scope should not appear in FreqHorn CHC result";
  return nullptr;
}
/// call back function to handle ) of forall
SmtTermInfoVlgPtr FreqHornInvariantParser::pop_quantifier_scope() {
  ILA_ASSERT(false) << "pop_quantifier_scope should not appear in FreqHorn CHC result";
  return nullptr;
}

SmtTermInfoVlgPtr FreqHornInvariantParser::search_quantified_var_stack(const std::string & name) {
  ILA_DLOG("FreqHornInvariantParser.search_var") << "Begin search var:"<<name<<std::endl;
  for (auto mp_pos = quantifier_def_stack.rbegin(); \
    mp_pos != quantifier_def_stack.rend(); ++ mp_pos) { // search from the closest binding
    if (IN(name,(*mp_pos) ))
      return & ( (*mp_pos) [name] );
  }
  ILA_DLOG("FreqHornInvariantParser.search_var") << "Not found var:"<<name<<std::endl;
  return nullptr;
} // search_quantified_var_stack


/// call back function to create a temporary (quantified variable)
// for the flattened-datatype, this should be the same as the datatype order
void FreqHornInvariantParser::declare_quantified_variable(const std::string &name, var_type * sort ) {
  ILA_ASSERT(false) << "declare_quantified_variable should not appear in FreqHorn CHC result";
} // declare_quantified_variable

/// call back function to apply an uninterpreted function
/// fall-through case if it is not an defined op, if failed, return NULL
/// for unflattened-hierarchy: this should be the place where things are called
/// it could be directly the (pred state)
/// or (pred (pred state)) ... you need to pass the right instance name allow side
SmtTermInfoVlgPtr FreqHornInvariantParser::mk_function(
  const std::string &name, var_type * sort, 
  const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) {
  // we don't really rely on the sort here: actually it should be NULL
  ILA_DLOG("FreqHornInvariantParser.mk_function") << "make func:" << name << ", #arg" << args.size() << std::endl;
  if (args.empty() and idx.empty()) {
    // first let's check if it is referring to a quantifier-bound variable
    auto term_ptr = search_quantified_var_stack(name);
    if (term_ptr)
      return term_ptr;
    ILA_ASSERT(false) << "unknown symbol:"<<name;
    return nullptr; // no use
  }
  // I'm assuming no func should be used
  ILA_ASSERT(false) << "unknown symbol for function:"<<name;
  return nullptr; // should not be reachable
} // mk_function

void FreqHornInvariantParser::define_function(const std::string &func_name, 
    const std::vector<SmtTermInfoVlgPtr> & args, var_type * ret_type,
    SmtTermInfoVlgPtr func_body) {
  ILA_ASSERT(false) << "define_function should not appear in FreqHorn CHC result, func:"<<func_name;
}


}; // namespace smt
}; // namespace ilang