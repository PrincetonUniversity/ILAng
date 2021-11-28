/// \file rfexpr_to_smt.cc Refinement map to smt-lib2
///  Hongce Zhang (hongcez@princeton.edu)

#include <ilang/rfmap-in/rfexpr_to_smt.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>

#include <cassert>

namespace ilang {
namespace rfmap {

std::string SmtType::type_to_smt2() const {
  if (is_bool())
    return "Bool";
  if (is_bv())
    return "(_ BitVec " + std::to_string(unified_width()) + ")";
  ILA_ERROR_IF(!is_array()) << "Does not know how to translate unknown type";
  return "(Array (_ BitVec " + std::to_string(addr_width) + ") (_ BitVec " +
         std::to_string(data_width) + "))";
}

static std::vector<std::string> voperator_str_smt = {
    "bvmul", // STAR
    "bvadd", "bvsub", "bvshl", "bvashr", "bvshl", "bvlshr", "bvudiv",
    "#notsupported", // POW **
    "bvurem", "bvuge", "bvule", "bvugt", "bvult", "not", "and", "or", "=", "=",
    "#special", "#special", "bvnot", "bvand", "bvor", "bvxor", "bvxnor",
    "bvnand",
    "bvnor",    // B_NOR
    "#special", // select/extract  [idx] operator  A[i1][i2] ->
                // index(index(A,i1),i2)   A[i1[i2]]  index(A, index(i1,i2))
    "#special", // extract [i1:i2] ternary
    "#special", // extract [i1:+i2] ternary
    "#special", // extract [i1:-i2] ternary
    "store",    // store  A:<3>:5:<4>:6:<5>:7  (not supported yet)
    "#notsupported", // AT
    "ite",           // ternary
    /*special ops*/
    "#special", // function app
    "concat",
    "#special", // REPEAT  if it is const we can handle
    /*Placeholder*/
    "MK_CONST", "MK_VAR",

    "#notsupported", // delay
    "#special", "#special" // forall and exist
};

static RfMapVarType get_type(const RfExpr& in) {
  auto tp = in->get_annotation<TypeAnnotation>();
  if (tp == nullptr)
    return RfMapVarType();
  return tp->type;
}

static std::string smt_const(unsigned value, unsigned width) {
  auto ret = IntToStrCustomBase(value, 2, false);
  if (ret.length() > width) {
    ILA_ERROR << "Creating SMT constant with value " << value
              << " width: " << width;
    throw verilog_expr::VexpException(
        verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
  }

  std::string zero;
  if (width > ret.length())
    for (unsigned idx = 0; idx < width - ret.length(); ++idx)
      zero += "0";
  return "#b" + zero + ret;
} // smt_const

static std::string split_bit(const std::string& opstr, unsigned width,
                             const std::string& childstr) {
  if (width <= 1)
    return childstr;

  std::vector<std::string> child;
  for (unsigned idx = 0; idx < width; ++idx) {
    auto ext =
        "(_ extract " + std::to_string(idx) + " " + std::to_string(idx) + ")";
    child.push_back("(" + ext + " " + childstr + ")");
  }

  std::string ret = "(" + opstr + " " + child.at(0) + " " + child.at(1) + ")";
  for (unsigned idx = 2; idx < child.size(); ++idx)
    ret = "(" + opstr + " " + ret + " " + child.at(idx) + ")";
  return ret;
}

static SmtType common_type(RfMapVarType tp1, RfMapVarType tp2) {
  if (tp1.is_array() || tp2.is_array()) {
    ILA_CHECK(tp2.is_array() && tp1.is_array() &&
              tp2.addr_width == tp1.addr_width &&
              tp2.data_width == tp1.data_width);
    return SmtType(tp1, false);
  }

  if (tp1.is_bv() && tp2.is_bv()) {
    return SmtType(std::max(tp1.unified_width(), tp2.unified_width()));
  }

  if (tp1.is_unknown() || tp2.is_unknown()) {
    if (!tp1.is_unknown())
      return SmtType(tp1, false);
    if (!tp2.is_unknown())
      return SmtType(tp2, false);
  }
  ILA_CHECK(false) << "unable to determine common type";
  return SmtType(); // should not be reachable
}

static std::string extend_width(const std::string& in, unsigned inw,
                                unsigned outw) {
  ILA_CHECK(outw > inw);
  return "(concat " + smt_const(0, outw - inw) + " " + in + ")";
}
// make sure in_bool -> out_bool
static std::string type_convert(SmtType out_tp, SmtType in_tp,
                                const std::string& in) {
  if (out_tp == in_tp)
    return in;

  if (out_tp.is_bool() && in_tp.is_bv()) {
    return "(not (= " + in + " " + smt_const(0, in_tp.unified_width()) + "))";
  }

  if (in_tp.is_bool() && out_tp.is_bv()) {
    auto retstr = "(ite " + in + " #b1 #b0)";
    ILA_CHECK(out_tp.unified_width() > 0);
    if(out_tp.unified_width() == 1)
      return retstr;
    return extend_width("(ite " + in + " #b1 #b0)", 1, out_tp.unified_width());
  }

  if (in_tp.is_bv() && out_tp.is_bv() &&
      in_tp.unified_width() != out_tp.unified_width()) {
    ILA_ASSERT(out_tp.unified_width() > in_tp.unified_width())
        << "[Convert to SMT] cutting input bit-vector, not allowed.";
    return extend_width(in, in_tp.unified_width(), out_tp.unified_width());
  }

  if (in_tp.is_array() || out_tp.is_array()) {
    ILA_CHECK(false) << "Unable to convert array of different sizes";
  }
  ILA_CHECK(false) << "Unable to convert types";
  return "|ERROR|";
}

// typeconvert
// intype == outtype
// bv_n -> bool
// bool -> bv_n
// bv_n -> bv_(n+m)
// E: truncate
// E: array -> ?
// E: ? -> array

std::string RfExpr2Smt::to_smt2_const(
    const std::shared_ptr<verilog_expr::VExprAstConstant>& in,
    SmtType expected_type) {
  unsigned out;
  bool succ = _compute_const(in, out);
  if (!succ)
    throw verilog_expr::VexpException(
        verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);

  auto b_w_l = in->get_constant();
  auto width = std::get<1>(b_w_l);
  if (width == 0)
    width = expected_type.unified_width();
  return type_convert(expected_type, SmtType(width), smt_const(out, width));

} // to_smt2_const

std::string
RfExpr2Smt::to_smt2_var(const std::shared_ptr<verilog_expr::VExprAstVar>& in,
                        SmtType expected_type) {
  RfMapVarType tp = get_type(in);
  auto ret = "|" + in->get_name().first + "|";
  if (!tp.is_array())
    ret = type_convert(expected_type, SmtType(tp.unified_width()), ret);
  else
    ILA_ASSERT(expected_type == SmtType(tp, false));
  return ret;
} // to_smt2_var

std::string RfExpr2Smt::to_smt2(const RfExpr& in, SmtType expected_type) {
  if (in->is_var()) {
    auto ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstVar>(in);
    ILA_NOT_NULL(ptr);
    return to_smt2_var(ptr, expected_type);
  }
  if (in->is_constant()) {
    auto ptr = std::dynamic_pointer_cast<verilog_expr::VExprAstConstant>(in);
    ILA_NOT_NULL(ptr);
    return to_smt2_const(ptr, expected_type);
  }

  auto op_ = in->get_op();
  const auto& child_ = in->get_child();

  ILA_ASSERT(op_ != verilog_expr::voperator::MK_CONST &&
             op_ != verilog_expr::voperator::MK_CONST);

  unsigned idx = static_cast<unsigned>(op_);
  ILA_ASSERT(idx < voperator_str_smt.size());
  auto opstr = voperator_str_smt.at(idx);
  if (opstr == "#notsupported")
    throw verilog_expr::VexpException(
        verilog_expr::ExceptionCause::UntranslatedSmtlib2, opstr);
  // TODO:

  if (child_.size() == 1 && (op_ == verilog_expr::voperator::L_NEG)) {

    RfMapVarType tp = get_type(child_.at(0));
    return type_convert(expected_type, SmtType(tp, true),
                        "(" + opstr + " " +
                            to_smt2(child_.at(0), SmtType(tp, true)) + ")");
  }

  if (child_.size() == 1 && (op_ == verilog_expr::voperator::B_NEG)) {

    RfMapVarType tp = get_type(child_.at(0));
    return type_convert(expected_type, SmtType(tp, false),
                        "(" + opstr + " " +
                            to_smt2(child_.at(0), SmtType(tp, false)) + ")");
  }

  if (child_.size() == 1 && op_ == verilog_expr::voperator::PLUS) {

    RfMapVarType tp = get_type(in);
    return type_convert(expected_type, SmtType(tp, false),
                        to_smt2(child_.at(0), SmtType(tp, false)));
  }

  if (child_.size() == 1 && op_ == verilog_expr::voperator::MINUS) {

    RfMapVarType tp = get_type(in);
    return type_convert(expected_type, SmtType(tp, false),
                        "(bvsub " + smt_const(0, tp.unified_width()) + " " +
                            to_smt2(child_.at(0), SmtType(tp, false)));
  }

  if (child_.size() == 1 && (op_ == verilog_expr::voperator::B_AND ||
                             op_ == verilog_expr::voperator::B_NAND ||
                             op_ == verilog_expr::voperator::B_OR ||
                             op_ == verilog_expr::voperator::B_NOR ||
                             op_ == verilog_expr::voperator::B_XOR ||
                             op_ == verilog_expr::voperator::B_EQU)) {

    RfMapVarType tp = get_type(in);

    return type_convert(expected_type, SmtType(tp, false),
                        split_bit(opstr, tp.unified_width(),
                                  to_smt2(child_.at(0), SmtType(tp, false))));
  }

  RfMapVarType parent_tp = get_type(in);

  // binary or more
  switch (op_) {
  case verilog_expr::voperator::STAR: // mul
  case verilog_expr::voperator::PLUS:
  case verilog_expr::voperator::MINUS:
  case verilog_expr::voperator::ASL:
  case verilog_expr::voperator::ASR:
  case verilog_expr::voperator::LSL:
  case verilog_expr::voperator::LSR:
  case verilog_expr::voperator::DIV:
  case verilog_expr::voperator::MOD:
    ILA_ASSERT(child_.size() == 2);
    return type_convert(
        expected_type, SmtType(parent_tp, false),
        "(" + opstr + " " + to_smt2(child_.at(0), SmtType(parent_tp, false)) +
            " " + to_smt2(child_.at(1), SmtType(parent_tp, false)) + ")");
    break;

  case verilog_expr::voperator::GTE:
  case verilog_expr::voperator::LTE:
  case verilog_expr::voperator::GT:
  case verilog_expr::voperator::LT:
  case verilog_expr::voperator::C_EQ:
  case verilog_expr::voperator::L_EQ:
    ILA_ASSERT(child_.size() == 2);
    {
      SmtType common_tp =
          common_type(get_type(child_.at(0)), get_type(child_.at(1)));
      return type_convert(expected_type, SmtType(parent_tp, true),
                          "(" + opstr + " " + to_smt2(child_.at(0), common_tp) +
                              " " + to_smt2(child_.at(1), common_tp) + ")");
    }
    break;

  case verilog_expr::voperator::C_NEQ:
  case verilog_expr::voperator::L_NEQ:
    ILA_ASSERT(child_.size() == 2);
    { // expect common_type to make bool false?
      SmtType common_tp =
          common_type(get_type(child_.at(0)), get_type(child_.at(1)));
      return type_convert(expected_type, SmtType(parent_tp, true),
                          "(not (= " + to_smt2(child_.at(0), common_tp) + " " +
                              to_smt2(child_.at(1), common_tp) + "))");
      break;
    }

  case verilog_expr::voperator::L_AND:
  case verilog_expr::voperator::L_OR:
    ILA_ASSERT(child_.size() == 2);
    return type_convert(
        expected_type, SmtType(parent_tp, true),
        "(" + opstr + " " +
            to_smt2(child_.at(0), SmtType(get_type(child_.at(0)), true)) + " " +
            to_smt2(child_.at(1), SmtType(get_type(child_.at(1)), true)) + ")");
    break;

  case verilog_expr::voperator::B_AND:
  case verilog_expr::voperator::B_OR:
  case verilog_expr::voperator::B_XOR:
  case verilog_expr::voperator::B_EQU:
  case verilog_expr::voperator::B_NAND:
  case verilog_expr::voperator::B_NOR: {
    SmtType common_tp =
        common_type(get_type(child_.at(0)), get_type(child_.at(1)));

    ILA_ASSERT(child_.size() == 2);
    return type_convert(expected_type, SmtType(parent_tp, false),
                        "(" + opstr + " " + to_smt2(child_.at(0), common_tp) +
                            " " + to_smt2(child_.at(1), common_tp) + ")");
    break;
  }

  default:
    break;
  } // end switch

  if (op_ == verilog_expr::voperator::INDEX) {
    RfMapVarType tp = get_type(child_.at(0));
    if (tp.is_array()) {
      return type_convert(
          expected_type, SmtType(tp.unified_width()),
          "(select " + to_smt2(child_.at(0), SmtType(tp, false)) + " " +
              to_smt2(child_.at(1), SmtType(tp.addr_width)) + ")");
    } // else is bv
    // request to index to be constant
    unsigned bitidx;
    bool succ = _compute_const(child_.at(1), bitidx);
    if (!succ)
      throw verilog_expr::VexpException(
          verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
    auto bitidxstr = std::to_string(bitidx);
    return type_convert(expected_type, SmtType(1) /* (_ BitVec 1) */,
                        "((_ extract " + bitidxstr + " " + bitidxstr + ") " +
                            to_smt2(child_.at(0), SmtType(tp, false)) + ")");
  } // end if INDEX

  if (op_ == verilog_expr::voperator::IDX_PRT_SEL_PLUS ||
      op_ == verilog_expr::voperator::IDX_PRT_SEL_MINUS ||
      op_ == verilog_expr::voperator::RANGE_INDEX) {

    unsigned l, r;
    bool succ = _compute_const(child_.at(1), l);
    succ = succ && _compute_const(child_.at(2), r);
    if (!succ)
      throw verilog_expr::VexpException(
          verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);

    if (op_ == verilog_expr::voperator::IDX_PRT_SEL_PLUS)
      r = l + r - 1;
    else if (op_ == verilog_expr::voperator::IDX_PRT_SEL_MINUS)
      r = l - r + 1;
    auto lstr = std::to_string(l);
    auto rstr = std::to_string(r);
    RfMapVarType tp = get_type(child_.at(0));
    return type_convert(expected_type, SmtType(l - r + 1),
                        "((_ extract " + lstr + " " + rstr + ") " +
                            to_smt2(child_.at(0), SmtType(tp, false)) + ")");
  } // IDX_PRT_SEL_PLUS, IDX_PRT_SEL_MINUS, RANGE_INDEX

  if (op_ == verilog_expr::voperator::STORE_OP) {
    SmtType tp0(get_type(child_.at(0)), false);
    SmtType tp1(get_type(child_.at(1)), false);
    // no need to convert
    ILA_ASSERT(expected_type == tp0);
    return "(store " + to_smt2(child_.at(0), tp0) + " " +
           to_smt2(child_.at(1), tp1) + ")";
    // do not convert as we are unable to do so
  } // STORE_OP

  if (op_ == verilog_expr::voperator::TERNARY) {
    RfMapVarType parent_tp = get_type(in);
    // you need to handle the case of array
    SmtType common_tp =
        common_type(get_type(child_.at(1)), get_type(child_.at(2)));

    if (parent_tp.is_array()) {
      // do not convert as we are unable to do so
      return "(ite " + to_smt2(child_.at(0), SmtType()) + " " +
             to_smt2(child_.at(1), common_tp) + " " +
             to_smt2(child_.at(2), common_tp) + ")";
    } // else

    return type_convert(expected_type, common_tp,
                        "(ite " + to_smt2(child_.at(0), SmtType()) + " " +
                            to_smt2(child_.at(1), common_tp) + " " +
                            to_smt2(child_.at(2), common_tp) + ")");
  }

  if (op_ == verilog_expr::voperator::FUNCTION_APP)
    throw verilog_expr::VexpException(
        verilog_expr::ExceptionCause::UntranslatedSmtlib2);

  if (op_ == verilog_expr::voperator::CONCAT) {
    ILA_ASSERT(in->get_child_cnt() == 2);
    return type_convert(
        expected_type, SmtType(parent_tp, false),
        "(concat " +
            to_smt2(child_.at(0), SmtType(get_type(child_.at(0)), false)) +
            " " +
            to_smt2(child_.at(1), SmtType(get_type(child_.at(1)), false)) +
            ")");
  } // CONCAT

  if (op_ == verilog_expr::voperator::REPEAT) {
    ILA_ASSERT(in->get_child_cnt() == 2);
    unsigned ntimes;
    if (!_compute_const(in->get_child().at(0), ntimes))
      throw verilog_expr::VexpException(
          verilog_expr::ExceptionCause::UnknownNumberSmtTranslation);
    ILA_ASSERT(ntimes > 0);
    std::string c1 =
        to_smt2(child_.at(1), SmtType(get_type(child_.at(1)), false));
    std::string ret = "(concat " + c1 + " " + c1 + ")";

    for (unsigned idx = 2; idx < ntimes; ++idx)
      ret = "(concat " + ret + " " + c1 + ")";

    return type_convert(expected_type, SmtType(parent_tp, false), ret);
  }

  if(op_ == verilog_expr::voperator::FORALL || op_ == verilog_expr::voperator::EXIST)  {
    ILA_ASSERT(in->get_child_cnt() == 1);
    ILA_ASSERT(in->get_str_parameter().size() == 1);
    ILA_ASSERT(in->get_parameter().size() == 1);
    const std::string & qvar = in->get_str_parameter().at(0);
    auto width = in->get_parameter().at(0);

    std::string c1 =
        to_smt2(child_.at(0), SmtType(get_type(child_.at(0)), true));
    std::string quantifier = op_ == verilog_expr::voperator::FORALL ? "forall" : "exists";
    std::string ret = "(" + quantifier + " ((" + qvar + " (_ BitVec " + std::to_string(width) + "))) " + c1 + ")";
    return type_convert(expected_type, SmtType(), ret); // convert bool : SmtType() to expected type
  }

  throw verilog_expr::VexpException(
      verilog_expr::ExceptionCause::UntranslatedSmtlib2);

  return "";

} // end to_smt

} // namespace rfmap
} // namespace ilang
