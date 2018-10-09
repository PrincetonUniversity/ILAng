/// \file
/// Header for memory model

#ifndef MEMORY_MODEL_H__
#define MEMORY_MODEL_H__

#include "mcm/axiom_helper.h"
#include "mcm/ast_helper.h"

/// \namespace ila
namespace ila {


/// Type of state read or write
enum { READ, WRITE, EITHER } AccessType; 
// used when query the type of accesses (in register trace step)

/// \brief The class for trace step (an instance of instruction)
/// As in the unrolling, there may be multiple instances of the same 
/// instructions, so we have the trace steps
// HZ note: accessors like w1.wfe.global should be interpreted as an accessor function
// e.g., _wfe_global(w1)
// This function may either convert to a derived class or access a fixed member
// to extract the attribute
// HZ note: In a memory model, usually a derived class of TraceStep is used.
class TraceStep {
  /// Type alias for z3::expr.
  typedef z3::expr ZExpr;
  /// Type for containing a set of z3::expr.
  typedef std::vector<z3::expr> ZExprVec;
  /// Type of set of trace steps
  typedef std::set<TraceStep> TraceStepSet;
  /// Type of state name set
  typedef std::set<std::string> StateNameSet;
  /// the type of trace step type
  enum {INST_EVT, FACET_EVT , INIT_EVT } TraceStepType;
  /// The type of z3Adapter pointer
  typedef std::shared_ptr<Z3ExprAdapter> Z3ExprAdapterPtr;

  // ------------------------- HELPERS -------------------------------------- //
  /// Maintain the unique names of trace steps
  std::string GetName(); // This is the helper function to generate unique names, 
                         // this is private and usshould not be used to return the name of 
                         // the current trace step. Please use name()
  static unsigned trace_step_seq_no;
  /// Set the read write set
  void InitReadWriteSet( const InstrPtr & inst  ) ;
protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// the type of this trace step (event)
  TraceStepType _type;
  // Type : INST_EVT
  /// The pointer to the instruction executed in this step
  InstrPtr _inst; // I assume it is nullptr by default
  // Type : FACET_EVT
  /// The pointer to the referred instruction
  InstrPtr _parent_inst;
  /// Set of states (should be global) that are read by this event: Type : FACET_EVT
  StateNameSet _read_state_set;
  /// Set of states (should be global) that are written by this event: Type : FACET_EVT
  StateNameSet _write_state_set;

  /// Set of states (that are read by inst or parent-inst)
  StateNameSet _inst_read_set; // this applies to both inst-evt and facet-evt 
  /// Set of states (that are written by inst or parent-inst)
  StateNameSet _inst_write_set; // this applies to both inst-evt and facet-evt 

  /// The reference to the constratint set, so it can add constraints when needed
  ZExprVec & _cstr;
  /// The name of trace step
  std::string _name;
  /// The time stamp
  Z3Expr timestamp;  
  /// The relative position
  size_t _pos_suffix;
  /// Keep an adapter that trace steps can share
  Z3ExprAdapterPtr _expr2z3_ptr_;
  /// Keep an adapter 
  z3::context & _ctx_;

public:
  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the host ILA
  inline InstrLvlAbsPtr host() const { return inst()->host(); }
  /// Return the name
  inline std::string name() const { return _name; }
  /// Return the set of states read by inst/parent-inst
  const StateNameSet & get_inst_read_set() const  { return _inst_read_set; }
  /// Return the set of states written by inst/parent-inst
  const StateNameSet & get_inst_write_set() const { return _inst_write_set; }
  /// Return the type of the trace step
  const TraceStepType type() const { return _type; }
  /// Return the associated instruction for facet / instruction event
  InstrPtr inst() const { return _type == TraceStepType::INST_EVT ? _inst : _parent_inst; }
  /// Return the position suffix (for facet, they should have the same suffix as the main step to ensure they use the same var)
  size_t pos_suffix() const { return _pos_suffix; }
  /// Return the adapter
  Z3ExprAdapterPtr z3adapter() { return _expr2z3_ptr_; }
  /// Return the context (for variable creation)
  z3::context & ctx() { return _ctx_; }

  
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// To create a trace step, you need to know the instruction also should give a constraint set
  TraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx , size_t pos , const Z3ExprAdapterPtr & z3a );
  /// This function allows you to overwrite the timestamp instead of creating a new one
  TraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx,  Z3Expr _ts_overwrite, size_t pos , const Z3ExprAdapterPtr & z3a );
  /// To create a facet event 
  TraceStep(const InstrPtr & ref_inst, ZExprVec & cstr , z3::context& ctx , const std::string &, size_t pos , const Z3ExprAdapterPtr & z3a );
  // ------------------------- MEMBERS -------------------------------------- //
  /// To update the set for FACET_EVT
  void AddStateAccess(const std::string & name, AccessType acc_type);
  /// To update the set for FACET_EVT
  void AddStateAccess(const StateNameSet &s, AccessType acc_type);
  /// Translate an arbitrary expr using the frame number of this step (so it refers to the var used in this step)
  ZExpr ConvertZ3OnThisStep(const ExprPtr & ast) { return z3adapter()->GetExpr( ast , std::to_string( pos_suffix() ) ); }
  

  // ------------------------- HELPERS -------------------------------------- //
  /// To determine if the instruction READ/WRITE a certain state 
  bool Access( AccessType acc_type , const std::string & name);
  /// To determine if the instruction READ/WRITE a certain set
  bool Access( AccessType acc_type , StateNameSet * m_p_stateset );
}; // class TraceStep

/// \brief The base class for memory models
class MemoryModel {
  /// Type alias for z3::expr.
  typedef z3::expr ZExpr;
  /// Type for containing a vector of z3::expr.
  typedef std::vector<ZExpr> ZExprVec;
  /// Type of an instruction vector to represent a sequence.
  typedef std::vector<InstrPtr> InstrVec;
  /// Type of a vector of instruction sequences (currently please represent holes via 0-ary functions)
  typedef std::vector<InstrVec> ProgramTemplate;
  /// Type of trace step pointer
  typedef std::shared_ptr<TraceStep> TraceStepPtr;
  /// Type of trace steps, we need to collect the set of trace steps (WRITE)
  typedef std::set<TraceStepPtr> TraceStepSet;
  /// Type of map of shared states (set of names -> list of exprs)
  typedef std::map<std::string, StateVarList> SharedStatesSet;
  /// Type of pointers to Z3ExprAdapter
  typedef std::shared_ptr<Z3ExprAdapter> Z3ExprAdapterPtr;
  /// Type of TraceStep set grouped by ILA (the same sequence as given to the register steps)
  typedef std::vector<std::vector<TraceStepPtr> > PerILATraceStepSet;
  /// Type of map ila-name to state-set
  typedef std::map<std::string, StateNameSet> ILANameStateNameSetMap;


protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The pointer to the initial trace step
  TraceStepPtr _init_trace_step; // will be assigned by function CreateGlobalInitStep
  /// The set of all trace steps
  TraceStepSet _all_trace_steps; // will be assigned by specific memory model
  /// The set of all instruction trace steps
  TraceStepSet _all_inst_trace_steps; // will be assigned by specific memory model
  /// The set of TraceStep set grouped by ILA (the same sequence as given to the register steps)
  PerILATraceStepSet _ila_trace_steps;
  /// The set of names of shared states
  const StateNameSet & m_shared_state_names; // will get a copy from the given set
  /// The internal storage of all private states of all ilas
  const ILANameStateNameSetMap & m_ila_private_state_names; // will get a copy from the given set
  /// The pointer to the (dummy) global ILA
  InstrLvlAbsPtr m_p_global_ila;
  // For passing argument, we need to keep track of the following info:
  /// A reference to Z3 context
  z3::context& _ctx_;
  /// A reference to the constraint list
  ZExprVec & _constr;
  /// An adapter that trace step can share, will allocate internally, by the constructor
  Z3ExprAdapterPtr _expr2z3_ptr_; 

public:
  /// To initialize the inner storage space.
  void virtual InitSize(const ProgramTemplate & _tmpl);
  /// To create more view operations associated with an instruction, and also to add them to the set
  void virtual RegisterSteps(size_t regIdx , InstrVec & _inst_seq ) = 0;
  /// To do some extra bookkeeping work when it is known that no more instruction steps are needed.
  void virtual FinishRegisterSteps() = 0;
  /// To apply the axioms, the complete program should be given
  void virtual ApplyAxioms() = 0;
  /// To constrain on the local states, based on whether they are in order or not, can be overwritten by the specific model.
  void virtual SetLocalState(std::vector<bool> ordered);
  // HZ note: All the steps should be registered through the first function: RegisterSteps
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  // we will need a wrapper on the outside
  MemoryModel(z3::context& ctx, 
    ZExprVec & _cstrlist, 
    const StateNameSet & shared_states, 
    const ILANameStateNameSetMap & private_states, 
    const InstrLvlAbsPtr & global_ila_ptr);
  // make destructor virtual
  virtual ~MemoryModel() {}
  // ------------------------- HELPERS -------------------------------------- //
  /// Determine if an instruction access a shared state
  // bool AccessShared ( const InstrPtr & ip, AccessType acc_type );  // (deprecated)


  // ------------------------- AXIOM HELPERS -------------------------------- //
protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// An AST traversor, make sure there are no nested asts
  NestedMemAddrDataAvoider nested_finder_;
  /// An AST traversor, here to find memory reads: address/data
  MemReadFinder            mem_load_expr_finder_;
  // ------------------------- HELPERS -------------------------------------- //
  /// A function for dervied classes to create init trace step
  TraceStepPtr CreateGlobalInitStep();
  // ------------------------- AXIOM HELPERS -------------------------------------- //
  // The implementation of the following functions can be found in axiom_helper.cpp
  // The type of results that can statically determined
  enum { STATIC_TRUE = 1 , STATIC_FALSE, STATIC_UNKNOWN } StaticResult;
  // The type of hints given to the functions to tell what kind of mem ops to look for
  enum { HINT_NONE = 0 , HINT_READ = 1, HINT_WRITE } AxiomFuncHint; // if read disable write-set, if write disable read-set // should only used for SameAddr/SameData
  // Happen-before
  z3::expr HB( TraceStep & l, TraceStep & r );
  // At the same time
  z3::expr Sync( TraceStep & l, TraceStep & r );
  // Program-order
  z3::expr PO( TraceStep & l, TraceStep & r );
  // Same address 
  z3::expr SameAddress( TraceStep & l, TraceStep & r , AxiomFuncHint lhint = HINT_NONE, AxiomFuncHint rhint = HINT_NONE);
  // Get decode (z3 not ast)
  z3::expr Decode( TraceStep & l );
  // Enforce same data
  z3::expr SameData( TraceStep & l, TraceStep & r , AxiomFuncHint lhint = HINT_NONE, AxiomFuncHint rhint = HINT_NONE);
  // Enforcing same core constraint
  bool     SameCore( TraceStep & l, TraceStep & r);
  // STATICALLY DETERMINED
  StaticResult SameAddressStatic( TraceStep & l, TraceStep & r );
  // STATICALLY DETERMINED
  StaticResult DecodeStatic( TraceStep & l);
  // STATICALLY DETERMINED
  StaticResult SameCoreStatic( TraceStep & l, TraceStep & r);

  /// This is to deal with forall (if does not exist, it should be true also)
  z3::expr Z3ForallList(const ZExprVec & l); // move into mcm class
  /// This is to apply to exists, (if does not exist, it should be false)
  z3::expr Z3ExistsList(const ZExprVec & l);
private:
  /// Private helper: return z3 expr to enforce address equality on mem var
  z3::expr MemVarSameAddress(
    const ExprPtr &leftWAddr, AddrDataVec & leftRAddrDataVec, 
    const ExprPtr &rightWAddr, AddrDataVec &rightRAddrDataVec, 
    TraceStep & traceL , TraceStep & traceR);
  /// Private helper: return z3 expr to enforce data equality on mem var
  z3::expr MemVarSameData(
    const std::pair<ExprPtr,ExprPtr> &leftAddrDataPair , AddrDataVec & leftRAddrDataVec, 
    const std::pair<ExprPtr,ExprPtr> &rightAddrDataPair, AddrDataVec & rightRAddrDataVec, 
    TraceStep & traceL , TraceStep & traceR);
  /// Private helper: from state update function to addr/data
  ExprPtr CheckAndPeel(const ExprPtr &e , const std::string & type, size_t argn);
  /// Private helper: return z3 expr to enforce data equality on non-mem var
  z3::expr NonMemVarSameData(
    TraceStep & l, TraceStep & r,
    const std::string & sname,
    AxiomFuncHint lhint, AxiomFuncHint rhint);

}; // class MemoryModel 




} // namespace ila

#endif // MEMORY_MODEL_H__