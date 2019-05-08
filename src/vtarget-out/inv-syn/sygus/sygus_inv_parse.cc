/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// to parse the sythesize result -- need to do the similar thing 
/// 
// Hongce Zhang

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_inv_parse.h>

#include <fstream>

namespace ilang {
namespace smt {


SyGuSInvariantParser::SyGuSInvariantParser(YosysSmtParser * yosys_smt_info, 
  bool _flatten_datatype, bool _flatten_hierarchy,
  const std::set<std::string> & _inv_pred_name,
  const std::string & dut_instance_name,
  bool discourage_outside_var,
  const correction_t & _corrections) :
    SmtlibInvariantParser(yosys_smt_info, _flatten_datatype, _flatten_hierarchy,
      _inv_pred_name, dut_instance_name, discourage_outside_var),
    corrections(_corrections)
  { 
    // we don't care about whether data_type has been flatten or not
    // the SyGuS input gen part will require datatype flattened if use transfer function
    // but it will create the var name correctly anyway

    // build all allowable names
    if (not dut_verilog_instance_name.empty()) {
      const auto & top_sts = yosys_smt_info->get_module_flatten_dt( 
        yosys_smt_info->get_module_def_orders().back() // the top module name
        );
      ILA_ASSERT(not top_sts.empty()) << "Empty top module states";
      for (auto && st : top_sts) {
        if ( st.verilog_name.empty() ) {
          auto n = st.internal_name;
          if (n.front() == '|' and n.back() == '|')
            n = n.substr(1,n.size()-2);
          _all_allowable_names.insert(n);
        }
        else
          _all_allowable_names.insert(st.verilog_name);
      }
    } // only an optional checking
  }

SyGuSInvariantParser::~SyGuSInvariantParser() {}


// parse from a file, we will add something there to make
// if sat --> failed (return false)
// if unsat --> add the (assert ...)
bool SyGuSInvariantParser::ParseInvResultFromFile(const std::string & fname) {
  std::ifstream fin(fname);
  if (not fin.is_open()) {
    ILA_ERROR << "Unable to read from : " << fname;
    return false;
  }

  std::string result;
  if (not std::getline(fin,result) ) {
    ILA_ASSERT(false) << "No output from the synthesizer!" << result;
    return false; // unknown result, possibly failed
  }

  if (result != std::string("unsat") and result.find("(define-fun ") != 0) {
    ILA_ERROR << "Unexpected output from the synthesizer:" << result;
    return false; // unknown result, possibly failed
  }

  if (result.find("(define-fun ") == 0) {
    // we don't get the unsat but we known it is and the rest should be the function
    fin.seekg(0,fin.beg);
    raw_string = correct_cvc4_bv_output(result);
  } else {
    std::stringstream sbuf;
    sbuf << fin.rdbuf(); // different from original, it starts (define-fun)
    raw_string = correct_cvc4_bv_output(sbuf.str());
  }
  // std::cout << raw_string;
  ParseSmtResultFromString(raw_string);
  return true;
}


std::string SyGuSInvariantParser::correct_cvc4_bv_output(const std::string & in) {
  auto bv_cor =  ReplaceAll(in,  "(BitVec",    "(_ BitVec");
  for (auto && or_pair : corrections) 
    bv_cor = ReplaceAll(bv_cor, or_pair.first, or_pair.second);
  return bv_cor;
}

// ----------------------- CALLBACK FUNCTIONS ----------------- //

/// this function receives the final assert result
void SyGuSInvariantParser::assert_formula(SmtTermInfoVlgPtr result) {
  ILA_ASSERT(false) << "BUG: assert should not exist in CVC4 SyGuS output.";
}

/// this function receives the final result
void SyGuSInvariantParser::define_function(const std::string &func_name, 
  const std::vector<SmtTermInfoVlgPtr> & args, var_type * ret_type,
  SmtTermInfoVlgPtr func_body) {
  // some sanity check here!
  ILA_ASSERT(ret_type->_type == var_type::tp::Bool)
    << "The invs should be (...) -> Bool type!";
  ILA_ASSERT(IN(func_name, inv_pred_name))
    << "The function name:" << func_name << " is unexpected!";
  final_translate_result = func_body->_translate; // the final result
} // define_function


/// call back function to create a sort
var_type * SyGuSInvariantParser::make_sort(const std::string &name, const std::vector<int> & idx) {
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

/// call back function to create a temporary (quantified variable)
// for the flattened-datatype, this should be the same as the datatype order
// 
void SyGuSInvariantParser::declare_quantified_variable(const std::string &name, var_type * sort ) {
  // check on the name part
  ILA_ASSERT(not quantifier_def_stack.empty());
  // ILA_ASSERT(not quantifier_var_def_idx_stack.empty());
  // I assume it has nothing to do with hierarchy flattening
  auto & top = quantifier_def_stack.back();

  // we need to extract the name from verilog
  auto top_module = design_smt_info_ptr->get_module_def_orders().back();
  /// we need to check the format
  std::string vlg_name = name;
  if (name.front() == '|' and name.back() == '|') {
    ILA_ASSERT(name.size() > 2) << "Unexpected empty name: " << name;
    vlg_name = name.substr(1,name.length()-2) ; // verilog-name should be extracted from the name part
  }
  if (S_IN('.', vlg_name)) {  
      // check it starts with |top.|
      auto starter = dut_verilog_instance_name+".";
      ILA_ASSERT(vlg_name.find(starter) == 0)
        << name << " should start w. " << starter;
  }
  // we don't explicitly check if this name is valid or not
  if (not dut_verilog_instance_name.empty())
    ILA_ERROR_IF(not IN(vlg_name,_all_allowable_names))
      << "Expecting " << vlg_name << " in all allowable names, but actually not.";
  /*( 
    design_smt_info_ptr->get_module_flatten_dt(top_module)
    [quantifier_var_def_idx_stack.back()])
    .verilog_name; */

  // save it
  top.insert(std::make_pair(name,
    SmtTermInfoVerilog(vlg_name,*sort,this)));

  //quantifier_var_def_idx_stack.back() ++; // actually this is not used at all
  
}

/// call back function to handle (forall
SmtTermInfoVlgPtr SyGuSInvariantParser::push_quantifier_scope() {
  quantifier_def_stack.push_back(quantifier_temp_def_t());
  // quantifier_var_def_idx_stack.push_back(0); --- should not be used at all
  return nullptr; // no body cares this
}
/// call back function to handle ) of forall
SmtTermInfoVlgPtr SyGuSInvariantParser::pop_quantifier_scope() {
  quantifier_def_stack.pop_back();
  // quantifier_var_def_idx_stack.pop_back();  --- should not be used at all
  return nullptr; // if we return null, it will not overwrite the make_forall_term result
}

SmtTermInfoVlgPtr SyGuSInvariantParser::search_quantified_var_stack(const std::string & name) {

  ILA_DLOG("SmtlibInvariantParser.search_var") << "Begin search var:"<<name<<std::endl;
  for (auto mp_pos = quantifier_def_stack.rbegin(); 
    mp_pos != quantifier_def_stack.rend(); ++ mp_pos) { // search from the closest binding
    if (IN(name,(*mp_pos) ))
      return & ( (*mp_pos) [name] );
  }
  ILA_DLOG("SmtlibInvariantParser.search_var") << "Not found var:"<<name<<std::endl;
  return nullptr;
} // search_quantified_var_stack


/// call back function to apply an uninterpreted function
/// fall-through case if it is not an defined op, if failed, return NULL
/// for unflattened-hierarchy: this should be the place where things are called
/// it could be directly the (pred state)
/// or (pred (pred state)) ... you need to pass the right instance name allow side
SmtTermInfoVlgPtr SyGuSInvariantParser::mk_function(
  const std::string &name, var_type * sort, 
  const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) {
  // we don't really rely on the sort here: actually it should be NULL
  ILA_DLOG("SmtlibInvariantParser.mk_function") << "make func:" << name << ", #arg" << args.size() << std::endl;
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

}; // namespace smt
}; // namespace ilang