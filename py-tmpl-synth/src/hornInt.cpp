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
        v->setName (_name + "_b" + boost::lexical_cast <std::string> (v->getId()));
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
        v->setName (_name + "_bv" + boost::lexical_cast <std::string> (v->getId()));
        // type
        if (isLongBv (n->type.bitWidth)) {
            v->setType ("(Array Int Int)");
        } else {
            v->setType ("Int");
        }
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

        //// Unary ////
        if (n->op >= BitvectorOp::Op::NEGATE && 
            n->op <= BitvectorOp::Op::EXTRACT) {

            hvptr_t arg0 = getVar (n->arg(0));

            if (n->op == BitvectorOp::Op::NEGATE) {
                // (= z (- 0 x))
                boost::format negateFmt ("(= %1% (- 0 %2%))");
                negateFmt % v->getName() % arg0->getName();
                v->setExec (negateFmt.str());
                // not implement
                ILA_ASSERT (!isLongBv (n->arg(0)->type.bitWidth), 
                            "Long bitvector negate not implemented.");
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                // (= z (bv2int (bvnot ((_ int2bv w) x))))
                boost::format cplFmt (
                        "(= %1% (bv2int (bvnot ((_ int2bv %2%) %3%))))");
                cplFmt % v->getName() % n->type.bitWidth % arg0->getName();
                v->setExec (cplFmt.str());
                // not implement
                ILA_ASSERT (!isLongBv (n->arg(0)->type.bitWidth), 
                            "Long bitvector negate not implemented.");
            } else if (n->op == BitvectorOp::Op::LROTATE || 
                       n->op == BitvectorOp::Op::RROTATE) {
                // not supported yet
                ILA_ASSERT (false, "rotate op not supported yet.");
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
                if (isLongBv (n->type.bitWidth)) {
                    // XXX Wrong implementation.
                    // (= (select z 0) x)
                    info ("Horn-Warning") << "Long bitvector zero extend "
                        << v->getName() << ".\n";
                    boost::format extLongBvFmt ("(= (select %1% 0) %2%)");
                    extLongBvFmt % v->getName() % arg0->getName();
                    v->setExec (extLongBvFmt.str());
                    return;
                }
                // (= z x)
                boost::format zextFmt ("(= %1% %2%)");
                zextFmt % v->getName() % arg0->getName();
                v->setExec (zextFmt.str());
            } else if (n->op == BitvectorOp::Op::S_EXT) {
                // not supported yet
                ILA_ASSERT (false, "signed extend not supported yet.");
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
                if (isLongBv (n->arg(0)->type.bitWidth)) {
                    // XXX Wrong implementation.
                    info ("Horn-Warning") << "Long bitvector extract "
                        << v->getName() << ".\n";

                    ILA_ASSERT (n->type.bitWidth == 8, "Only support byte");
                    ILA_ASSERT (n->param(1) % 8 == 0, "Need to be aligned.");
                    // (= z (select x l/8))
                    boost::format extractLongBv ("(= %1% (select %2% %3%))");
                    extractLongBv % v->getName()
                                  % arg0->getName()
                                  % (n->param(1) / 8);
                    v->setExec (extractLongBv.str());
                    return;
                }
                // (= z (bv2int ((_ extract m l) ((_ int2bv w)x))))
                boost::format extractOp (
                "(= %1% (bv2int ((_ extract %2% %3%) ((_ int2bv %4%) %5%))))");
                extractOp % v->getName()
                          % n->param(0)
                          % n->param(1)
                          % n->arg(0)->type.bitWidth
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

            if (isLongBv (n->type.bitWidth)) {
                // XXX Wrong implementation.
                // (= z x)
                info ("Horn-Warning") << "Long bitvector binary operation "
                    << v->getName() << ".\n";
                boost::format binLongBvFmt ("(= %1% %2%)");
                binLongBvFmt % v->getName() % arg1->getName();
                v->setExec (binLongBvFmt.str());
                return;
            }
                
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
                    "(= %1% (bv2int (%2% ((_ int2bv %3%) %4%) ((_ int2bv %5%) %6%))))");
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
            int dataSize  = n->type.bitWidth;
            bool isLittle = (n->param(1) == LITTLE_E);

            bool detail = true;
            if (!detail || (chunkNum == 1)) {
                boost::format singleReadFmt ("(= %1% (select %2% %3%))");
                singleReadFmt % v->getName()
                              % mem->getName()
                              % addr->getName();
                v->setExec (singleReadFmt.str());
                return;
            }

            ILA_ASSERT (dataSize == (chunkNum * chunkSize), 
                        "Size mismatch in ReadMemBlock.");

            // If dataSize > _bvMaxSize, use Array to represent the variable.
            bool useArr = isLongBv (dataSize);
            if (useArr && isLittle) {
                // (= (select z 0) (select A (+ x 0)))
                // (= (select z 1) (select A (+ x 1)))
                // (= (select z 2) (select A (+ x 2)))
                boost::format partEqFmt (
                "(= (select %1% %2%) (select %3% (+ %4% %5%)))");
                for (int i = 0; i < chunkNum; i++) {
                    partEqFmt % v->getName()
                              % i
                              % mem->getName()
                              % addr->getName()
                              % i;
                    v->setExec (partEqFmt.str());
                }
            } else if (useArr && !isLittle) {
                // (= (select z 0) (select A (+ x 2)))
                // (= (select z 1) (select A (+ x 1)))
                // (= (select z 2) (select A (+ x 0)))
                boost::format partEqFmt (
                "(= (select %1% %2%) (select %3% (+ %4% %5%)))");
                for (int i = 0; i < chunkNum; i++) {
                    partEqFmt % v->getName()
                              % i
                              % mem->getName()
                              % addr->getName()
                              % (chunkNum-1-i);
                    v->setExec (partEqFmt.str());
                }
            } else if (!useArr && isLittle) {
                // FIXME
                // (= (bv2int (concat ((_ int2bv w) (select A x))
                //            (concat ((_ int2bv w) (select A (+ x 1)))
                //            (concat ((_ int2bv w) (select A (+ x 2)))
                //                    ((_ int2bv w) (select A (+ x 3)))))))
                //    z)
                boost::format headFmt (
                "(= (bv2int (concat ((_ int2bv %1%) (select %2% %3%))");
                boost::format bodyFmt (
                "           (concat ((_ int2bv %1%) (select %2% (+ %3% %4%)))");
                boost::format tailFmt (
                "                   ((_ int2bv %1%) (select %2% (+ %3% %4%)))");
                boost::format eqFmt (
                "   %1%)");

                headFmt % chunkSize % mem->getName() % addr->getName();
                v->setExec (headFmt.str());

                for (int i = 1; i < chunkNum-1; i++) {
                    bodyFmt % chunkSize 
                            % mem->getName() 
                            % addr->getName()
                            % i;
                    v->setExec (bodyFmt.str());
                }

                if (chunkNum > 1) {
                    tailFmt % chunkSize
                            % mem->getName()
                            % addr->getName()
                            % (chunkNum-1);
                    std::string tail = tailFmt.str();
                    size_t tailSize = tail.size();
                    tail.resize (tailSize + chunkNum, ')');
                    v->setExec (tail);
                }

                eqFmt % v->getName();
                v->setExec (eqFmt.str());
            } else {
                // FIXME
                // (= (bv2int (concat ((_ int2bv w) (select A (+ x 3)))
                //            (concat ((_ int2bv w) (select A (+ x 2)))
                //            (concat ((_ int2bv w) (select A (+ x 1)))
                //                    ((_ int2bv w) (select A x))))))
                //    z)
                boost::format headFmt (
                "(= (bv2int (concat ((_ int2bv %1%) (select %2% (+ %3% $4$)))");
                boost::format bodyFmt (
                "           (concat ((_ int2bv %1%) (select %2% (+ %3% %4%)))");
                boost::format tailFmt (
                "                   ((_ int2bv %1%) (select %2% %3%))");
                boost::format eqFmt (
                "   %1%)");

                headFmt % chunkSize 
                        % mem->getName() 
                        % addr->getName()
                        % (chunkNum-1);
                v->setExec (headFmt.str());

                for (int i = chunkNum-2; i >= 1; i--) {
                    bodyFmt % chunkSize
                            % mem->getName()
                            % addr->getName()
                            % i;
                    v->setExec (bodyFmt.str());
                }

                tailFmt % chunkSize % mem->getName() % addr->getName();
                std::string tail = tailFmt.str();
                size_t tailSize = tail.size();
                tail.resize (tailSize + chunkNum, ')');
                v->setExec (tail);

                eqFmt % v->getName();
                v->setExec (eqFmt.str());
            }
                        
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
            hvptr_t fun = getVar (n->arg(0));
            log1 ("Horn") << "set nd " << fun->getName() << " " << exec << "\n";
            fun->setNd (exec);
        } else {
            ILA_ASSERT (false, "Unknown BitvectorOp.");
        }

    }

    void HornTranslator::initBvVarInt (const BitvectorVar* n, hvptr_t v)
    {
        // name should be exactly the same as the design.
        v->setName (n->getName());
        // type
        if (isLongBv (n->type.bitWidth)) {
            v->setType ("(Array Int Int)");
        } else {
            v->setType ("Int");
        }
        // exec
        v->setExec ("true");
        // ins
        v->addInVar (v);
        // outs
        v->addOutVar (v);
    }

    void HornTranslator::initBvConstInt (const BitvectorConst* n, hvptr_t v)
    {
        // name is the value.
        boost::format nameFmt ("%1%");
        nameFmt % n->val();
        v->setName (nameFmt.str());
        // type
        if (isLongBv (n->type.bitWidth)) {
            v->setType ("(Array Int Int)");
        } else {
            v->setType ("Int");
        }
        // exec
        v->setExec ("true");
        // ins
        // outs
        v->setConst ();
    }

    void HornTranslator::initMemOpInt (const MemOp* n, hvptr_t v)
    {
        // name
        v->setName (_name + "_mem" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("(Array Int Int)");
        // in
        for (unsigned i = 0; i != n->nArgs(); i++) {
            hvptr_t arg_i = getVar (n->arg(i));
            v->mergeInVars (arg_i);
        }
        // out
        v->addOutVar (v);
        // exec
        ILA_ASSERT (n->nArgs() == 3, "MemOp should have 3 args.");
        hvptr_t arg0 = getVar (n->arg(0));
        hvptr_t arg1 = getVar (n->arg(1));
        hvptr_t arg2 = getVar (n->arg(2));

        if (n->op == MemOp::Op::STORE) {
            // (= z (store mem addr data))
            boost::format storeFmt ("(= %1% (store %2% %3% %4%))");
            storeFmt % v->getName()
                     % arg0->getName()
                     % arg1->getName()
                     % arg2->getName();
            v->setExec (storeFmt.str());
        } else if (n->op == MemOp::Op::ITE) {
            // (= z (ite cond then else))       if ite as node
            // (rel.z A B C Z)                  if ite as clause

            if (_iteAsNode) {
                boost::format iteFmt ("(= %1% (ite %2% %3% %4%))");
                iteFmt % v->getName()
                       % arg0->getName()
                       % arg1->getName()
                       % arg2->getName();
                v->setExec (iteFmt.str());
            } else {
                v->setExec ("true");
            }
        } else if (n->op == MemOp::Op::STOREBLOCK) {
            bool isLittle = (n->endian == LITTLE_E);
            int chunkSize = n->arg(0)->type.dataWidth;
            int dataSize  = n->arg(2)->type.bitWidth;
            int chunkNum  = dataSize / chunkSize;

            bool detail = true;
            if (!detail || (chunkNum == 1)) {
                boost::format singleWriteFmt ("(= %1% (store %2% %3%))");
                singleWriteFmt % v->getName()
                               % arg0->getName()
                               % arg1->getName();
                v->setExec (singleWriteFmt.str());
                return;
            }

            for (int i = 0; i < chunkNum; i++) {
                copyVar (v, i);
            }

            // If dataSize > _bvMaxSize, use Array to represent long bitvector.
            bool useArr = isLongBv (dataSize);
            boost::format arrStoreFmt (
                "(= %1% (store %2% (+ %3% %4%) (select %5% %6%)))");
            boost::format arrEqFmt (
                "(= %1% %2%)");
            if (useArr && isLittle) {
                // (= z_2 (store A   (+ addr 2) (select val 2)))
                // (= z_1 (store z_2 (+ addr 1) (select val 1)))
                // (= z_0 (store z_1 (+ addr 0) (select val 0)))
                // (= z z_0)
                arrStoreFmt % addSuffix (v->getName(), chunkNum-1)
                            % arg0->getName()
                            % arg1->getName()
                            % (chunkNum-1)
                            % arg2->getName()
                            % (chunkNum-1);
                v->setExec (arrStoreFmt.str());
                
                for (int i = chunkNum-2; i >= 0; i--) {
                    arrStoreFmt % addSuffix (v->getName(), i)
                                % addSuffix (v->getName(), i+1)
                                % arg1->getName()
                                % i
                                % arg2->getName()
                                % i;
                    v->setExec (arrStoreFmt.str());
                }

                arrEqFmt % v->getName() % addSuffix (v->getName(), 0);
                v->setExec (arrEqFmt.str());
                return;
            } 

            if (useArr && !isLittle) {
                // (= z_2 (store A   (+ addr 0) (select val 2)))
                // (= z_1 (store z_2 (+ addr 1) (select val 1)))
                // (= z_0 (store z_1 (+ addr 2) (select val 0)))
                // (= z z_0)
                arrStoreFmt % addSuffix (v->getName(), chunkNum-1)
                            % arg0->getName()
                            % arg1->getName()
                            % 0
                            % arg2->getName()
                            % (chunkNum-1);
                v->setExec (arrStoreFmt.str());

                for (int i = chunkNum-2; i >= 0; i--) {
                    arrStoreFmt % addSuffix (v->getName(), i)
                                % addSuffix (v->getName(), i+1)
                                % arg1->getName()
                                % (chunkNum-1-i)
                                % arg2->getName()
                                % i;
                    v->setExec (arrStoreFmt.str());
                }

                arrEqFmt % v->getName() % addSuffix (v->getName(), 0);
                v->setExec (arrEqFmt.str());
                return;
            }

            boost::format memBlkAddFmt (
                "(= %1% (store %2% (+ %3% %4%) (bv2int ((_ extract %5% %6%) ((_ int2bv %7%) %8%)))))");
            boost::format memBlkOrgFmt (
                "(= %1% (store %2% %3% (bv2int ((_ extract %4% %5%) ((_ int2bv %6%) %7%)))))");

            if (isLittle) {
                // FIXME
// (= z_2 (store A      addr    (bv2int ((_ extract 7 0)   ((_ int2bv w) val)))))
// (= z_1 (store z_2 (+ addr 1) (bv2int ((_ extract 15 8)  ((_ int2bv w) val)))))
// (= z   (store z_1 (+ addr 2) (bv2int ((_ extract 23 16) ((_ int2bv w) val)))))
                memBlkOrgFmt % addSuffix (v->getName(), chunkNum-1)
                             % arg0->getName()
                             % arg1->getName()
                             % (chunkSize - 1)
                             % 0
                             % dataSize
                             % arg2->getName();
                v->setExec (memBlkOrgFmt.str());

                for (int i = 1; i < chunkNum-1; i++) {
                    memBlkAddFmt % addSuffix (v->getName(), i)
                                 % addSuffix (v->getName(), i+1)
                                 % arg1->getName()
                                 % (chunkNum-1-i)
                                 % (chunkSize * (chunkNum-i) - 1)
                                 % (chunkSize * (chunkNum-i-1))
                                 % dataSize
                                 % arg2->getName();
                    v->setExec (memBlkAddFmt.str());
                }

                memBlkAddFmt % v->getName()
                             % addSuffix (v->getName(), 1)
                             % arg1->getName()
                             % (chunkNum-1)
                             % (chunkSize * chunkNum - 1)
                             % (chunkSize * (chunkNum-1))
                             % dataSize
                             % arg2->getName();
                v->setExec (memBlkAddFmt.str());
            } else {
                // FIXME
// (= z_2 (store A   (+ addr 2) (bv2int ((_ extract 7 0)   ((_ int2bv w) val)))))
// (= z_1 (store z_2 (+ addr 1) (bv2int ((_ extract 15 8)  ((_ int2bv w) val)))))
// (= z   (store z_1    addr    (bv2int ((_ extract 23 16) ((_ int2bv w) val)))))
                memBlkAddFmt % addSuffix (v->getName(), chunkNum-1)
                             % arg0->getName()
                             % arg1->getName()
                             % (chunkNum - 1)
                             % (chunkSize - 1)
                             % 0
                             % dataSize
                             % arg2->getName();
                v->setExec (memBlkAddFmt.str());

                for (int i = 1; i < chunkNum-1; i++) {
                    memBlkAddFmt % addSuffix (v->getName(), i)
                                 % addSuffix (v->getName(), i+1)
                                 % arg1->getName()
                                 % i
                                 % (chunkSize * (chunkNum-i) - 1)
                                 % (chunkSize * (chunkNum-i-1))
                                 % dataSize
                                 % arg2->getName();
                    v->setExec (memBlkAddFmt.str());
                }

                memBlkOrgFmt % v->getName()
                             % addSuffix (v->getName(), 1)
                             % arg1->getName()
                             % (chunkSize * chunkNum - 1)
                             % (chunkSize * (chunkNum-1))
                             % dataSize
                             % arg2->getName();
                v->setExec (memBlkOrgFmt.str());
            }
        } else {
            ILA_ASSERT (false, "Unknown MemOp.");
        }
    }

    void HornTranslator::initMemVarInt (const MemVar* n, hvptr_t v)
    {
        // name should be the same as the design.
        v->setName (n->getName());
        // type
        v->setType ("(Array Int Int)");
        // exec 
        v->setExec ("true");
        // in
        v->addInVar (v);
        // out
        v->addOutVar (v);
    }

    void HornTranslator::initMemConstInt (const MemConst* n, hvptr_t v)
    {
        // name is the value?
        v->setName (_name + "_mem" + boost::lexical_cast <std::string> (v->getId()));
        // type
        v->setType ("(Array Int Int)");
        // exec
        v->setExec (v->getPred());
        genMemConstRules (n, v);
        _db->addRel (v);
        // in
        // out
        v->addOutVar (v);
        v->setConst();
    }

    void HornTranslator::initFuncVarInt (const FuncVar* n, hvptr_t v)
    {
        // FuncVar is actaully a relation.
        // name should be the same as the design.
        v->setName (n->getName());
        // type (arg_i_type ret_type)
        std::string type = "(";
        for (unsigned i = 0; i != n->type.argsWidth.size(); i++) {
            if (isLongBv (n->type.argsWidth[i])) {
                type += "(Array Int Int) ";
            } else {
                type += "Int ";
            }
        }
        if (isLongBv (n->type.bitWidth)) {
            type += "(Array Int Int))";
        } else {
            type += "Int)";
        }
        v->setType (type);
        // exec 
        v->setExec ("true");
        _db->addRel (v);
        addClause (v);
        
        // in
        // out
    }

    bool HornTranslator::isLongBv (const int& w) const
    {
        return w > _bvMaxSize;
    }
}
