#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

#include <ast.hpp>
#include <util.hpp>
#include <exception.hpp>
#include <logging.hpp>
#include <common.hpp>
#include <horn.hpp>

namespace ila
{
    void HornTranslator::initVarInt (hvptr_t v, nptr_t node)
    {
        Node* n = node.get();

        const BoolOp* boolop = NULL;
        const BoolVar* boolvar = NULL;
        const BoolConst* boolconst = NULL;

        const BitvectorOp* bvop = NULL;
        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;

        const MemOp* memop = NULL;
        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;

        const FuncVar* funcvar = NULL;

        const BoolChoice* boolchoice = NULL;
        const BitvectorChoice* bvchoice = NULL;
        const MemChoice* memchoice = NULL;
        const ReadSlice* readslice = NULL;
        const WriteSlice* writeslice = NULL;

        //// Bool ////
        if ((boolop = dynamic_cast <BoolOp*> (n))) {
            initBoolOpInt (boolop, v);
        } else if ((boolvar = dynamic_cast <BoolVar*> (n))) {
            initBoolVarInt (boolvar, v);
        } else if ((boolconst = dynamic_cast <BoolConst*> (n))) {
            initBoolConstInt (boolconst, v);
        //// Bitvector ////
        } else if ((bvop = dynamic_cast <BitvectorOp*> (n))) {
            initBvOpInt (bvop, v);
        } else if ((bvvar = dynamic_cast <BitvectorVar*> (n))) {
            initBvVarInt (bvvar, v);
        } else if ((bvconst = dynamic_cast <BitvectorConst*> (n))) {
            initBvConstInt (bvconst, v);
        //// Memory ////
        } else if ((memop = dynamic_cast <MemOp*> (n))) {
            initMemOpInt (memop, v);
        } else if ((memvar = dynamic_cast <MemVar*> (n))) {
            initMemVarInt (memvar, v);
        } else if ((memconst = dynamic_cast <MemConst*> (n))) {
            initMemConstInt (memconst, v);
        //// Func ////
        } else if ((funcvar = dynamic_cast <FuncVar*> (n))) {
            initFuncVarInt (funcvar, v);
        //// Choice ////
        } else if ((boolchoice = dynamic_cast <BoolChoice*> (n))) {
            ILA_ASSERT (false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast <BitvectorChoice*> (n))) {
            ILA_ASSERT (false, "BitvectorChoice not implemented.");
        } else if ((memchoice = dynamic_cast <MemChoice*> (n))) {
            ILA_ASSERT (false, "MemChoice not imeplemented.");
        } else if ((readslice = dynamic_cast <ReadSlice*> (n))) {
            ILA_ASSERT (false, "ReadSlice not imeplemented.");
        } else if ((writeslice = dynamic_cast <WriteSlice*> (n))) {
            ILA_ASSERT (false, "WriteSlice not imeplemented.");
        } else {
            ILA_ASSERT (false, "Unknown node type.");
        }
    }

    void HornTranslator::initBoolOpInt (const BoolOp* n, hvptr_t v)
    {
        // name
        v->setName ("b" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("Bool");
        // in
        for (unsigned i = 0; i != n->nArgs(); i++) {
            hvptr_t arg_i = getVar (n->arg(i));
            v->mergeInVars (arg_i);
        }
        // out
        v->addOutVar (v);

        // exec
        static std::string boolOpNames[] = {
            "invalid",
            "not",                  // not
            "and", "or", "xor",     // and, or, xor
            "xor", "and", "or",     // xnor, nand, nor
            "=>",                   // imply,
            "<", ">", "<=", ">=",   // signed
            "<", ">", "<=", ">=",   // unsinged
            "=", "=",               // equal, distinct
            "ite"                   // ite
        };

        //// Unary ////
        if (n->op == BoolOp::Op::NOT) {
            // z = !x --> (= z (not x))
            boost::format boolOpNotFmt ("(= %1% (not %2%))");
            hvptr_t arg0 = getVar (n->arg(0));
            boolOpNotFmt % v->getName() % arg0->getName();
            v->setExec (boolOpNotFmt.str());
        //// Binary ////
        } else if (n->op >= BoolOp::Op::AND &&
                   n->op <= BoolOp::Op::DISTINCT) {
            hvptr_t arg0 = getVar (n->arg(0));
            hvptr_t arg1 = getVar (n->arg(1));

            boost::format priFmt ("(= %1% (%2% %3% %4%))");
            boost::format negFmt ("(= %1% (not (%2% %3% %4%)))");

            if ((n->op >= BoolOp::Op::AND   &&
                 n->op <= BoolOp::Op::XOR)  ||
                (n->op >= BoolOp::Op::IMPLY &&
                 n->op <= BoolOp::Op::EQUAL)) {
                // use primitive format (= z (op x y))
                priFmt % v->getName()    
                       % boolOpNames[n->op]
                       % arg0->getName() 
                       % arg1->getName();
                v->setExec (priFmt.str());
            } else if ((n->op >= BoolOp::Op::XNOR && 
                        n->op <= BoolOp::Op::NOR) ||
                        n->op == BoolOp::Op::DISTINCT) {
                // use negated format (= z (not (op x y)))
                negFmt % v->getName()
                       % boolOpNames[n->op]
                       % arg0->getName()
                       % arg1->getName();
                v->setExec (negFmt.str());
            } else {
                ILA_ASSERT (false, "Unknonw Binary BoolOp.");
            }
        //// Ternary ////
        } else if (n->op == BoolOp::Op::IF) {
            // ITE (c, t, e, z) --> (rel.z c t e z)
            // ITE (c, t, e, z) --> (= z (ite c t e))

            if (_iteAsNode) {
                hvptr_t vCond = getVar (n->arg(0));
                hvptr_t vThen = getVar (n->arg(1));
                hvptr_t vElse = getVar (n->arg(2));
                boost::format iteFmt ("(= %1% (%2% %3% %4% %5%))");
                iteFmt % v->getName()
                       % boolOpNames[n->op]
                       % vCond->getName()
                       % vThen->getName()
                       % vElse->getName();
                v->setExec (iteFmt.str());
            } else {
                v->setExec ("true"); 
            }
        } else {
            ILA_ASSERT (false, "Unknown BoolOp.");
        }
    }

    void HornTranslator::initBoolVarInt (const BoolVar* n, hvptr_t v)
    {
        initBoolVar (n, v);
    }

    void HornTranslator::initBoolConstInt (const BoolConst* n, hvptr_t v)
    {
        initBoolConst (n, v);
    }

    void HornTranslator::initBvOpInt (const BitvectorOp* n, hvptr_t v)
    {
        // name
        v->setName ("bv" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("Int");
        // in
        for (unsigned i = 0; i != n->nArgs(); i++) {
            hvptr_t arg_i = getVar (n->arg(i));
            v->mergeInVars (arg_i);
        }
        // out
        v->addOutVar (v);

        // exec
        std::string bvOpNames[] = {
            "invalid",
            // unary
            "bvneg", "bvnot",
            "rotate-left", "rotate-right",
            "concat",
            "sign-extend",
            "extract",
            // binary
            "+", "-", 
            "bvand", "bvor", "bvxor", "bvxnor", "bvnand", "bvnor",
            "/", "/", "rem", "rem", "mod", 
            "bvshl", "bvlshr", "bvashr", "*", "concat", 
            "get-bit",
            "select", "read-block",
            // ternary
            "ite", "apply_fun", 
        };

        //boost::format bvUnaryIntFmt ("(= %1% (%2% %3%))");
        //boost::format bvBinaryIntFmt ("(= %1% (%2% %3% %4%))");
        //boost::format bvUnaryFmt (
                //"(= %1% (bv2int (%2% ((_ int2bv %3%) %4%))))");
        //// Unary ////
        if (n->op >= BitvectorOp::Op::NEGATE && 
            n->op <= BitvectorOp::Op::EXTRACT) {

            hvptr_t arg0 = getVar (n->arg(0));

            if (n->op == BitvectorOp::Op::NEGATE) {
                // (= z (- 0 x))
                boost::format negateFmt ("(= %1% (- 0 %2%))");
                negateFmt % v->getName() % arg0->getName();
                v->setExec (negateFmt.str());
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                // (= z (bv2int (bvnot ((_ int2bv w) x))))
                boost::format cplFmt (
                        "(= %1% (bv2int (bvnot ((_ int2bv %2%) %3%))))");
                cplFmt % v->getName() % n->type.bitWidth % arg0->getName();
                v->setExec (cplFmt.str());
            } else if (n->op == BitvectorOp::Op::LROTATE || 
                       n->op == BitvectorOp::Op::RROTATE) {
                // not supported yet
                ILA_ASSERT (false, "rotate op not supported yet.");
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
                // (= z x)
                boost::format zextFmt ("(= %1% %2%)");
                zextFmt % v->getName() % arg0->getName();
                v->setExec (zextFmt.str());
            } else if (n->op == BitvectorOp::Op::S_EXT) {
                // not supported yet
                ILA_ASSERT (false, "signed extend not supported yet.");
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
                // (= z (bv2int ((_ extract m l) ((_ int2bv w)x))))
                boost::format extractOp (
                   "(= %1% (bv2int ((_ extract %2% %3%) ((_ int2bv %4%) %5))))");
                extractOp % v->getName()
                          % n->param(0)
                          % n->param(1)
                          % n->type.bitWidth
                          % arg0->getName();
                v->setExec (extractOp.str());
            } else {
                ILA_ASSERT (false, "unknown unary BvOp.");
            }
        //// Binary ////
        } else if (n->op >= BitvectorOp::Op::ADD && 
                   n->op <= BitvectorOp::Op::READMEM) {

            hvptr_t arg0 = getVar (n->arg(0));
            hvptr_t arg1 = getVar (n->arg(1));

            if (n->op == BitvectorOp::Op::ADD ||
                n->op == BitvectorOp::Op::SUB ||
               (n->op >= BitvectorOp::Op::SDIV && 
                n->op <= BitvectorOp::Op::SMOD) ||
                n->op == BitvectorOp::Op::MUL ||
                n->op == BitvectorOp::Op::READMEM) {
                // (= z (op x y))
                boost::format binFmt ("(= %1% (%2% %3% %4%))");
                binFmt % v->getName()
                       % bvOpNames[n->op]
                       % arg0->getName()
                       % arg1->getName();
                v->setExec (binFmt.str());
            } else if ((n->op >= BitvectorOp::Op::AND &&
                        n->op <= BitvectorOp::Op::NOR) || 
                       (n->op >= BitvectorOp::Op::SHL &&
                        n->op <= BitvectorOp::Op::ASHR) ||
                        n->op == BitvectorOp::Op::CONCAT) {
                // (= z (bv2int (op ((_ int2bv w) x) ((_ int2bv w) y))))
                boost::format binFmt (
                    "(= %1% (bv2int (%2% ((_ int2bv %3%) %4%) ((_ int2bv %5%) %y%))))");
                binFmt % v->getName()
                       % bvOpNames[n->op]
                       % n->arg(0)->type.bitWidth
                       % arg0->getName()
                       % n->arg(1)->type.bitWidth
                       % arg1->getName();
                v->setExec (binFmt.str());
            } else if (n->op == BitvectorOp::Op::GET_BIT) {
                // (= z (bv2int ((_ extract 0 0) (bvlshr ((_ int2bv w) x) ((_ int2bv w) y)))))
                boost::format getbitFmt (
                        "(= %1% (bv2int ((_ extract 0 0) (bvlshr ((_ int2bv %2%) %3%) ((_ int2bv %4%) %5%)))))");
                getbitFmt % v->getName()
                          % n->arg(0)->type.bitWidth
                          % arg0->getName()
                          % n->arg(1)->type.bitWidth
                          % arg1->getName();
                v->setExec (getbitFmt.str());
            } else {
                ILA_ASSERT (false, "unknown binary BvOp.");
            }
        } else if (n->op == BitvectorOp::Op::READMEMBLOCK) {
            hvptr_t mem  = getVar (n->arg(0));
            hvptr_t addr = getVar (n->arg(1));
            int chunkSize = n->arg(0)->type.dataWidth;
            int chunkNum  = n->param(0);
            bool isLittle = (n->param(1) == LITTLE_E);

            bool detail = true;
            if (!detail) {
                boost::format singleReadFmt ("(= %1% (select %2% %3%))");
                singleReadFmt % v->getName()
                              % mem->getName()
                              % addr->getName();
                v->setExec (singleReadFmt.str());
                return;
            }

            if (isLittle) {
                // (= (bv2int (concat ((_ int2bv w) (select A x))
                //            (concat ((_ int2bv w) (select A (+ x 1)))
                //            (concat ((_ int2bv w) (select A (+ x 2)))
                //                    ((_ int2bv w) (select A (+ x 3)))))))
                //    z)
            }

            // big:
            // (= z (((concat (select A x) 
            //        (concat (select A (+ x w))
            //                (select A (+ x 2w)))))))
            // little:
            // (= z (((concat (select A (+ x 2w) 
            //        (concat (select A (+ x w))
            //                (select A x)))))))

                        
        //// Ternary ////
        } else if (n->op == BitvectorOp::Op::IF) {
            // z = ite (c, t, e) --> (=z (ite c, t, e))
            // z = ite (c, t, e) --> (rel.z c, t, e, z)
            
            if (_iteAsNode) {
                hvptr_t vCond = getVar (n->arg(0));
                hvptr_t vThen = getVar (n->arg(1));
                hvptr_t vElse = getVar (n->arg(2));
                boost::format iteFmt ("(= %1% (%2% %3% %4% %5%))");
                iteFmt % v->getName()
                       % bvOpNames[n->op]
                       % vCond->getName()
                       % vThen->getName()
                       % vElse->getName();
                v->setExec (iteFmt.str());
            } else {
                v->setExec ("true"); 
            }
        } else if (n->op == BitvectorOp::Op::APPLY_FUNC) {
            // z = foo (x, y) --> (foo x y z)
            std::string exec = "(";
            for (unsigned i = 0; i != n->nArgs(); i++) {
                exec += (getVar (n->arg(i))->getName() + " ");
            }
            exec += (v->getName() + ")");
            v->setExec (exec);
        } else {
            ILA_ASSERT (false, "Unknown BitvectorOp.");
        }

    }

    void HornTranslator::initBvVarInt (const BitvectorVar* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initBvConstInt (const BitvectorConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemOpInt (const MemOp* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemVarInt (const MemVar* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initMemConstInt (const MemConst* n, hvptr_t v)
    {
        // TODO
    }

    void HornTranslator::initFuncVarInt (const FuncVar* n, hvptr_t v)
    {
        // TODO
    }
}
