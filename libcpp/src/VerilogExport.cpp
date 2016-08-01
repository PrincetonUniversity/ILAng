

#include <abstraction.hpp>
#include <VerilogExport.hpp>
#include <util.hpp>

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
            //std::cout<<"iterate on next"<<std::endl;
            //start_iterate(np.next.get());
            //translate_memory_item(false,addr_width,data_width);
            //std::cout<<"iterate on next finish"<<std::endl;
        }
    }

    void VerilogExport::exportFunc( const std::string &name, const npair_t &np)
    {
        const FuncVar * funcvar = NULL;

        ILA_ASSERT( (funcvar = dynamic_cast<const FuncVar *>(np.var.get()) ), "function variable type mismatched.");

        vlg_stmt_t funcDecal = "function " + WidthToRange(funcvar->type.bitWidth) + " ";
        funcDecal += name + " ;\n";

        int argNo = 0;

        for (const auto &argWidth : funcvar->type.argsWidth)
            funcDecal += vlg_stmt_t("input ") + WidthToRange(argWidth) + " arg" + toStr(argNo++) + ";\n";
        funcDecal += "    begin\n//TODO: Add the specific function HERE.";
        funcDecal += "    end\n";

        funcDecal += "endfunction\n";

        add_stmt(funcDecal);

    }

    void VerilogExport::translate_memory_item(bool is_init_stmt, int addr_width,int data_width)
    {
        ILA_ASSERT(memopStack.size() == 1, "Cannot translate 0 or > 1 mem op");
        ILA_ASSERT(iterStack.size() == 1,  "No memory var name is specified");

        vlg_name_t mem_name = getOperand();
        
        memStackItem mem_value = memopStack.back();
        memopStack.pop_back();

        if ( is_init_stmt )
        {
            for (auto const & cond_addr_data_pair : mem_value.values )
            {
                // ignore the conditions
                for (auto const & addr_data_pair : cond_addr_data_pair.second )
                {
                    add_init_stmt(mem_name + "[" + addr_data_pair.first + "] <= " + addr_data_pair.second  );
                }
            }
        }
        else
        {
            // sometimes we do need multiple ports
            // so, let's count the port number
            unsigned maxPort = 1;
            for (auto const & cond_addr_data_pair : mem_value.values)
                if ( cond_addr_data_pair.second.size() > maxPort )
                    maxPort = cond_addr_data_pair.second.size();

            //vector<vlg_name_t> addr_sigs;
            //vector<vlg_name_t> data_sigs;
            std::vector<vlg_stmt_t> addr_muxs;
            std::vector<vlg_stmt_t> data_muxs;

            std::vector<vlg_stmt_t> addr_muxs_rparenthesis;
            std::vector<vlg_stmt_t> data_muxs_rparenthesis;

            for (unsigned pNo = 0; pNo < maxPort ; pNo ++)
            {
                vlg_name_t addr_sig = mem_name + "_addr_" + toStr(pNo) ;
                vlg_name_t data_sig = mem_name + "_data_" + toStr(pNo) ;

                add_wire(addr_sig,addr_width);
                add_wire(data_sig,data_width);

                //addr_sigs.push_back(addr_sig);
                //data_sigs.push_back(data_sig);

                add_always_stmt(mem_name + "[" + addr_sig + "] <= " + data_sig );

                vlg_stmt_t addr_mux = "assign " + addr_sig + " = \n";
                vlg_stmt_t data_mux = "assign " + data_sig + " = \n";

                addr_muxs.push_back(addr_mux);
                data_muxs.push_back(data_mux);
                addr_muxs_rparenthesis.push_back("");
                data_muxs_rparenthesis.push_back("");
            }
            
            for (auto const & cond_addr_data_pair : mem_value.values)
            {
                unsigned portN = 0;
                const vlg_stmt_t & cond = cond_addr_data_pair.first;

                for(auto const & addr_data_pair : cond_addr_data_pair.second)
                {
                    vlg_stmt_t &addr_mux = addr_muxs[portN];
                    vlg_stmt_t &data_mux = data_muxs[portN];

                    const vlg_stmt_t & addr = addr_data_pair.first;
                    const vlg_stmt_t & data = addr_data_pair.second;

                    addr_mux += vlg_stmt_t("( ") + cond + " ) ? (" + addr + " ) : (\n";
                    data_mux += vlg_stmt_t("( ") + cond + " ) ? (" + data + " ) : (\n";

                    addr_muxs_rparenthesis[portN] += ")";
                    data_muxs_rparenthesis[portN] += ")";

                    portN ++;
                }
            }
            // once we finish iterate on that
            //
            for (unsigned portN = 0; portN < maxPort ; portN++ )
            {
                add_stmt( addr_muxs[portN] + "0" +  addr_muxs_rparenthesis[portN] + ";" );
                add_stmt( data_muxs[portN] + mem_name + "[0]" + data_muxs_rparenthesis[portN]+ ";" );
            }
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

        vlg_name_t tmp_result = NewId();
        vlg_stmt_t tmp_stmt = vlg_stmt_t("assign ") + tmp_result + " = " + result_stmt +" ;";

        add_wire(tmp_result, 1);
        add_stmt(tmp_stmt);
        return tmp_result;
    }

    vlg_name_t VerilogExport::translateBitvectorOp(const BitvectorOp* bvop)
    {
        int width = bvop->type.bitWidth;
        int arity = bvop->nArgs();
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
                result_stmt = vlg_stmt_t(" { {") + toStr(outWidth - bvWidth) +"{"+ arg0 +"["+ toStr(bvWidth)  + "] }  }, " + arg0 + "} ";
            }
        } else if  (op == BitvectorOp::EXTRACT) {
            unsigned hi = static_cast<unsigned> (bvop->param(0));
            unsigned lo = static_cast<unsigned> (bvop->param(1));

            result_stmt =  arg0 + "[" + toStr(hi) +":"+toStr(lo) +"]";
        } else if (arity == 2) {
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
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) >>> ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::MUL) { 
                result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) * ( " +  arg2 + " )) ";
            } else if (op == BitvectorOp::CONCAT) { 
                result_stmt = vlg_stmt_t(" { ( ") + arg1 + " ) , ( " +  arg2 + " ) } ";
            } else if (op == BitvectorOp::GET_BIT) { 
                result_stmt = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 + " ] ) ";
            } else if (op == BitvectorOp::READMEM) { 
                // FIXME: Now we have multiple read ports
                result_stmt = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 + " ] ) ";
            } else if (op == BitvectorOp::READMEMBLOCK) { 
                //result_stmt = vlg_stmt_t(" ( ( ") + arg1 + " ) / ( " +  arg2 + " )) ";
                ILA_ASSERT(bvop->nParams() == 2, "Two parameters expected.");
                int chunks = bvop->param(0);
                endianness_t e = (endianness_t) bvop->param(1);
                ILA_ASSERT(chunks >= 1, "One or more chunks expected.");

                // read from arg1 , start addr = arg1 , repeat chunks' time 
                for (int i=0; i < chunks; i++) {
                    vlg_stmt_t data_i = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 + "+" + toStr(i) + " ] ) "; 
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
                ILA_ASSERT(false,"Operator not supported.");
            }
        } else if (op == BitvectorOp::IF) {
            vlg_name_t arg3 = getArg(bvop, 2);
            vlg_name_t arg2 = getArg(bvop, 1);
            vlg_name_t arg1 = getArg(bvop, 0);

            result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ? ( " +  arg2 + " ) : ( " + arg3 + " )";
        } else if (op == BitvectorOp::APPLY_FUNC) {
            const Node * funcVar = bvop->arg(0).get();
            result_stmt = funcVar->getName() + "(";
            vlg_stmt_t arg_stmt = getArg(bvop, 1);
            for (int i = 2; i != arity; i++) {
                arg_stmt = getArg(bvop, i) + " , " + arg_stmt;
            }
            result_stmt = result_stmt + arg_stmt + ")";
        } else {
            ILA_ASSERT(false,"Operator not supported.");
        }

        vlg_name_t tmp_result = NewId();
        vlg_stmt_t tmp_stmt = vlg_stmt_t("assign ") + tmp_result + " = " + result_stmt +" ;";

        add_wire(tmp_result,width);
        add_stmt( tmp_stmt );
        return tmp_result;
    }

    void VerilogExport::nodeVistorFunc(const Node *n)
    {

        // memoize
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
            // TODO: implement this.
            ILA_ASSERT(false, "MemConst not yet implemented.");
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            ILA_ASSERT(false, "MemOp not yet implemented.");
#if 0
            const MemOp::Op op = memop->getOp();
            vlg_stmt_t result;

            ILA_ASSERT(op!=MemOp::INVALID,"Cannot translate invalid operator to Verilog.");

            if( op == MemOp::STORE) {

                vlg_stmt_t data = getOperand();
                vlg_stmt_t addr = getOperand();
                vlg_stmt_t mem = getOperand();

                memStackItem prevValue = memopStack.back();

                memopStack.pop_back();

                prevValue.setItem(addr,data);

                memopStack.push_back(prevValue);

                result = mem;

            } else if ( op == MemOp::STOREBLOCK) {

                // full size.
                int fullDataSize = memop->arg(2)->type.bitWidth;
                // size of each chunk.
                int chunkSize = memop->arg(0)->type.dataWidth;
                // number of chunks.
                int chunks = fullDataSize / chunkSize;
                // this in the index added to the memory address
                int chunkIndex = 0;
                // this is index used to extract the data.
                int dataIndex = memop->endian == LITTLE_E ? 0 : fullDataSize - chunkSize;
                // fwd/backwd?
                int dataIncr  = memop->endian == LITTLE_E ? chunkSize : -chunkSize;
                // mem.
                vlg_stmt_t data = getOperand();
                vlg_stmt_t addr = getOperand();
                vlg_stmt_t mem = getOperand();

                memStackItem mem_op_tmp = memopStack.back();
                memopStack.pop_back();

                for (; chunkIndex < chunks; chunkIndex++, dataIndex += dataIncr)
                {
                    vlg_stmt_t addr_i = addr + " + " + toStr(chunkIndex);
                    vlg_stmt_t extract_data_stmt = data + "[" + toStr(dataIndex + chunkSize - 1) + ":" + toStr(dataIndex) + "]";

                    mem_op_tmp.setItem(addr_i,extract_data_stmt);
                }
                
                memopStack.push_back(mem_op_tmp);

                result = mem;

            } else if ( op == MemOp::ITE ) {

                vlg_stmt_t m2   = getOperand();
                vlg_stmt_t m1   = getOperand();
                vlg_stmt_t cond = getOperand();

                ILA_ASSERT( memopStack.size() >=2 , "Not enough operands for memory ite" );
                //ILA_ASSERT( m1 == m2, std::string( m1 + " is not the same as " + m2 ));

                memStackItem mem_operand2 = memopStack.back();
                memopStack.pop_back();
                memStackItem mem_operand1 = memopStack.back();
                memopStack.pop_back();

                memopStack.push_back(memStackItem(cond,mem_operand1,mem_operand2));

                result = m1;
            }
#endif
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            nmap[n] = funcvar->getName();
        } else {
            ILA_ASSERT(false, "Node type not supported in VerilogExport.");
        }
    }

    vlg_name_t VerilogExport::NewId()
    {
        return "n" + toStr(idCounter++);
    }

    vlg_stmt_t VerilogExport::getOperand()
    {
        vlg_stmt_t tmp = iterStack.back();
        iterStack.pop_back();
        return tmp;
    }

    VerilogExport::VerilogExport (const std::string &modName,const std::string &clk,const std::string &rst)
        : moduleName(modName)
        , clkName(clk)
        , rstName(rst)
        , nmap(NUM_HASHTABLE_BUCKETS, nodeHash, nodeEqual)
        , idCounter(0)
    {

    }
    void VerilogExport::setModuleName(const std::string &modName)
    {
        moduleName = modName;
    }
    void VerilogExport::finalExport(std::ostream & fout)
    {
        // module XXX ( A,B,C,clk,rst );

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

        for(auto const &mem : mems)
            fout << "reg "<<std::setw(10)<<WidthToRange( std::get<2>(mem) )<<" "<<( std::get<0>(mem) )<< WidthToRange(std::pow(2, std::get<1>(mem)))<<";\n";

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

    // ---------------------------------------------------------------------------------

    memStackItem::memStackItem()
    {

    }
    memStackItem::memStackItem(int index, int value)
    {
        values["1"][toStr(index)] = toStr(value);
    }
    memStackItem::memStackItem(const vlg_addr_t &addr,const vlg_addr_t &data )
    {
        values["1"][addr] = data;
    }

    memStackItem::memStackItem(const MemValues& mv)
    {
        for (auto const & addr_data_pair : mv.values)
            values["1"][toStr(addr_data_pair.first)] = toStr(addr_data_pair.second);
    }

    memStackItem::memStackItem(const vlg_stmt_t &cond, const memStackItem &l, const memStackItem &r)
    {
        for (auto const & cond_addr_data_pair : l.values)
        {
            vlg_stmt_t cond_l = " (" + cond + " ) && (" + cond_addr_data_pair.first + ")";
            values[cond_l] = cond_addr_data_pair.second;
        }
        for (auto const & cond_addr_data_pair : r.values)
        {
            vlg_stmt_t cond_r =  "!(" + cond + " ) && (" + cond_addr_data_pair.first + ")";
            values[cond_r] = cond_addr_data_pair.second;
        }
    }
    void memStackItem::setItem(int index, int value)
    {
        values["1"][toStr(index)] = toStr(value);
    }
    void memStackItem::setItem(const vlg_addr_t &addr,const vlg_addr_t &data )
    {
        values["1"][addr] = data;
    }
}
