/// \file
/// The implementation of the abstraction to ILA converter.

#include <ilang/synth-interface/synth_abs_converter.h>
#include <ilang/util/log.h>

namespace ilang {

SynthAbsConverter::SynthAbsConverter() {}

SynthAbsConverter::~SynthAbsConverter() {}

SynthAbsConverterPtr SynthAbsConverter::New() {
  return std::make_shared<SynthAbsConverter>();
}

InstrLvlAbsPtr SynthAbsConverter::Convert(const ilasynth::Abstraction& abs) {
  // destination ILA
  auto model_name = abs.getName();
  auto m = InstrLvlAbs::New(model_name);

  // port basic abstraction definition
  PortInputs(abs, m);
  PortStates(abs, m);
  PortFuncs(abs, m);

  PortValid(abs, m);
  PortFetch(abs, m);

  PortInits(abs, m);

  // TODO instruction

  // TODO child-ILAs

  return m;
}

ExprPtr
SynthAbsConverter::ConvertSynthNodeToIlangExpr(const ilasynth::nptr_t& node,
                                               const InstrLvlAbsPtr& ila) {
  ILA_CHECK(!node_expr_map_.empty()) << "Empty map -- missing leaf vars";
  ILA_NOT_NULL(node);
  auto n = node.get();

  // return if already visit
  auto pos = node_expr_map_.find(n);
  if (pos != node_expr_map_.end()) {
    return pos->second;
  }

  // create new Expr w.r.t the node
  auto CnvtNode2Expr = [this](const ilasynth::Node* nl) { CnvtNodeToExpr(nl); };

  node->depthFirstVisit(CnvtNode2Expr);

  pos = node_expr_map_.find(n);
  ILA_ASSERT(pos != node_expr_map_.end()) << "Fail converting " << n->getName();

  return pos->second;
}

void SynthAbsConverter::PortInputs(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) {
  auto inps_synth = abs.getInps();
  for (auto it : inps_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    // create input var accordingly
    if (type.isBool()) {
      ila->NewBoolInput(name);
    } else if (type.isBitvector()) {
      ila->NewBvInput(name, type.bitWidth);
    } else {
      ILA_ASSERT(type.isMem())
          << "Unknown type " << type << " for input " << name;
      ila->NewMemInput(name, type.addrWidth, type.dataWidth);
    }

    // update book keeping
    ILA_ASSERT(node_expr_map_.find(node.get()) == node_expr_map_.end());
    node_expr_map_[node.get()] = ila->input(name);

    ILA_DLOG("SynthImport") << "Input: " << ila->input(name);
  }
}

void SynthAbsConverter::PortStates(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) {
  // bool
  auto bits_synth = abs.getBits();
  for (auto it : bits_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();

    ILA_ASSERT(type.isBool());
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    auto var = ila->NewBoolState(name);

    ILA_ASSERT(node_expr_map_.find(node.get()) == node_expr_map_.end());
    node_expr_map_[node.get()] = var;

    ILA_DLOG("SynthImport") << "Bool Var: " << ila->state(name);
  }

  // bv
  auto regs_synth = abs.getRegs();
  for (auto it : regs_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();

    ILA_ASSERT(type.isBitvector());
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    auto var = ila->NewBvState(name, type.bitWidth);

    ILA_ASSERT(node_expr_map_.find(node.get()) == node_expr_map_.end());
    node_expr_map_[node.get()] = var;

    ILA_DLOG("SynthImport") << "Bv Var: " << ila->state(name);
  }

  // mem
  auto mems_synth = abs.getMems();
  for (auto it : mems_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();

    ILA_ASSERT(type.isMem());
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    auto var = ila->NewMemState(name, type.addrWidth, type.dataWidth);

    ILA_ASSERT(node_expr_map_.find(node.get()) == node_expr_map_.end());
    node_expr_map_[node.get()] = var;

    ILA_DLOG("SynthImport") << "Mem Var: " << ila->state(name);
  }
}

void SynthAbsConverter::PortValid(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  auto valid_synth = abs.getFetchValidNode();
  auto type = valid_synth->getType();
  ILA_WARN_IF(!type.isBool()) << "Non-Bool valid function " << valid_synth;

  auto valid_ilang = ConvertSynthNodeToIlangExpr(valid_synth, ila);

  return;
}

void SynthAbsConverter::PortFetch(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  // TODO
  return;
}

void SynthAbsConverter::PortInits(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  // TODO
  return;
}

void SynthAbsConverter::PortFuncs(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  auto funs_synth = abs.getFuns();
  for (auto it : funs_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isFunc());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    // output sort
    ILA_CHECK(type.bitWidth > 0) << "Invalid output width " << type.bitWidth;
    auto out_sort = Sort::MakeBvSort(type.bitWidth);

    // argument sort
    std::vector<decltype(Sort::MakeBvSort(1))> args_sort = {};
    auto& args_width = type.argsWidth;
    for (auto i = 0; i != args_width.size(); i++) {
      args_sort.push_back(Sort::MakeBvSort(args_width.at(i)));
    }

    // create the func object
    auto func = Func::New(name, out_sort, args_sort);
    ILA_DLOG("SynthImport") << "Fun: " << func;

    // add to the mapping
    ILA_ERROR_IF(funcs_.find(name) != funcs_.end()) << "Redefine " << name;

    funcs_[name] = func;
  }

  return;
}

void SynthAbsConverter::PortDecodeFuncs(const ilasynth::Abstraction& abs,
                                        const InstrLvlAbsPtr& ila) {
  // TODO
  return;
}

void SynthAbsConverter::PortNextStateFuncs(const ilasynth::Abstraction& abs,
                                           const InstrLvlAbsPtr& ila) {
  // TODO
  return;
}

void SynthAbsConverter::CnvtNodeToExpr(const ilasynth::Node* n) {
  ILA_NOT_NULL(n);
  ILA_ASSERT(node_expr_map_.find(n) == node_expr_map_.end());

  // Only convert consts and operators, since we need host info for vars.
  // vars should and must be already created.
  if (n->isConstant()) {
    CnvtNodeToExprConst(n);
  } else {
    auto type = n->getType();
    if (type.isBool()) {
      CnvtNodeToExprBoolOp(n);
    } else if (type.isBitvector()) {
      CnvtNodeToExprBvOp(n);
    } else {
      ILA_ASSERT(type.isMem()) << "Unknown type for operation " << type;
      CnvtNodeToExprMemOp(n);
    }
  }

  return;
}

void SynthAbsConverter::CnvtNodeToExprConst(const ilasynth::Node* n) {
  // place holder for the result
  decltype(ExprFuse::BoolConst(true)) expr = NULL;

  auto type = n->getType();
  if (type.isBool()) {
    auto val = true; // FIXME
    expr = ExprFuse::BoolConst(val);
  } else if (type.isBitvector()) {
    auto val = 0; // FIXME
    expr = ExprFuse::BvConst(val, type.bitWidth);
  } else {
    ILA_ASSERT(type.isMem());
    auto def_val = 0; // FIXME
    expr = ExprFuse::MemConst(def_val, type.addrWidth, type.dataWidth);
  }

  ILA_NOT_NULL(expr) << "Fail converting constant node " << n->getName();
  node_expr_map_[n] = expr;

  return;
}

void SynthAbsConverter::CnvtNodeToExprBoolOp(const ilasynth::Node* n) {
  // get input arguments
  ExprPtrVec expr_args = {};
  for (auto i = 0; i != n->nArgs(); i++) {
    auto node_arg_i = n->arg(i);
    auto pos = node_expr_map_.find(node_arg_i.get());
    ILA_ASSERT(pos != node_expr_map_.end()) << "Invalid DF-visit";

    auto expr_arg_i = pos->second;
    expr_args.push_back(expr_arg_i);
  }

  // construct Expr
  auto op_ptr = dynamic_cast<const ilasynth::BoolOp*>(n);
  ILA_NOT_NULL(op_ptr) << "Fail casting " << n->getName() << " to Bool Op";

  decltype(ExprFuse::BoolConst(true)) expr = NULL;

  switch (op_ptr->getOp()) {
  case (ilasynth::BoolOp::Op::NOT):
    expr = ExprFuse::Not(expr_args.at(0));
    break;
  case ilasynth::BoolOp::Op::AND:
    expr = ExprFuse::And(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::OR:
    expr = ExprFuse::Or(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::XOR:
    expr = ExprFuse::Xor(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::XNOR: {
    auto tmp_xor = ExprFuse::Xor(expr_args.at(0), expr_args.at(1));
    expr = ExprFuse::Not(tmp_xor);
    break;
  }
  case ilasynth::BoolOp::Op::NAND: {
    auto tmp_and = ExprFuse::And(expr_args.at(0), expr_args.at(1));
    expr = ExprFuse::Not(tmp_and);
    break;
  }
  case ilasynth::BoolOp::Op::NOR: {
    auto tmp_or = ExprFuse::Or(expr_args.at(0), expr_args.at(1));
    expr = ExprFuse::Not(tmp_or);
    break;
  }
  case ilasynth::BoolOp::Op::IMPLY:
    expr = ExprFuse::Imply(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SLT:
    expr = ExprFuse::Lt(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SGT:
    expr = ExprFuse::Gt(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SLE:
    expr = ExprFuse::Le(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SGE:
    expr = ExprFuse::Ge(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::ULT:
    expr = ExprFuse::Ult(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::UGT:
    expr = ExprFuse::Ugt(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::ULE:
    expr = ExprFuse::Ule(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::UGE:
    expr = ExprFuse::Uge(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::EQUAL:
    expr = ExprFuse::Eq(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::DISTINCT:
    expr = ExprFuse::Ne(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::IF:
    expr = ExprFuse::Ite(expr_args.at(0), expr_args.at(1), expr_args.at(2));
    break;
  default:
    ILA_ERROR << "Cannot find corresponding Bool Op for " << n->getName();
    break;
  };

  ILA_NOT_NULL(expr) << "Fail converting Bool Op node " << n->getName();
  node_expr_map_[n] = expr;

  return;
}

void SynthAbsConverter::CnvtNodeToExprBvOp(const ilasynth::Node* n) {
  // get input arguments
  ExprPtrVec expr_args = {};
  for (auto i = 0; i != n->nArgs(); i++) {
    auto node_arg_i = n->arg(i);
    auto pos = node_expr_map_.find(node_arg_i.get());
    ILA_ASSERT(pos != node_expr_map_.end()) << "Invalid DF-visit";

    auto expr_arg_i = pos->second;
    expr_args.push_back(expr_arg_i);
  }

  // get input parameters

  // construct Expr
  auto op_ptr = dynamic_cast<const ilasynth::BitvectorOp*>(n);
  ILA_NOT_NULL(op_ptr) << "Fail casting " << n->getName() << " to Bv Op";

  decltype(ExprFuse::BvConst(1, 1)) expr = NULL;

  switch (op_ptr->getOp()) {
  case (ilasynth::BitvectorOp::Op::NEGATE):
    // expr = ExprFuse::Not(expr_args.at(0));
  default:
    ILA_ERROR << "Cannot find corresponding Bv Op for " << n->getName();
    break;
  };

  ILA_NOT_NULL(expr) << "Fail converting Bv Op node " << n->getName();
  node_expr_map_[n] = expr;

  return;
}

void SynthAbsConverter::CnvtNodeToExprMemOp(const ilasynth::Node* n) {
  // TODO
  return;
}

} // namespace ilang

