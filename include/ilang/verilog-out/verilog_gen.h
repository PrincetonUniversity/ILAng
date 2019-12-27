/// \file
/// Header for generating Verilog files
/// Currently not supported
///  1. Load(Store) / Load(ITE) / Load(MemConst) or their combination
///  2. Function on memory
///
/// For 0-ary func, they will be treated as nondet
/// apply the same nondet func twice, will generate two variables
/// if you do want to share the nondet val, please reuse the sub-tree

#ifndef ILANG_VERILOG_OUT_VERILOG_GEN_H__
#define ILANG_VERILOG_OUT_VERILOG_GEN_H__

#include <list>
#include <map>
#include <unordered_map>
#include <vector>

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

typedef ExprHash VerilogGenHash;
class VlgSglTgtGen;
class VlgVerifTgtGen;
class IntefaceDirectiveRecorder;
class TestVerilogExport;

/// \brief Base class of VerilogGenerator
class VerilogGeneratorBase {
public:
  // --------------------- TYPE DEFINITIONS ---------------------------- //
  /// The type of bool value in ila
  using IlaBoolValType = bool;
  /// The type of bitvector value in ila
  using IlaBvValType = BvVal::BvValType;
  /// The unsigned type of bitvector value in ila
  using IlaBvValUnsignedType = BvVal::BvValType;
  /// let the test class use this module
  friend class TestVerilogExport;
  /// let VlgVerifTgtGen use this module to generate the wrapper module
  friend class VlgSglTgtGen;
  /// let IntefaceDirectiveRecorder use this module to generate the wrapper
  /// module
  friend class IntefaceDirectiveRecorder;
  /// type of read port
  typedef struct {
    /// what to connect for raddr
    std::string raddr;
    /// what to connect for rdata
    std::string rdata;
    /// what to connect for ren
    std::string ren;
  } rport_t;
  /// type of write port
  typedef struct {
    /// what to connect for waddr
    std::string waddr;
    /// what to connect for wdata
    std::string wdata;
    /// what to connect for wen
    std::string wen;
  } wport_t;

  /// Type of Verilog id names
  typedef std::string vlg_name_t;
  /// Type of Verilog statement
  typedef std::string vlg_stmt_t;
  /// Type of Verilog constants
  typedef std::string vlg_const_t;
  /// Type of Verilog address
  typedef std::string vlg_addr_t;
  /// Type of Verilog data
  typedef std::string vlg_data_t;
  /// Type of Verilog statements (a vector)
  typedef std::vector<vlg_name_t> vlg_stmts_t;
  /// Type of Verilog names (a vector)
  typedef std::vector<vlg_name_t> vlg_names_t;
  /// Type of Verilog signal, name & bw
  typedef std::pair<vlg_name_t, int> vlg_sig_t;
  /// Type of Verilog signals (a vector)
  typedef std::vector<vlg_sig_t> vlg_sigs_t;
  /// Type of Verilog signals (a vector)
  typedef std::map<vlg_name_t, int> vlg_sigs_map_t;
  /// Type of a map: name -> need to add keep?
  typedef std::map<vlg_name_t, bool> vlg_sig_keep_t;
  /// Type of set of Verilog signals
  typedef std::set<vlg_sig_t> vlg_sigs_set_t;
  /// Type of Verilog ITEs (IN sequential block)
  typedef std::tuple<vlg_stmt_t, vlg_stmt_t, vlg_stmt_t> vlg_ite_stmt_t;
  /// Type of Verilog ITEs statements
  typedef std::vector<vlg_ite_stmt_t> vlg_ite_stmts_t;
  /// Type of the memorys that are going to be created
  typedef std::tuple<vlg_name_t, int, int, int>
      vlg_mem_t; // name addr_width data_width entryNum
  /// Type of collection of memorys
  typedef std::map<vlg_name_t, vlg_mem_t> vlg_mems_rec_t;
  /// This is type of an individual write.
  struct mem_write_entry_t {
    ExprPtr addr;
    ExprPtr data;
  };
  /// This is type of a list of writes.
  typedef std::list<mem_write_entry_t> mem_write_entry_list_t;
  /// Type of a stack of writes use in visitMemNodes
  typedef std::list<mem_write_entry_list_t> mem_write_entry_list_stack_t;
  /// This is the write and its associated condition.
  struct mem_write_t {
    ExprPtr cond;
    mem_write_entry_list_t writes;
  };
  /// List of writes w. associated conditions.
  typedef std::list<mem_write_t> mem_write_list_t;

  /// Type of app func
  struct function_app_t {
    /// arguments
    std::vector<vlg_sig_t> args;
    /// result
    const vlg_sig_t result;
    /// ila func name
    const std::string func_name;
    /// constructor
    function_app_t(const vlg_sig_t& res, const std::string fn)
        : result(res), func_name(fn) {}
  }; // struct function_app_t
  typedef std::vector<function_app_t> function_app_vec_t;

  /// Type of ite update unknown 
  struct state_update_unknown {
    /// the condition
    const vlg_name_t condition;
    // you don't need the value
    state_update_unknown(const vlg_name_t & c) : condition(c) {}
  }; // struct state_update_unknown
  typedef std::map<std::string, state_update_unknown> state_update_ite_unknown_map_t;

  /// Type for caching the generated expressions.
  typedef std::unordered_map<const ExprPtr, vlg_name_t, VerilogGenHash> ExprMap;
  /// Type for cacheing the constant
  // (this is needed because our hash is not fully working)
  typedef std::map<std::pair<IlaBvValType, unsigned>, vlg_name_t> CnstMap;
  /// Type for memory annotation
  typedef std::map<std::string, bool> memory_export_annotation_t;

  // VerilogGen Configure
public:
  /// the structure to configure the verilog generator
  struct VlgGenConfig {
    /// whether to export as a verilog array or an interface to operate external
    /// memory
    bool extMem;
    /// whether to treat function as internal module/external module
    enum funcOption { Internal, External } fcOpt;
    /// whether to have the start signal
    bool start_signal;
    /// whether to set vlg name according to the node name
    bool pass_node_name;
    /// whether to give random init to the register
    bool reg_random_init; // this is also to avoid Yosys optimization
    /// whether to expand the memory and connect everything to the outside
    /// cannot be true the same time as extMem
    bool expand_mem;
    /// whether to collect the ite(c, v, unknown) thing
    bool collect_ite_unknown_update;

    /// Constructor, set default value, ExternalMem : false, function: internal
    /// module
    VlgGenConfig( // provide the default settings
        bool ExternalMem = true, funcOption funcOpt = funcOption::Internal,
        bool gen_start = false, bool pass_name = false, bool rand_init = false,
        bool ExpandMem = false, bool CollectIteUnknownUpdate = false)
        : extMem(ExternalMem), fcOpt(funcOpt), start_signal(gen_start),
          pass_node_name(pass_name), reg_random_init(rand_init),
          expand_mem(ExpandMem), collect_ite_unknown_update(CollectIteUnknownUpdate) {}
    /// Overwrite configuration, used by vtarget gen
    VlgGenConfig(const VlgGenConfig& c, bool ExternalMem, funcOption funcOpt,
                 bool gen_start, bool rand_init, bool ExpandMem, bool CollectIteUnknownUpdate)
        : extMem(ExternalMem), fcOpt(funcOpt), start_signal(gen_start),
          pass_node_name(c.pass_node_name), reg_random_init(rand_init),
          expand_mem(ExpandMem), collect_ite_unknown_update(CollectIteUnknownUpdate) {}
    // set other fields if there are such need (?)
  }; // end of struct VlgGenConfig

  // --------------------- HELPER for DEBUG PURPOSE ----------------------------
  //
  friend std::ostream& operator<<(std::ostream& out,
                                  const mem_write_entry_t& mwe);
  friend std::ostream& operator<<(std::ostream& out,
                                  const mem_write_entry_list_t& mwel);
  friend std::ostream& operator<<(std::ostream& out,
                                  const mem_write_entry_list_stack_t& mwel);
  friend std::ostream& operator<<(std::ostream& out, const mem_write_t& mw);
  friend std::ostream& operator<<(std::ostream& out,
                                  const mem_write_list_t& mwl);

  // --------------------- MEMBERS ---------------------------- //
protected:
  // --------------------- Verilog  related ---------------------------- //
  /// Verilog Module Name
  vlg_name_t moduleName;
  /// Clock signal name
  vlg_name_t clkName;
  /// Reset signal name
  vlg_name_t rstName;
  /// Output signals that allows to determine if an instruction's decode is
  /// true,  not need for width
  vlg_names_t decodeNames;
  /// Output signals that allows to determine if an instruction's valid is true,
  /// not need for width
  vlg_name_t validName;
  /// start signal name, may not be used
  vlg_name_t startName;
  /// An input, that can be used to control which instruction you would like to
  /// execute if more than one is ready you can assume in JasperGold that:
  /// $onehot(grant) && ( grant & decodeAccName == grant ) to enforce that: you
  /// only grant to one and only one instruction whose decode is true. another
  /// approach is to set grant to all 1s.
  vlg_sig_t grantAccName;
  /// accumulated decode signals
  vlg_sig_t decodeAccName;
  /// The name of internal counter
  vlg_name_t counterName;
  /// vector of input signals
  vlg_sigs_map_t inputs;
  /// vector of output signals
  vlg_sigs_map_t outputs;
  /// vector of memory input signals
  vlg_sigs_t mem_i;
  /// vector of memory output signals
  vlg_sigs_t mem_o;
  /// vector of signals that probe each element of a memory
  vlg_sigs_t mem_probe_o;
  /// vector of wires to be defined
  vlg_sigs_map_t wires;
  /// a map to store if a wire needs to keep
  vlg_sig_keep_t wires_keep;
  /// vector of regs to be defined
  vlg_sigs_t regs;
  /// vector of mems to be defined
  vlg_mems_rec_t mems_internal;
  /// vector of mems from outside (will not be defined)
  vlg_mems_rec_t mems_external;
  /// statements to be used when reset, for initial conditions, it will try to
  /// translate, but won't guarantee
  vlg_stmts_t init_stmts;
  /// The other part will be put into SVA assumptions, and the module will have
  /// a sparate counter to enforce the assumptions
  vlg_stmts_t init_assumpts;
  /// statements to be outside the always block
  vlg_stmts_t statements;
  /// statements to be used in the always block but out of the reset
  vlg_stmts_t always_stmts;
  /// statements to be used in the always block but out of the reset with ITE
  /// conditions
  vlg_ite_stmts_t
      ite_stmts; // this stmt is only used in sequential always block
  /// For auxiliary definitions
  vlg_stmt_t preheader;
  /// The map to cache the expression (we only need to store the name)
  ExprMap nmap;
  /// The map to cache the constants (o.w. there will be overhead, as each
  /// constant may appear multiple times)
  CnstMap cmap;

  /// For traverse a mem expression
  mem_write_list_t current_writes;
  /// For traverse a mem expression, hold a pointer to the writes, so they will
  /// not be destroyed before used
  mem_write_list_t past_writes;

  /// to hold all valid names, a sanity check
  vlg_sigs_set_t all_valid_names;
  /// To record which mem interface signal correspond to what...
  /// ila read ports
  std::map<std::string, std::map<unsigned, rport_t>> ila_rports;
  /// ila write ports
  std::map<std::string, std::map<unsigned, wport_t>> ila_wports;
  /// a collection of all function application
  function_app_vec_t ila_func_app;
  /// a collection of all state update ite unknown
  state_update_ite_unknown_map_t state_update_ite_unknown;
  // Annotations
  memory_export_annotation_t memory_export_annotation;

  // --------------------- HELPER FUNCTIONS ---------------------------- //
  /// Check if a name is reserved (clk/rst/modulename/decodeName/ctrName)
  bool check_reserved_name(const vlg_name_t& n) const;
  /// Get the width of an ExprPtr, must be supported sort
  int static get_width(const ExprPtr& n);
  /// convert a widith to a verilog string
  std::string static WidthToRange(int w);
  /// get a new id
  vlg_name_t new_id();
  /// if the exprptr contains some meaning in its name, will try to incorporate
  /// that to the name;
  vlg_name_t new_id(const ExprPtr& e);

public:
  /// sanitize a name string, so it will generate illegal verilog identifier
  static vlg_name_t sanitizeName(const vlg_name_t& n);
  /// sanitize the name of an expr, so it will generate illegal verilog
  /// identifier
  static vlg_name_t sanitizeName(const ExprPtr& n);
  /// will force to be hex
  static vlg_const_t ToVlgNum(IlaBvValType value, unsigned width);

protected:
  /// The id counter
  unsigned idCounter;
  /// The configuration
  const VlgGenConfig cfg_;
  /// reference name list
  std::map<std::string, std::string> reference_name_set;
  /// Set of functions that need to be translated, we will collect this while
  /// translating the exprs
  std::set<FuncPtr> func_ptr_set;

  // --------------------- HELPER FUNCTIONS ---------------------------- //
public:
  /// record an input signal
  void add_input(const vlg_name_t& n, int w);
  /// record an output signal
  void add_output(const vlg_name_t& n, int w);
  /// record a wire
  void add_wire(const vlg_name_t& n, int w, bool keep = false);
  /// record a register
  void add_reg(const vlg_name_t& n, int w);
  /// record a stmt (outside the always block)
  void add_stmt(const vlg_stmt_t& s);
  /// record an assignment stmt (outside the always block), will call add_stmt
  void add_assign_stmt(const vlg_name_t& l, const vlg_name_t& r);
  /// record an assignment in the always block (after the reset, in the else
  /// branch, guarded by the valid condition )
  void add_always_stmt(const vlg_stmt_t& s);
  /// record an assignemnt in the always block (in if(rst) branch )
  void add_init_stmt(const vlg_stmt_t& s);
  /// record an ite assignment, (after the reset, in the else branch, guarded by
  /// the valid condition ), (if fstmt == "", will not generate its else block)
  void add_ite_stmt(const vlg_stmt_t& cond, const vlg_stmt_t& tstmt,
                    const vlg_stmt_t& fstmt);
  /// record an internal memory
  void add_internal_mem(const vlg_name_t& mem_name, int addr_width,
                        int data_width, int entry_num);
  /// record an external memory
  void add_external_mem(const vlg_name_t& mem_name, int addr_width,
                        int data_width, int entry_num);
  /// add an item to the preheader
  void add_preheader(const vlg_stmt_t& stmt);

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// \param[in] Configuration
  /// \param[in] Top module name, if empty, get it from instruction name
  /// \param[in] clock signal name
  /// \param[in] reset signal name
  VerilogGeneratorBase(const VlgGenConfig& config = VlgGenConfig(),
                       const std::string& modName = "",
                       const std::string& clk = "clk",
                       const std::string& rst = "rst");

  /// after parsing either the Instruction/ILA, use this function to dump to a
  /// file.
  virtual void DumpToFile(std::ostream& fout) const;

  // --------------------- ANNOTATION INTERFACE ---------------------------- //
  /// add memory annotation, please invoke right after constructor
  void AnnotateMemory(const memory_export_annotation_t& annotation);
}; // class VerilogGeneratorBase

/// \brief Class of Verilog Generator
class VerilogGenerator : public VerilogGeneratorBase {
public:
  // --------------------- TYPE DEFINITIONS ---------------------------- //
  /// let the test class use this module
  friend class TestVerilogExport;
  /// Type of Verilog id names'
  using vlg_name_t = VerilogGeneratorBase::vlg_name_t;
  /// Type of Verilog statement
  using vlg_stmt_t = VerilogGeneratorBase::vlg_stmt_t;
  /// Type of Verilog address
  using vlg_addr_t = VerilogGeneratorBase::vlg_addr_t;
  /// Type of Verilog data
  using vlg_data_t = VerilogGeneratorBase::vlg_data_t;
  /// Type of Verilog statements (a vector)
  using vlg_stmts_t = VerilogGeneratorBase::vlg_stmts_t;
  /// Type of Verilog names (a vector)
  using vlg_names_t = VerilogGeneratorBase::vlg_names_t;
  /// Type of Verilog signal, name & bw
  using vlg_sig_t = VerilogGeneratorBase::vlg_sig_t;
  /// Type of Verilog signals (a vector)
  using vlg_sigs_t = VerilogGeneratorBase::vlg_sigs_t;
  /// Type of a map: name -> need to add keep?
  using vlg_sig_keep_t = VerilogGeneratorBase::vlg_sig_keep_t;
  /// Type of set of Verilog signals
  using vlg_sigs_set_t = VerilogGeneratorBase::vlg_sigs_set_t;
  /// Type of Verilog ITEs (IN sequential block)
  using vlg_ite_stmt_t = VerilogGeneratorBase::vlg_ite_stmt_t;
  /// Type of Verilog ITEs statements
  using vlg_ite_stmts_t = VerilogGeneratorBase::vlg_ite_stmts_t;
  /// Type of the memorys that are going to be created
  using vlg_mem_t = VerilogGeneratorBase::vlg_mem_t;
  /// Type of collection of memorys
  using vlg_mems_rec_t = VerilogGeneratorBase::vlg_mems_rec_t;
  /// This is type of an individual write.
  using mem_write_entry_t = VerilogGeneratorBase::mem_write_entry_t;
  /// This is type of a list of writes.
  using mem_write_entry_list_t = VerilogGeneratorBase::mem_write_entry_list_t;
  /// Type of a stack of writes use in visitMemNodes
  using mem_write_entry_list_stack_t =
      VerilogGeneratorBase::mem_write_entry_list_stack_t;
  /// This is the write and its associated condition.
  using mem_write_t = VerilogGeneratorBase::mem_write_t;
  /// List of writes w. associated conditions.
  using mem_write_list_t = VerilogGeneratorBase::mem_write_list_t;
  /// Type for caching the generated expressions.
  using ExprMap = VerilogGeneratorBase::ExprMap;
  // VerilogGen Configure
  /// the structure to configure the verilog generator
  using VlgGenConfig = VerilogGeneratorBase::VlgGenConfig;
  /// Type of function apply record
  using function_app_t = VerilogGeneratorBase::function_app_t;
  /// Type of func app vector record
  using function_app_vec_t = VerilogGeneratorBase::function_app_vec_t;

private:
  // --------------------- HELPER FUNCTIONS ---------------------------- //
  /// handle a input variable (memvar/bool/bv)
  void insertInput(const ExprPtr& input);
  /// handle a state variable
  void insertState(const ExprPtr& state);

  // Here we are not using depthfirstSearch as we need to alternate between
  // root-first/root-last traversal
  /// traverse to the subtree, caller: ParseNonMemUpdateExpr
  void parseArg(const ExprPtr& e);
  /// After you parse a subtree, this can help you get the vlg name associated
  /// with it
  VerilogGenerator::vlg_name_t getVlgFromExpr(const ExprPtr& e);
  /// a short cut of calling getVlgFromExpr to find arg's vlg names
  VerilogGenerator::vlg_name_t getArg(const ExprPtr& e, const size_t& i);
  /// Handle function application , Caller: translateBoolOp, translateBvOp
  vlg_name_t translateApplyFunc(std::shared_ptr<ExprOpAppFunc> func_app_ptr_);
  /// called by ParseNonMemUpdateExpr to deal with a boolop node
  vlg_name_t translateBoolOp(const std::shared_ptr<ExprOp>& e);
  /// called by ParseNonMemUpdateExpr to deal with a bvop node
  vlg_name_t translateBvOp(const std::shared_ptr<ExprOp>& e);
  /// travserse an expression, not used as mem-write subtree
  void ParseNonMemUpdateExpr(const ExprPtr& e);
  /// check if a mem-write subtree is what we can handle right now
  bool CheckMemUpdateNode(const ExprPtr& e, const std::string& mem_var_name);
  /// traverse the memory-write subtree of "e", its upper level has the
  /// condition "cond"
  void VisitMemNodes(const ExprPtr& e, const ExprPtr& cond,
                     mem_write_entry_list_stack_t& writesStack);

  /// add signals & stmts for an internal counter to trace start (more not be
  /// useful)
  void addInternalCounter(vlg_name_t decode_sig_name, size_t width = 8);
  /// use: func_ptr_set ;  affect: prehear, only export if func is internal
  void ExportFuncDefs();

  /// generate the signals to write a memory (external/internal)
  void ExportCondWrites(const ExprPtr& mem_var,
                        const mem_write_list_t& writeList);
  /// parse an expr used as the memory update, will affect: past_writes &
  /// current_writes
  void ParseMemUpdateNode(const ExprPtr& cond, const ExprPtr& e,
                          const std::string& mem_var_name);

public:
  // --------------------- CONSTRUCTOR ---------------------------- //
  /// \param[in] Configuration
  /// \param[in] Top module name, if empty, get it from instruction name
  /// \param[in] clock signal name
  /// \param[in] reset signal name
  VerilogGenerator(const VlgGenConfig& config = VlgGenConfig(),
                   const std::string& modName = "",
                   const std::string& clk = "clk",
                   const std::string& rst = "rst");
  /// Parse an ILA, will gen all its instructions
  void ExportIla(const InstrLvlAbsPtr& ila_ptr_);
  /// Parse an instruction
  void ExportTopLevelInstr(const InstrPtr& instr_ptr_);
}; // class VerilogGenerator

}; // namespace ilang

#endif // ILANG_VERILOG_OUT_VERILOG_GEN_H__
