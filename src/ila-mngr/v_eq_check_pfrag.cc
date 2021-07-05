/// \file
/// Program fragment-based verification checking driver.

#include <ilang/ila-mngr/v_eq_check_progfrag.h>

#include <sstream>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/ila-mngr/u_unroller_smt.h>

namespace ilang {

namespace pfast {

  bool operator==(const Block& a, const Block& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i != a.size(); ++i) {
      if (a[i] == b[i]) continue;
      return false;
    }
    return true;
  }

  bool operator==(const ProgramFragment& a, const ProgramFragment& b) {
    // [TODO] check == operator on unordered sets
    return (a.params == b.params) && (a.body == b.body);
  }

  std::string to_string(const Stmt& s) { 
    PrettyPrinter pp {};
    std::visit(pp, s);
    return pp.str();
  }

  std::string to_string(const ProgramFragment& pf) { 
    PrettyPrinter pp {};
    pp(pf);
    return pp.str(); 
  }

  std::string to_string(const Block& b) { 
    PrettyPrinter pp {};
    pp(b);
    return pp.str(); 
  }

  void PrettyPrinter::operator()(const ProgramFragment& pf) {
    buf_ << reserved_word("main") << "(";
    bool first = true;
    for (const auto& param : pf.params) {
      if (first) first = false;
      else buf_ << ", ";
      buf_ << param;
    }
    buf_ << ") ";

    this->indent_ = 0;
    (*this)(pf.body);
    
    buf_ << "\n";
  }

  void PrettyPrinter::operator()(const Block& b) {
    buf_ << "{\n";
    this->indent_ += 2;
    for (int i = 0; i != b.size(); ++i) {
      buf_ << indent_str();
      std::visit(*this, b[i]);
      buf_ << "\n";
    }
    this->indent_ -= 2;
    buf_ << indent_str() << "}";
  }

  void PrettyPrinter::operator()(const Assert& a) {
    buf_ << reserved_word("assert") << " " << a.assertion;
  }

  void PrettyPrinter::operator()(const Assume& a) {
    buf_ << reserved_word("assert") << " " << a.assumption;
  }

  void PrettyPrinter::operator()(const Call& c) {
    buf_ << reserved_word("call") << " " << c.instr->name().str();
    if (c.input_constraint) {
      buf_ << " where " << c.input_constraint;
    }
  }

  std::string PrettyPrinter::reserved_word(const std::string& word) { 
    std::string res = word;
    for (auto & c: res) c = toupper(c);
    return res;
  }

  std::string PrettyPrinter::indent_str() { return std::string(this->indent_, ' '); }

}

namespace pgraph {

  using namespace pfast;

  struct PGraphBuilder {

    CutPointGraph get_pg() { return pg_; }

    void operator()(const ProgramFragment& pf) { 
      (*this)(pf.body);
    }

    void operator()(const Block& b) {
      for (const Stmt& s : b) std::visit(*this, s);
      running_seq_to_newloc("end");
    }

    void operator()(const Call& c) {
      running_seq_.emplace_back(c);
    }

    void operator()(const Assume& a) {
      running_seq_.emplace_back(a);
    }

    void operator()(const Assert& a) {
      running_seq_to_newloc("assert");
      add_edge_from_curloc({pfast::Assume{asthub::Not(a.assertion)}}, LOC_ERROR);
      running_seq_.clear();
      running_seq_.emplace_back(Assume{a.assertion});
    }


  private:

    CutPointGraph pg_ {};
    StmtSeq running_seq_ {};
    int loc_ctr_ {0};
    Location curloc_ {LOC_BEGIN};

    void running_seq_to_newloc(const std::string& loc_ident) {
      Location next = newloc(loc_ident);
      add_edge_from_curloc(running_seq_, next);
      set_curloc(next);
      running_seq_.clear();
    }

    void add_edge_from_curloc(const Edge& edge, const Location& loc) {
      Location cur = curloc();
      pg_.try_emplace(cur);  // creates an Edges object at pg[cur] if none exists
      EdgeTo new_edge {edge, loc};
      pg_[cur].push_back(new_edge);
    }

    Location curloc() { return curloc_; }
    void set_curloc(const Location& loc) { curloc_ = loc; }

    Location newloc(const std::string& loc_ident) {
      return "loc" + std::to_string(loc_ctr_++) + "_" + loc_ident;
    }

  };

  CutPointGraph program_graph(const pfast::ProgramFragment& pf) {
    PGraphBuilder builder {};
    builder(pf);
    return builder.get_pg();
  }

}

template <class Generator>
class PathUnrollerCustomDecidingVars: public PathUnroller<Generator> {

public:
  PathUnrollerCustomDecidingVars(
    SmtShim<Generator>& smt_shim, const ExprPtrVec& deciding_vars, 
    const std::string& suffix = ""):
      PathUnroller<Generator>(smt_shim, suffix), custom_deciding_vars_ {deciding_vars} {}
  
  ~PathUnrollerCustomDecidingVars()=default;

protected:
  void SetDecidingVars() { this->deciding_vars_ = custom_deciding_vars_; }

private:
  const ExprPtrVec custom_deciding_vars_;

};


PFToCHCEncoder::PFToCHCEncoder(const InstrLvlAbsPtr& ila, const pfast::ProgramFragment& pf):
    PFToCHCEncoder(ila, pgraph::program_graph(pf), pf.params) {}

PFToCHCEncoder::PFToCHCEncoder(const InstrLvlAbsPtr& ila, const pgraph::CutPointGraph& pg, const ExprSet& params):
    ila_ {ila}, pg_ {pg}, params_ {params} {

  z3::params p {ctx_};
  p.set("engine", "spacer");
  ctxfp_.set(p);

  record_scopes(pg_, params_);
  encode();
}


std::string PFToCHCEncoder::to_string() {
  z3::func_decl_vector queries = get_error_queries();
  std::stringstream encoding;
  encoding << ctxfp_.to_string();
  for (const z3::func_decl& f : queries) {
    encoding << "(query " << f.name() << ")\n";
  }
  return encoding.str();
}


void PFToCHCEncoder::encode() {
  Z3ExprAdapter z3_adapter {ctx_};

  for (const auto& [loc, edges] : pg_) {
     for (const auto& [edge, next] : edges) {
       encode_transition(loc, edge, next);
     }
  }
}

void PFToCHCEncoder::encode_transition(
      const pgraph::Location& start, 
      const pgraph::StmtSeq& transition, 
      const pgraph::Location& end) {

  Z3ExprAdapter z3_adapter {ctx_};
  SmtShim smt_solver {z3_adapter};
  PathUnrollerCustomDecidingVars unroller {smt_solver, pred_scope_};

  InstrVec seq {};
  int step_ctr = 0;

  if (start != pgraph::LOC_BEGIN) {
      unroller.AssertStep(get_or_make_loc_predicate(start), 0);
  }
  
  for (auto& stmt : transition) {
    std::visit([&unroller, &seq, &step_ctr](const auto& s) {
      using T = std::decay_t<decltype(s)>;
      constexpr bool is_Assume = std::is_same_v<T, pfast::Assume>;
      constexpr bool is_Call = std::is_same_v<T, pfast::Call>;
      constexpr bool is_unknown = !(is_Assume || is_Call);
      if constexpr (is_Assume) {
        unroller.AssertStep(s.assumption, step_ctr);
      } else if constexpr (is_Call) {
        seq.push_back(s.instr);
        if (s.input_constraint) unroller.AssertStep(s.input_constraint, step_ctr);
        ++step_ctr;
      } else {
        // compile-time error
        static_assert(
          is_unknown, "record_scopes not implemented for given type of BasicStmt."
        );
      }
    }, stmt);
  }

  z3::expr_vector forall_args {ctx_};
  for (int i = 0; i != step_ctr + 1; ++i) {
    for (const auto& v : total_scope_) {
      forall_args.push_back(unroller.GetSmtCurrent(v, i));
    }
  }
  // while (max_step_count_ <= step_ctr) {
  //   for (const auto& v : total_scope_) {
  //     auto v_step = unroller.GetSmtCurrent(v, max_step_count_).decl();
  //     ctxfp_.register_relation(v_step);
  //   }
  //   ++max_step_count_;
  // }
 
  z3::expr_vector body {ctx_};
  
  body.push_back(unroller.Unroll(seq));
  auto dvs = unroller.GetLastDecidingVars();
  ExprSet deciding_vars {dvs.begin(), dvs.end()};

  for (const auto& v : get_scope(end)) {
    auto end_pred_v = smt_solver.GetShimExpr(v, PRED_END_SUFFIX);
    
    forall_args.push_back(end_pred_v);
    
    int last_v_step = (deciding_vars.find(v) == deciding_vars.end()) ? 0 : step_ctr;
    auto last_v_update = unroller.GetSmtCurrent(v, last_v_step);
    body.push_back(smt_solver.Equal(last_v_update, end_pred_v));
  }

  ExprPtr end_pred = get_or_make_loc_predicate(end);
  
  z3::expr rule = z3::forall(forall_args, z3::implies(
    z3::mk_and(body), smt_solver.GetShimExpr(end_pred, PRED_END_SUFFIX)
  ));

  ctxfp_.add_rule(rule, ctx_.str_symbol((start + "_to_" + end).c_str()));
}

void PFToCHCEncoder::record_scopes(const pgraph::CutPointGraph& pg, const ExprSet& params) {
  ExprSet uvars {params};
  for (const auto& [loc, edges] : pg) {
    for (const auto& edgeTo : edges) {
      for (const auto& stmt : edgeTo.edge) {
        add_unique_vars(stmt, uvars, total_scope_);
      }
    }
  }

  pred_scope_ = {uvars.begin(), uvars.end()};
}

void PFToCHCEncoder::add_unique_vars(
  const pgraph::BasicStmt& s, ExprSet& pred_scope, ExprSet& total_scope
) {
  std::visit([&pred_scope, &total_scope](const auto& s) {
    using T = std::decay_t<decltype(s)>;
    constexpr bool is_Assume = std::is_same_v<T, pfast::Assume>;
    constexpr bool is_Call = std::is_same_v<T, pfast::Call>;
    constexpr bool is_unknown = !(is_Assume || is_Call);
    if constexpr (is_Assume) {
      // Assume should not use any new variables.
      // OLD: absknob::InsertVar(s.assumption, scope);
    } else if constexpr (is_Call) {
      // add ILA state variables to the scope
      absknob::InsertStt(s.instr->host(), pred_scope);
      absknob::InsertVar(s.instr->host(), total_scope);
      // we do not include the state of children unless an instruction
      // of the child is called.
      // Also, the constraint should not use any new variables.
    } else {
      // compile-time error
      static_assert(
        is_unknown, "record_scopes not implemented for given type of BasicStmt."
      );
    }
  }, s);
}

ExprPtr PFToCHCEncoder::get_or_make_loc_predicate(const pgraph::Location& loc) {
  auto res = loc_predicates_.find(loc);
  if (res != loc_predicates_.end()) return res->second;
  loc_predicates_[loc] = new_predicate(loc, get_scope(loc));
  return loc_predicates_[loc];
}

ExprPtr PFToCHCEncoder::new_predicate(const std::string& name, const ExprPtrVec& args) {
  std::vector<SortPtr> arg_sorts;
  for (const auto& e : args) {
    arg_sorts.push_back(e->sort());
  }
  FuncPtr f = Func::New(name, Sort::MakeBoolSort(), arg_sorts);
  z3::func_decl fd = f->GetZ3FuncDecl(ctx_);
  ctxfp_.register_relation(fd);
  return asthub::AppFunc(f, args);
}

z3::func_decl_vector PFToCHCEncoder::get_error_queries() {
  z3::func_decl_vector queries {ctx_};

  ExprPtr p = get_or_make_loc_predicate(pgraph::LOC_ERROR);
  queries.push_back(
    std::dynamic_pointer_cast<ExprOpAppFunc>(p)
      ->func()->GetZ3FuncDecl(ctx_));
  
  return queries;
}

}