/// \file
/// Header for memory model

#ifndef MEMORY_MODEL_H__
#define MEMORY_MODEL_H__

#include "mcm/axiom_helper.h"
#include "mcm/ast_helper.h"

/// \namespace ila
namespace ila {


/// Type of state read or write
enum AccessType { READ, WRITE, EITHER } ; 
class MemoryModel;
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
  /// Add friend, so it can get access to the types
  friend class MemoryModel;

public:
  /// Type alias for z3::expr.
  typedef z3::expr ZExpr;
  /// Type for containing a set of z3::expr.
  typedef std::vector<ZExpr> ZExprVec;
  /// Type of trace step pointer
  typedef std::shared_ptr<TraceStep> TraceStepPtr;
  /// Type of set of trace steps
  typedef std::set<TraceStepPtr> TraceStepPtrSet;
  /// Type of state name set
  typedef std::set<std::string> StateNameSet;
  /// the type of trace step type
  enum TraceStepType {INST_EVT, FACET_EVT , INIT_EVT };

private:
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
  z3::expr timestamp;  
  /// The relative position
  size_t _pos_suffix;
  /// Keep an adapter that trace steps (won't shared w. others)
  mutable Z3ExprAdapter _expr2z3_;
  /// Keep a context to allocate z3 vars
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
  InstrPtr inst() const { return _type == TraceStepType::INST_EVT || _type == TraceStepType::INIT_EVT ? _inst : _parent_inst; }
  /// Return the position suffix (for facet, they should have the same suffix as the main step to ensure they use the same var)
  size_t pos_suffix() const { return _pos_suffix; }
  /// Return the adapter
  inline Z3ExprAdapter & z3adapter() const { return _expr2z3_; }
  /// Return the context (for variable creation)
  z3::context & ctx() { return _ctx_; }

  
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// To create a trace step, you need to know the instruction also should give a constraint set: INST_EVT
  TraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx , size_t pos );
  /// This function allows you to overwrite the timestamp instead of creating a new one: INIT_EVT
  TraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx,  ZExpr _ts_overwrite, size_t pos  );
  /// To create a facet event: FACET_EVT
  TraceStep(const InstrPtr & ref_inst, ZExprVec & cstr , z3::context& ctx , const std::string &fevt_name, size_t pos );
  /// Destructor, make it virtual
  virtual ~TraceStep() {}
  // ------------------------- MEMBERS -------------------------------------- //
  /// To update the set for FACET_EVT
  void AddStateAccess(const std::string & name, AccessType acc_type);
  /// To update the set for FACET_EVT
  void AddStateAccess(const StateNameSet &s, AccessType acc_type);
  /// Translate an arbitrary expr using the frame number of this step (so it refers to the var used in this step)
  ZExpr ConvertZ3OnThisStep(const ExprPtr & ast) const { return z3adapter().GetExpr( ast , std::to_string( pos_suffix() ) ); }

  // ------------------------- HELPERS -------------------------------------- //
  /// To determine if the instruction READ/WRITE a certain state 
  bool Access( AccessType acc_type , const std::string & name) const;
  /// To determine if the instruction READ/WRITE a certain set
  bool Access( AccessType acc_type , const StateNameSet & stateset ) const;
}; // class TraceStep

/// \brief The base class for memory models
class MemoryModel {

public:
  /// Type alias for z3::expr.
  using ZExpr = TraceStep::ZExpr;
  /// Type for containing a vector of z3::expr.
  using ZExprVec = TraceStep::ZExprVec;
  /// Type of trace step shared pointers
  using TraceStepPtr = TraceStep::TraceStepPtr;
  /// Type of trace steps, we need to collect the set of trace steps (WRITE)
  using TraceStepPtrSet = TraceStep::TraceStepPtrSet;
  /// Type of trace step type, INIT/INST/FACET
  using TraceStepType = TraceStep::TraceStepType;
  /// Type of set of state names
  using StateNameSet = TraceStep::StateNameSet;
  /// Type of vector of (addr,data) pair
  using AddrDataVec = MemReadFinder::AddrDataVec;
  /// Type of an instruction vector to represent a sequence.
  typedef std::vector<InstrPtr> InstrVec;
  /// Type of a vector of instruction sequences (currently please represent holes via 0-ary functions)
  typedef std::vector<InstrVec> ProgramTemplate;
  /// Type of TraceStep set grouped by ILA (the same sequence as given to the register steps)
  typedef std::vector<std::vector<TraceStepPtr> > PerILATraceStepPtrSet;
  /// Type of map ila-name to state-set
  typedef std::map<std::string, StateNameSet> ILANameStateNameSetMap;


protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The pointer to the initial trace step
  TraceStepPtr _init_trace_step; // will be assigned by function CreateGlobalInitStep
  /// The set of all trace steps
  TraceStepPtrSet _all_trace_steps; // will be assigned by specific memory model
  /// The set of all instruction trace steps
  TraceStepPtrSet _all_inst_trace_steps; // will be assigned by specific memory model
  /// The set of TraceStep set grouped by ILA (the same sequence as given to the register steps)
  PerILATraceStepPtrSet _ila_trace_steps;
  /// The set of names of shared states
  const StateNameSet & m_shared_state_names; // will get a copy from the given set
  /// The internal storage of all private states of all ilas
  const ILANameStateNameSetMap & m_ila_private_state_names; // will get a copy from the given set
  /// The pointer to the (dummy) global ILA
  InstrLvlAbsPtr m_p_global_ila;
  // For passing argument, we need to keep track of the following info:
  /// A reference to Z3 context , even in the sence of const, it should allow us to allocate new variables
  z3::context& _ctx_;
  /// A reference to the constraint list
  ZExprVec & _constr;
  /// An adapter that trace step can share, will allocate internally, by the constructor
  Z3ExprAdapter _expr2z3_; 

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the context (for variable creation)
  z3::context & ctx() const { return _ctx_; }

public:
  /// To initialize the inner storage space.
  void virtual InitSize(const ProgramTemplate & _tmpl);
  /// To create more view operations associated with an instruction, and also to add them to the set
  void virtual RegisterSteps(size_t regIdx , const InstrVec & _inst_seq ) = 0;
  /// To do some extra bookkeeping work when it is known that no more instruction steps are needed.
  void virtual FinishRegisterSteps() = 0;
  /// To apply the axioms, the complete program should be given
  void virtual ApplyAxioms() = 0;
  /// To constrain on the local states, based on whether they are in order or not, can be overwritten by the specific model.
  void virtual SetLocalState(const std::vector<bool> & ordered);
  // HZ note: All the steps should be registered through the first function: RegisterSteps
  /// Assert a property that some trace step (decided by filter) should follow
  void virtual AddSingleTraceStepProperty( ExprPtr property, std::function<bool(const TraceStep &)> filter);
  /// Assert a property that some pair of trace steps (decided by filter) should follow
  void virtual AddDoubleTraceStepProperty( std::function<z3::expr(const TraceStep &,const TraceStep &)>, std::function<bool(const TraceStep &,const TraceStep &)> );
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
  mutable NestedMemAddrDataAvoider nested_finder_;
  /// An AST traversor, here to find memory reads: address/data
  mutable MemReadFinder            mem_load_expr_finder_;
  // ------------------------- HELPERS -------------------------------------- //
  /// A function for dervied classes to create init trace step
  TraceStepPtr CreateGlobalInitStep();
  // ------------------------- AXIOM HELPERS -------------------------------------- //
  // The implementation of the following functions can be found in axiom_helper.cpp
  // The type of results that can statically determined
  enum StaticResult { STATIC_TRUE = 1 , STATIC_FALSE, STATIC_UNKNOWN } ;
  // The type of hints given to the functions to tell what kind of mem ops to look for
  enum AxiomFuncHint { HINT_NONE = 0 , HINT_READ = 1, HINT_WRITE } ; // if read disable write-set, if write disable read-set // should only used for SameAddr/SameData
  // Happen-before
  z3::expr HB( const TraceStep & l, const TraceStep & r ) const;
  // At the same time
  z3::expr Sync( const TraceStep & l, const TraceStep & r ) const;
  // Program-order
  z3::expr PO( const TraceStep & l, const TraceStep & r ) const;
  // Same address 
  z3::expr SameAddress( const TraceStep & l, const TraceStep & r , const std::string & sname, AxiomFuncHint lhint = HINT_NONE, AxiomFuncHint rhint = HINT_NONE) const;
  // Get decode (z3 not ast)
  z3::expr Decode( const TraceStep & l ) const;
  // Enforce same data
  z3::expr SameData( const TraceStep & l, const TraceStep & r , const std::string & sname,  AxiomFuncHint lhint = HINT_NONE, AxiomFuncHint rhint = HINT_NONE) const;
  // Enforcing same core constraint
  bool     SameCore( const TraceStep & l, const TraceStep & r) const;
  // STATICALLY DETERMINED // not implemented
  StaticResult SameAddressStatic( const TraceStep & l, const TraceStep & r ) const;
  // STATICALLY DETERMINED // not implemented
  StaticResult DecodeStatic( const TraceStep & l) const;
  // STATICALLY DETERMINED // not implemented
  StaticResult SameCoreStatic( const TraceStep & l, const TraceStep & r) const;

  /// This is to deal with forall (if does not exist, it should be true also)
  z3::expr Z3ForallList(const ZExprVec & l) const; // move into mcm class
  /// This is to apply to exists, (if does not exist, it should be false)
  z3::expr Z3ExistsList(const ZExprVec & l) const;
private:
  /// Private helper: return z3 expr to enforce address equality on mem var
  z3::expr MemVarSameAddress(
    const ExprPtr &leftWAddr, const AddrDataVec & leftRAddrDataVec, 
    const ExprPtr &rightWAddr, const AddrDataVec &rightRAddrDataVec, 
    const TraceStep & traceL , const TraceStep & traceR) const;
  /// Private helper: return z3 expr to enforce data equality on mem var
  z3::expr MemVarSameData(
    const std::pair<ExprPtr,ExprPtr> &leftAddrDataPair , const AddrDataVec & leftRAddrDataVec, 
    const std::pair<ExprPtr,ExprPtr> &rightAddrDataPair, const AddrDataVec & rightRAddrDataVec, 
    const TraceStep & traceL , const TraceStep & traceR) const;
  /// Private helper: from state update function to addr/data
  ExprPtr CheckAndPeel(const ExprPtr &e , const std::string & type, size_t argn) const;
  /// Private helper: return z3 expr to enforce data equality on non-mem var
  z3::expr NonMemVarSameData(
    const TraceStep & l, const TraceStep & r,
    const std::string & sname,
    AxiomFuncHint lhint, AxiomFuncHint rhint) const;
  /// Private helpr: sanity check on two steps make sure both access the same state and has the same type, not requiring it to be memvar, will ILA_ASSERT instead of return false
  void SameAddrDataSanityCheck( const TraceStep & l, const TraceStep & r , const std::string & sname ) const;

}; // class MemoryModel 




} // namespace ila

#endif // MEMORY_MODEL_H__