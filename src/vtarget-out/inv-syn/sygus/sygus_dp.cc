/// \file Invariant Synthesis -- SyGuS
/// to work with CVC4 (the latest version please)
/// The data-point (dp) approach
/// (not passing the whole transition function)
/// 
// Hongce Zhang (hongcez@princeton.edu)


#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/sygus/sygus_dp.h>

#include <fstream>

namespace ilang {

std::string cmpOp_template = R"#!#!#(
 (= Var%width% VarOrVal%width%)
 (bvult Var%width% VarOrVal%width%)
 (bvule Var%width% VarOrVal%width%)
 (bvugt Var%width% VarOrVal%width%)
 (bvuge Var%width% VarOrVal%width%) 
)#!#!#";


std::string cmpOp_template_Bool = R"#!#!#(
 (= VarBool Conj)
 (not (= VarBool Conj))
 (= VarBool true)
 (= VarBool false)
)#!#!#";


std::string VarOrVal_template = R"#!#!#(
   (VarOrVal%width% (_ BitVec %width%) (Var%width%
                            Val%width%))
)#!#!#";

std::string Var_template = R"#!#!#(
    (Var%width% (_ BitVec %width%) (%vars%))
)#!#!#";

std::string Val_template = R"#!#!#(
    (Val%width% (_ BitVec %width%) (%vals%))
)#!#!#";



std::string syntax_basic = R"#!#!#(

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



std::string syntax_arithmetic_lv1 = R"#!#!#(

; %arg%
;(x (_ BitVec 8)) (y (_ BitVec 8)) (z (_ BitVec 8))

; %cmpOps%
; (= Exp8 Exp8)
; (bvult Exp8 Exp8)
; (bvule Exp8 Exp8)
; (bvugt Exp8 Exp8)
; (bvuge Exp8 Exp8)  ; diff per bitvar length

; %exps%
; (Exp8 (_ BitVec 8) (
;                      (bvadd Var8 VarOrVal8)
;                      (bvsub Var8 VarOrVal8)
;                      (bvand Var8 VarOrVal8)
;                      (bvor Var8 VarOrVal8)
;                      (bvneg Var8)
;  ))
; ... for others as well

; %varOrVal%
;   (VarOrVal8 (_ BitVec 8) (Var8
;                            Val8))
; %vars%
;   (Var8 (_ BitVec 8) (x y z))   ; you can also try extend/extract
; %vals%
;   (Val8 (_ BitVec 8) (#b00000000 #b00000001 #b00001111 #b11111111))
  

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

// this is the recursive type...
std::string syntax_arithmetic_lvN = R"#!#!#(

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



std::string cnst_pos_template = "(constraint (INV %pos_vals%))";
std::string cnst_neg_template = "(constraint (not (INV %neg_vals%)))";
// the reset are 
// (constraint (INV #x0a #x0b ...))
// (check-synth)
// the sequence (order) is very important!
//




Cvc4SygusInputGenerator::Cvc4SygusInputGenerator(
  const smt::YosysSmtParser & smt_design_info,       // the design info is needed
  const std::vector<std::string> & inv_var_name_vec, // the variables we are going to consider
  const sygus_options_t & SygusOptions           // the options
  ) : 
  var_names (inv_var_name_vec), design_info(smt_design_info), 
  options(SygusOptions) {

  ILA_WARN_IF(SygusOptions.UseExtract) << "Not supported yet : extract";
  ILA_WARN_IF(SygusOptions.UseExtend)  << "Not supported yet : extend";
  ILA_WARN_IF(SygusOptions.UseConcat)  << "Not supported yet : concat";
    
}

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

std::string Cvc4SygusInputGenerator::get_template_basic() {

  const auto & var_idx = design_info.get_var_idx();

  std::map<unsigned, std::vector<std::string>> width_to_names;

  // args
  std::string args;
  {
    std::vector<std::string> args_list;
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
    args = Join(args_list, " ");
  } // args

  std::string cmpOp;
  {
    for(auto wn : width_to_names) {
      auto w = wn.first;
      if(w == 0) {
        cmpOp += cmpOp_template_Bool;
      }
      else {
        std::string cmpOpSub = ReplaceAll(cmpOp_template, "%width%",
          std::to_string(w));
        cmpOp += cmpOpSub;
      }
    }
  } // cmpOp

  std::string varOrVal;
  {
    for(auto wn : width_to_names) {
      if(wn.first == 0) continue;
      varOrVal += ReplaceAll(VarOrVal_template, "%width%", std::to_string(wn.first));
    }
  } // varOrVal

  std::string vars;
  {
    for(auto wn : width_to_names) {
      if(wn.first == 0) {
        varOrVal += 
          ReplaceAll(
            ReplaceAll(Var_template, "%width%", "Bool"), 
            "%vars%",
            Join(wn.second, " ")
          );
      } else {
        varOrVal += 
          ReplaceAll(
            ReplaceAll(Var_template, "%width%", std::to_string(wn.first)), 
            "%vars%",
            Join(wn.second, " ")
          );
      } // if-else
    } // for
  } // vars

  std::string vals;
  {
    for(auto wn : width_to_names) {
      if(wn.first == 0)
        continue; // no need for bool val
      varOrVal += 
        ReplaceAll(
          ReplaceAll(Val_template, "%width%", std::to_string(wn.first)), 
          "%vals%",
          generate_syntax_const(wn.first)
        );
    } // for
  } // vals
}

std::string convert_to_binary(unsigned v, unsigned w) {
  std::string ret;
  for (int i = 0; i < w; ++i) {
    ret = std::to_string(v&1) + ret;
    v = v >> 1;
  }
  ILA_ASSERT(v == 0);
  ILA_ASSERT(ret.size() == w);
  return "#b" + ret;
}

std::string Cvc4SygusInputGenerator::generate_syntax_const(unsigned w) const {
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
std::string Cvc4SygusInputGenerator::generate_datapoint_constraints(TraceDataPoints * dpts) const {
  // pos ex
  const auto & var_idx = design_info.get_var_idx();
  std::vector<std::string> constraints;
  for(const auto & aframe : dpts->pos_ex ) {
    std::vector<std::string> frame_vals;
    for (const auto & vname : var_names) {
      ILA_ASSERT(IN(vname, aframe)) << vname << " is not in the datapoint frame!";
      ILA_ASSERT(IN(vname, var_idx)) << vname << " is not in the smt!";
      auto data_type_ptr = var_idx.at(vname);
      auto width = data_type_ptr->_type._width;
      ILA_ASSERT( data_type_ptr->_type.GetBoolBvWidth() 
        == aframe.at(vname).second.GetBoolBvWidth()) << "Bit-width does not match!";
      if (data_type_ptr->_type.is_bool())
        frame_vals.push_back( aframe.at(vname).first == 0 ? "false" : "true"  );
      else
        frame_vals.push_back( convert_to_binary(aframe.at(vname).first, width));
    }
    constraints.push_back( ReplaceAll(cnst_pos_template, 
      "%pos_vals%", Join(frame_vals," ") ));
  }

  std::vector<std::string> frame_vals;
  const auto & aframe = dpts->neg_ex;
  for (const auto & vname : var_names) {
    ILA_ASSERT(IN(vname, aframe)) << vname << " is not in the datapoint frame!";
    ILA_ASSERT(IN(vname, var_idx)) << vname << " is not in the smt!";
    auto data_type_ptr = var_idx.at(vname);
    auto width = data_type_ptr->_type._width;
    ILA_ASSERT( data_type_ptr->_type.GetBoolBvWidth() 
      == aframe.at(vname).second.GetBoolBvWidth()) << "Bit-width does not match!";
    if (data_type_ptr->_type.is_bool())
      frame_vals.push_back( aframe.at(vname).first == 0 ? "false" : "true"  );
    else
      frame_vals.push_back( convert_to_binary(aframe.at(vname).first, width));
  }
  constraints.push_back( ReplaceAll(cnst_neg_template, 
    "%neg_vals%", Join(frame_vals," ") ));

  return Join(constraints,"\n"); // TODO:
}

void Cvc4SygusInputGenerator::ExportToFile(const std::string & fn, TraceDataPoints * dpts) {
  ILA_NOT_NULL(dpts);
  
  if (dpts->neg_ex.empty()) {
    ILA_ERROR << "No cex inserted! Cannot invoke SyGuS!";
    return;
  }

  std::ofstream fout(fn);
  if (not fout.is_open()) {
    ILA_ERROR << "Cannot open " << fn << " for write.";
    return;
  }
  // to do : add functions here
  // ignore those in dpts but not in inv_var_name_vec!
  fout << get_template_basic();
  fout << generate_datapoint_constraints(dpts);
  fout << "\n(check-synth)\n";
}



}; // namespace ilang