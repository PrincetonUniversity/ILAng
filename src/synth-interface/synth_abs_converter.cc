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
  ILA_ERROR_IF(!PortInputs(abs, m)) << "Fail porting input variables";
  ILA_ERROR_IF(!PortStates(abs, m)) << "Fail porting state variables";
  ILA_ERROR_IF(!PortValid(abs, m)) << "Fail porting the valid function";
  ILA_ERROR_IF(!PortFetch(abs, m)) << "Fail porting the fetch function";
  ILA_ERROR_IF(!PortInits(abs, m)) << "Fail porting initial conditions";

  // collect uninterpreted functions
  ILA_ERROR_IF(!PortFuncs(abs, m)) << "Fail porting uninterpreted functions";

  // instruction

  // TODO child-ILAs

  return m;
}

bool SynthAbsConverter::PortInputs(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) {
  auto inps_synth = abs.getInps();
  for (auto it : inps_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    if (type.isBool()) {
      ila->NewBoolInput(name);
    } else if (type.isBitvector()) {
      ila->NewBvInput(name, type.bitWidth);
    } else {
      ILA_CHECK(type.isMem()) << "Unknown node type " << type;
      ila->NewMemInput(name, type.addrWidth, type.dataWidth);
    }

    node_expr_map_[node.get()] = ila->input(name);
    ILA_DLOG("SynthImport") << "Input: " << ila->input(name);
  }

  return true;
}

bool SynthAbsConverter::PortStates(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) {
  // bool
  auto bits_synth = abs.getBits();
  for (auto it : bits_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isBool());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    auto var = ila->NewBoolState(name);
    node_expr_map_[node.get()] = var;
    ILA_DLOG("SynthImport") << "Bool Var: " << ila->state(name);
  }

  // bv
  auto regs_synth = abs.getRegs();
  for (auto it : regs_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isBitvector());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    auto var = ila->NewBvState(name, type.bitWidth);
    node_expr_map_[node.get()] = var;
    ILA_DLOG("SynthImport") << "Bv Var: " << ila->state(name);
  }

  // mem
  auto mems_synth = abs.getMems();
  for (auto it : mems_synth) {
    auto node = it.second.var;

    auto type = node->getType();
    ILA_CHECK(type.isMem());

    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    auto var = ila->NewMemState(name, type.addrWidth, type.dataWidth);
    node_expr_map_[node.get()] = var;
    ILA_DLOG("SynthImport") << "Mem: " << ila->state(name);
  }

  // TODO what strategy?

  return true;
}

ExprPtr
SynthAbsConverter::ConvertSynthNodeToIlangExpr(const ilasynth::Node* node,
                                               const InstrLvlAbsPtr& ila) {
  ILA_NOT_NULL(node);

  // return if already visit
  auto pos = node_expr_map_.find(node);
  if (pos != node_expr_map_.end()) {
    return pos->second;
  }

  // create new Expr w.r.t the node
  auto CnvtNode2Expr = [this](const ilasynth::Node* n) {
    if (n->isConstant()) {
      ILA_CHECK(ConvertConstNode(n));
    } else {
      ILA_CHECK(ConvertOpNode(n));
    }
  };

  node->depthFirstVisit(CnvtNode2Expr);

  pos = node_expr_map_.find(node);
  ILA_CHECK(pos != node_expr_map_.end())
      << "Fail converting " << node->getName();

  return pos->second;
}

bool SynthAbsConverter::PortValid(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  auto valid_synth = abs.getFetchValidNode();
  auto type = valid_synth->getType();
  ILA_WARN_IF(!type.isBool()) << "Non-Bool valid function " << valid_synth;

  auto valid_ilang = ConvertSynthNodeToIlangExpr(valid_synth.get(), ila);

  return true;
}

bool SynthAbsConverter::PortFetch(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  // TODO
  return true;
}

bool SynthAbsConverter::PortInits(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  // TODO
  return true;
}

bool SynthAbsConverter::PortFuncs(const ilasynth::Abstraction& abs,
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

  return true;
}

bool SynthAbsConverter::PortDecodeFuncs(const ilasynth::Abstraction& abs,
                                        const InstrLvlAbsPtr& ila) {
  // TODO
  return true;
}

bool SynthAbsConverter::PortNextStateFuncs(const ilasynth::Abstraction& abs,
                                           const InstrLvlAbsPtr& ila) {
  // TODO
  return true;
}

bool SynthAbsConverter::ConvertConstNode(const ilasynth::Node* n) {
  // var should be visit before
  ILA_CHECK(n->isConstant()) << "Non-constant leaf node " << n->getName();
  ILA_CHECK(node_expr_map_.find(n) == node_expr_map_.end());

  // create constant accordingly
  auto type = n->getType();
  decltype(ExprFuse::BoolConst(true)) expr = NULL;
  if (type.isBool()) {
    auto val = true; // FIXME
    expr = ExprFuse::BoolConst(val);
  } else if (type.isBitvector()) {
    auto val = 0; // FIXME
    expr = ExprFuse::BvConst(val, type.bitWidth);
  } else {
    ILA_CHECK(type.isMem()) << "Unknown constant type " << type;
    auto def_val = 0; // FIXME also the entry data
    expr = ExprFuse::MemConst(def_val, type.addrWidth, type.dataWidth);
  }

  ILA_NOT_NULL(expr) << "Constant node not converted";
  node_expr_map_[n] = expr;

  return true;
}

bool SynthAbsConverter::ConvertOpNode(const ilasynth::Node* n) {
  ILA_CHECK(node_expr_map_.find(n) == node_expr_map_.end());

  auto type = n->getType();
  // decltype(ExprFuse::BoolConst(true)) expr = NULL;

  if (type.isBool()) {
    auto expr = ConvertBoolOpNode(n);
    node_expr_map_[n] = expr;
  } else if (type.isBitvector()) {
    auto expr = ConvertBvOpNode(n);
    node_expr_map_[n] = expr;
  } else {
    ILA_CHECK(type.isMem()) << "Unknown constant type " << type;
    auto expr = ConvertMemOpNode(n);
    node_expr_map_[n] = expr;
  }

  // ILA_NOT_NULL(expr);
  // node_expr_map_[n] = expr;

  return true;
}

ExprPtr SynthAbsConverter::ConvertBoolOpNode(const ilasynth::Node* n) {
  // get input arguments
  ExprPtrVec expr_args = {};
  for (auto i = 0; i != n->nArgs(); i++) {
    auto node_arg_i = n->arg(i);
    ILA_NOT_NULL(node_arg_i) << "NULL operand";

    auto pos = node_expr_map_.find(node_arg_i.get());
    ILA_CHECK(pos != node_expr_map_.end()) << "Missed DF-visit";

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
    // XXX check what is distinct
    expr = ExprFuse::Ne(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::IF:
    expr = ExprFuse::Ite(expr_args.at(0), expr_args.at(1), expr_args.at(2));
    break;
  default:
    ILA_ERROR << "Cannot find matched Bool Op for " << n->getName();
    break;
  };

  ILA_NOT_NULL(expr) << "Fail converting Bool Op node " << n->getName();
  return expr;
}

ExprPtr SynthAbsConverter::ConvertBvOpNode(const ilasynth::Node* n) {
  ILA_NOT_NULL(n);
  ILA_DLOG("Synthimport") << "Convert Bv op node";
  // TODO
  return NULL;
}

ExprPtr SynthAbsConverter::ConvertMemOpNode(const ilasynth::Node* n) {
  ILA_NOT_NULL(n);
  // TODO
  return NULL;
}

} // namespace ilang

