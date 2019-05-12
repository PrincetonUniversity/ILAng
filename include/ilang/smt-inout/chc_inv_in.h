/// \file CHC Invariant Input Parsing
// --- Hongce Zhang (hongcez@princeton.edu)

#ifndef CHC_INV_IN_H__
#define CHC_INV_IN_H__

#include <ilang/smt-inout/chc_inv_in_wrapper.h>
#include <ilang/smt-inout/yosys_smt_parser.h>

#include <functional>
#include <map>
#include <string>

extern "C" {
#include "smtparser/smtlib2abstractparser.h"
#include "smtparser/smtlib2abstractparser_private.h"
}

namespace ilang {
namespace smt {
/// SmtlibInvariantParser
// we will need a pointer to the SmtlibInvariantParser
class SmtlibInvariantParser;

/// \brief a wrapper of the abstract parser
/// so it is okay to do crazy stuff
struct smtlib2_abstract_parser_wrapper {
  /// this is equivalent to its parent
  smtlib2_abstract_parser parser;
  /// a pointer to allow us to access to the object-oriented part
  SmtlibInvariantParser * inv_parser;
}; // struct smtlib2_abstract_parser_wrapper

/// \brief the type of term info that needs to be carried
template <class T>
struct SmtTermInfo{
  /// the corresponding translation (for verilog: std::string)
  T _translate;
  /// the type uptill now
  var_type _type;
  /// the context -- all predefined datatypes/predicates/functions
  SmtlibInvariantParser * _context;
  // --------------- CONSTRUCTOR -------------- //
  /// default constructor
  SmtTermInfo() {}
  /// complete constructor
  SmtTermInfo(const T & trans, const var_type & p, SmtlibInvariantParser * c ) :
    _translate(trans), _type(p), _context(c) {}
}; // struct SmtContext

/// For verilog, it will be just std::string
/// For translating to ILA, it could be ExprPtr
typedef SmtTermInfo<std::string> SmtTermInfoVerilog;
/// the pointer type
typedef SmtTermInfoVerilog * SmtTermInfoVlgPtr;

/// \brief the class for parsing invariant
class SmtlibInvariantParser: public SmtlibInvariantParserBase {
public:
  // -------------- TYPEs ------------------- //
  /// a function to map state name (internal name reference to verilog signal)
  typedef std::function<std::string(const std::string &)>
    verilog_internal_name_lookup_fn_t;
  /// the type of container to hold the terms
  typedef std::map<std::string,SmtTermInfoVerilog> term_container_t;
  /// then we need stack for forall infos
  typedef std::map<std::string, SmtTermInfoVerilog> quantifier_temp_def_t;
  /// and the stack
  typedef std::vector<quantifier_temp_def_t> quantifier_def_stack_t;
  /// the sort container
  typedef std::map<std::string,var_type> sort_container_t;
  /// the container of temporary variables
  typedef std::map<std::string, SmtTermInfoVerilog> local_vars_t;
  /// the container of all the free variables
  typedef std::map<std::string, int> free_vars_t;
  
public:
  // -------------- CONSTRUCTOR ------------------- //
  SmtlibInvariantParser(YosysSmtParser * yosys_smt_info, 
    bool _flatten_datatype, bool _flatten_hierarchy,
    const std::set<std::string> & _inv_pred_name,
    const std::string & dut_instance_name,
    bool discourageOutOfScopeVariable = true);
  /// no copy constructor
  SmtlibInvariantParser(const SmtlibInvariantParser &) = delete;
  /// no assignment
  SmtlibInvariantParser & operator=(const SmtlibInvariantParser &) = delete;

  // -------------- DESTRUCTOR ------------------- //
  virtual ~SmtlibInvariantParser();

  // -------------- METHODS ------------------- //
  // parse from a file, we will add something there to make
  // if sat --> failed (return false)
  // if unsat --> add the (assert ...)
  bool virtual ParseInvResultFromFile(const std::string & fname) override;
  // parse from a string: assume we have the (assert ...) there
  void virtual ParseSmtResultFromString(const std::string & text) override;
  /// get the translate result
  std::string GetFinalTranslateResult() const override;
  /// get the local variable definitions
  const local_vars_t & GetLocalVarDefs() const;
  /// get the free variable definitions
  const free_vars_t & GetFreeVarDefs() const;

protected:
  // ----------------- MEMBERS ------------------- //
  /// the parser interface
  smtlib2_abstract_parser_wrapper * parser_wrapper;
  /// the term container
  // we will allocate on this container
  // there will be pointers going into it
  term_container_t term_container;
  /// we will allocate in this container
  sort_container_t sort_container;
  /// the temporary def stacks
  quantifier_def_stack_t quantifier_def_stack;
  /// sentry -- probably no use
  unsigned mask;
  /// a collection of functions that should be treated as inv predicates
  const std::set<std::string> inv_pred_name;
  /// the quantifier declare index (order)
  std::vector<unsigned> quantifier_var_def_idx_stack;
  /// to hold the local variables
  local_vars_t local_vars;
  /// to hold the free variables
  free_vars_t  free_vars;
  /// a counter to get local variable name
  std::string get_a_new_local_var_name();
  /// the idx to it
  static unsigned local_var_idx;
  /// the final translated result
  std::string final_translate_result;
  /// we need to store the right vlog instance name
  const std::string dut_verilog_instance_name;

  /// a pointer to get the knowlege of the context
  YosysSmtParser * design_smt_info_ptr;
  /// whether we are on a design w. datatype flattened
  const bool datatype_flattened;
  /// whether we are on a design w. hierarchy flattened
  const bool hierarchy_flattened;
  /// discourage out-of-scope variable referall
  const bool no_outside_var_refer;

  /// bad state
  bool _bad_state;
  /// If it is bad state, return true and display a message
  bool bad_state_return(void);

public:
  /// check if this module is in a bad state
  bool in_bad_state(void) const { return _bad_state; }

public:
  // ----------------- CALLBACK FUNS INTERFACE ------------------- //
  /// call back function to handle (forall
  virtual SmtTermInfoVlgPtr push_quantifier_scope();
  /// call back function to handle ) of forall
  virtual SmtTermInfoVlgPtr pop_quantifier_scope();
  /// declare function (useful for FreqHorn)
  virtual void declare_function(const std::string &name, var_type * sort);
  /// call back function to create a sort
  virtual var_type * make_sort(const std::string &name, const std::vector<int> &);
  /// call back function to create a temporary (quantified variable)
  virtual void declare_quantified_variable(const std::string &name, var_type * sort );
  /// call back function to apply an uninterpreted function
  /// fall-through case if it is not an defined op, if failed, return NULL
  virtual SmtTermInfoVlgPtr mk_function(
    const std::string &name, var_type * sort, 
    const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args);
  /// call back function to make a number term
  virtual SmtTermInfoVlgPtr mk_number(const std::string & rep, int width, int base);
  /// find if a certain var is a quantified variable
  virtual SmtTermInfoVlgPtr search_quantified_var_stack(const std::string & name);
  /// this function receives the final assert result
  virtual void assert_formula(SmtTermInfoVlgPtr result);
  /// this function receives the final result
  virtual void define_function(const std::string &func_name, 
    const std::vector<SmtTermInfoVlgPtr> & args, var_type * ret_type,
    SmtTermInfoVlgPtr func_body);

#define DECLARE_OPERATOR(name) \
  SmtTermInfoVlgPtr mk_##name(const std::string & symbol, var_type * sort, \
    const std::vector<int> & idx, const std::vector<SmtTermInfoVlgPtr> & args) 

  // I hope it will expand lexically
  DECLARE_OPERATOR(true);
  DECLARE_OPERATOR(false);

  DECLARE_OPERATOR(and);
  DECLARE_OPERATOR(or);
  DECLARE_OPERATOR(not);
  DECLARE_OPERATOR(implies);
  DECLARE_OPERATOR(eq);
  DECLARE_OPERATOR(ite);
  DECLARE_OPERATOR(xor);
  DECLARE_OPERATOR(nand);
  DECLARE_OPERATOR(concat);
  DECLARE_OPERATOR(bvnot);
  DECLARE_OPERATOR(bvand);
  DECLARE_OPERATOR(bvnand);
  DECLARE_OPERATOR(bvor);
  DECLARE_OPERATOR(bvnor);
  DECLARE_OPERATOR(bvxor);
  DECLARE_OPERATOR(bvxnor);
  DECLARE_OPERATOR(bvult);
  DECLARE_OPERATOR(bvslt);
  DECLARE_OPERATOR(bvule);
  DECLARE_OPERATOR(bvsle);
  DECLARE_OPERATOR(bvugt);
  DECLARE_OPERATOR(bvsgt);
  DECLARE_OPERATOR(bvuge);
  DECLARE_OPERATOR(bvsge);
  DECLARE_OPERATOR(bvcomp);
  DECLARE_OPERATOR(bvneg);
  DECLARE_OPERATOR(bvadd);
  DECLARE_OPERATOR(bvsub);
  DECLARE_OPERATOR(bvmul);
  DECLARE_OPERATOR(bvudiv);
  DECLARE_OPERATOR(bvsdiv);
  DECLARE_OPERATOR(bvsmod);
  DECLARE_OPERATOR(bvurem);
  DECLARE_OPERATOR(bvsrem);
  DECLARE_OPERATOR(bvshl);
  DECLARE_OPERATOR(bvlshr);
  DECLARE_OPERATOR(bvashr);
  DECLARE_OPERATOR(extract);
  DECLARE_OPERATOR(bit2bool);
  DECLARE_OPERATOR(repeat);
  DECLARE_OPERATOR(zero_extend);
  DECLARE_OPERATOR(sign_extend);
  DECLARE_OPERATOR(rotate_left);
  DECLARE_OPERATOR(rotate_right);

#undef DECLARE_OPERATOR

}; // SmtlibInvariantParser
                                             

}; // namespace smt
}; // namespace ilang

#endif // CHC_INV_IN_H__
