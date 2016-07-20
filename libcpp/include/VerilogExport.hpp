
#ifndef __VERILOG_EXPORT_HPP_DEFINED__
#define __VERILOG_EXPORT_HPP_DEFINED__

#include <tuple>

#include <iostream>
#include <ast.hpp>
#include <abstraction.hpp>

#include <ast/node.hpp>

namespace ila
{
	typedef std::string 				vlg_name_t;
	typedef std::string					vlg_stmt_t;
	typedef std::string					vlg_addr_t;
	typedef std::string					vlg_data_t;
	typedef std::vector<vlg_name_t> 	vlg_stmts_t;
	typedef std::pair<vlg_name_t,int> 	vlg_sig_t;
	typedef std::vector<vlg_sig_t> 		vlg_sigs_t;

	typedef std::tuple<vlg_name_t,int,int> vlg_mem_t; // name addr_width data_width
	typedef std::vector<vlg_mem_t>		vlg_mems_t;


	struct memStackItem
	{
		typedef	std::map<vlg_addr_t,vlg_data_t>		mem_item_t;
		//				addr 			data 		condition
		typedef std::map<vlg_stmt_t, mem_item_t>	mem_map_t;

		mem_map_t values;


		memStackItem();
		memStackItem(int index, int value);
		memStackItem(const vlg_addr_t &,const vlg_addr_t & );
		memStackItem(const MemValues& mv);

		memStackItem(const vlg_stmt_t &cond, const memStackItem &l, const memStackItem &r);

		void setItem(int index, int value);
		void setItem(const vlg_addr_t &,const vlg_addr_t & );

	};


	class VerilogExport
	{
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

	protected:

		int get_width(const Node *n);

		void add_input(const vlg_name_t & n,int w);
		void add_output(const vlg_name_t & n,int w);
		void add_wire(const vlg_name_t & n,int w);
		void add_reg(const vlg_name_t & n,int w);
		void add_stmt(const vlg_stmt_t & s);
		void add_always_stmt(const vlg_stmt_t & s);
		void add_init_stmt(const vlg_stmt_t & s);

		void start_iterate(const Node *n);

		std::vector<vlg_stmt_t> 	iterStack;
		std::vector<memStackItem>	memopStack;
		vlg_stmt_t getOperand(); 

		bool EnoughArgsOnStack(const Node *n);
		void nodeVistorFunc(const Node *n);


		int idCounter;
		vlg_name_t NewId();

	public:
		VerilogExport (const std::string &modName,const std::string &clk,const std::string &rst);
		void exportInp(const std::string &name, const npair_t &np);
		void exportReg(const std::string &name, const npair_t &np);
		void exportBit(const std::string &name, const npair_t &np);

		void finalExport(std::ostream & );

		void exportMem(const std::string &name, const npair_t &np)
		{
			// FIXME: not implemented
		}
		void exportFunc( const std::string &name, const npair_t &np)
		{
			// FIXME: not implemented
		}

		void exportUabs( const Abstraction & uabs)
		{
			// FIXME: not implemented
		}

	private:

		std::string WidthToRange(int w);

	};
}


#endif