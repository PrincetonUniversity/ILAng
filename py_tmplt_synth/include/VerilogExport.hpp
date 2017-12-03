
#ifndef __VERILOG_EXPORT_HPP_DEFINED__
#define __VERILOG_EXPORT_HPP_DEFINED__

#include <tuple>

#include <iostream>
#include <ast.hpp>
#include <abstraction.hpp>

#include <ast/node.hpp>

namespace ila
{
    struct VlgExportConfig{
        bool _extMem;
        bool _fmodule;
        VlgExportConfig(bool ExternalMem = false, bool FunctionAsModule = true) : _extMem(ExternalMem), _fmodule(FunctionAsModule)
        {}
    };

    typedef std::string                 vlg_name_t;
    typedef std::string                 vlg_stmt_t;
    typedef std::string                 vlg_addr_t;
    typedef std::string                 vlg_data_t;
    typedef std::vector<vlg_name_t>     vlg_stmts_t;
    typedef std::pair<vlg_name_t,int>   vlg_sig_t;
    typedef std::vector<vlg_sig_t>      vlg_sigs_t;

    typedef std::tuple<vlg_stmt_t,vlg_stmt_t,vlg_stmt_t>  vlg_ite_stmt_t;
    typedef std::vector<vlg_ite_stmt_t>             vlg_ite_stmts_t;
    typedef std::pair<vlg_name_t, vlg_sigs_t>       vlg_per_mem_access_t; // intended for embedded memory (not external memory)

    typedef std::tuple<vlg_name_t,int,int>          vlg_mem_t; // name addr_width data_width
    typedef std::vector<vlg_mem_t>                  vlg_mems_t;

    // This is an individual write.
    struct mem_write_entry_t
    {
        nptr_t addr;
        nptr_t data;
    };
    // This is a list of writes.
    typedef std::list<mem_write_entry_t> mem_write_entry_list_t;
    typedef std::list<mem_write_entry_list_t> mem_write_entry_list_stack_t;
    // This is the write and its associated condition.
    struct mem_write_t 
    {
        nptr_t cond;
        mem_write_entry_list_t writes;
    };
    // List of writes and associated conditions.
    typedef std::list<mem_write_t> mem_write_list_t;

    std::ostream& operator<<(
        std::ostream& out, const mem_write_entry_t& mwe);
    std::ostream& operator<<(
        std::ostream& out, const mem_write_entry_list_t& mwel);
    std::ostream& operator<<(
        std::ostream& out, const mem_write_entry_list_stack_t& mwel);        
    std::ostream& operator<<(
        std::ostream& out, const mem_write_t& mw);
    std::ostream& operator<<(
        std::ostream& out, const mem_write_list_t& mwl);

    class VerilogExport
    {
    public:
        typedef std::unordered_map<
            const Node*, vlg_name_t,
            decltype(&nodeHash), decltype(&nodeEqual)> vexpr_map_t;

    private:
        vlg_name_t moduleName;
        vlg_name_t clkName;
        vlg_name_t rstName;

        vlg_sigs_t inputs; // cinputs ? why?
        vlg_sigs_t outputs;
        vlg_sigs_t mem_i;
        vlg_sigs_t mem_o;
        
        vlg_sigs_t wires;
        vlg_sigs_t regs;
        vlg_mems_t mems;

        vlg_stmts_t init_stmts;
        vlg_stmts_t statements;
        vlg_stmts_t always_stmts;
        vlg_ite_stmts_t ite_stmts; // this stmt is only used in sequential always block
        vlg_stmt_t  preheader; // For auxiliary definitions

        vexpr_map_t nmap;
        rwmap_t notCache;

        mem_write_list_t current_writes;
        mem_write_list_t past_writes;

    protected:

        int get_width(const Node *n);

        void add_input(const vlg_name_t & n,int w);
        void add_output(const vlg_name_t & n,int w);
        void add_wire(const vlg_name_t & n,int w);
        void add_reg(const vlg_name_t & n,int w);
        void add_mem(const vlg_name_t &n, int addr_width,int data_width);
        void add_stmt(const vlg_stmt_t & s);
        void add_always_stmt(const vlg_stmt_t & s);
        void add_init_stmt(const vlg_stmt_t & s);
        void add_ite_stmt(const vlg_stmt_t & cond, const vlg_stmt_t & tstmt, const vlg_stmt_t & fstmt);
        void start_iterate(const Node *n);

        vlg_name_t getName(const Node* n);
        vlg_name_t getArg(const Node* n, int i);
        vlg_name_t translateBoolOp(const BoolOp* boolop);
        vlg_name_t translateBitvectorOp(const BitvectorOp* bvop);

        void nodeVistorFunc(const Node *n);
        void exportCondWrites(
            const std::string &n, int addr_width, 
            int data_width, const mem_write_list_t & writeList);
        void checkMemVar(const Node *n, const MemVar*& mem, int& fail);
        void visitMemNodes(
            const Node* n, const nptr_t& cond,
            mem_write_entry_list_stack_t& writesStack);
        static nptr_t logicalAnd(const nptr_t& c1, const nptr_t& c2);

        unsigned idCounter;
        vlg_name_t NewId();
        vlg_name_t NewId(const std::string &refName);

        bool ExternalMem;
        bool FunctionAsModule;

    public:
        VerilogExport (const std::string &modName,const std::string &clk,const std::string &rst, const VlgExportConfig & config);
        void exportInp(const std::string &name, const npair_t &np);
        void exportReg(const std::string &name, const npair_t &np);
        void exportBit(const std::string &name, const npair_t &np);

        void finalExport(std::ostream & );

        void exportMem(const std::string &name, const npair_t &np);
        void exportFunc( const std::string &name, const npair_t &np);
        void setModuleName(const std::string &modName);

        void exportUabs( const Abstraction & uabs)
        {
            ILA_ASSERT(false, "Not implemented.");
        }
    private:

        std::string WidthToRange(int w);
    };
}


#endif
