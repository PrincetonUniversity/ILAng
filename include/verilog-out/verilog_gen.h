/// \file
/// Header for generating Verilog files
/// Currently not supported 
///  1. Load(Store) / Load(ITE) / Load(MemConst) or their combination
///  2. Function on memory

#ifndef VERILOG_GEN_H__
#define VERILOG_GEN_H__

#include "ila/expr_fuse.h"
#include "z3++.h"
#include <map>
#include <unordered_map>
#include <vector>

/// \namespace ila
namespace ila {

  typedef ExprHash VerilogGenHash;


  /// \brief Class of Verilog Generator
  class VerilogGenerator
  { 
    // --------------------- TYPE DEFINITIONS ---------------------------- //
    /// Type of Verilog id names
    typedef std::string                 vlg_name_t;
    /// Type of Verilog statement
    typedef std::string                 vlg_stmt_t;
    /// Type of Verilog address
    typedef std::string                 vlg_addr_t;
    /// Type of Verilog data
    typedef std::string                 vlg_data_t;
    /// Type of Verilog statements (a vector)
    typedef std::vector<vlg_name_t>     vlg_stmts_t;
    /// Type of Verilog signal, name & bw
    typedef std::pair<vlg_name_t,int>   vlg_sig_t;
    /// Type of Verilog signals (a vector)
    typedef std::vector<vlg_sig_t>      vlg_sigs_t;
    /// Type of set of Verilog signals
    typedef std::set<vlg_sig_t>         vlg_sigs_set_t;
    /// Type of Verilog ITEs (IN sequential block)
    typedef std::tuple<vlg_stmt_t,vlg_stmt_t,vlg_stmt_t>  vlg_ite_stmt_t;
    /// Type of Verilog ITEs statements
    typedef std::vector<vlg_ite_stmt_t>             vlg_ite_stmts_t;
    /// Type of the memorys that are going to be created
    typedef std::tuple<vlg_name_t,int,int>          vlg_mem_t; // name addr_width data_width
    /// Type of collection of memorys
    typedef std::map< vlg_name_t, vlg_mem_t>        vlg_mems_rec_t;
    /// This is type of an individual write.
    struct mem_write_entry_t
    {
      ExprPtr addr;
      ExprPtr data;
    };
    /// This is type of a list of writes.
    typedef std::list<mem_write_entry_t> mem_write_entry_list_t;
    /// Type of a stack of writes use in visitMemNodes
    typedef std::list<mem_write_entry_list_t> mem_write_entry_list_stack_t;
    /// This is the write and its associated condition.
    struct mem_write_t 
    {
      ExprPtr cond;
      mem_write_entry_list_t writes;
    };
    /// List of writes w. associated conditions.
    typedef std::list<mem_write_t> mem_write_list_t;
    // VerilogGen Configure
    struct VlgGenConfig{
      bool extMem;   // whether to export as a verilog array or an interface to operate external memory
      enum funcOption { Internal, External } fcOpt;
      VlgGenConfig( // provide the default settings
        bool ExternalMem = false,
        funcOption funcOpt = funcOption::Internal ) : 
          extMem(ExternalMem), 
          fcOpt(funcOpt)
      {}
    };


    /// Type for caching the generated expressions.
    typedef std::unordered_map<const ExprPtr, vlg_name_t, VerilogGenHash> ExprMap;


    // --------------------- HELPER for DEBUG PURPOSE ---------------------------- //
    friend std::ostream& operator<<(
      std::ostream& out, const mem_write_entry_t& mwe);
    friend std::ostream& operator<<(
      std::ostream& out, const mem_write_entry_list_t& mwel);
    friend std::ostream& operator<<(
      std::ostream& out, const mem_write_entry_list_stack_t& mwel);        
    friend std::ostream& operator<<(
      std::ostream& out, const mem_write_t& mw);
    friend std::ostream& operator<<(
      std::ostream& out, const mem_write_list_t& mwl);

    // --------------------- MEMBERS ---------------------------- //
  private:
    // --------------------- Verilog  related ---------------------------- //
    /// Verilog Module Name
    vlg_name_t moduleName;
    /// Clock signal name
    vlg_name_t clkName;
    /// Reset signal name
    vlg_name_t rstName;
    /// Output signals that allows to determine if an instruction's decode is true
    vlg_sigs_t decodeName;
    /// vector of input signals
    vlg_sigs_t inputs; 
    /// vector of output signals
    vlg_sigs_t outputs;
    /// vector of memory input signals
    vlg_sigs_t mem_i;
    /// vector of memory output signals
    vlg_sigs_t mem_o;
    /// vector of wires to be defined
    vlg_sigs_t wires;
    /// vector of regs to be defined
    vlg_sigs_t regs;
    /// vector of mems to be defined
    vlg_mems_rec_t mems_internal;
    /// vector of mems from outside (will not be defined)
    vlg_mems_rec_t mems_external;
    /// statements to be used when reset, for initial conditions, it will try to translate, but won't guarantee
    vlg_stmts_t init_stmts;
    /// The other part will be put into SVA assumptions, and the module will have a sparate counter to enforce the assumptions
    vlg_stmts_t init_assumpts;
    /// statements to be outside the always block
    vlg_stmts_t statements;
    /// statements to be used in the always block but out of the reset
    vlg_stmts_t always_stmts;
    /// statements to be used in the always block but out of the reset with ITE conditions
    vlg_ite_stmts_t ite_stmts; // this stmt is only used in sequential always block
    /// For auxiliary definitions
    vlg_stmt_t  preheader; 
    /// The map to cache the expression (we only need to store the name)
    ExprMap nmap;

    /// For traverse a mem expression
    mem_write_list_t current_writes;
    /// For traverse a mem expression, hold a pointer to the writes, so they will not be destroyed before used 
    mem_write_list_t past_writes; 

    /// to hold all valid names, a sanity check
    vlg_sigs_set_t all_valid_names;

    // --------------------- HELPER FUNCTIONS ---------------------------- //
    /// Check if a name is reserved (clk/rst/modulename/decodeName/ctrName)
    bool check_reserved_name(const vlg_name_t & n) const;
    /// Get the width of an ExprPtr, must be supported sort
    int static get_width(const ExprPtr &n) const;
    /// convert a widith to a verilog string
    std::string static width_to_vlg_range(int w) const;
    /// get a new id
    vlg_name_t new_id();
    /// if the exprptr contains some meaning in its name, will try to incorporate that to the name;
    vlg_name_t new_id(const ExprPtr & e); 

    /// The id counter
    unsigned idCounter;
    /// The configuration
    const VlgGenConfig cfg_;
    /// reference name list
    std::map<std::string, std::string> reference_name_set;
    /// Set of functions that need to be translated, we will collect this while translating the exprs
    std::set<FuncPtr> func_ptr_set;

  public:
    // --------------------- CONSTRUCTOR ---------------------------- //
    VerilogGenerator(
      const std::string &modName = "",
      const std::string &clk = "clk",
      const std::string &rst = "rst", 
      const VlgGenConfig & config = VlgGenConfig());

    void ParseIla( const InstrLvlAbsPtr & ila_ptr_ );
    void ParseInstr( const InstrPtr & instr_ptr_ );

    void finalExport(std::ostream & fout) const;


  };

}; // namespace ila

#endif // VERILOG_GEN_H__
