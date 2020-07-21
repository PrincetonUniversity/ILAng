/// \file
/// The implementation of the abstraction to ILA converter.

#include <ilang/target-itsy/abst_to_ila.h>

#include <ilang/util/log.h>

namespace ilang {

SynthAbsConverter::SynthAbsConverter() { Reset(); }

SynthAbsConverter::~SynthAbsConverter() { Reset(); }

SynthAbsConverterPtr SynthAbsConverter::New() {
  return std::make_shared<SynthAbsConverter>();
}

InstrLvlAbsPtr SynthAbsConverter::Convert(const ilasynth::Abstraction& abs) {
  Reset();

  // output placeholder
  auto model_name = abs.getName();
  auto m = InstrLvlAbs::New(model_name);

  // leaf nodes
  PortInputs(abs, m);
  PortStates(abs, m);
  PortFuncs(abs, m);

  // instruction
  PortInstructions(abs, m);

  // others
  PortValid(abs, m);
  PortFetch(abs, m);
  PortInits(abs, m);

  // hierarchy (i.e., child-ILA) was not supported in the synthesis engine.

  return m;
}

void SynthAbsConverter::Port(const ilasynth::Abstraction& abs,
                             const InstrLvlAbsPtr& ila) {
  ILA_NOT_NULL(ila);
  Reset();

  // leaf nodes
  PortInputs(abs, ila);
  PortStates(abs, ila);
  PortFuncs(abs, ila);

  // instruction
  PortInstructions(abs, ila);

  // others
  PortValid(abs, ila);
  PortFetch(abs, ila);
  PortInits(abs, ila);

  // hierarchy (i.e., child-ILA) was not supported in the synthesis engine.
  return;
}

ExprPtr
SynthAbsConverter::ConvertSynthNodeToIlangExpr(const ilasynth::nptr_t& node,
                                               const InstrLvlAbsPtr& ila) {
  ILA_CHECK(!node_expr_map_.empty()) << "Empty map -- missing leaf vars";
  ILA_NOT_NULL(ila);
  ILA_NOT_NULL(node);
  auto n = node.get();

  // return if already visit
  auto pos = node_expr_map_.find(n);
  if (pos != node_expr_map_.end()) {
    return pos->second;
  }

  auto CnvtNode2Expr = [this](const ilasynth::Node* nl) {
    // create new Expr w.r.t the node
    CnvtNodeToExpr(nl);
  };

  node->depthFirstVisit(CnvtNode2Expr);

  // make sure Expr has been converted/generated
  pos = node_expr_map_.find(n);
  ILA_ASSERT(pos != node_expr_map_.end()) << "Fail converting " << n->getName();

  return pos->second;
}

void SynthAbsConverter::PortInputs(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port input variables";

  auto inps_synth = abs.getInps();
  for (auto it : inps_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    if (ila->input(name)) {
      ILA_DLOG("SynthImport") << "Use input " << name << " in " << ila;
    } else {
      // create input var accordingly
      switch (type.type) {
      case ilasynth::NodeType::Type::BOOL:
        ila->NewBoolInput(name);
        break;
      case ilasynth::NodeType::Type::BITVECTOR:
        ila->NewBvInput(name, type.bitWidth);
        break;
      default:
        ILA_ERROR << "Input of type " << type.type << " not supported.";
        break;
      };
      ILA_DLOG("SynthImport") << "Define input " << ila->input(name);
    }

    // update book keeping
    auto res = node_expr_map_.emplace(node.get(), ila->input(name));
    ILA_WARN_IF(!res.second) << "Input " << res.first->second << " re-ported.";
  }
}

void SynthAbsConverter::PortStates(const ilasynth::Abstraction& abs,
                                   const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port state variables";

  // bool
  auto bits_synth = abs.getBits();
  for (auto it : bits_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();

    ILA_ASSERT(type.isBool());
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    if (ila->state(name)) {
      ILA_DLOG("SynthImport") << "Use state " << name << " in " << ila;
    } else {
      auto var = ila->NewBoolState(name);
      ILA_DLOG("SynthImport") << "Define state " << var;
    }

    auto res = node_expr_map_.emplace(node.get(), ila->state(name));
    ILA_WARN_IF(!res.second) << "State " << res.first->second << "re-ported.";
  }

  // bv
  auto regs_synth = abs.getRegs();
  for (auto it : regs_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();

    ILA_ASSERT(type.isBitvector());
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    if (ila->state(name)) {
      ILA_DLOG("SynthImport") << "Use state " << name << " in " << ila;
    } else {
      auto var = ila->NewBvState(name, type.bitWidth);
      ILA_DLOG("SynthImport") << "Define state " << var;
    }

    auto res = node_expr_map_.emplace(node.get(), ila->state(name));
    ILA_WARN_IF(!res.second) << "State " << res.first->second << "re-ported.";
  }

  // mem
  auto mems_synth = abs.getMems();
  for (auto it : mems_synth) {
    auto node = it.second.var;
    auto type = node->getType();
    auto name = node->getName();

    ILA_ASSERT(type.isMem());
    ILA_WARN_IF(name != it.first) << name << " != " << it.first;

    if (ila->state(name)) {
      ILA_DLOG("SynthImport") << "Use state " << name << " in " << ila;
    } else {
      auto var = ila->NewMemState(name, type.addrWidth, type.dataWidth);
      ILA_DLOG("SynthImport") << "Define state " << var;
    }

    auto res = node_expr_map_.emplace(node.get(), ila->state(name));
    ILA_WARN_IF(!res.second) << "State " << res.first->second << "re-ported.";
  }
}

void SynthAbsConverter::PortValid(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port valid function";
  auto valid_synth = abs.getFetchValidRef();
  if (valid_synth) {
    auto valid_ilang = ConvertSynthNodeToIlangExpr(valid_synth, ila);
    ila->SetValid(valid_ilang);
  }
  return;
}

void SynthAbsConverter::PortFetch(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port fetch function";
  auto fetch_synth = abs.getFetchExprRef();
  if (fetch_synth) {
    auto fetch_ilang = ConvertSynthNodeToIlangExpr(fetch_synth, ila);
    ila->SetFetch(fetch_ilang);
  }
  return;
}

void SynthAbsConverter::PortInits(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port initial conditions";
  // only add initial condition for state vars that are already defined
  for (decltype(ila->state_num()) i = 0; i != ila->state_num(); i++) {
    auto var_expr = ila->state(i);
    auto var_name = var_expr->name().str();

    // initial value
    try {
      auto init_val_node = abs.getInit(var_name)->node;
      if (init_val_node) {
        auto init_val_expr = ConvertSynthNodeToIlangExpr(init_val_node, ila);
        ila->AddInit(asthub::Eq(var_expr, init_val_expr));
      }
    } catch (...) {
      ILA_DLOG("SynthImport") << "No initial value for " << var_name;
    }

    // initial predicate
    try {
      auto init_pred_node = abs.getIpred(var_name)->node;
      if (init_pred_node) {
        auto init_pred_expr = ConvertSynthNodeToIlangExpr(init_pred_node, ila);
        ila->AddInit(init_pred_expr);
      }
    } catch (...) {
      ILA_DLOG("SynthImport") << "No initial predicate for " << var_name;
    }
  }

  return;
}

void SynthAbsConverter::PortFuncs(const ilasynth::Abstraction& abs,
                                  const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port uninterpreted functions";
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
    for (size_t i = 0; i != args_width.size(); i++) {
      args_sort.push_back(Sort::MakeBvSort(args_width.at(i)));
    }

    // create the func object
    auto func = Func::New(name, out_sort, args_sort);
    ILA_DLOG("SynthImport") << "Fun: " << func;

    // add to the mapping
    auto res = node_func_map_.emplace(node.get(), func);
    ILA_WARN_IF(!res.second) << "Func " << name << " has been ported.";
  }

  return;
}

void SynthAbsConverter::PortInstructions(const ilasynth::Abstraction& abs,
                                         const InstrLvlAbsPtr& ila) {
  ILA_DLOG("SynthImport") << "Port instructions";
  std::map<ExprPtr, InstrPtr> instr_map;

  // get the set of decode functions
  auto& decode_exprs = decom_entry_;
  // auto decode_exprs = ExprSet();
  auto decode_synth = abs.getDecodeNodes();
  for (auto decode_node_i : decode_synth) {
    auto decode_expr_i = ConvertSynthNodeToIlangExpr(decode_node_i, ila);
    decode_exprs.insert(decode_expr_i);

    // create instruction for each decode function
    auto instr_i = ila->NewInstr(); // XXX name
    instr_i->set_decode(decode_expr_i);
    instr_map.emplace(decode_expr_i, instr_i);
  }

  // get the next state function of each state var
  for (decltype(ila->state_num()) i = 0; i != ila->state_num(); i++) {
    auto var = ila->state(i);

    // next state functions are conjuncted when being exported
    auto name = var->name().str();

    ExprPtr next_expr = nullptr;
    try {
      auto next_node = abs.getNext(name)->node;
      next_expr = ConvertSynthNodeToIlangExpr(next_node, ila);
    } catch (...) { // catch exception if next func not specified
      next_expr = var;
    }

    // decompose the next state functions
    DecomposeExpr(next_expr);

    // update each instruction
    for (auto decode : decode_exprs) {
      auto pos_instr = instr_map.find(decode);
      ILA_ASSERT(pos_instr != instr_map.end());
      auto instr = pos_instr->second;

      auto pos_next = decom_match_.find(decode);
      ILA_ASSERT(pos_next != decom_match_.end()) << var << " " << decode;
      auto next = pos_next->second;

      instr->set_update(var, next);
    }
  }

  return;
}

void SynthAbsConverter::DecomposeExpr(const ExprPtr& src) {

  auto Compare = [this](const ExprPtr& n) {
    // syntactically decompose at ITE nodes
    const ExprOpIte* expr_ite = nullptr;
    if ((expr_ite = dynamic_cast<const ExprOpIte*>(n.get()))) {
      // check if the condition argument is one of the entries
      auto condition = n->arg(0);
      for (auto entry : decom_entry_) {
        if (asthub::TopEq(condition, entry)) {
          // this glue node is decomposed
          decom_glue_.insert(n);
          // record success matching
          auto res = decom_match_.emplace(entry, n->arg(1));
          ILA_WARN_IF(!res.second) << "Sub-expr of " << entry << " exists.";
          // track the else branch
          decom_else_.insert(n->arg(2));
          // should have only one match
          break;
        }
      }
    }
  };

  // set up intermediate and result space
  decom_match_.clear();
  decom_glue_.clear();
  decom_else_.clear();
  ILA_ASSERT(!decom_entry_.empty());

  // start decompose
  src->DepthFirstVisit(Compare);

  // determine sub-expression of lumped entries
  auto default_sub_expr = src; // required when not being composed at all
  for (auto else_i : decom_else_) {
    if (decom_glue_.find(else_i) == decom_glue_.end()) {
      default_sub_expr = else_i;
    }
  }

  // update mapping for lumped entries
  for (auto entry : decom_entry_) {
    decom_match_.emplace(entry, default_sub_expr);
  }

  return;
}

void SynthAbsConverter::CnvtNodeToExpr(const ilasynth::Node* n) {
  ILA_NOT_NULL(n);

  // return if already visited
  if (node_expr_map_.find(n) != node_expr_map_.end()) {
    return;
  }
  if (node_func_map_.find(n) != node_func_map_.end()) {
    return;
  }

  // Only convert consts and operators, since we need host info for vars.
  // vars should and must be already created.
  if (n->isConstant()) {
    CnvtNodeToExprConst(n);
  } else {
    auto type = n->getType();
    switch (type.type) {
    case ilasynth::NodeType::Type::BOOL:
      CnvtNodeToExprBoolOp(n);
      break;
    case ilasynth::NodeType::Type::BITVECTOR:
      CnvtNodeToExprBvOp(n);
      break;
    case ilasynth::NodeType::Type::MEM:
      CnvtNodeToExprMemOp(n);
      break;
    default:
      ILA_ERROR << "Op of type other than Bool/Bv/Mem not supported.";
      break;
    };
  }

  return;
}

void SynthAbsConverter::CnvtNodeToExprConst(const ilasynth::Node* n) {
  // place holder for the result
  decltype(asthub::BoolConst(true)) expr = nullptr;

  auto type = n->getType();
  switch (type.type) {
  case ilasynth::NodeType::Type::BOOL: {
    auto bool_const = static_cast<const ilasynth::BoolConst*>(n);
    expr = asthub::BoolConst(bool_const->val());
    break;
  }

  case ilasynth::NodeType::Type::BITVECTOR: {
    auto bv_const = static_cast<const ilasynth::BitvectorConst*>(n);
    auto val = static_cast<int>(bv_const->val());
    expr = asthub::BvConst(val, type.bitWidth);
    break;
  }

  case ilasynth::NodeType::Type::MEM: {
    auto mem_const = static_cast<const ilasynth::MemConst*>(n);
    auto def_value = static_cast<int>(mem_const->memvalues.def_value);

    auto mem_value = MemVal(def_value);

    for (auto pair : mem_const->memvalues.values) {
      auto addr = static_cast<int>(pair.first);
      auto data = static_cast<int>(pair.second);
      mem_value.set_data(addr, data);
    }

    expr = asthub::MemConst(mem_value, type.addrWidth, type.dataWidth);
    break;
  }

  default: // FUNC
    ILA_ERROR << "Const of type other than Bool/Bv/Mem not supported.";
    break;
  };

  // update book keeping
  ILA_CHECK(expr) << "Fail converting constant node " << n->getName();
  auto res = node_expr_map_.emplace(n, expr);
  ILA_WARN_IF(!res.second) << "Expr of " << n->getName() << " exists.";

  return;
}

void SynthAbsConverter::CnvtNodeToExprBoolOp(const ilasynth::Node* n) {
  // get input arguments
  ExprPtrVec expr_args = {};
  for (decltype(n->nArgs()) i = 0; i != n->nArgs(); i++) {
    auto node_arg_i = n->arg(i);
    auto pos = node_expr_map_.find(node_arg_i.get());
    ILA_ASSERT(pos != node_expr_map_.end()) << "Invalid DF-visit";

    auto expr_arg_i = pos->second;
    expr_args.push_back(expr_arg_i);
  }

  // construct Expr
  auto op_ptr = dynamic_cast<const ilasynth::BoolOp*>(n);
  ILA_CHECK(op_ptr) << "Fail casting " << n->getName() << " to Bool Op";

  decltype(asthub::BoolConst(true)) expr = nullptr;

  switch (op_ptr->getOp()) {
  case ilasynth::BoolOp::Op::NOT:
    expr = asthub::Not(expr_args.at(0));
    break;
  case ilasynth::BoolOp::Op::AND:
    expr = asthub::And(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::OR:
    expr = asthub::Or(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::XOR:
    expr = asthub::Xor(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::XNOR: {
    auto tmp_xor = asthub::Xor(expr_args.at(0), expr_args.at(1));
    expr = asthub::Not(tmp_xor);
    break;
  }
  case ilasynth::BoolOp::Op::NAND: {
    auto tmp_and = asthub::And(expr_args.at(0), expr_args.at(1));
    expr = asthub::Not(tmp_and);
    break;
  }
  case ilasynth::BoolOp::Op::NOR: {
    auto tmp_or = asthub::Or(expr_args.at(0), expr_args.at(1));
    expr = asthub::Not(tmp_or);
    break;
  }
  case ilasynth::BoolOp::Op::IMPLY:
    expr = asthub::Imply(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SLT:
    expr = asthub::Lt(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SGT:
    expr = asthub::Gt(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SLE:
    expr = asthub::Le(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::SGE:
    expr = asthub::Ge(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::ULT:
    expr = asthub::Ult(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::UGT:
    expr = asthub::Ugt(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::ULE:
    expr = asthub::Ule(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::UGE:
    expr = asthub::Uge(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::EQUAL:
    expr = asthub::Eq(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::DISTINCT:
    expr = asthub::Ne(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BoolOp::Op::IF:
    expr = asthub::Ite(expr_args.at(0), expr_args.at(1), expr_args.at(2));
    break;
  default:
    ILA_ERROR << "Cannot find corresponding Bool Op for " << n->getName();
    break;
  };

  ILA_CHECK(expr) << "Fail converting Bool Op node " << n->getName();
  auto res = node_expr_map_.emplace(n, expr);
  ILA_WARN_IF(!res.second) << "Expr of " << n->getName() << " exists.";

  return;
}

void SynthAbsConverter::CnvtNodeToExprBvOp(const ilasynth::Node* n) {
  // get input arguments
  ExprPtrVec expr_args = {};
  for (decltype(n->nArgs()) i = 0; i != n->nArgs(); i++) {
    auto node_arg_i = n->arg(i);

    // APPLY_FUNC
    if (node_arg_i->getType().isFunc()) {
      ILA_ASSERT(node_func_map_.find(node_arg_i.get()) != node_func_map_.end());
      continue;
    }
    // normal bit-vector operation
    auto pos = node_expr_map_.find(node_arg_i.get());
    ILA_ASSERT(pos != node_expr_map_.end()) << "Invalid DF-visit";

    auto expr_arg_i = pos->second;
    expr_args.push_back(expr_arg_i);
  }

  // construct Expr
  auto op_ptr = dynamic_cast<const ilasynth::BitvectorOp*>(n);
  ILA_CHECK(op_ptr) << "Fail casting " << n->getName() << " to Bv Op";

  decltype(asthub::BvConst(1, 1)) expr = nullptr;

  switch (op_ptr->getOp()) {
  case ilasynth::BitvectorOp::Op::NEGATE:
    expr = asthub::Negate(expr_args.at(0));
    break;
  case ilasynth::BitvectorOp::Op::COMPLEMENT:
    expr = asthub::Complement(expr_args.at(0));
    break;
  case ilasynth::BitvectorOp::Op::LROTATE:
    expr = asthub::LRotate(expr_args.at(0), op_ptr->param(0));
    break;
  case ilasynth::BitvectorOp::Op::RROTATE:
    expr = asthub::RRotate(expr_args.at(0), op_ptr->param(0));
    break;
  case ilasynth::BitvectorOp::Op::Z_EXT:
    expr = asthub::ZExt(expr_args.at(0), op_ptr->param(0));
    break;
  case ilasynth::BitvectorOp::Op::S_EXT:
    expr = asthub::SExt(expr_args.at(0), op_ptr->param(0));
    break;
  case ilasynth::BitvectorOp::Op::EXTRACT:
    expr = asthub::Extract(expr_args.at(0), op_ptr->param(0), op_ptr->param(1));
    break;
  case ilasynth::BitvectorOp::Op::ADD:
    expr = asthub::Add(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::SUB:
    expr = asthub::Sub(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::AND:
    expr = asthub::And(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::OR:
    expr = asthub::Or(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::XOR:
    expr = asthub::Xor(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::XNOR: {
    auto tmp_xor = asthub::Xor(expr_args.at(0), expr_args.at(1));
    expr = asthub::Not(tmp_xor);
    break;
  }
  case ilasynth::BitvectorOp::Op::NAND: {
    auto tmp_and = asthub::And(expr_args.at(0), expr_args.at(1));
    expr = asthub::Not(tmp_and);
    break;
  }
  case ilasynth::BitvectorOp::Op::NOR: {
    auto tmp_or = asthub::Or(expr_args.at(0), expr_args.at(1));
    expr = asthub::Not(tmp_or);
    break;
  }
  case ilasynth::BitvectorOp::Op::SDIV:
    ILA_ERROR << "SDIV not implemented.";
    break;
  case ilasynth::BitvectorOp::Op::UDIV:
    expr = asthub::Div(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::SREM:
    expr = asthub::SRem(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::UREM:
    expr = asthub::URem(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::SMOD:
    expr = asthub::SMod(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::SHL:
    expr = asthub::Shl(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::LSHR:
    expr = asthub::Lshr(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::ASHR:
    expr = asthub::Ashr(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::MUL:
    expr = asthub::Mul(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::CONCAT:
    expr = asthub::Concat(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::GET_BIT:
    expr = asthub::Extract(expr_args.at(0), op_ptr->param(0), op_ptr->param(0));
    break;
  case ilasynth::BitvectorOp::Op::READMEM:
    expr = asthub::Load(expr_args.at(0), expr_args.at(1));
    break;
  case ilasynth::BitvectorOp::Op::READMEMBLOCK: {
    auto chunks = op_ptr->param(0);
    auto endian = op_ptr->param(1);
    for (auto i = 0; i < chunks; i++) {
      auto addr_i = asthub::Add(expr_args.at(1), i);
      auto data_i = asthub::Load(expr_args.at(0), addr_i);
      if (i == 0) {
        expr = data_i;
      } else {
        if (endian == ilasynth::endianness_t::LITTLE_E) {
          expr = asthub::Concat(data_i, expr);
        } else {
          expr = asthub::Concat(expr, data_i);
        }
      }
    }
    break;
  }
  case ilasynth::BitvectorOp::Op::IF:
    expr = asthub::Ite(expr_args.at(0), expr_args.at(1), expr_args.at(2));
    break;
  case ilasynth::BitvectorOp::Op::APPLY_FUNC: {
    auto func_node = n->arg(0);
    auto func_find = node_func_map_.find(func_node.get());
    ILA_ASSERT(func_find != node_func_map_.end());

    auto func = func_find->second;
    expr = asthub::AppFunc(func, expr_args);
    break;
  }
  default:
    ILA_ERROR << "Cannot find corresponding Bv Op for " << n->getName();
    break;
  };

  ILA_CHECK(expr) << "Fail converting Bv Op node " << n->getName();
  auto res = node_expr_map_.emplace(n, expr);
  ILA_WARN_IF(!res.second) << "Expr of " << n->getName() << " exists.";

  return;
}

void SynthAbsConverter::CnvtNodeToExprMemOp(const ilasynth::Node* n) {
  // get input arguments
  ExprPtrVec expr_args = {};
  for (decltype(n->nArgs()) i = 0; i != n->nArgs(); i++) {
    auto node_arg_i = n->arg(i);
    auto pos = node_expr_map_.find(node_arg_i.get());
    ILA_ASSERT(pos != node_expr_map_.end()) << "Invalid DF-visit";

    auto expr_arg_i = pos->second;
    expr_args.push_back(expr_arg_i);
  }

  // construct Expr
  auto op_ptr = dynamic_cast<const ilasynth::MemOp*>(n);
  ILA_CHECK(op_ptr) << "Fail casting " << n->getName() << " to Mem Op";

  decltype(asthub::MemConst(0, 8, 8)) expr = nullptr;

  switch (op_ptr->getOp()) {
  case ilasynth::MemOp::Op::STORE:
    expr = asthub::Store(expr_args.at(0), expr_args.at(1), expr_args.at(2));
    break;

  case ilasynth::MemOp::Op::STOREBLOCK: {
    auto total_size = op_ptr->arg(2)->type.bitWidth;
    auto chunk_size = op_ptr->arg(0)->type.dataWidth;

    auto bit_idx = (op_ptr->endian == ilasynth::endianness_t::LITTLE_E)
                       ? 0
                       : total_size - chunk_size;
    auto bit_inc = (op_ptr->endian == ilasynth::endianness_t::LITTLE_E)
                       ? chunk_size
                       : -chunk_size;

    expr = expr_args.at(0);
    auto addr = expr_args.at(1);
    auto data = expr_args.at(2);

    for (auto i = 0; i < chunk_size; i++, bit_idx += bit_inc) {
      auto addr_i = asthub::Add(addr, i);
      auto data_i = asthub::Extract(data, bit_idx + chunk_size - 1, bit_idx);
      expr = asthub::Store(expr, addr_i, data_i);
    }

    break;
  }

  case ilasynth::MemOp::Op::ITE:
    expr = asthub::Ite(expr_args.at(0), expr_args.at(1), expr_args.at(2));
    break;

  default:
    ILA_ERROR << "Cannot find corresponding Mem Op for " << n->getName();
    break;
  };

  ILA_CHECK(expr) << "Fail converting Mem Op node " << n->getName();
  auto res = node_expr_map_.emplace(n, expr);
  ILA_WARN_IF(!res.second) << "Expr " << res.first->second << " exists.";

  return;
}

} // namespace ilang
