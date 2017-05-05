

#include <abstraction.hpp>
#include <VerilogExport.hpp>
#include <util.hpp>
#include <logging.hpp>
#include <boost/range/adaptor/reversed.hpp>

#define toStr(x) (boost::lexical_cast<std::string>(x))

namespace ila
{


    int VerilogExport::get_width(const Node *n)
    {
        const BoolExpr * boolexp = NULL;
        const BitvectorExpr * bitvectorexpr = NULL;
        const FuncExpr * funcexpr = NULL;
        const MemExpr * memexpr = NULL;

        if (  (boolexp = dynamic_cast<const BoolExpr*>(n)) )  {
            return 1;
        }
        else if( (bitvectorexpr = dynamic_cast<const BitvectorVar*>(n)) ) {
            return bitvectorexpr->type.bitWidth;
        }
        else if( (funcexpr = dynamic_cast<const FuncExpr*>(n)) ) {
            return funcexpr->type.bitWidth;
        }
        else if( (memexpr = dynamic_cast<const MemExpr*>(n))  ) {
            return memexpr->type.dataWidth;
        }
        else
            ILA_ASSERT(false, "Node type not supported.");

        return 0;

    }    
    void VerilogExport::exportInp( const std::string &name, const npair_t &np)
    {
        // I just ignore all the other fields and assert np.var can be cast to bitVar
        int w = get_width(np.var.get());
        add_input(name,w);
        add_wire(name,w);

    }
    void VerilogExport::exportReg( const std::string &name, const npair_t &np)
    {
        // 1. get width
        int w = get_width(np.var.get());
        add_reg(name,w);
        add_output(name,w);

        // 2. get init statements
        if(np.init.get())
        {
            start_iterate(np.init.get());
            vlg_name_t result = getName(np.init.get());
            add_init_stmt( name + " <= " + result );
        }

        if(np.next.get())
        {
            start_iterate(np.next.get());
            vlg_name_t result = getName(np.next.get());
            add_always_stmt( name + " <= " + result  );     
        }

    }

    void VerilogExport::exportBit( const std::string &name, const npair_t &np)
    {
        // for bit ? stmts + outputs

        int w = 1;
        add_reg(name,w);
        add_output(name,w);

        // 2. get init statements
        if(np.init.get())
        {
            start_iterate(np.init.get());
            vlg_name_t result = getName(np.init.get());
            add_init_stmt( name + " <= " + result );
        }

        if(np.next.get())
        {
            start_iterate(np.next.get());
            vlg_name_t result = getName(np.next.get());
            add_always_stmt( name + " <= " + result  );     
        }
    }


    std::ostream& operator<<(
        std::ostream& out, const mem_write_t& mw)
    {
        return out << "cond: " << *mw.cond.get() << "; write: " << mw.writes;
    }

    std::ostream& operator<<(
        std::ostream& out, const mem_write_list_t& mwl)
    {
        for (auto&& mw : mwl) {
            out << mw << "; ";
        }
        return out;
    }

    void VerilogExport::exportMem(const std::string &name, const npair_t &np)
    {
        // FIXME: not implemented
        const MemVar * memvar = NULL;
        ILA_ASSERT( (memvar = dynamic_cast<const MemVar*>(np.var.get())) , "memory variable type mismatched" );
        int addr_width = memvar->type.addrWidth;
        int data_width = memvar->type.dataWidth;

        add_mem(name,addr_width,data_width);
        if(np.init.get())
        {
            //std::cout<<"iterate on init"<<std::endl;
            //start_iterate(np.init.get());
            //translate_memory_item(true,addr_width,data_width);
            //std::cout<<"iterate on init finish"<<std::endl;
        }

        if(np.next.get())
        {
            log2("VerilogExport") << "memory : " << *np.var.get() << std::endl;
            log2("VerilogExport") << "next   : " << *np.next.get() << std::endl;

            const Node* next = np.next.get();
            const Node* var = np.var.get();

            if (var->equal(next)) {
                log2("VerilogExport") << "equal" << std::endl;
                return;
            }

            nptr_t cond = BoolConst::get(true);
            mem_write_entry_list_stack_t writesStack;
            mem_write_entry_list_t empty_write_entry_list;
            writesStack.push_back( empty_write_entry_list );

            for (const auto &w: current_writes)
                past_writes.push_back(w);
                
            current_writes.clear();
            visitMemNodes(next, cond, writesStack);
            //std::cout << current_writes << std::endl;

            exportCondWrites(name,addr_width,data_width,current_writes);

            
        }
    }
    void VerilogExport::exportCondWrites(const std::string &name, int addrWidth, int dataWidth, 
        const mem_write_list_t & writeList) 
    {
        // count the maximum ports needed, that is for a single condition what's max size of mem_write_entry_list_t
        unsigned max_port_no = 0;
        for (const auto & mw : writeList)
            if(max_port_no < mw.writes.size())
                max_port_no = mw.writes.size();
        for (unsigned portIdx = 0; portIdx < max_port_no; ++portIdx)
        {
            add_wire(name + "_addr" + toStr(portIdx),addrWidth);
            add_wire(name + "_data" + toStr(portIdx),dataWidth);
            add_wire(name + "_wen"  + toStr(portIdx),1);
            if(ExternalMem) {
                mem_o.push_back( vlg_sig_t(name + "_addr" + toStr(portIdx),addrWidth) );
                mem_o.push_back( vlg_sig_t(name + "_data" + toStr(portIdx),dataWidth) );
                mem_o.push_back( vlg_sig_t(name + "_wen"  + toStr(portIdx),1) );
            }
        }
        std::vector<vlg_stmt_t> enabStmt(max_port_no,"1'b0");
        std::vector<vlg_stmt_t> addrStmt(max_port_no,"0");
        std::vector<vlg_stmt_t> dataStmt(max_port_no,"'dx"); 
        // Note the reverse here!
        for (const auto & mw : boost::adaptors::reverse(writeList) ) {
            start_iterate(mw.cond.get());
            vlg_name_t cond = getName(mw.cond.get());
            int portIdx = 0;
            for (const auto &wr : mw.writes)
            {
                start_iterate(wr.addr.get());
                vlg_name_t addr = getName(wr.addr.get());
                start_iterate(wr.data.get());
                vlg_name_t data = getName(wr.data.get());

                addrStmt[portIdx] = cond + " ? (" + addr + ") : (" + addrStmt[portIdx] + ")";
                dataStmt[portIdx] = cond + " ? (" + data + ") : (" + dataStmt[portIdx] + ")";
                enabStmt[portIdx] = cond + " ? ( 1'b1 ) : ("       + enabStmt[portIdx] + ")";

                portIdx ++;
            }

        }
        for (unsigned portIdx = 0; portIdx < max_port_no; ++portIdx)
        {
            // add statements
            vlg_name_t addrWireName = name + "_addr" + toStr(portIdx);
            vlg_name_t dataWireName = name + "_data" + toStr(portIdx);
            vlg_name_t enabWireName = name + "_wen"  + toStr(portIdx);
            add_stmt(vlg_stmt_t("assign ") + addrWireName + " = " + addrStmt[portIdx] + ";" );
            add_stmt(vlg_stmt_t("assign ") + dataWireName + " = " + dataStmt[portIdx] + ";" );
            add_stmt(vlg_stmt_t("assign ") + enabWireName + " = " + enabStmt[portIdx] + ";" );
            // add memory updates in the always block
            if(ExternalMem) {
                // DO NOTHING
            }
            else {
                vlg_stmt_t assignment = name + " [ " + addrWireName + " ] " + "<= "  + dataWireName;
                vlg_stmt_t condition  = enabWireName;
                add_ite_stmt(condition, assignment, ""); // no else statement
            }
        }
    }

    void VerilogExport::exportFunc( const std::string &name, const npair_t &np)
    {
        const FuncVar * funcvar = NULL;

        ILA_ASSERT( (funcvar = dynamic_cast<const FuncVar *>(np.var.get()) ), "function variable type mismatched.");

        if(FunctionAsModule) {
            vlg_stmt_t funcModDef = "module fun_" + funcvar->getName() + " (\n";
            int argNo = 1;
            for (const auto &argWidth : funcvar->type.argsWidth)
                funcModDef += "    input " + WidthToRange(argWidth) + " arg" + toStr(argNo++) + ",\n";
            funcModDef += "    output " + WidthToRange(funcvar->type.bitWidth) + " result\n";
            funcModDef += ");\n";
            funcModDef += "//TODO: Add the specific function HERE.\n";
            funcModDef += "endmodule\n";
            preheader += funcModDef;
        }
        else {
            vlg_stmt_t funcDecal = "function " + WidthToRange(funcvar->type.bitWidth) + " ";
            funcDecal += name + " ;\n";

            int argNo = 0;

            for (const auto &argWidth : funcvar->type.argsWidth)
                funcDecal += vlg_stmt_t("input ") + WidthToRange(argWidth) + " arg" + toStr(argNo++) + ";\n";
            funcDecal += "    begin\n//TODO: Add the specific function HERE.\n";
            funcDecal += "    end\n";

            funcDecal += "endfunction\n";

            add_stmt(funcDecal);
        }
    }

    // ---------------------------------------------------------------------------------------------

    void VerilogExport::add_input(const vlg_name_t & n,int w)
    {
        inputs.push_back(vlg_sig_t(n,w));
    }
    void VerilogExport::add_output(const vlg_name_t & n,int w)
    {
        outputs.push_back(vlg_sig_t(n,w));
    }
    void VerilogExport::add_wire(const vlg_name_t & n,int w)
    {
        wires.push_back(vlg_sig_t(n,w));
    }
    void VerilogExport::add_reg(const vlg_name_t & n,int w)
    {
        regs.push_back(vlg_sig_t(n,w));
    }
    void VerilogExport::add_stmt(const vlg_stmt_t & s)
    {
        statements.push_back(s);
    }
    void VerilogExport::add_always_stmt(const vlg_stmt_t & s)
    {
        always_stmts.push_back(s);
    }
    void VerilogExport::add_init_stmt(const vlg_stmt_t & s)
    {
        init_stmts.push_back(s);
    }
    void VerilogExport::add_ite_stmt(const vlg_stmt_t & cond, const vlg_stmt_t & tstmt, const vlg_stmt_t & fstmt)
    {
        ite_stmts.push_back(std::make_tuple(cond,tstmt,fstmt));
    }

    void VerilogExport::add_mem(const vlg_name_t &n, int addr_width,int data_width)
    {
        mems.push_back(vlg_mem_t(n,addr_width,data_width));
    }

    // ---------------------------------------------------------------------------------------------

    void VerilogExport::start_iterate(const Node *n)
    {
        auto visitorFun =  [this] (const Node *nptr) { this->nodeVistorFunc(nptr); };
        n->depthFirstVisit( visitorFun );
    }

    vlg_name_t VerilogExport::getName(const Node* n)
    {
        auto pos = nmap.find(n);
        ILA_ASSERT(pos != nmap.end(), "Arg not in map.");
        return pos->second;
    }

    vlg_name_t VerilogExport::getArg(const Node* n, int i)
    {
        Node* arg_i = n->arg(i).get();
        auto pos = nmap.find(arg_i);
        ILA_ASSERT(pos != nmap.end(), "Arg not in map.");
        return pos->second;
    }

    vlg_name_t VerilogExport::translateBoolOp(const BoolOp* boolop)
    {
        vlg_stmt_t result_stmt;
        const BoolOp::Op op = boolop->getOp();
        int arity = boolop->nArgs();

        ILA_ASSERT(op != BoolOp::INVALID,"Cannot translate invalid operator to Verilog.");

        if(op == BoolOp::NOT) {
            vlg_name_t arg = getArg(boolop, 0);
            result_stmt = vlg_stmt_t("~ ( ") + arg + " )";
        } else if( arity == 2 ) {
            vlg_name_t arg2 = getArg(boolop, 1);
            vlg_name_t arg1 = getArg(boolop, 0);

            if( op == BoolOp::AND )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) & ( " +  arg2 + " ) ";
            else if( op == BoolOp::OR )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) | ( " +  arg2 + " ) ";
            else if( op == BoolOp::XOR )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ^ ( " +  arg2 + " ) ";
            else if( op == BoolOp::XNOR )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ^~ ( " +  arg2 + " ) ";
            else if( op == BoolOp::NAND )
                result_stmt = vlg_stmt_t(" ~( ( ") + arg1 + " ) & ( " +  arg2 + " ) ) ";
            else if( op == BoolOp::NOR )
                result_stmt = vlg_stmt_t(" ~( ( ") + arg1 + " ) | ( " +  arg2 + " ) ) ";
            else if( op == BoolOp::IMPLY )
                result_stmt = vlg_stmt_t(" ( ~( ") + arg1 + " ) | ( " +  arg2 + " ) ) ";
            else if(  op == BoolOp::ULT )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) < ( " +  arg2 + " ) ";
            else if(  op == BoolOp::UGT )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) > ( " +  arg2 + " ) ";
            else if(  op == BoolOp::ULE )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) <= ( " +  arg2 + " ) ";
            else if(  op == BoolOp::UGE )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) >= ( " +  arg2 + " ) ";
            else if( op == BoolOp::SLT)
                result_stmt = vlg_stmt_t(" $signed( ") + arg1 + " ) < $signed( " +  arg2 + " ) ";
            else if( op == BoolOp::SGT  )
                result_stmt = vlg_stmt_t(" $signed( ") + arg1 + " ) > $signed( " +  arg2 + " ) ";
            else if( op == BoolOp::SLE )
                result_stmt = vlg_stmt_t(" $signed( ") + arg1 + " ) <= $signed( " +  arg2 + " ) ";
            else if( op == BoolOp::SGE )
                result_stmt = vlg_stmt_t(" $signed( ") + arg1 + " ) >= $signed( " +  arg2 + " ) ";
            else if( op == BoolOp::EQUAL )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) == ( " +  arg2 + " ) ";
            else if( op == BoolOp::DISTINCT )
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) != ( " +  arg2 + " ) ";
            else
                ILA_ASSERT(false,"operator not supported.");
        } else if( op == BoolOp::IF ) {
            vlg_name_t arg3 = getArg(boolop, 2);
            vlg_name_t arg2 = getArg(boolop, 1);
            vlg_name_t arg1 = getArg(boolop, 0);
            result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ? ( " +  arg2 + " ) : ( " + arg3 + " )";
        } else {
            ILA_ASSERT(false, "Operator not supported.");
        }

        vlg_name_t tmp_result = NewId( boolop->getRefName() );
        vlg_stmt_t tmp_stmt = vlg_stmt_t("assign ") + tmp_result + " = " + result_stmt +" ;";

        add_wire(tmp_result, 1);
        add_stmt(tmp_stmt);
        return tmp_result;
    }

    vlg_name_t VerilogExport::translateBitvectorOp(const BitvectorOp* bvop)
    {
        int width = bvop->type.bitWidth;
        const BitvectorOp::Op op = bvop->getOp();

        vlg_name_t arg0 = getArg(bvop, 0);
        vlg_stmt_t result_stmt;

        if (op == BitvectorOp::NEGATE) { // negate : 2's complement
            result_stmt = vlg_stmt_t("( ~ ( ") + arg0 + " ) + 1'b1 )";
        } else if(op == BitvectorOp::COMPLEMENT) {// 1's complement
            result_stmt = vlg_stmt_t("~ ( ") + arg0 + " )";
        } else if(op == BitvectorOp::LROTATE) {
            int rotN = bvop->param(0);
            // since the widths of two are the same, I didn't bother to call arg->width
            rotN = rotN % width;
            if (rotN == 0) result_stmt = arg0;
            else {
                result_stmt = vlg_stmt_t("  { ") + arg0 + " [" + toStr(width - rotN) +":0] ," 
                    +  arg0  + "[" + toStr(width)+":" +  toStr(width-rotN +1)+"] }";
            }
        } else if(op == BitvectorOp::RROTATE) {
            int rotN = bvop->param(0);
            // since the widths of two are the same, I didn't bother to call arg->width
            rotN = rotN % width;
            if (rotN == 0) result_stmt = arg0;
            else {
                result_stmt = vlg_stmt_t(" { ") + arg0  + "[" + toStr(rotN-1)+":0] ," 
                    +  arg0  + "[" + toStr(width)+":" +  toStr(rotN)+"] }";
            }
        } else if(op == BitvectorOp::Z_EXT ) {
            unsigned outWidth = static_cast<unsigned> (bvop->param(0));
            unsigned bvWidth = static_cast<unsigned> (bvop->arg(0)->type.bitWidth);

            if (outWidth == bvWidth) result_stmt = arg0;
            else  {
                result_stmt = vlg_stmt_t(" {") + toStr(outWidth - bvWidth) +"'d0 , " + arg0 + "} ";
            }
        } else if( op == BitvectorOp::S_EXT ) {
            unsigned outWidth = static_cast<unsigned> (bvop->param(0));
            unsigned bvWidth = static_cast<unsigned> (bvop->arg(0)->type.bitWidth);

            if (outWidth == bvWidth) result_stmt = arg0;
            else {
                result_stmt = vlg_stmt_t(" { {") + toStr(outWidth - bvWidth) +"{"+ arg0 +"["+ toStr(bvWidth-1)  + "] }  }, " + arg0 + "} ";
            }
        } else if  (op == BitvectorOp::EXTRACT) {
            unsigned hi = static_cast<unsigned> (bvop->param(0));
            unsigned lo = static_cast<unsigned> (bvop->param(1));

            result_stmt =  arg0 + "[" + toStr(hi) +":"+toStr(lo) +"]";
        } else if (op >= BitvectorOp::ADD && op <= BitvectorOp::READMEMBLOCK) {
            vlg_name_t arg2 = getArg(bvop, 1);
            vlg_name_t arg1 = getArg(bvop, 0);

            if (op == BitvectorOp::ADD) {
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) + ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::SUB ) {
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) - ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::AND) { 
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) & ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::OR) { 
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) | ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::XOR) { 
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ^ ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::XNOR) { 
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ^~ ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::NAND) { 
                result_stmt = vlg_stmt_t(" ~(( ") + arg1 + " ) & ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::NOR) { 
                result_stmt = vlg_stmt_t(" ~(( ") + arg1 + " ) | ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::SDIV) { 
                result_stmt = vlg_stmt_t(" ( $signed( ") + arg1 + " ) / $signed( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::UDIV) { 
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) / ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::SREM) {  // Verilog  default follows srem
                result_stmt = vlg_stmt_t(" ( $signed( ") + arg1 + " ) % $signed( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::UREM) { 
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) % ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::SMOD) { 
                // FIXME: this should be changed 
                // t = a % b
                // if a[hi]^b[hi] res = divisor signed (divisor - t) ; else t
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) % ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::SHL) {  // only shift, use 0 on the right
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) << ( " +  arg2 + " ) ";
            } else if (op == BitvectorOp::LSHR) { 
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) >> ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::ASHR) { 
                result_stmt = vlg_stmt_t(" ( $signed( ") + arg1 + " ) >>> ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::MUL) { 
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) * ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::CONCAT) { 
                result_stmt = vlg_stmt_t(" { ( ") + arg1 + " ) , ( " +  arg2 + " ) } ";
            } else if (op == BitvectorOp::GET_BIT) { 
                result_stmt = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 + " ] ) ";
            } else if (op == BitvectorOp::READMEM) { 
                // FIXME: Now we have multiple read ports
                if (ExternalMem) {
                    int addrWidth = bvop->arg(0)->type.addrWidth;
                    int dataWidth = bvop->arg(0)->type.dataWidth;
                    vlg_name_t addrName = arg1 + "_addr_" + NewId();
                    vlg_name_t dataName = arg1 + "_data_" + NewId();

                    mem_o.push_back( vlg_sig_t(addrName, addrWidth) );
                    mem_i.push_back( vlg_sig_t(dataName, dataWidth) );
                    
                    vlg_stmt_t tmp_stmt = vlg_stmt_t("assign ") + addrName + " = " + arg2 +" ;";
                    add_stmt(tmp_stmt);
                    
                    result_stmt = vlg_stmt_t(dataName);
                }
                else
                    result_stmt = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 + " ] ) ";
            } else if (op == BitvectorOp::READMEMBLOCK) { 
                int addrWidth = bvop->arg(0)->type.addrWidth;
                int dataWidth = bvop->arg(0)->type.dataWidth;
                ILA_ASSERT(bvop->nParams() == 2, "Two parameters expected.");
                int chunks = bvop->param(0);
                endianness_t e = (endianness_t) bvop->param(1);
                ILA_ASSERT(chunks >= 1, "One or more chunks expected.");

                // read from arg1 , start addr = arg1 , repeat chunks' time 
                for (int i=0; i < chunks; i++) {
                    vlg_stmt_t data_i;
                    if (ExternalMem) {
                        vlg_name_t addrName = arg1 + "_addr_" + NewId();
                        vlg_name_t dataName = arg1 + "_data_" + NewId();
                        
                        mem_o.push_back( vlg_sig_t(addrName, addrWidth) );
                        mem_i.push_back( vlg_sig_t(dataName, dataWidth) );
                        
                        vlg_stmt_t tmp_stmt = vlg_stmt_t("assign ") + addrName + " = " + arg2 + "+" + toStr(i) +" ;";
                        add_stmt(tmp_stmt);
                    
                        data_i = dataName;
                    }
                    else
                        data_i = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 + "+" + toStr(i) + " ] ) "; 
                    if (i == 0) {
                        result_stmt = data_i;
                    } else {
                        if (e == LITTLE_E) {
                            result_stmt =  vlg_stmt_t("{") + data_i +","+ result_stmt + "}" ;
                        } else {
                            result_stmt = vlg_stmt_t("{") + result_stmt +","+ data_i + "}" ;
                        }
                    }
                }
            } else {
                log1 ("VerilogExport") << BitvectorOp::operatorNames[op] << " not supported.\n";
                ILA_ASSERT(false,"Operator not supported.");
            }
        } else if (op == BitvectorOp::IF) {
            vlg_name_t arg3 = getArg(bvop, 2);
            vlg_name_t arg2 = getArg(bvop, 1);
            vlg_name_t arg1 = getArg(bvop, 0);

            result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ? ( " +  arg2 + " ) : ( " + arg3 + " )";
        } else if (op == BitvectorOp::APPLY_FUNC) {
            const Node * funcVar = bvop->arg(0).get();
            if(FunctionAsModule) {
                result_stmt = NewId();
                add_wire(result_stmt, get_width(funcVar) );
                vlg_stmt_t funcInstantiation = "fun_"+ funcVar->getName() + "  "+"applyFunc_"+NewId() + "(\n";
                int arity = bvop->nArgs();
                for (int i = 1; i != arity; i++) {
                    funcInstantiation +=  "    .arg"+toStr(i)+"( " + getArg(bvop, i) + " ),\n";
                }
                funcInstantiation += "    .result( " + result_stmt + " )\n" ;
                funcInstantiation += ");";
                add_stmt(funcInstantiation);
            }
            else {
                result_stmt = funcVar->getName() + "(";
                vlg_stmt_t arg_stmt = getArg(bvop, 1);
                int arity = bvop->nArgs();
                for (int i = 2; i != arity; i++) 
                    arg_stmt = arg_stmt +  " , " + getArg(bvop, i) ;
                result_stmt = result_stmt + arg_stmt + ")";
            }
        } else {
            log1 ("VerilogExport") << BitvectorOp::operatorNames[op] << " not supported.\n";
            ILA_ASSERT(false,"Operator not supported.");
        }

        vlg_name_t tmp_result = NewId(bvop->getRefName() );
        vlg_stmt_t tmp_stmt = vlg_stmt_t("assign ") + tmp_result + " = " + result_stmt +" ;";

        add_wire(tmp_result,width);
        add_stmt( tmp_stmt );
        return tmp_result;
    }

    void VerilogExport::nodeVistorFunc(const Node *n)
    {

        // memorize
        if (nmap.find(n) != nmap.end()) return;

        // booleans
        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        // bitvectors
        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        // memories
        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp*  memop = NULL;
        // functions
        const FuncVar* funcvar = NULL;

        //// booleans ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            nmap[n] = boolvar->getName();
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            vlg_name_t bcnst = vlg_stmt_t("1'b") + (boolconst->val()? "1":"0");
            nmap[n] = bcnst;
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            vlg_name_t opres = translateBoolOp(boolop);
            nmap[n] = opres;
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            nmap[n] = bvvar->getName();
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            int width = bvconst->type.bitWidth;
            vlg_stmt_t constStmt = toStr(width) + "'d" + bvconst->vstr();
            nmap[n] = constStmt;
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            vlg_name_t opres = translateBitvectorOp(bvop);
            nmap[n] = opres;
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            nmap[n] = memvar->getName();
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            ILA_ASSERT(false, "MemConst not yet implemented.");
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            ILA_ASSERT(false, "Complex memory expressions not implemented yet.");
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            nmap[n] = funcvar->getName();
        } else {
            ILA_ASSERT(false, "Node type not supported in VerilogExport.");
        }
    }

    void VerilogExport::checkMemVar(const Node *n, const MemVar*& mem, int& fail)
    {
        const BitvectorOp* bvop = NULL;
        const MemOp*  memop = NULL;
        const MemVar* memvar = NULL;

        if (fail) return;
        if ((bvop = dynamic_cast<const BitvectorOp*>(n))) { 
            if ((bvop->getOp() == BitvectorOp::READMEM) || 
                (bvop->getOp() == BitvectorOp::READMEMBLOCK)) {

                const Node* arg0 = bvop->arg(0).get();
                memvar = dynamic_cast<const MemVar*>(arg0);
                if (memvar == NULL) {
                    fail = 1;
                    return;
                }
            }
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            MemOp::Op op = memop->getOp();
            if (op == MemOp::STORE || op == MemOp::STOREBLOCK) {
                const Node* arg0 = memop->arg(0).get();
                memvar = dynamic_cast<const MemVar*>(arg0);
                if (memvar != NULL) {
                    if (mem == NULL) {
                        mem = memvar;
                    } else if (mem != memvar) {
                        fail = 2;
                        return;
                    }
                }
            }
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            if (mem == NULL) {
                mem = memvar;
            } else if (mem != memvar) {
                fail = 3;
                return;
            }
        }
    }

    std::ostream& operator<<(
        std::ostream& out, const mem_write_entry_t& mwe)
    {
        return out << *mwe.addr.get() << ":" << *mwe.data.get() << "; ";
    }

    std::ostream& operator<<(
        std::ostream& out, const mem_write_entry_list_t& mwel)
    {
        out << "[";
        for (auto&& mwe : mwel) {
            out << mwe;
        }
        return out << "]";
    }
    
    std::ostream& operator<<(
        std::ostream& out, const mem_write_entry_list_stack_t& mwel)
    {
        unsigned i=0;
        for (const auto &sitem : mwel)
            out <<"["<< (i++) <<"]:"<<sitem<<std::endl;
        return out;
    }


    void VerilogExport::visitMemNodes(
        const Node* n, const nptr_t& cond,
        mem_write_entry_list_stack_t& writesStack)
    {
        const MemVar* memvar = dynamic_cast<const MemVar*>(n);
        const MemOp* memop = dynamic_cast<const MemOp*>(n);
        ILA_ASSERT(memvar != NULL || memop != NULL, 
            "expected a memvar or memop.");

        log1("VerilogExport")<<"Visiting:"<<(*n)<<std::endl;
        log1("VerilogExport")<<writesStack;

        if (memvar != NULL) {
            // here is where the recursion terminates.
            mem_write_entry_list_t writes = writesStack.back();
            mem_write_t mw = { cond, writes };
            log2("VerilogExport")<<"adding:"<<mw<<std::endl;
            current_writes.push_back(mw);
        } else  {
            // we have a memop.
            MemOp::Op op = memop->getOp();
            if (op == MemOp::ITE) {
                //ILA_ASSERT(writes.size() == 0, "unexpected writes.");
                // compute conditions for each branch.
                nptr_t cite_t(memop->arg(0));
                nptr_t cite_f(BoolOp::negate(cite_t, notCache));
                nptr_t ctrue  = logicalAnd(cond, cite_t);
                nptr_t cfalse = logicalAnd(cond, cite_f);
                // recurse.
                mem_write_entry_list_t writes = writesStack.back();
                writesStack.push_back(writes);
                visitMemNodes(memop->arg(1).get(), ctrue, writesStack);
                writesStack.pop_back();
                writesStack.push_back(writes);
                visitMemNodes(memop->arg(2).get(), cfalse, writesStack);
                writesStack.pop_back();
            } else if (op == MemOp::STORE) {
                mem_write_entry_t mw = { memop->arg(1), memop->arg(2) };
                mem_write_entry_list_t & writes = writesStack.back();
                writes.push_back(mw);
                const nptr_t& mem(memop->arg(0));
                visitMemNodes(mem.get(), cond, writesStack);
            }
        }
    }

    nptr_t VerilogExport::logicalAnd(const nptr_t& c1, const nptr_t& c2)
    {
        if (!c1) {
            return c2;
        } else if (!c2) {
            return c1;
        } else {
            return nptr_t(new BoolOp(BoolOp::AND, c1, c2));
        }
    }

    vlg_name_t VerilogExport::NewId()
    {
        return "n" + toStr(idCounter++);
    }
    
    vlg_name_t VerilogExport::NewId(const std::string &refName)
    {
        if( refName != "" )
            return "n" + toStr(idCounter++) + "__"+refName;
        return NewId();
    }

    VerilogExport::VerilogExport (const std::string &modName,const std::string &clk,const std::string &rst, const VlgExportConfig & config)
        : moduleName(modName)
        , clkName(clk)
        , rstName(rst)
        , nmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
        , notCache(NUM_HASHTABLE_BUCKETS_SMALL, nodeHash, nodeEqual)
        , idCounter(0)
        , ExternalMem(config._extMem)
        , FunctionAsModule(config._fmodule)
    {

    }
    void VerilogExport::setModuleName(const std::string &modName)
    {
        moduleName = modName;
    }
    void VerilogExport::finalExport(std::ostream & fout)
    {
        // module XXX ( A,B,C,clk,rst );

        if(preheader != "") {
            fout << "/* PREHEADER */\n";
            fout << preheader<<"\n";
            fout << "/* END OF PREHEADER */\n";
        }

        if(ExternalMem) {
            for(const auto &io: mem_i)
                inputs.push_back(io);
            for(const auto &io: mem_o)
                outputs.push_back(io);
        }
        
        fout << "module "<< moduleName<< "(\n";
        for(auto const &sig_pair : inputs)
            fout << sig_pair.first <<",\n";
        for(auto const &sig_pair : outputs)
            fout << sig_pair.first <<",\n";
        fout << clkName <<","<<rstName<<",\nstep\n);\n";


        for(auto const &sig_pair  : inputs)
            fout << "input "<<std::setw(10)<<WidthToRange(sig_pair.second)<<" "<<(sig_pair.first) << ";\n";
        fout << "input "<<clkName<<";\ninput "<<rstName<<";\ninput step;\n";

        for(auto const &sig_pair : outputs)
            fout << "output "<<std::setw(10)<<WidthToRange(sig_pair.second)<<" "<<(sig_pair.first) << ";\n";

        for(auto const &sig_pair : regs)
            fout << "reg " <<std::setw(10)<<WidthToRange(sig_pair.second)<<" "<<(sig_pair.first) << ";\n";

        for(auto const &sig_pair : wires)
            fout << "wire " <<std::setw(10)<<WidthToRange(sig_pair.second)<<" "<<(sig_pair.first) << ";\n";
        if(ExternalMem) {

        }
        else {
            for(auto const &mem : mems)
                fout << "reg "<<std::setw(10)<<WidthToRange( std::get<2>(mem) )<<" "<<( std::get<0>(mem) )<< WidthToRange(std::pow(2, std::get<1>(mem)))<<";\n";
        }

        fout << "wire "<<clkName<<";\nwire "<<rstName<<";\n"<<"wire step;\n";

        for(auto const &stmt : statements)
            fout << stmt <<"\n";

        fout << "always @(posedge "<< clkName<<") begin\n";
        fout << "   if("<< rstName<<") begin\n";

        for(auto const &stmt : init_stmts) 
            fout << "       "<<stmt<<";\n";

        fout << "   end\n";
        fout << "   else if(step) begin\n";

        for(auto const &stmt : always_stmts) 
            fout << "       "<<stmt<<";\n";

        for (auto const &stmt : ite_stmts) {
            fout << "       "<<"if (" << std::get<0>(stmt) <<") begin\n";
            fout << "       "<<"    "<< std::get<1>(stmt)<<" ;\n";
            fout << "       "<<"end\n";
            if(std::get<2>(stmt) != "") {
                fout << "       "<<"else begin\n            "<<std::get<2>(stmt)<<" ;\n        end\n";
            }
        }

        fout << "   end\n";
        fout << "end\n";

        fout << "endmodule\n";
    }

    std::string VerilogExport::WidthToRange(int w)
    {
        if(w>1)
            return std::string("[") + toStr(w-1) + ":0]";
        return "";
    }

}
