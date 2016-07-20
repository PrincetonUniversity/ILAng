

#include <abstraction.hpp>
#include <VerilogExport.hpp>
#include <util.hpp>

#define toStr(x) (boost::lexical_cast<std::string>(x))

/*


    struct npair_t {
        nptr_t var;
        nptr_t init;
        nptr_t ipred;
        nptr_vec_t next_vec;
        nptr_t next;
        const npair_t* parent;
        }

*/

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
            add_init_stmt( name + " <= " + getOperand() );
        }

        if(np.next.get())
        {
            start_iterate(np.next.get());
            add_always_stmt( name + " <= " + getOperand()  );     
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
            add_init_stmt( name + " <= " + getOperand() );
        }

        if(np.next.get())
        {
            start_iterate(np.next.get());
            add_always_stmt( name + " <= " + getOperand()  );  
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


    // ---------------------------------------------------------------------------------------------

    void VerilogExport::start_iterate(const Node *n)
    {
        iterStack.clear();
        memopStack.clear();

        auto visitorFun =  [this] (const Node *nptr) { this->nodeVistorFunc(nptr); };
        n->depthFirstVisit( visitorFun );

        ILA_ASSERT(iterStack.size() == 1, "Iteration for verilog generation failed. Not one result is generated.");
        ILA_ASSERT(memopStack.size() <= 1, "Iteration for verilog generation failed. More than one result is generated.");
    }

    void VerilogExport::nodeVistorFunc(const Node *n)
    {

        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;
        const BoolChoice* bchoiceop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;
        const BitvectorChoice* bvchoiceop = NULL;
        const BVInRange* inrangeop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp*  memop = NULL;
        const MemChoice* mchoiceop = NULL;

        const FuncVar* funcvar = NULL;


        //// booleans ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            iterStack.push_back(boolvar->getName());

        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {

            iterStack.push_back(vlg_stmt_t("1'b") + (boolconst->val()? "1":"0") );

        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {

            ILA_ASSERT(EnoughArgsOnStack(n),"Not enough operands.");
            // translate op

            vlg_stmt_t result_stmt;

            const BoolOp::Op op = boolop->getOp();
            int arity = boolop->nArgs();

            ILA_ASSERT(op != BoolOp::INVALID,"Cannot translate invalid operator to Verilog.");

            if(op == BoolOp::NOT)
                result_stmt = vlg_stmt_t("~ ( ") + getOperand() + " )";
            else if( arity == 2 ) 
            {
                vlg_name_t arg2 = getOperand();
                vlg_name_t arg1 = getOperand();

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
                    //ILA_ASSERT(false,"operator imply can not be translated to Verilog.")
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
            }
            else if( op == BoolOp::IF ) {
                vlg_name_t arg3 = getOperand();
                vlg_name_t arg2 = getOperand();
                vlg_name_t arg1 = getOperand();
                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ? ( " +  arg2 + " ) : ( " + arg3 + " )";
            }
            else
                ILA_ASSERT(false,"operator not supported.");

            vlg_name_t tmp_result     = NewId();
            vlg_stmt_t tmp_stmt        = vlg_stmt_t("assign ") + tmp_result + " = " + result_stmt +" ;";

            add_wire(tmp_result,1);
            add_stmt( tmp_stmt );
            iterStack.push_back(tmp_result);


            // pop ? from stacks
        } else if((bchoiceop = dynamic_cast<const BoolChoice*>(n))) {
            // this should not happen ?
            ILA_ASSERT(false, "Not synthesized yet because bool choice type encountered.");

        //// bitvectors ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            iterStack.push_back(bvvar->getName());            

        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            int width = bvconst->type.bitWidth;

            vlg_stmt_t constStmt = toStr(width) + "'d" + bvconst->vstr();
            iterStack.push_back(constStmt);

        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {

            ILA_ASSERT(EnoughArgsOnStack(n),"Not enough operands.");

            int width = bvop->type.bitWidth;


            int arity = bvop->nArgs();
            const BitvectorOp::Op op = bvop->getOp();

            ILA_ASSERT(op != BitvectorOp::INVALID, "Cannot translate invalid operator to Verilog.");

            vlg_stmt_t result_stmt;

            if(op == BitvectorOp::NEGATE) // negate : 2's complement
                result_stmt = vlg_stmt_t("( ~ ( ") + getOperand() + " ) + 1'b1 )";
            else if(op == BitvectorOp::COMPLEMENT)    // 1's complement
                result_stmt = vlg_stmt_t("~ ( ") + getOperand() + " )";
            else if(op == BitvectorOp::LROTATE) {
                int rotN = bvop->param(0);
                // since the widths of two are the same, I didn't bother to call arg->width
                rotN = rotN % width;
                if (rotN == 0)
                    result_stmt = getOperand();
                else
                {
                    auto operand = getOperand();
                    result_stmt = vlg_stmt_t("  { ") + operand + " [" + toStr(width - rotN) +":0] ," 
                                    +  operand  + "[" + toStr(width)+":" +  toStr(width-rotN +1)+"] }";
                }
            }
            else if(op == BitvectorOp::RROTATE) {
                int rotN = bvop->param(0);
                // since the widths of two are the same, I didn't bother to call arg->width
                rotN = rotN % width;
                if (rotN == 0)
                    result_stmt = getOperand();
                else
                {
                    auto operand = getOperand();
                    result_stmt = vlg_stmt_t(" { ") + operand  + "[" + toStr(rotN-1)+":0] ," 
                                    +  operand  + "[" + toStr(width)+":" +  toStr(rotN)+"] }";
                }
            }
            else if(op == BitvectorOp::Z_EXT )
            {
                unsigned outWidth = static_cast<unsigned> (bvop->param(0));
                unsigned bvWidth = static_cast<unsigned> (bvop->arg(0)->type.bitWidth);

                ILA_ASSERT(outWidth >= bvWidth,"cannot use extend to shrink the width");

                if (outWidth == bvWidth)
                    result_stmt = getOperand();
                else 
                    result_stmt = vlg_stmt_t(" {") + toStr(outWidth - bvWidth) +"'d0 , " + getOperand() + "} ";

            }     
            else if( op == BitvectorOp::S_EXT )
            {
                unsigned outWidth = static_cast<unsigned> (bvop->param(0));
                unsigned bvWidth = static_cast<unsigned> (bvop->arg(0)->type.bitWidth);

                ILA_ASSERT(outWidth >= bvWidth,"cannot use extend to shrink the width");

                auto operand = getOperand();

                if (outWidth == bvWidth)
                    result_stmt = getOperand();
                else {
                    result_stmt = vlg_stmt_t(" { {") + toStr(outWidth - bvWidth) +"{"+ operand +"["+ toStr(bvWidth)  + "] }  }, " + operand + "} ";
                }
            
            }
            else if  (op == BitvectorOp::EXTRACT) {
                unsigned hi = static_cast<unsigned> (bvop->param(0));
                unsigned lo = static_cast<unsigned> (bvop->param(1));

                result_stmt =  getOperand() + "[" + toStr(hi) +":"+toStr(lo) +"]";
            }

            else if (arity == 2)
            {
                vlg_name_t arg2 = getOperand();
                vlg_name_t arg1 = getOperand();

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
                    result_stmt = vlg_stmt_t(" { ( ") + arg1 + " ) / ( " +  arg2 + " ) } ";
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
                        vlg_stmt_t data_i = vlg_stmt_t(" (  ") + arg1 + " [ " +  arg2 +"+"+ toStr(i) + " ] ) "; 
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
                } else     
                    ILA_ASSERT(false,"Operator not supported.");
            } else if (op == BitvectorOp::IF) {
                vlg_name_t arg3 = getOperand();
                vlg_name_t arg2 = getOperand();
                vlg_name_t arg1 = getOperand();

                result_stmt = vlg_stmt_t(" ( ") + arg1 + " ) ? ( " +  arg2 + " ) : ( " + arg3 + " )";
            } else if ( op == BitvectorOp::APPLY_FUNC) {
                const Node * funcPtr = bvop->arg(0).get();
                const FuncVar * funcvar = NULL;
                ILA_ASSERT( (funcvar = dynamic_cast<const  FuncVar *>(funcPtr)), "Cannot apply a non-funcVar." );

                result_stmt = funcvar->getName() + "(";

                unsigned nargs = funcvar->type.argsWidth.size();
                ILA_ASSERT ( nargs <= iterStack.size() ,"not enough operands to apply func"  );

                // first we put the 1st variable
                vlg_stmt_t arg_stmt = getOperand();

                for (int i = 2; i != arity; i++) {
                    arg_stmt = getOperand() + " , " + arg_stmt;
                }
                result_stmt = result_stmt + arg_stmt + ")";
            } else
                ILA_ASSERT(false,"Operator not supported.");


            vlg_name_t tmp_result     = NewId();
            vlg_stmt_t tmp_stmt        = vlg_stmt_t("assign ") + tmp_result + " = " + result_stmt +" ;";

            add_wire(tmp_result,width);
            add_stmt( tmp_stmt );
            iterStack.push_back(tmp_result);

            

        } else if ((bvchoiceop = dynamic_cast<const BitvectorChoice*>(n))) {

            ILA_ASSERT(false, "Not synthesized yet because bitvector choice type encountered.");

        } else if ((inrangeop = dynamic_cast<const BVInRange*>(n))) {

            ILA_ASSERT(false, "Not synthesized yet because bitvector in range type encountered.");
        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            // return the name , not enough but also need to push mem op to mem stack
            iterStack.push_back(memvar->getName());  
            memopStack.push_back(memStackItem());

        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {

            iterStack.push_back( memconst->getName() );  
            memopStack.push_back(memStackItem(memconst->memvalues));

        } else if ((memop = dynamic_cast<const MemOp*>(n))) {

            ILA_ASSERT(EnoughArgsOnStack(n),"Not enough operands.");
            
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
            // push to 
        iterStack.push_back(result);



        } else if ((mchoiceop = dynamic_cast<const MemChoice*>(n))) {

            ILA_ASSERT(false, "Not synthesized yet because bool choice type encountered.");


        //// Functions ////
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {


            // ILA_ASSERT(EnoughArgsOnStack(n),"Not enough operands.");
            // return name
            iterStack.push_back(funcvar->getName());     
        }
        else
            ILA_ASSERT(false, "Node type not supported for Verilog node visitor.");

    }

    vlg_name_t VerilogExport::NewId()
    {
        return "n" + toStr(idCounter++);
    }

    bool VerilogExport::EnoughArgsOnStack(const Node *n)
    {
        const BoolOp* boolop = NULL;
        const BitvectorOp* bvop = NULL;
        const MemOp*  memop = NULL;
        const FuncVar* funcvar = NULL;
        
        if ((boolop = dynamic_cast<const BoolOp*>(n))) {

            if( boolop->nArgs() > iterStack.size() )
                return false;
            return true;
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {

            if( bvop->nArgs() > iterStack.size() )
                return false;
            return true;

        } else if ((memop = dynamic_cast<const MemOp*>(n))) {

            if( memop->nArgs() > iterStack.size() )
                return false;
            if( memop->nArgs() > memopStack.size() )
                return false;
            return true;

        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            // we shouldn't check it here, but at apply func
            //nargs = funcvar->type.argsWidth.size();
            //if (nargs > iterStack.size() )
            //    return false;
            return true;
        }
        else
            ILA_ASSERT(false, "Node type not supported for stack n-ary check.");

        return true;

    }

    vlg_stmt_t VerilogExport::getOperand()
    {
        vlg_stmt_t tmp = iterStack.back();
        iterStack.pop_back();
        return tmp;
    }

    VerilogExport::VerilogExport (const std::string &modName,const std::string &clk,const std::string &rst)
        : moduleName(modName), clkName(clk), rstName(rst),idCounter(0)
    {

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