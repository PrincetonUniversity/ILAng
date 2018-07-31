/// \file
/// Header for memory model

#ifndef MEMORY_MODEL_H__
#define MEMORY_MODEL_H__

/// \namespace ila
namespace ila {


/// Type of state read or write
enum { READ, WRITE } AccessType;

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

  // ------------------------- HELPERS -------------------------------------- //
  /// Maintain the unique names of trace steps
  std::string GetName();
  static unsigned trace_step_seq_no;
  /// Set the read write set
  void InitReadWriteSet( const InstrPtr & inst  ) ;
protected:
  // ------------------------- MEMBERS -------------------------------------- //
  /// the type of this trace step (event)
  enum {INST_EVT, FACET_EVT} _type;
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
public:
  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  /// Return the host ILA
  inline InstrLvlAbsPtr host() const { return _inst->host(); }
  /// Return the name
  inline std::string name() const { return _name; }
  /// Return the set of states read by inst/parent-inst
  const StateNameSet & get_inst_read_set() const  { return _inst_read_set; }
  /// Return the set of states written by inst/parent-inst
  const StateNameSet & get_inst_write_set() const { return _inst_write_set; }
  
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// To create a trace step, you need to know the instruction also should give a constraint set
  TraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx );
  /// This function allows you to overwrite the timestamp instead of creating a new one
  TraceStep(const InstrPtr & inst , ZExprVec & cstr , z3::context& ctx,  Z3Expr _ts_overwrite );


  /// To create a facet event 
  TraceStep(const InstrPtr & ref_inst, ZExprVec & cstr , z3::context& ctx , const std::string &);
  // ------------------------- MEMBERS -------------------------------------- //
  /// To update the set for FACET_EVT
  void AddStateAccess(const std::string & name, AccessType acc_type);
  /// To update the set for FACET_EVT
  void AddStateAccess(const StateNameSet &s, AccessType acc_type);


  // ------------------------- HELPERS -------------------------------------- //
  /// To determine if the instruction READ/WRITE a certain state 
  bool Access( AccessType acc_type , const std::string & name);
  /// To determine if the instruction READ/WRITE a certain set
  bool Access( AccessType acc_type , SharedStatesSet * m_p_shared_states );
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

protected:
  // Axiom function RF
  // Axiom function FR
  // Axiom function CO
  // pre-defined SameAddress, SameData, Decode, HB, PO, Sync, SameCore
  // A derived class may contain set of trace steps
  /// 
  TraceStepSet _all_trace_steps;
  TraceStepSet _all_inst_trace_steps;

  SharedStatesSet * m_p_shared_states;
  StateNameSet   m_shared_state_names;

public:
  /// To create more view operations associated with an instruction, and also to add them to the set
  void virtual RegisterSteps(InstrVec & _inst_seq,  ZExprVec & _constr, z3::context& ctx_ ) = 0;
  /// To do some extra bookkeeping work when it is known that no more instruction steps are needed.
  void virtual FinishRegisterSteps(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ ) = 0;
  /// To apply the axioms, the complete program should be given
  void virtual ApplyAxioms(ProgramTemplate & _tmpl, ZExprVec & _constr, z3::context& ctx_ ) = 0;
  // HZ note: All the step should be registered through the first function: RegisterSteps

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  MemoryModel() : m_p_shared_states(NULL) {}

  // ------------------------- HELPERS -------------------------------------- //
  /// Determine if an instruction access a shared state
  bool AccessShared ( const InstrPtr & ip, AccessType acc_type );

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //
  void SetSharedStates(SharedStatesSet * p);

}; // class MemoryModel 



/******************************************************************************/
// Helper Class
/******************************************************************************/

/// \brief Class of finding variable uses.
/// So that we don't need to create pi variables
/// for unused state variables.
/// FIXME: currently there is no need to 
/// make a class for it, but in the future it is 
/// possible to use a hash table to avoid traverse
/// the same sub-tree twice.
// T can be ExprPtr or std::string
// C is the converter from ExprPtr to T
template <class T, typename C> 
class VarUseFinder {
public:
  /// Type of vector of ExprPtr with is_var() == true
  typedef std::set<T> VarUseList;
  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor: do nothing
  VarUseFinder() {}
  /// Default destructor: do nothing
  ~VarUseFinder() {}

  // ------------------------- METHODS -------------------------------------- //
  /// Find variable uses for an expression
  void Traverse(const ExprPtr & expr, VarUseList & uses );
  /// Find variable uses for an instruction (update + decode)
  void Traverse(const InstrPtr & i, VarUseList & uses );
  /// Find variable uses for an ila (instruction + fetch + valid )
  void Traverse(const InstrLvlAbsPtr & i, VarUseList & uses );

}; // class VarUseFinder


/******************************************************************************/
// Helper Functions
/******************************************************************************/

/// This is to deal with forall (if does not exist, it should be true also)
z3::expr Z3ForallList(const std::vector<z3::expr> & l, z3::context& ctx_);
/// This is to apply to exists, (if does not exist, it should be false)
z3::expr Z3ExistsList(const std::vector<z3::expr> & l, z3::context& ctx_);
/// This is just a shortcut to be used for generated axiom 
z3::expr Z3Implies(const z3::expr &a, const z3::expr &b);
/// This is just a shortcut to be used for generated axiom 
z3::expr Z3And(const z3::expr &a, const z3::expr &b);


} // namespace ila

#endif // MEMORY_MODEL_H__