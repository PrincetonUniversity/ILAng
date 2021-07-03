/// \file rfexpr_to_smt.cc Refinement map to smt-lib2
///  Hongce Zhang (hongcez@princeton.edu)

#include <ilang/rfmap-in/rfexpr_to_smt.h>
#include <ilang/util/str_util.h>
#include <ilang/util/log.h>

#include <cassert>


namespace ilang {
namespace rfmap {


static std::vector<std::string> voperator_str_smt = {
  "bvmul", // STAR
  "bvadd",
  "bvsub",
  "bvshl",
  "bvashr",
  "bvshl",
  "bvlshr",
  "bvudiv",
  "#notsupported", // POW **
  "bvurem",
  "bvuge",
  "bvule",
  "bvugt",
  "bvult",
  "not",
  "and",
  "or",
  "=",
  "=",
  "#special", 
  "#special",
  "bvnot",
  "bvand",
  "bvor",
  "bvxor",
  "bvxnor",
  "bvnand",
  "bvnor", // B_NOR
  "#special", // select/extract  [idx] operator  A[i1][i2] -> index(index(A,i1),i2)   A[i1[i2]]  index(A, index(i1,i2))
  "#special", // extract [i1:i2] ternary
  "#special", // extract [i1:+i2] ternary
  "#special", // extract [i1:-i2] ternary
  "store", // store  A:<3>:5:<4>:6:<5>:7  (not supported yet)
  "#notsupported", // AT
  "ite", // ternary
  /*special ops*/
  "#special", // function app
  "concat", 
  "#special", // REPEAT  if it is const we can handle
  /*Placeholder*/
  "MK_CONST",
  "MK_VAR",

  "#notsupported" // delay
};

static RfMapVarType get_type(const RfExpr & in) {
  auto tp = in->get_annotation<TypeAnnotation>();
  if (tp == nullptr)
    return RfMapVarType();
  return tp->type;
}

static std::string smt_const(unsigned value, unsigned width) {
  auto ret = IntToStrCustomBase(value, 2, false);
  if(ret.length() > width)
    throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
  
  std::string zero;
  if(width > ret.length())
    for (unsigned idx = 0; idx < width - ret.length(); ++ idx)
      zero += "0";
  return "#b" + zero + ret;
} // smt_const

static std::string split_bit(const std::string & opstr, 
    unsigned width, const std::string & childstr) {
  if(width <= 1)
    return childstr;

  std::vector<std::string> child;
  for(unsigned idx = 0; idx < width; ++ idx) {
    auto ext = "(_ extract " + std::to_string(idx) + " " + std::to_string(idx) + ")";
    child.push_back("(" + ext + " " + childstr +  ")");
  }

  std::string ret = "(" + opstr + " " + child.at(0) + " " + child.at(1)+")";
  for (unsigned idx = 2; idx < child.size(); ++ idx)
    ret = "(" + opstr + " " + ret + " " + child.at(idx) +")";
  return ret;
}

// make sure in_bool -> out_bool
static std::string bvboolconvert(bool out_bool, bool in_bool, size_t inwidth, const std::string & in) {
	if(in_bool == out_bool)
	  return in;
	if(in_bool && !out_bool)
		return "(ite " + in + " #b1 #b0)";
	// else: !in_bool && out_bool
	return "(not (= " + in + " "+ smt_const(0, inwidth) +"))";	
}
// typeconvert
// intype == outtype 
// bv_n -> bool
// bool -> bv_n
// bv_n -> bv_(n+m)
// E: truncate
// E: array -> ?
// E: ? -> array

std::string RfExpr2Smt::to_smt2_const(const std::shared_ptr<verilog_expr::VExprAstConstant> & in, SmtType expected_type) {
  unsigned out;
  bool succ = _compute_const(in, out);
  if(!succ)
   throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);

  auto b_w_l = in->get_constant();
  auto width = std::get<1>(b_w_l);
  return bvboolconvert(request_bool, false, width, smt_const(out, width) );

} // to_smt2_const

std::string RfExpr2Smt::to_smt2_var(const std::shared_ptr<verilog_expr::VExprAstVar> & in, SmtType expected_type) {
  RfMapVarType tp = in->get_annotation<TypeAnnotation>()->type;
  auto ret = "|" + in->get_name().first+"|";
  if(!tp.is_array())
    ret = bvboolconvert(request_bool, false, tp.unified_width(), ret);
  return ret;
} // to_smt2_var


std::string RfExpr2Smt::to_smt2(const RfExpr &in, SmtType expected_type) {
  if(in->is_var()) {
    auto ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in);
    ILA_NOT_NULL(ptr);
    return to_smt2_var(ptr, request_bool);
  }
  if (in->is_constant()) {
    auto ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(in);
    ILA_NOT_NULL(ptr);
    return to_smt2_const(ptr, request_bool);
  }

  auto op_ = in->get_op();
  const auto & child_ = in->get_child();

  assert(op_ != verilog_expr::voperator::MK_CONST && op_ != verilog_expr::voperator::MK_CONST);

  unsigned idx = static_cast<unsigned>(op_);
  assert(idx < voperator_str_smt.size());
  auto opstr = voperator_str_smt.at(idx);
  if (opstr == "#notsupported")
    throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UntranslatedSmtlib2, opstr );
  // TODO: 

  if ( child_.size() == 1 &&
      (op_ == verilog_expr::voperator::L_NEG)) {

  	RfMapVarType tp = get_type(child_.at(0));
    return type_convert( expected_type, SmtType(tp,true),
    	"("+opstr + " " + to_smt2(child_.at(0), SmtType(tp,true) )+")");
  }

  if ( child_.size() == 1 &&
      (op_ == verilog_expr::voperator::B_NEG)) {

  	RfMapVarType tp = get_type(child_.at(0));
    return type_convert(expected_type, SmtType(tp,false),
    	"("+opstr + " " + to_smt2(child_.at(0), SmtType(tp,false))+")");
  }

  if (child_.size() == 1 &&
  		op_ == verilog_expr::voperator::PLUS) {

  	RfMapVarType tp = get_type(in);
  	return type_convert(expected_type, SmtType(tp,false),
  		to_smt2(child_.at(0), SmtType(tp,false)));
  }

  if (child_.size() == 1 &&
  		op_ == verilog_expr::voperator::MINUS) {

  	RfMapVarType tp = get_type(in);
  	return type_convert(expected_type, SmtType(tp,false),
  		"(bvsub " + smt_const(0,tp.unified_width()) + " "+to_smt2(child_.at(0), SmtType(tp,false)));
  }

  if (child_.size() == 1 &&
  	( op_ == verilog_expr::voperator::B_AND  ||
      op_ == verilog_expr::voperator::B_NAND ||
      op_ == verilog_expr::voperator::B_OR   ||
      op_ == verilog_expr::voperator::B_NOR  ||
      op_ == verilog_expr::voperator::B_XOR  ||
      op_ == verilog_expr::voperator::B_EQU
      )) {

  	RfMapVarType tp = get_type(in);

  	return type_convert(expected_type, SmtType(tp,false),
  		split_bit(opstr, tp.unified_width(), to_smt2(child_.at(0), SmtType(tp,false))));
  }

  RfMapVarType parent_tp = get_type(in);

  // binary or more
  switch(op_) {
    case verilog_expr::voperator::STAR: // mul
    case verilog_expr::voperator::PLUS:
    case verilog_expr::voperator::MINUS:
    case verilog_expr::voperator::ASL:
    case verilog_expr::voperator::ASR:
    case verilog_expr::voperator::LSL:
    case verilog_expr::voperator::LSR:
    case verilog_expr::voperator::DIV:
    case verilog_expr::voperator::MOD:
      assert(child_.size() == 2);
      return bvboolconvert(request_bool, false, parent_tp.unified_width(),
      "("+opstr+" " + to_smt2(child_.at(0),false) + " " + to_smt2(child_.at(1),false)+")"
      );
    	break;

    case verilog_expr::voperator::GTE:
    case verilog_expr::voperator::LTE:
    case verilog_expr::voperator::GT:
    case verilog_expr::voperator::LT:
    case verilog_expr::voperator::C_EQ:
    case verilog_expr::voperator::L_EQ:
      assert(child_.size() == 2);
      return bvboolconvert(request_bool, true, parent_tp.unified_width(),
      "("+opstr+" " + to_smt2(child_.at(0),false) + " " + to_smt2(child_.at(1),false)+")"
      );
    
    	break;

    case verilog_expr::voperator::C_NEQ:
    case verilog_expr::voperator::L_NEQ:
      assert(child_.size() == 2);
      return bvboolconvert(request_bool, true, parent_tp.unified_width(),
      "(not (= " + to_smt2(child_.at(0),false) + " " + to_smt2(child_.at(1),false)+"))"
      );
      break;

    case verilog_expr::voperator::L_AND:
    case verilog_expr::voperator::L_OR:
      assert(child_.size() == 2);
      return bvboolconvert(request_bool, true, parent_tp.unified_width(),
      "(" + opstr + " " + to_smt2(child_.at(0),true) + " " + to_smt2(child_.at(1),true)+")"
      );
      break;

    case verilog_expr::voperator::B_AND:
    case verilog_expr::voperator::B_OR:
    case verilog_expr::voperator::B_XOR:
    case verilog_expr::voperator::B_EQU:
    case verilog_expr::voperator::B_NAND:
    case verilog_expr::voperator::B_NOR:
      assert(child_.size() == 2);
      return bvboolconvert(request_bool, false, parent_tp.unified_width(),
      "(" + opstr + " " + to_smt2(child_.at(0),false) + " " + to_smt2(child_.at(1),false)+")"
      );
      break;

    	
    default:
    	break;
  } // end switch

  if(op_ == verilog_expr::voperator::INDEX) {
  	RfMapVarType tp = get_type(child_.at(0));
    if(tp.is_array()) {
      return bvboolconvert(request_bool, false, tp.unified_width(),
        "(select " + to_smt2(child_.at(0),false) + " " + to_smt2(child_.at(1),false) + ")");
    } // else is bv
    // request to index to be constant
    unsigned bitidx;
    bool succ = _compute_const(child_.at(1),bitidx);
    if(!succ)
      throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
    auto bitidxstr = std::to_string(bitidx);
    return  bvboolconvert(request_bool, false,1,
      "((_ extract " + bitidxstr + " " + bitidxstr+") " + to_smt2(child_.at(0),false)+")");
  }

  if(op_ == verilog_expr::voperator::IDX_PRT_SEL_PLUS ||
     op_ == verilog_expr::voperator::IDX_PRT_SEL_MINUS ||
     op_ == verilog_expr::voperator::RANGE_INDEX
    ) {
    
    unsigned l,r;
    bool succ = _compute_const(child_.at(1),l);
    succ = succ && _compute_const(child_.at(2),r);
    if(!succ)
      throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
    
    if(op_ == verilog_expr::voperator::IDX_PRT_SEL_PLUS)
      r = l + r - 1;
    else if (op_ == verilog_expr::voperator::IDX_PRT_SEL_MINUS)
      r = l - r + 1;
    auto lstr = std::to_string(l);
    auto rstr = std::to_string(r);
    return  bvboolconvert(request_bool, false,l-r+1,
      "((_ extract " + lstr + " " + rstr+") " + to_smt2(child_.at(0),false)+")");
  }
  
  if (op_ == verilog_expr::voperator::STORE_OP) {
    return "(store " + to_smt2(child_.at(0),false) + " " + to_smt2(child_.at(1),false)+")";
  }

  if (op_ == verilog_expr::voperator::TERNARY) {
    RfMapVarType tp = get_type(child_.at(1));
    if(tp.is_array())
      return "(ite " + to_smt2(child_.at(0), true) + " " +
        to_smt2(child_.at(1), false) + " " +
        to_smt2(child_.at(2), false) +")";
    return bvboolconvert(request_bool, false, tp.unified_width(),
      "(ite " + to_smt2(child_.at(0), true) + " " +
        to_smt2(child_.at(1), false) + " " +
        to_smt2(child_.at(2), false) +")");
  }

  if (op_ == verilog_expr::voperator::FUNCTION_APP)
    throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UntranslatedSmtlib2);
  
  if (op_ == verilog_expr::voperator::CONCAT) {
    assert( in->get_child_cnt() == 2 );
    return bvboolconvert(request_bool, false, parent_tp.unified_width(),
      "(concat " + to_smt2(child_.at(0), false) + " " +
      to_smt2(child_.at(1), false) + ")");
  }

  if (op_ == verilog_expr::voperator::REPEAT) {
    assert( in->get_child_cnt() == 2 );
    unsigned ntimes;
    if(!_compute_const(in->child(0), ntimes))
      throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
    assert(ntimes > 0);
    std::string ret = "(concat";
    std::string c1 = to_smt2(child_.at(1), false);
    for(unsigned idx = 0; idx < ntimes; ++idx)
      ret += " " + c1;
    ret += ")";
    return ret;
  }
  throw verilog_expr::VexpException(verilog_expr::ExceptionCause::UntranslatedSmtlib2);

  return "";

} // end to_smt



} // namespace rfmap
} // namespace ilang


