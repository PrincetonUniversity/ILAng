#include <imexport.hpp>
#include <util.hpp>

namespace ila
{
    ImExport::ImExport()
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
        const MemWr* memwr = NULL;

        //// bools ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            out << "( boolVar " << boolvar->name << " )";
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            out << "( boolConst " << boolconst->name << " " 
                << (boolconst->val() ? "true )" : "flase )");
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            out << "( boolOp " << boolop->name << " " 
                << BoolOp::operatorNames[(int)boolop->getOp()];
            for (unsigned i = 0; i != boolop->nArgs(); i++) {
                out << " ";
                exportAst(out, boolop->arg(i).get());
            }
            out << " )";
        //// bitvector ////
        } else if((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            out << "( bvVar " << bvvar->name 
                << " " << bvvar->type.bitWidth << " )";
        } else if((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            out << "( bvConst " << bvconst->name 
                << " " << bvconst->type.bitWidth 
                << " " << bvconst->vstr() << " )";
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            out << "( bvOp " << bvop->name //<< " " << type.bitWidth 
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
            out << "( memVar " << memvar->name << " " << memvar->type.addrWidth
                << " " << memvar->type.dataWidth << " )";
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            out << "( memConst " << memconst->name 
                << " " << memconst->type.addrWidth 
                << " " << memconst->type.dataWidth << " ";
            exportMemValues(out, memconst->memvalues);
            out << " )";
        } else if ((memwr = dynamic_cast<const MemWr*>(n))) {
            out << "( memWr " << memwr->name;
            //<< type.addrWidth << " " << type.dataWidth << " ";
            for (unsigned i = 0; i != memwr->nArgs(); i++) {
                out << " ";
                exportAst(out, memwr->arg(i).get());
            }
            out << ")";
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
                nptr = nptr_t(new BoolVar(c, name));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "boolConst") {
            std::string value = next(in);
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new BoolConst(c, value == "true"));
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
                    nptr = nptr_t(new BoolOp(c, op, arg0));
                }
            } else if (op >= BoolOp::Op::AND && 
                       op <= BoolOp::Op::DISTINCT) {
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BoolOp(c, op, arg0, arg1));
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
                    nptr = nptr_t(new BoolOp(c, op, args_));
                }
            } else {
                ILA_ASSERT(false, "Unknown bool op type " + opname);
                nptr = NULL;
            }

            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            return nptr;
        } else if (nodeType == "bvVar") {
            std::string wstr = next(in);
            int width = atoi(wstr.c_str());
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new BitvectorVar(c, name, width));
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
                nptr = nptr_t(new BitvectorConst(c, value, width));
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
                    nptr = nptr_t(new BitvectorOp(c, op, arg0));
                }
            } else if (op >= BitvectorOp::Op::LROTATE &&
                       op <= BitvectorOp::Op::S_EXT) {
                nptr_t arg0 = importAst(c, in);
                int par0 = eatIdx(in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(c, op, arg0, par0));
                }
            } else if (op == BitvectorOp::Op::EXTRACT) {
                nptr_t arg0 = importAst(c, in);
                int par0 = eatIdx(in);
                int par1 = eatIdx(in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(c, op, arg0, par0, par1));
                }
            } else if (op >= BitvectorOp::Op::ADD &&
                       op <= BitvectorOp::Op::READMEM) { 
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                if (nptr == NULL) {
                    nptr = nptr_t(new BitvectorOp(c, op, arg0, arg1));
                }
            } else if (op >= BitvectorOp::Op::IF) {
                nptr_t arg0 = importAst(c, in);
                nptr_t arg1 = importAst(c, in);
                nptr_t arg2 = importAst(c, in);
                if (nptr == NULL) {
                    nptr_vec_t args_;
                    args_.push_back(arg0);
                    args_.push_back(arg1);
                    args_.push_back(arg2);
                    nptr = nptr_t(new BitvectorOp(c, op, args_));
                }
            } else {
                ILA_ASSERT(false, "Unknown bv type " + opname);
                nptr = NULL;
            }

            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            return nptr;
        } else if (nodeType == "memVar") {
            std::string awstr = next(in);
            std::string dwstr = next(in);
            int addrW = atoi(awstr.c_str());
            int dataW = atoi(dwstr.c_str());
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new MemVar(c, name, addrW, dataW));
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
                nptr = nptr_t(new MemConst(c, mem));
                mapInsert(name, nptr);
            }
            return nptr;
        } else if (nodeType == "memWr") {
            nptr_t mem  = importAst(c, in);
            nptr_t addr = importAst(c, in);
            nptr_t data = importAst(c, in);
            ILA_ASSERT(nextChar(in) == ')', "Miss )");
            nptr_t nptr = mapFind(name);
            if (nptr == NULL) {
                nptr = nptr_t(new MemWr(mem, addr, data));
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
        char buf;
        while (!in.eof()) {
            buf = in.get();
            if (buf != ' ') return buf;
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

    BitvectorOp::Op ImExport::getBvOpType(const std::string& opName) const
    {
        // FIXME any better way?
        for (int op = BitvectorOp::Op::INVALID; 
                op <= BitvectorOp::Op::IF; op++) {
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
