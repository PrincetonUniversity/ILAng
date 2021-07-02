/// \file
/// Program-fragment-based ILA equivalence checking using
/// constrained horn clauses.

#ifndef ILANG_ILA_MNGR_V_EQ_CHECK_PROGFRAG_H__
#define ILANG_ILA_MNGR_V_EQ_CHECK_PROGFRAG_H__

#include <unordered_map>
#include <variant>
#include <vector>
#include <set>
#include <sstream>

#include <z3++.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/ila-mngr/u_unroller.h>

/// \namespace ilang
namespace ilang {

  /// \namespace pfast
  /// Defines the program-fragment AST
  namespace pfast {

    using Constraint = ExprPtr;

    struct Assert;
    struct Assume;
    struct Call;
    // struct Update;

    using Stmt = std::variant<Assert, Assume, Call>;

    /// Converts to a string for pretty printing
    std::string to_string(const Stmt& s);

    struct Block : public std::vector<Stmt> {
      using base=std::vector<Stmt>;
      using base::base;
      using base::operator=;
    };

    /// Checks structural equality
    bool operator==(const Block& a, const Block& b);

    /// Converts to a string for pretty printing
    std::string to_string(const Block& b);

    struct ProgramFragment {
      ExprSet params;
      Block body;
    };
    
    /// Checks structural equality
    bool operator==(const ProgramFragment& a, const ProgramFragment& b);

    /// Converts to a string for pretty printing
    std::string to_string(const ProgramFragment& pf);

    struct Assert {
      const Constraint assertion;
      /// Checks structural equality
      bool operator==(const Assert& b) const {
        return asthub::TopEq(assertion, b.assertion);
      }
    };

    struct Assume {
      const Constraint assumption;
      /// Checks structural equality
      bool operator==(const Assume& b) const {
        return asthub::TopEq(assumption, b.assumption);
      }
    };

    struct Call {
      const InstrPtr instr;
      const Constraint input_constraint;

      /// Checks structural equality
      bool operator==(const Call& b) const {
        return (instr == b.instr)
          && (bool(input_constraint) == bool(b.input_constraint))
          && (!input_constraint || asthub::TopEq(input_constraint, b.input_constraint));
      }
    };

    /// \class PrettyPrinter
    /// A visitor for pretty-printing program-fragment AST elements
    class PrettyPrinter {
    public: 
      PrettyPrinter(): buf_ {} {}
      ~PrettyPrinter()=default;
      void operator()(const ProgramFragment& pf);
      void operator()(const Block& b);

      void operator()(const Assert& a);
      void operator()(const Assume& a);
      void operator()(const Call& c);

      std::string str() { return buf_.str(); }
    private:
      std::ostringstream buf_;
      int indent_;

      std::string reserved_word(const std::string& word);
      std::string indent_str();
    };

  }

  /// \namespace pgraph
  /// Expresses program fragments using cut-point graphs
  namespace pgraph {

    using Location = std::string;
    constexpr char LOC_BEGIN[] = "begin";
    constexpr char LOC_ERROR[] = "fail";

    using BasicStmt = std::variant<pfast::Call, pfast::Assume>;
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

    using Predicate = z3::func_decl;

  public:
    PFToCHCEncoder(const InstrLvlAbsPtr& ila, const pfast::ProgramFragment& pf);
    ~PFToCHCEncoder()=default;

    std::string to_string();

    z3::check_result check_assertions() {
      z3::expr q = get_error_query();
      // z3::func_decl_vector q = get_error_query();
      return ctxfp_.query(q);
    }

  private:
    const InstrLvlAbsPtr ila_;
    const pgraph::CutPointGraph pg_;
    const ExprSet params_;
    ExprPtrVec pred_scope_;
    ExprSet total_scope_;

    z3::context ctx_ {};
    z3::fixedpoint ctxfp_ {ctx_};

    std::unordered_map<pgraph::Location, ExprPtr> loc_predicates_;
    int max_step_count_ {0};

    constexpr static char PRED_END_SUFFIX[] = "end";

    // internal constructor
    PFToCHCEncoder(const InstrLvlAbsPtr& ila, const pgraph::CutPointGraph& pg, const ExprSet& params);

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

    ExprPtr get_or_make_loc_predicate(const std::string& name);
    ExprPtr new_predicate(const std::string& name, const ExprPtrVec& args);

    z3::expr get_error_query();
    // z3::func_decl_vector get_error_query();

  };

}

#endif