/// \file
/// Program-fragment-based ILA equivalence checking using
/// constrained horn clauses.

#ifndef ILANG_ILA_MNGR_V_EQ_CHECK_PROGFRAG_H__
#define ILANG_ILA_MNGR_V_EQ_CHECK_PROGFRAG_H__

#include <unordered_map>
#include <variant>
#include <vector>
#include <set>

#include <z3++.h>

#include <ilang/ila/instr_lvl_abs.h>

#include <ilang/ila-mngr/u_progfrag.h>
#include <ilang/ila-mngr/u_unroller.h>

/// \namespace ilang
namespace ilang {

  /// \namespace pgraph
  /// Expresses program fragments using cut-point graphs
  namespace pgraph {

    using Location = std::string;
    constexpr char LOC_BEGIN[] = "begin";
    constexpr char LOC_ERROR[] = "fail";
    constexpr char LOC_END[] = "end";

    using BasicStmt = std::variant<pfast::Call, pfast::Assume, pfast::Update>;
    using StmtSeq = std::vector<BasicStmt>;

    using Edge = StmtSeq;
    
    struct EdgeTo {
      Edge edge;
      Location to;
    };

    using Edges = std::vector<EdgeTo>;

    using CutPointGraph = std::unordered_map<Location, Edges>;

    CutPointGraph program_graph(const pfast::ProgramFragment& pf);

  }

  // TODO: Use an unroller to convert sequences of 
  // instructions to predicates
  // Should I create a program fragment unroller?
  // Decision: use PathUnroller.Unroll, PathUnroller.GetSMTCurrent
  class PFToCHCEncoder {

    using Predicate = ExprPtr;

  public:
    using Result = z3::check_result;

    static constexpr Result VALID = z3::unsat;
    static constexpr Result INVALID = z3::sat; 

    PFToCHCEncoder(
      z3::context& ctx, z3::fixedpoint& ctxfp, 
      const InstrLvlAbsPtr& ila, const pfast::ProgramFragment& pf);
    ~PFToCHCEncoder()=default;

    std::string to_string();

    Result check_assertions() {
      // z3::expr q = get_error_query();
      z3::func_decl_vector q = get_error_queries();
      return ctxfp_.query(q);
    }

  private:
    const InstrLvlAbsPtr ila_;
    const pgraph::CutPointGraph pg_;
    const ExprSet params_;
    ExprPtrVec pred_scope_;
    ExprSet total_scope_;

    z3::context& ctx_;
    z3::fixedpoint& ctxfp_;

    std::unordered_map<pgraph::Location, ExprPtr> loc_predicates_;
    int max_step_count_ {0};

    constexpr static char PRED_END_SUFFIX[] = "end";

    // internal constructor
    PFToCHCEncoder(
      z3::context& ctx, z3::fixedpoint& ctxfp,
      const InstrLvlAbsPtr& ila, const pgraph::CutPointGraph& pg, const ExprSet& params);

    void encode();

    void encode_transition(
      const pgraph::Location& start, 
      const pgraph::StmtSeq& transition, 
      const pgraph::Location& end);

    void record_scopes(const pgraph::CutPointGraph& pg, const ExprSet& params);
    void add_unique_vars(
      const pgraph::BasicStmt& s, ExprSet& pred_scope, ExprSet& total_scope);

    ExprPtrVec get_scope(const pgraph::Location& l) {
      return pred_scope_;  // for now, same scope for the whole graph
    }

    Predicate get_or_make_loc_predicate(const std::string& name);
    Predicate new_predicate(const std::string& name, const ExprPtrVec& args);

    z3::func_decl_vector get_error_queries();

  };

}

#endif