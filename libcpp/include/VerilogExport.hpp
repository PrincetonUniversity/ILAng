
#ifndef __VERILOG_EXPORT_HPP_DEFINED__
#define __VERILOG_EXPORT_HPP_DEFINED__

#include <tuple>

#include <iostream>
#include <ast.hpp>
#include <abstraction.hpp>

#include <ast/node.hpp>

namespace ila
{
    typedef std::string                 vlg_name_t;
    typedef std::string                 vlg_stmt_t;
    typedef std::string                 vlg_addr_t;
    typedef std::string                 vlg_data_t;
    typedef std::vector<vlg_name_t>     vlg_stmts_t;
    typedef std::pair<vlg_name_t,int>   vlg_sig_t;
    typedef std::vector<vlg_sig_t>      vlg_sigs_t;

    typedef std::tuple<vlg_name_t,int,int> vlg_mem_t; // name addr_width data_width
    typedef std::vector<vlg_mem_t>      vlg_mems_t;

    // This is an individual write.
    struct mem_write_entry_t
    {
        Node* addr;
        Node* data;
    };
    // This is a list of writes.
    typedef std::list<mem_write_entry_t> mem_write_entry_list_t;
    // This is the write and its associated condition.
    struct mem_write_t 
    {
        Node* cond;
        mem_write_entry_list_t writes;
    };
    // List of writes and associated conditions.
    typedef std::list<mem_write_t> mem_write_list_t;

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
        
        vlg_sigs_t wires;
        vlg_sigs_t regs;
        vlg_mems_t mems;

        vlg_stmts_t init_stmts;
        vlg_stmts_t statements;
        vlg_stmts_t always_stmts;

        vexpr_map_t nmap;

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

        void start_iterate(const Node *n);

        vlg_name_t getName(const Node* n);
        vlg_name_t getArg(const Node* n, int i);
        vlg_name_t translateBoolOp(const BoolOp* boolop);
        vlg_name_t translateBitvectorOp(const BitvectorOp* bvop);

        void nodeVistorFunc(const Node *n);

        unsigned idCounter;
        vlg_name_t NewId();

    public:
        VerilogExport (const std::string &modName,const std::string &clk,const std::string &rst);
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
