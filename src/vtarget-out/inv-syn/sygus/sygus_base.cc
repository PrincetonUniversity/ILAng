/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// the base (contains the grammar part)
/// 
// Hongce Zhang (hongcez@princeton.edu)


#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_base.h>

namespace ilang {


// ------------------- no-eec templates --------------------- //

const std::string VarOrVal_template = R"#!#!#(
   (VarOrVal%width% (_ BitVec %width%) (Var%width%
                            Val%width%))
)#!#!#";

const std::string Var_template = R"#!#!#(
    (Var%width% (_ BitVec %width%) (%vars%))
)#!#!#";

const std::string Val_template = R"#!#!#(
    (Val%width% (_ BitVec %width%) (%vals%))
)#!#!#";

// ------------------- basic templates --------------------- //

const std::string cmpOp_template = R"#!#!#(
 (= Var%width% VarOrVal%width%)
 (bvult Var%width% VarOrVal%width%)
 (bvule Var%width% VarOrVal%width%)
 (bvugt Var%width% VarOrVal%width%)
 (bvuge Var%width% VarOrVal%width%) 
)#!#!#";


const std::string cmpOp_template_Bool = R"#!#!#(
 (= VarBool Conj)
 (not (= VarBool Conj))
 (= VarBool true)
 (= VarBool false)
)#!#!#";


const std::string syntax_basic = R"#!#!#(

(synth-fun INV (%arg%) Bool
  ((Start Bool (Conj))
   (Conj Bool (Clause
               (and Clause Conj)))
   (Clause Bool (Atom
                 (or Atom Clause)))
   (Atom Bool (Judgement
                 (not Judgement)))
   (Judgement Bool (%cmpOps%))
   %varOrVal%
   %vars%
   %vals%))
  
)#!#!#";

// ------------------- lv1 templates --------------------- //

const std::string cmpOp_lv1_template_Bool = R"#!#!#(
 (= ExprBool Conj)
 (not (= ExprBool Conj))
 (= ExprBool true)
 (= ExprBool false)
)#!#!#";

const std::string cmpOp_lv1_template = R"#!#!#(
 (= Exp%width% Exp%width%)
 (bvult Exp%width% Exp%width%)
 (bvule Exp%width% Exp%width%)
 (bvugt Exp%width% Exp%width%)
 (bvuge Exp%width% Exp%width%) 
)#!#!#";


const std::string exps_lv1_template_Bool = R"#!#!#(
(ExprBool Bool (VarBool
                true
                false
                (and VarBool VarBool)
                (or VarBool VarBool)
                (not VarBool)))
)#!#!#";

const std::string exps_lv1_template = R"#!#!#(  
 (Exp%width% (_ BitVec %width%) ( VarOrVal%width%
                      (bvadd VarOrVal%width% VarOrVal%width%)
                      (bvsub VarOrVal%width% VarOrVal%width%)
                      (bvand VarOrVal%width% VarOrVal%width%)
                      (bvor VarOrVal%width% VarOrVal%width%)
                      (bvneg VarOrVal%width%)
)#!#!#";

const std::string syntax_arithmetic_lv1 = R"#!#!#(
(synth-fun INV (%arg%) Bool
  ((Start Bool (Conj))
   (Conj Bool (Clause
               (and Clause Conj)))
   (Clause Bool (Atom
                 (or Atom Clause)))
   (Atom Bool (Judgement
                 (not Judgement)))
   (Judgement Bool (%cmpOps%))
   %exps%
   %varOrVal%
   %vars%
   %vals%))
  
)#!#!#";

// ------------------- lvR templates --------------------- //

const std::string & cmpOp_lvR_template = cmpOp_lv1_template;
const std::string & cmpOp_lvR_template_Bool = cmpOp_lv1_template_Bool;

const std::string exps_lvR_template_Bool = R"#!#!#(
(ExprBool Bool (VarBool
                true
                false
                (and ExprBool ExprBool)
                (or ExprBool ExprBool)
                (not ExprBool)))
)#!#!#";

const std::string exps_lvR_template = R"#!#!#(  
 (Exp%width% (_ BitVec %width%) ( VarOrVal%width%
                      (bvadd Exp%width% Exp%width%)
                      (bvsub Exp%width% Exp%width%)
                      (bvand Exp%width% Exp%width%)
                      (bvor Exp%width% Exp%width%)
                      (bvneg Exp%width%)
)#!#!#";

// this is the recursive type...
const std::string syntax_arithmetic_lvR = R"#!#!#(
(synth-fun INV (%arg%) Bool
  ((Start Bool (Conj))
   (Conj Bool (Clause
               (and Clause Conj)))
   (Clause Bool (Atom
                 (or Atom Clause)))
   (Atom Bool (Judgement
                 (not Judgement)))
   (Judgement Bool (%cmpOps%))
   %exps%
   %varOrVal%
   %vars%
   %vals%))
)#!#!#";



// the reset are 
// (constraint (INV #x0a #x0b ...))
// (check-synth)
// the sequence (order) is very important!
//


/*
; %arg%
;(x (_ BitVec 8)) (y (_ BitVec 8)) (z (_ BitVec 8))

; %cmpOps%
; (= Var8 VarOrVal8)
; (bvult Var8 VarOrVal8)
; (bvule Var8 VarOrVal8)
; (bvugt Var8 VarOrVal8)
; (bvuge Var8 VarOrVal8)  ; diff per bitvar length

; %varOrVal%
;   (VarOrVal8 (_ BitVec 8) (Var8
;                            Val8))
; %vars%
;   (Var8 (_ BitVec 8) (x y z))   ; you can also try extend/extract
; %vals%
;   (Val8 (_ BitVec 8) (#b00000000 #b00000001 #b00001111 #b11111111))
*/

Cvc4SygusBase::Cvc4SygusBase(
  const smt::YosysSmtParser & smt_design_info,       // the design info is needed
  const std::vector<std::string> & inv_var_name_vec, // the variables we are going to consider
  const sygus_options_t & SygusOptions,           // the options
  const std::string & customized_invariant_arg
  ) : 
  var_names (inv_var_name_vec), design_info(smt_design_info), 
  options(SygusOptions),
  inv_arg_customize(not customized_invariant_arg.empty()),
  invariant_arg(customized_invariant_arg) {

  ILA_WARN_IF(SygusOptions.UseExtract) << "Not supported yet : extract";
  ILA_WARN_IF(SygusOptions.UseExtend)  << "Not supported yet : extend";
  ILA_WARN_IF(SygusOptions.UseConcat)  << "Not supported yet : concat";

  arg_to_widx();
}

Cvc4SygusBase::~Cvc4SygusBase() { } // do nothing

// init two containers: args_list & width_to_names
// will be used by other functions
void Cvc4SygusBase::arg_to_widx() {
  const auto & var_idx = design_info.get_var_idx();

  for (auto && st : var_names) {
    ILA_ASSERT(IN(st,var_idx)) << "statename:" << st << " not found in design's smt!";
    const auto & var_tp_ptr = var_idx.at(st);
    auto vname = '|' + st + '|';
    args_list.push_back( '(' + vname + ' ' + var_tp_ptr->_type.toString() + ')' );
    if (var_tp_ptr->_type.is_bool())
      width_to_names[0].push_back(vname);
    else if (var_tp_ptr->_type.is_bv())
      width_to_names[var_tp_ptr->_type._width].push_back(vname);
    else
      ILA_ASSERT(false) << "Unhandled type:" << var_tp_ptr->_type._type ;
  }
}

// eec : extend/extract/concat
void Cvc4SygusBase::add_val_or_var_no_eec(std::string varOrVal) const {
    for(auto wn : width_to_names) {
      if(wn.first == 0) continue;
      varOrVal += ReplaceAll(VarOrVal_template, "%width%", std::to_string(wn.first));
    }
} // add_val_or_var_no_eec

// eec : extend/extract/concat
void Cvc4SygusBase::add_vars_no_eec(std::string vars) const {
    for(auto wn : width_to_names) {
      if(wn.first == 0) {
        vars += 
          ReplaceAll(
            ReplaceAll(Var_template, "%width%", "Bool"), 
            "%vars%",
            Join(wn.second, " ")
          );
      } else {
        vars += 
          ReplaceAll(
            ReplaceAll(Var_template, "%width%", std::to_string(wn.first)), 
            "%vars%",
            Join(wn.second, " ")
          );
      } // if-else
    } // for
} // add_vars_no_eec

void Cvc4SygusBase::add_vals(std::string & vals) const {
    for(auto wn : width_to_names) {
      if(wn.first == 0)
        continue; // no need for bool val
      vals += 
        ReplaceAll(
          ReplaceAll(Val_template, "%width%", std::to_string(wn.first)), 
          "%vals%",
          generate_syntax_const(wn.first)
        );
    } // for
} // add_vals

// basic template : no arithmetics
std::string Cvc4SygusBase::get_template_basic() const{
  // args
  std::string args = Join(args_list, " ");
  std::string cmpOp;
  {
    for(auto wn : width_to_names) {
      auto w = wn.first;
      if(w == 0) {
        cmpOp += cmpOp_template_Bool;
      }
      else {
        std::string cmpOpSub = ReplaceAll(cmpOp_lv1_template, "%width%",
          std::to_string(w));
        cmpOp += cmpOpSub;
      }
    }
  } // cmpOp

  std::string varOrVal;
  add_val_or_var_no_eec(varOrVal);

  std::string vars;
  add_vars_no_eec(vars);

  std::string vals;
  add_vals(vals);

  auto ret = syntax_basic;
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? args : invariant_arg);
  ret = ReplaceAll(ret,"%cmpOps%",   cmpOp);
  ret = ReplaceAll(ret,"%varOrVal%", varOrVal);
  ret = ReplaceAll(ret,"%vars%",     vars);
  ret = ReplaceAll(ret,"%vals%",     vals);

  return ret;
}

/*
; %arg%
;(x (_ BitVec 8)) (y (_ BitVec 8)) (z (_ BitVec 8))

; %cmpOps%
; (= Exp8 Exp8)
; (bvult Exp8 Exp8)
; (bvule Exp8 Exp8)
; (bvugt Exp8 Exp8)
; (bvuge Exp8 Exp8)  ; diff per bitvar length
;
; %exps%
; (Exp8 (_ BitVec 8) ( VarOrVal8
;                      (bvadd VarOrVal8 VarOrVal8)
;                      (bvsub VarOrVal8 VarOrVal8)
;                      (bvand VarOrVal8 VarOrVal8)
;                      (bvor VarOrVal8 VarOrVal8)
;                      (bvneg VarOrVal8)
;  ))
; ... for others as well

; %varOrVal%
;   (VarOrVal8 (_ BitVec 8) (Var8
;                            Val8))
; %vars%
;   (Var8 (_ BitVec 8) (x y z))   ; you can also try extend/extract
; %vals%
;   (Val8 (_ BitVec 8) (#b00000000 #b00000001 #b00001111 #b11111111))
*/

// basic template : no arithmetics
std::string Cvc4SygusBase::get_template_lv1() const{
  // args
  std::string args = Join(args_list, " ");
  std::string cmpOp;
  {
    for(auto wn : width_to_names) {
      auto w = wn.first;
      if(w == 0) {
        cmpOp += cmpOp_lv1_template_Bool;
      }
      else {
        std::string cmpOpSub = ReplaceAll(cmpOp_lv1_template, "%width%",
          std::to_string(w));
        cmpOp += cmpOpSub;
      }
    }
  } // cmpOp

  // %exps%
  std::string exps;
  {
    for (auto wn : width_to_names) {
      if (wn.first == 0)
        exps += exps_lv1_template_Bool;
      else {
        exps += ReplaceAll(exps_lv1_template, "%width%",
          std::to_string(wn.first) );
      } // if-else
    } // for
  } // exps

  std::string varOrVal;
  add_val_or_var_no_eec(varOrVal);

  std::string vars;
  add_vars_no_eec(vars);

  std::string vals;
  add_vals(vals);

  auto ret = syntax_arithmetic_lv1;
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? args : invariant_arg);
  ret = ReplaceAll(ret,"%cmpOps%",   cmpOp);
  ret = ReplaceAll(ret,"%exps%",     exps);
  ret = ReplaceAll(ret,"%varOrVal%", varOrVal);
  ret = ReplaceAll(ret,"%vars%",     vars);
  ret = ReplaceAll(ret,"%vals%",     vals);

  return ret;
}

/*
; %arg%
;(x (_ BitVec 8)) (y (_ BitVec 8)) (z (_ BitVec 8))

; %cmpOps%
; (= Exp8 Exp8)
; (bvult Exp8 Exp8)
; (bvule Exp8 Exp8)
; (bvugt Exp8 Exp8)
; (bvuge Exp8 Exp8)  ; diff per bitvar length
; ... you can try only the related length
; or all the length and use extract/concat/...

; %exps%
; (Exp8 (_ BitVec 8) (VarOrVal8
;                      (bvadd Exp8 Exp8)
;                      (bvsub Exp8 Exp8)
;                      (bvand Exp8 Exp8)
;                      (bvor Exp8 Exp8)
;                      (bvneg Exp8)
;  ))
; ... for others as well

; %varOrVal%
;   (VarOrVal8 (_ BitVec 8) (Var8
;                            Val8))
; %vars%
;   (Var8 (_ BitVec 8) (x y z))   ; you can also try extend/extract
; %vals%
;   (Val8 (_ BitVec 8) (#b00000000 #b00000001 #b00001111 #b11111111))
*/

std::string Cvc4SygusBase::get_template_lvR() const {
  // args
  std::string args = Join(args_list, " ");
  std::string cmpOp;
  {
    for(auto wn : width_to_names) {
      auto w = wn.first;
      if(w == 0) {
        cmpOp += cmpOp_lvR_template_Bool;
      }
      else {
        std::string cmpOpSub = ReplaceAll(cmpOp_lvR_template, "%width%",
          std::to_string(w));
        cmpOp += cmpOpSub;
      }
    }
  } // cmpOp

  // %exps%
  std::string exps;
  {
    for (auto wn : width_to_names) {
      if (wn.first == 0)
        exps += exps_lvR_template_Bool;
      else {
        exps += ReplaceAll(exps_lvR_template, "%width%",
          std::to_string(wn.first) );
      } // if-else
    } // for
  } // exps

  std::string varOrVal;
  add_val_or_var_no_eec(varOrVal);

  std::string vars;
  add_vars_no_eec(vars);

  std::string vals;
  add_vals(vals);

  auto ret = syntax_arithmetic_lvR;
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? args : invariant_arg);
  ret = ReplaceAll(ret,"%cmpOps%",   cmpOp);
  ret = ReplaceAll(ret,"%exps%",     exps);
  ret = ReplaceAll(ret,"%varOrVal%", varOrVal);
  ret = ReplaceAll(ret,"%vars%",     vars);
  ret = ReplaceAll(ret,"%vals%",     vals);

  return ret;
}


std::string Cvc4SygusBase::get_template() const {
  if (options.UseArithmetics == sygus_options_t::None)
    return get_template_basic();
  if (options.UseArithmetics == sygus_options_t::Level1)
    return get_template_lv1();
  if (options.UseArithmetics == sygus_options_t::Recursive)
    return get_template_lvR();
  ILA_ASSERT(false) << "Incorrect sygus arithmetic syntax configuration: " << options.UseArithmetics;
  return "";
}


std::string Cvc4SygusBase::convert_to_binary(unsigned v, unsigned w) {
  std::string ret;
  for (int i = 0; i < w; ++i) {
    ret = std::to_string(v&1) + ret;
    v = v >> 1;
  }
  ILA_ASSERT(v == 0);
  ILA_ASSERT(ret.size() == w);
  return "#b" + ret;
}

std::string Cvc4SygusBase::generate_syntax_const(unsigned w) const {
  ILA_ASSERT(w != 0);
  unsigned max = ( 0x1 << w ) - 1 ;
  std::vector<std::string> vals;
  if (w <= options.AllConstantUnderThisSize) {
    for (unsigned v = 0; v <= max; ++ v) {
      vals.push_back(convert_to_binary(v,w));
    }
  } else {
    std::set<unsigned> special_vals (options.SpecialValueForAllOtherWidth);
    special_vals.insert(0);
    special_vals.insert(1);
    special_vals.insert(2);
    special_vals.insert(max/2);
    special_vals.insert(max/2-1);
    special_vals.insert(max/2+1);
    special_vals.insert(max-1);
    special_vals.insert(max);
    for (auto  v : special_vals)
      vals.push_back(convert_to_binary(v,w));
  } //   
  return Join(vals, " "); // TODO:
}


}; // namespace ilang
