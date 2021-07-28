/// \file
/// Defines the program fragment AST

#ifndef ILANG_ILA_MNGR_U_PROGFRAG_H__
#define ILANG_ILA_MNGR_U_PROGFRAG_H__

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
    struct Update;
    struct While;

    using Stmt = std::variant<Assert, Assume, Call, Update, While>;

    /// Converts to a string for pretty printing
    std::string to_string(const Stmt& s);

    struct Block : public std::vector<Stmt> {
      using base=std::vector<Stmt>;
      using base::base;
      using base::operator=;
    };

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
      Constraint assertion;
      /// Checks structural equality
      bool operator==(const Assert& b) const {
        return asthub::TopEq(assertion, b.assertion);
      }
    };

    static_assert(std::is_copy_constructible_v<Assert>, "assert not copy constructible");
    static_assert(std::is_copy_assignable_v<Assert>, "assert not copy assignable");

    struct Assume {
      Constraint assumption;
      /// Checks structural equality
      bool operator==(const Assume& b) const {
        return asthub::TopEq(assumption, b.assumption);
      }
    };

    static_assert(std::is_copy_constructible_v<Assume>, "assume not copy constructible");
    static_assert(std::is_copy_assignable_v<Assume>, "assume not copy assignable");

    struct Call {
      InstrPtr instr;
      Constraint input_constraint;

      /// Checks structural equality
      bool operator==(const Call& b) const {
        return (instr == b.instr)
          && (bool(input_constraint) == bool(b.input_constraint))
          && (!input_constraint || asthub::TopEq(input_constraint, b.input_constraint));
      }
    };

    static_assert(std::is_copy_constructible_v<Call>, "call not copy constructible");
    static_assert(std::is_copy_assignable_v<Call>, "call not copy assignable");

    struct Update: public ExprMap {
      using base=ExprMap;
      using base::base;
      using base::operator=;
    };

    static_assert(std::is_copy_constructible_v<Update>, "update not copy constructible");
    static_assert(std::is_copy_assignable_v<Update>, "update not copy assignable");

    struct While {
      Constraint loop_condition;
      Block body;

      /// Checks structural equality
      bool operator==(const While& w) const {
        return (asthub::TopEq(loop_condition, w.loop_condition)
                  && body == w.body);
      }
    };

    static_assert(std::is_copy_constructible_v<While>, "while not copy constructible");
    static_assert(std::is_copy_assignable_v<While>, "while not copy assignable");

    static_assert(std::is_copy_constructible_v<Stmt>, "stmt not copy constructible");
    static_assert(std::is_copy_assignable_v<Stmt>, "stmt not copy constructible");


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
      void operator()(const Update& u);
      void operator()(const While& w);

      std::string str() { return buf_.str(); }
    private:
      std::ostringstream buf_;
      int indent_;

      std::string reserved_word(const std::string& word);
      std::string indent_str();
    };

  }
}

#endif