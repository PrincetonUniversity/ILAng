#include <abstraction.hpp>
#include <imexport.hpp>
#include <util.hpp>

namespace ila
{
    ImExport::ImExport(FuncReduction *funcRedPtr, int reduce):FuncReductor(funcRedPtr),reduceWhenImport(reduce)
    {
    }

    ImExport::~ImExport()
    {
    }

    // -----------------------------------------------------------------------//
    void ImExport::exportAst(std::ostream& out, const Node* n)
    {
        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemOp* memop = NULL;

        const BitvectorChoice* bvchoice = NULL;
        const BoolChoice* boolchoice = NULL;
        const MemChoice* memchoice = NULL;
        const WriteSlice* writeslice = NULL;
        const ReadSlice* readslice = NULL;

        const FuncVar* funcvar = NULL;

        //// bools ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            out << "( boolVar " << boolvar->getName() << " )";
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            out << "( boolConst " << boolconst->getName() << " "
                << (boolconst->val() ? "true )" : "flase )");
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            out << "( boolOp " << boolop->getName() << " "
                << BoolOp::operatorNames[(int)boolop->getOp()];
            for (unsigned i = 0; i != boolop->nArgs(); i++) {
                out << " ";
                exportAst(out, boolop->arg(i).get());
            }
            out << " )";
        //// bitvector ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            out << "( bvVar " << bvvar->getName()
                << " " << bvvar->type.bitWidth << " )";
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            out << "( bvConst " << bvconst->getName()
                << " " << bvconst->type.bitWidth 
                << " " << bvconst->vstr() << " )";
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            out << "( bvOp " << bvop->getName() //<< " " << type.bitWidth
                << " " << BitvectorOp::operatorNames[(int)bvop->getOp()];
            for (unsigned i = 0; i != bvop->nArgs(); i++) {
                out << " ";
                exportAst(out, bvop->arg(i).get());
            }
            for (unsigned i = 0; i != bvop->nParams(); i++) {
                out << " #" << bvop->param(i);
            }
            out << " )";
        //// memories ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            out << "( memVar " << memvar->getName() << " " << memvar->type.addrWidth
                << " " << memvar->type.dataWidth << " )";
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            out << "( memConst " << memconst->getName()
                << " " << memconst->type.addrWidth 
                << " " << memconst->type.dataWidth << " ";
            exportMemValues(out, memconst->memvalues);
            out << " )";
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            out << "( memOp " << memop->getName();
            out << " " << memop->operatorNames[memop->op] << " ";
            out << "#" << (int) memop->endian << " ";
            //<< type.addrWidth << " " << type.dataWidth << " ";
            for (unsigned i = 0; i != memop->nArgs(); i++) {
                out << " ";
                exportAst(out, memop->arg(i).get());
            }
            out << " )";
        //// functions ////
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            out << "( funcVar " << funcvar->getName() << " "
                << funcvar->type.bitWidth << " <- (";
            for (unsigned i = 0; i != funcvar->type.argsWidth.size(); i++) {
                out << ((i == 0) ? " " : ", ") << funcvar->type.argsWidth[i];
            }
            out << " ) )";
        //// Choice ////
        } else if ((boolchoice = dynamic_cast<const BoolChoice*>(n))) {
            ILA_ASSERT(false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast<const BitvectorChoice*>(n))) {
            ILA_ASSERT(false, "BitvectorChoice not implemented." + bvchoice->getName());
        } else if ((memchoice = dynamic_cast<const MemChoice*>(n))) {
            ILA_ASSERT(false, "MemChoice not implemented.");
        } else if ((writeslice = dynamic_cast<const WriteSlice*>(n))) {
            ILA_ASSERT(false, "WriteSlice not implemented.");
        } else if ((readslice = dynamic_cast<const ReadSlice*>(n))) {
            ILA_ASSERT(false, "ReadSlice not implemented.");
        } else {
            out << "( )";
        }

        return;
    }

    // -----------------------------------------------------------------------//
    nptr_t ImExport::importAst(Abstraction* c, std::istream& in)
    {
        ILA_ASSERT(next(in) == "(", "Miss (");
        std::string nodeType = next(in);
        if (nodeType == ")") return NULL;
        std::string name = next(in);

        if (nodeType == "boolVar") {
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new BoolVar(name));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "boolConst") {
            std::string value = next(in);
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(BoolConst::get(value == "true"));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "boolOp") {
            std::string opname = next(in);
            BoolOp::Op op = getBoolOpType(opname);
            nptr_t nptr = mapFind(name);

            if (op == BoolOp::Op::NOT) {
                nptr_t arg0 = importAst(c, in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BoolOp(op, arg0));
                }
            } else if (op >= BoolOp::Op::AND && 
                       op <= BoolOp::Op::DISTINCT) {
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BoolOp(op, arg0, arg1));
                }
            } else if (op == BoolOp::Op::IF) {
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                nptr_t arg2 = importAst(c, in);
                if (nptr == NULL) {
                    nptr_vec_t args_;
                    args_.push_back(arg0);
                    args_.push_back(arg1);
                    args_.push_back(arg2);
                    nptr = nptr_t(new BoolOp(op, args_));
                }
            } else {
                ILA_ASSERT(false, "Unknown bool op type " + opname);
                nptr = NULL;
            }

            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            if(reduceWhenImport==1) FuncReductor->InsertOrDupNoRecursive(nptr);
            return nptr;
        } else if (nodeType == "bvVar") {
            std::string wstr = next(in);
            int width = atoi(wstr.c_str());
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new BitvectorVar(name, width));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "bvConst") {
            std::string wstr = next(in);
            std::string vstr = next(in);
            int width = atoi(wstr.c_str());
            int value = atoi(vstr.c_str());
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new BitvectorConst(value, width));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "bvOp") {
            //std::string wstr = next(in);
            //int width = atoi(wstr.c_str());
            std::string opname = next(in);
            BitvectorOp::Op op = getBvOpType(opname);
            nptr_t nptr = mapFind(name);

            if (op >= BitvectorOp::Op::NEGATE &&
                op <= BitvectorOp::Op::COMPLEMENT) {
                nptr_t arg0 = importAst(c, in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(op, arg0));
                }
            } else if (op >= BitvectorOp::Op::LROTATE &&
                       op <= BitvectorOp::Op::S_EXT) {
                nptr_t arg0 = importAst(c, in);
                int par0 = eatIdx(in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(op, arg0, par0));
                }
            } else if (op == BitvectorOp::Op::EXTRACT) {
                nptr_t arg0 = importAst(c, in);
                int par0 = eatIdx(in);
                int par1 = eatIdx(in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(op, arg0, par0, par1));
                }
            } else if (op >= BitvectorOp::Op::ADD &&
                       op <= BitvectorOp::Op::READMEM) { 
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(op, arg0, arg1));
                }
            } else if (op == BitvectorOp::Op::READMEMBLOCK) {
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                int chunks = eatIdx(in);
                endianness_t e = (endianness_t) eatIdx(in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(op, arg0, arg1, chunks, e));
                }
            } else if (op == BitvectorOp::Op::IF) {
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                nptr_t arg2 = importAst(c, in);
                if (nptr == NULL) {
                    nptr_vec_t args_;
                    args_.push_back(arg0);
                    args_.push_back(arg1);
                    args_.push_back(arg2);
                    nptr = nptr_t(new BitvectorOp(op, args_));
                }
            } else if (op == BitvectorOp::Op::APPLY_FUNC) {
                nptr_t fun = importAst(c, in);
                nptr_vec_t args_;
                args_.push_back(fun);
                for (unsigned i = 0; i != fun->type.argsWidth.size(); i++) {
                    nptr_t arg = importAst(c, in);
                    args_.push_back(arg);
                }
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(op, args_));
                }
            } else {
                ILA_ASSERT(false, "Unknown bv type " + opname);
                nptr = NULL;
            }
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            if(reduceWhenImport==1) FuncReductor->InsertOrDupNoRecursive(nptr);
            return nptr;
        } else if (nodeType == "memVar") {
            std::string awstr = next(in);
            std::string dwstr = next(in);
            int addrW = atoi(awstr.c_str());
            int dataW = atoi(dwstr.c_str());
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new MemVar(name, addrW, dataW));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "memConst") {
            std::string awstr = next(in);
            std::string dwstr = next(in);
            int addrW = atoi(awstr.c_str());
            int dataW = atoi(dwstr.c_str());
            MemValues mem = importMemValue(in, addrW, dataW);
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new MemConst(mem));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "memOp") {
            std::string opname = next(in);
            MemOp::Op op = getMemOpType(opname);
            endianness_t e = (endianness_t)(eatIdx(in));
            nptr_t a0  = importAst(c, in);
            nptr_t a1 = importAst(c, in);
            nptr_t a2 = importAst(c, in);
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                if (e == UNKNOWN_E) {
                    nptr = nptr_t(new MemOp(op, a0, a1, a2));
                } else {
                    nptr = nptr_t(new MemOp(op, a0, a1, a2, e));
                }
                mapInsert(name, nptr);
            }
            
            if(reduceWhenImport==1) FuncReductor->InsertOrDupNoRecursive(nptr);
            return nptr;
        } else if (nodeType == "funcVar") {
            std::string resWidthStr = next(in);
            int resW = atoi(resWidthStr.c_str());
            std::vector<int> argsW;
            ILA_ASSERT(next(in) == "<-", "Miss <-");
            ILA_ASSERT(nextChar(in) == '(', "Miss (");
            std::string buf = next(in);
            while (buf != ")") {
                int w = atoi(buf.c_str());
                argsW.push_back(w);
                buf = next(in);
            }
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new FuncVar(name, resW, argsW));
                mapInsert(name, nptr);
            }
            return nptr;
        } else {
            ILA_ASSERT(false, "Unrecognizable node type.");
        }

        return NULL;
    }

    // -----------------------------------------------------------------------//
    char ImExport::nextChar(std::istream& in) const
    {
        char buf = '\0'; // init.
        while (!in.eof()) {
            buf = in.get();
            if (buf != ' ' && buf != '\n') return buf;
        }
        return buf;
    }

    std::string ImExport::next(std::istream& in) const
    {
        std::string buf;
        in >> buf;
        return buf;
    }

    int ImExport::eatIdx(std::istream& in) const
    {
        ILA_ASSERT(nextChar(in) == '#', "Bad parameter format.");
        std::string buf = next(in);
        return atoi(buf.c_str());
    }

    nptr_t ImExport::mapFind(const std::string& name) const
    {
        const nref_map_t::const_iterator it = _nodeMap.find(name);
        if (it == _nodeMap.end()) {
            return NULL;
        } else {
            return it->second;
        }
    }

    void ImExport::mapInsert(const std::string& name, nptr_t nptr)
    {
        _nodeMap.insert(std::pair<std::string, nptr_t>(name, nptr));
    }

    void ImExport::addMapVars(Abstraction* c)
    {
        for (auto&& it : _nodeMap) {
            c->addVar(it.second);
        }
    }

    MemOp::Op ImExport::getMemOpType(const std::string& opName) const
    {
        for (int op =  (int) MemOp::INVALID; 
                 op <= (int) MemOp::ITE;
                 op++)
        {
            if (opName == MemOp::operatorNames[op]) {
                return static_cast<MemOp::Op>(op);
            }
        }
        return MemOp::INVALID;
    }

    BitvectorOp::Op ImExport::getBvOpType(const std::string& opName) const
    {
        // FIXME any better way?
        for (int op = BitvectorOp::Op::INVALID; 
                op <= BitvectorOp::Op::APPLY_FUNC; op++) {
            if (opName == BitvectorOp::operatorNames[op]) {
                return static_cast<BitvectorOp::Op>(op);
            }
        }
        return BitvectorOp::Op::INVALID;
    }

    BoolOp::Op ImExport::getBoolOpType(const std::string& opName) const
    {
        for (int op = BoolOp::Op::INVALID;
                op <= BoolOp::Op::IF; op++) {
            if (opName == BoolOp::operatorNames[op]) {
                return static_cast<BoolOp::Op>(op);
            }
        }
        return BoolOp::Op::INVALID;
    }

    void ImExport::exportMemValues(std::ostream& out, const MemValues& val)
    {
        out << "[ ";
        for (auto p : val.values) {
            out << " " << std::hex << "0x" << p.first 
                << " : " << "0x" << p.second;
        }

        out << " default : 0x" << std::hex << val.def_value << std::dec << " ]";
    }

    MemValues ImExport::importMemValue(std::istream& in, int aw, int dw) 
    {
        MemValues::map_t values;
        mp_int_t def_val = 0x00;

        ILA_ASSERT(nextChar(in) == '[', "Miss [ for MemValues.");
        std::string addrStr;
        std::string hexValStr;

        while ((addrStr = next(in)) != "default") {
            ILA_ASSERT(nextChar(in) == ':', "Miss : for MemValues.");
            hexValStr = next(in);
            mp_int_t addr(addrStr);
            mp_int_t hexVal(hexValStr);
            values[addr] = hexVal;
        }

        ILA_ASSERT(nextChar(in) == ':', "Miss : for MemValues default.");
        hexValStr = next(in);
        ILA_ASSERT(nextChar(in) == ']', "Miss ] for MemValues.");

        def_val = mp_int_t(hexValStr);
        MemValues mv(aw, dw, values, def_val);
        
        return mv;
    }
    
}
