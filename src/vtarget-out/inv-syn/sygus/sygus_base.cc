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

// ------------------- hardwired templates --------------------- //
unsigned ctrl_data_sep_width = 5;

unsigned other_comp_sep_width = ctrl_data_sep_width;

std::vector<std::string> compOp({});

std::map<int,std::set<unsigned>> nums(
  {
    //{16,{0xff00,0xff01,0xff02, 0xff04, 0xff10, 0xff20}},
    {28,{0}}
  }
);
// bitwidth -> (op -> n-ary)
std::map<unsigned,std::map<std::string,unsigned>> arithmOp (
  {{128,{{"bvadd",2}}}}
);

extract_op::extract_op (unsigned h, unsigned l, unsigned f, unsigned t, const std::set<std::string> & s) :
  high(h),low(l),from(f),to(t),
    reps("extract_" + std::to_string(high) + "_" 
      + std::to_string(low) + "_" + std::to_string(from) + "_"
      + std::to_string(to)),
    replacement("(_ extract "+ std::to_string(high) + " " + std::to_string(low) +")"),
    smt("((_ extract "+ std::to_string(high) + " " + std::to_string(low) +") x)"),
    exheading("(define-fun |" + reps + "| ((x (_ BitVec " + std::to_string(from) + ")))"
      + " (_ BitVec " + std::to_string(to) + ") " + smt + ")"),
    from_state_name(s)
    { 
    ILA_ASSERT(h-l+1 == t);
    ILA_ASSERT(from >= to);
    ILA_ASSERT(h>=l); }

// to -> (op -> from)
// result_width : h,l, from, result_width
std::map<unsigned, std::vector<extract_op>> extractExtOp (
  {
    {16, {
      extract_op(15,0,128,16, {}),
      } }, //  extract_15_0_128_16
    /*{1, {
      extract_op(31,31,32,1),
      extract_op(20,20,32,1),
      extract_op(15,15,32,1),
      extract_op(7,7,32,1)
      } },
    {11, {extract_op(30,20,32,11)} },
    {12, {extract_op(31,20,32,12)} },
    {8, {extract_op(19,12,32,8)} },
    {6, {extract_op(30,25,32,6)} },
    {4, {
      extract_op(11,8,32,4),
      extract_op(19,16,32,4),
      extract_op(24,21,32,4)} },
    {31, {extract_op(31,1,32,31)} }*/
  }
);

std::vector<std::string> extra_heading;

const std::string cmpOp_lv1_template_Bool_hw = R"#!#!#(
 (= ExprBool Conj)
 (not (= ExprBool Conj))
 (= ExprBool true)
 (= ExprBool false)
)#!#!#";



const std::string cmpOp_lv1_eqOnly_template_hw = R"#!#!#(
  (= Exp%width% Exp%width%)
  (not (= Exp%width% Exp%width%))
)#!#!#";


const std::string exps_lv1_template_Bool_hw = R"#!#!#(
(ExprBool Bool (VarBool
                true
                false
                (and VarBool VarBool)
                (or VarBool VarBool)
                (not VarBool)))
)#!#!#";

const std::string exps_lv1_template_Bv1_hw = R"#!#!#(
 (Exp1 (_ BitVec 1) ( VarOrVal1
                      ;(bvand VarOrVal1 VarOrVal1)
                      ;(bvor VarOrVal1 VarOrVal1)
                      ;(bvnot VarOrVal1)
                      %extraOp%))
)#!#!#";

const std::string exps_lv1_template_hw = R"#!#!#(  
 (Exp%width% (_ BitVec %width%) ( VarOrVal%width%
                                  %extraOp%))
)#!#!#";

const std::string syntax_arithmetic_lv1_hw = R"#!#!#(
%extraheading%

(synth-fun INV (%arg%) Bool
  ((Start Bool (CONJIMP))

  (CONJIMP Bool (IMP
                 (and IMP CONJIMP)
                ))

  (IMP Bool ((=> PreCond PostCond)))

; ---------- controls ------------
   (PreCond Bool (true
                  CtrlAtom
                  CtrlConj))
   (CtrlConj Bool ((and CtrlAtom CtrlAtom)
                   (and CtrlAtom CtrlAtom CtrlAtom)))
   (CtrlAtom Bool (CtrlJudgement
                   (not CtrlJudgement)))   
    (CtrlJudgement Bool (%ctrlCmpOps%))

; ---------- data ------------
    (PostCond Bool (DataAtom
                  DataDisj))
   (DataDisj Bool ((or DataAtom DataAtom)))
   (DataAtom Bool (DataJudgement
                   (not DataJudgement)))   
   (DataJudgement Bool (%dataCmpOps%))

; ---------- common ------------
   %exps%
   %varOrVal%
   %vars%
   %vals%))
  
)#!#!#";


// ------------------- basic templates --------------------- //
const std::string cmpOp_template = R"#!#!#(
 (= Var%width% VarOrVal%width%)
 (bvult Var%width% VarOrVal%width%)
 (bvule Var%width% VarOrVal%width%)
 (bvugt Var%width% VarOrVal%width%)
 (bvuge Var%width% VarOrVal%width%) 
)#!#!#";

const std::string cmpOp_eqOnly_template = R"#!#!#(
  (= Var%width% VarOrVal%width%)
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
)#!#!#";


const std::string cmpOp_lv1_eqOnly_template = R"#!#!#(
  (= Exp%width% Exp%width%)
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
                      (bvnot VarOrVal%width%)))
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

const std::string & cmpOp_lvR_eqOnly_template = cmpOp_lv1_eqOnly_template;
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
                      (bvnot Exp%width%)
                      (bvneg Exp%width%)))
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


// ------------------------------------ 




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
  const std::string & customized_invariant_arg,
  const std::map<std::string, int> & width_info,
  const Cvc4Syntax & syntax
  ) : 
  var_names (inv_var_name_vec), design_info(smt_design_info), 
  options(SygusOptions),
  additional_width_info(width_info),
  inv_arg_customize(not customized_invariant_arg.empty()),
  invariant_arg(customized_invariant_arg) {

  ILA_WARN_IF(SygusOptions.UseExtract) << "Not supported yet : extract";
  ILA_WARN_IF(SygusOptions.UseExtend)  << "Not supported yet : extend";
  ILA_WARN_IF(SygusOptions.UseConcat)  << "Not supported yet : concat";

  // assign syntax
  ctrl_data_sep_width = syntax.ctrl_data_sep_width;
  other_comp_sep_width = syntax.other_comp_sep_width;
  compOp = syntax.compOp;
  nums = syntax.nums;
  arithmOp = syntax.arithmOp;
  extractExtOp = syntax.extractExtOp;

  arg_to_widx();
}

Cvc4SygusBase::~Cvc4SygusBase() { } // do nothing

// init two containers: args_list & width_to_names
// will be used by other functions
void Cvc4SygusBase::arg_to_widx() {
  const auto & var_idx = design_info.get_var_idx();

  for (auto && st : var_names) {
    smt::var_type tp;
    if (IN(st,var_idx)) {
      tp = var_idx.at(st)->_type;
    } else if (IN(st,additional_width_info)) {
      tp._type = tp.BV;
      tp._width = additional_width_info.at(st);
    } else
      ILA_ASSERT(false) << "statename:" << st << " not found in design's smt / additional info!";
      
    auto vname = '|' + st + '|';
    args_list.push_back( '(' + vname + ' ' + tp.toString() + ')' );
    if (tp.is_bool())
      width_to_names[0].push_back(vname);
    else if (tp.is_bv())
      width_to_names[tp._width].push_back(vname);
    else
      ILA_ASSERT(false) << "Unhandled type:" << tp._type ;
  }
}

// eec : extend/extract/concat
void Cvc4SygusBase::add_val_or_var_no_eec(std::string & varOrVal) const {
    for(auto wn : width_to_names) {
      if(wn.first == 0) continue;
      varOrVal += ReplaceAll(VarOrVal_template, "%width%", std::to_string(wn.first));
    }
} // add_val_or_var_no_eec

// eec : extend/extract/concat
void Cvc4SygusBase::add_vars_no_eec(std::string & vars) const {
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
        std::string cmpOpSub = ReplaceAll(
          (options.UseEqOnlyBvComparison) ? cmpOp_eqOnly_template : cmpOp_template,
          "%width%",
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
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? invariant_arg : args );
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
        std::string cmpOpSub = ReplaceAll( // remove the fancy comparators
          (options.UseEqOnlyBvComparison) ? cmpOp_lv1_eqOnly_template : cmpOp_lv1_template,
          "%width%",
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
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? invariant_arg : args);
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
        std::string cmpOpSub = ReplaceAll(
           (options.UseEqOnlyBvComparison) ? cmpOp_lvR_eqOnly_template : cmpOp_lvR_template,
           "%width%",
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
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? invariant_arg : args);
  ret = ReplaceAll(ret,"%cmpOps%",   cmpOp);
  ret = ReplaceAll(ret,"%exps%",     exps);
  ret = ReplaceAll(ret,"%varOrVal%", varOrVal);
  ret = ReplaceAll(ret,"%vars%",     vars);
  ret = ReplaceAll(ret,"%vals%",     vals);

  return ret;
}

std::string Cvc4SygusBase::get_template_hardwired() const{
  std::vector<std::string> extra_heading_local(extra_heading);

  // args
  std::string args = Join(args_list, " ");
  
  std::string dataCmpOp;
  std::string ctrlCmpOp;
  {
    for(auto wn : width_to_names) {
      auto w = wn.first;
      if(w == 0) {
        ctrlCmpOp += cmpOp_lv1_template_Bool_hw;
      }
      else {
        auto compTempl = cmpOp_lv1_eqOnly_template_hw;
        if (w > other_comp_sep_width) {
          for (auto && op : compOp) {
            compTempl += "(" + op +" Exp%width% Exp%width%)\n";
          }
        } // add sep
        std::string cmpOpSub = ReplaceAll( // remove the fancy comparators
          compTempl,
          "%width%",
          std::to_string(w));

        if (w > ctrl_data_sep_width) {
          // it could be just data
          dataCmpOp += cmpOpSub;    
        } else {
          // it is control/data
          dataCmpOp += cmpOpSub;
          ctrlCmpOp += cmpOpSub;       
        }
      }
    }
    if (dataCmpOp.empty()) dataCmpOp = "true";
    if (ctrlCmpOp.empty()) ctrlCmpOp = "true";
  } // cmpOp/dataOp


  // %exps%
  std::string exps;
  {
    for (auto wn : width_to_names) {
      if (wn.first == 0)
        exps += exps_lv1_template_Bool_hw;
      else if (wn.first == 1) {
        std::string extraOp = "";
        if ( IN(1, extractExtOp) && ! extractExtOp.at(1).empty() ) {
          for (auto && extractOp : extractExtOp.at(1) ) {
            if ( not IN( extractOp.from, width_to_names) ) continue;
            extra_heading_local.push_back(extractOp.exheading+"\n"); 
            corrections.insert(std::make_pair(extractOp.reps, extractOp.replacement));
            if (extractOp.from_state_name.empty())
              extraOp += "(" + extractOp.reps + " Var" + std::to_string(extractOp.from) + ")\n";
            else {
              for(auto && vn : extractOp.from_state_name) {
                for(auto && sn : width_to_names.at(extractOp.from)) {
                  if ( sn.find(vn) != sn.npos ) {
                    extraOp += "(" + extractOp.reps + " " + sn + ")\n";
                  }
                }
              }
            } // end if there specify the state
            
          }
        }

        auto expr_tmpl = ReplaceAll(exps_lv1_template_Bv1_hw, "%extraOp%", extraOp);
        exps += expr_tmpl;
      } else { // now index into the arithmOp
        std::string extraOp = "";
        auto width = wn.first;
        if ( IN( width, arithmOp) && ! arithmOp.at(width).empty() ) {
          for (auto && op_ary_pair : arithmOp.at(width)) {
            extraOp += "(" + op_ary_pair.first;
            for (size_t idx = 0; idx < op_ary_pair.second; ++ idx) 
              extraOp += " VarOrVal%width%";
            extraOp += ")\n";
          }
        } // check normal op
        if ( IN(width, extractExtOp) && ! extractExtOp.at(width).empty() ) {
          for (auto && extractOp : extractExtOp.at(width) ) {
            if ( not IN( extractOp.from, width_to_names) ) continue;
            extra_heading_local.push_back(extractOp.exheading+"\n"); 
            corrections.insert(std::make_pair(extractOp.reps, extractOp.replacement));
            if (extractOp.from_state_name.empty())
              extraOp += "(" + extractOp.reps + " Var" + std::to_string(extractOp.from) + ")\n";
            else {
              for(auto && vn : extractOp.from_state_name) {
                for(auto && sn : width_to_names.at(extractOp.from)) {
                  if ( sn.find(vn) != sn.npos ) {
                    extraOp += "(" + extractOp.reps + " " + sn + ")\n";
                  }
                }
              }
            } // end if there specify the state
          }
        }

        auto expr_tmpl = ReplaceAll(exps_lv1_template_hw, "%extraOp%", extraOp);

        exps += ReplaceAll(expr_tmpl, "%width%",
          std::to_string(width) );
      } // if-else
    } // for
  } // exps

  std::string varOrVal;
  add_val_or_var_no_eec(varOrVal);

  std::string vars;
  add_vars_no_eec(vars);

  std::string vals;
  add_vals(vals);

  std::string heading;
  for (auto && h : extra_heading_local)
    heading += h + "\n";

  auto ret = syntax_arithmetic_lv1_hw;
  ret = ReplaceAll(ret,"%extraheading%", heading);
  ret = ReplaceAll(ret,"%arg%",      inv_arg_customize ? invariant_arg : args);
  ret = ReplaceAll(ret,"%ctrlCmpOps%",   ctrlCmpOp);
  ret = ReplaceAll(ret,"%dataCmpOps%",   dataCmpOp);
  ret = ReplaceAll(ret,"%exps%",     exps);
  ret = ReplaceAll(ret,"%varOrVal%", varOrVal);
  ret = ReplaceAll(ret,"%vars%",     vars);
  ret = ReplaceAll(ret,"%vals%",     vals);
  
  return ret; // please check
}

std::string Cvc4SygusBase::get_template() const {
  return get_template_hardwired();

  if (options.UseArithmetics == sygus_options_t::_use_arithmetics_t::None)
    return get_template_basic();
  if (options.UseArithmetics == sygus_options_t::_use_arithmetics_t::Level1)
    return get_template_lv1();
  if (options.UseArithmetics == sygus_options_t::_use_arithmetics_t::Recursive)
    return get_template_lvR();
  ILA_ASSERT(false) << "Incorrect sygus arithmetic syntax configuration: " << options.UseArithmetics;
  return "";
}

std::string Cvc4SygusBase::generate_syntax_const(unsigned w) const {
  ILA_ASSERT(w != 0);
  unsigned max = ( 0x1 << w ) - 1 ;
  std::vector<std::string> vals;
  if (w <= options.AllConstantUnderThisSize) {
    for (unsigned v = 0; v <= max; ++ v) {
      vals.push_back(smt::convert_to_binary(v,w));
    }
  } else {
    ILA_WARN_IF (not options.SpecialValueForAllOtherWidth.empty())
      << "FIXME: currently `SpecialValueForAllOtherWidth` is ignored!";
    std::set<unsigned> special_vals;
    special_vals.insert(0);

    if (IN(w,nums)) {
      for (auto n : nums.at(w))
        special_vals.insert(n);
    }

    for (auto  v : special_vals)
      vals.push_back(smt::convert_to_binary(v,w));
    /*
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
      vals.push_back(smt::convert_to_binary(v,w));*/
  } //   
  return Join(vals, " "); // TODO:
}


const Cvc4SygusBase::correction_t & Cvc4SygusBase::GetCorrectionMap() const {
  return corrections;
}


}; // namespace ilang
