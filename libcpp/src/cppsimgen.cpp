#include <cppsimgen.hpp>
#include <boost/lexical_cast.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int CppVar::varCnt = 0;

    // ---------------------------------------------------------------------- //
    CppVar::CppVar(const std::string& type, const std::string& name)
        : _type(type)
        , _name(name)
    {
    }

    CppVar::CppVar(const std::string& type)
        : _type(type)
    {
        _name = "cppVar_" + boost::lexical_cast<std::string>(varCnt++);
    }

    CppVar::~CppVar()
    {
    }

    // ---------------------------------------------------------------------- //
    std::string CppVar::def() const
    {
        return (_type + " " + _name);
    }

    std::string CppVar::use() const
    {
        return (_name);
    }

    // ---------------------------------------------------------------------- //
    int CppFun::funCnt = 0;

    // ---------------------------------------------------------------------- //
    CppFun::CppFun(const std::string& type, const std::string& name) 
        : _type(type)
        , _name(name)
    {
    }

    CppFun::CppFun(const std::string& type)
        : _type(type)
    {
        _name = "cppFun_" + boost::lexical_cast<std::string>(funCnt++);
    }

    CppFun::~CppFun()
    {
    }

    // ---------------------------------------------------------------------- //
    void CppFun::addArg(const CppVar* arg)
    {
        _args.push_back(arg);
    }

    void CppFun::addBody(const std::string& code)
    {
        _codeList.push_back(code);
    }
        
    // ---------------------------------------------------------------------- //
    void CppFun::dumpDef(std::ostream& out) const
    {
        // TODO
    }

    void CppFun::dumpCode(std::ostream& out) const
    {
        for (unsigned i = 0; i != _codeList.size(); i++) {
            out << "\t\t" << _codeList[i] << "\n";
        }
    }

    // ---------------------------------------------------------------------- //
    CppSimGen::CppSimGen(const std::string& prefix)
        : _prefix(prefix)
    {
    }

    CppSimGen::~CppSimGen()
    {
    }

    // ---------------------------------------------------------------------- //
    const CppVar* CppSimGen::addInput(const std::string& type,
                                      const std::string& name)
    {
        CppVar* ip = new CppVar(type, name);
        checkAndInsert(_inputs, name, ip);
        checkAndInsert(_varMap, name, ip);
        return ip;
    }

    const CppVar* CppSimGen::addState(const std::string& type,
                                      const std::string& name)
    {
        CppVar* var = new CppVar(type, name);
        checkAndInsert(_states, name, var);
        checkAndInsert(_varMap, name, var);
        return var;
    }

    const CppFun* CppSimGen::addFun(const std::string& type,
                                    const std::string& name)
    {
        // Create new fun and put it in funMap.
        CppFun* fun = new CppFun(type, name);
        checkAndInsert(_funMap, name, fun);
        // Insert inputs and global state into the function's varmap
        // Also set the input as fun's arguments.
        CppVarMap* varMap = new CppVarMap;
        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second);
            fun->addArg(it->second);
        }
        for (auto it = _states.begin(); it != _inputs.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second);
        }
        _varInFun[fun] = varMap;
        return fun;
    }

    void CppSimGen::operator() (const Node* n)
    {
        CppVarMap::iterator it = _curVarMap->find(n->name);
        if (it != _curVarMap->end()) {
            return;
        }

        const BoolVar* boolvar = NULL; 
        const BoolConst* boolconst = NULL;
        const BoolOp* boolop = NULL;

        const BitvectorVar* bvvar = NULL;
        const BitvectorConst* bvconst = NULL;
        const BitvectorOp* bvop = NULL;

        const MemVar* memvar = NULL;
        const MemConst* memconst = NULL;
        const MemWr*  memwr = NULL;

        CppVar* res = NULL;

        //// Bool ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            res = getBoolVarCpp(boolvar);
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            res = getBoolConstCpp(boolconst);
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            res = getBoolOpCpp(boolop);
        //// Bitvector ////
        } else if ((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            res = getBvVarCpp(bvvar);
        } else if ((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            res = getBvConstCpp(bvconst);
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            res = getBvOpCpp(bvop);
        //// Mem ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            res = getMemVarCpp(memvar);
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            res = getMemConstCpp(memconst);
        } else if ((memwr = dynamic_cast<const MemWr*>(n))) {
            res = getMemWrCpp(memwr);
        } else {
            ILA_ASSERT(false, "Unknown node type.");
        }

        checkAndInsert(*_curVarMap, n->name, res);
    }

    // Build function body with ast node.
    void CppSimGen::buildFun(CppFun* f, nptr_t nptr)
    {
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        _curVarMap = it->second;
        _curFun = f;
        nptr->depthFirstVisit(*this);
    }

    // Export all code to the output stream.
    void CppSimGen::exportAll(std::ostream& out) const
    {
        // TODO
        // Better option: declare const outside update functions.
    }

    // ---------------------------------------------------------------------- //
    CppVar* CppSimGen::getBoolVarCpp(const BoolVar* n)
    {
        // FIXME This should not happen?
        CppVar* var = new CppVar("bool", n->name);
        std::string code = var->def();
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getBoolConstCpp(const BoolConst* n)
    {
        CppVar* var = new CppVar("bool", n->name);
        std::string code;
        if (n->val()) {
            code = var->def() + " = true;";
        } else {
            code = var->def() + " = false;";
        }
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getBoolOpCpp(const BoolOp* n)
    {
        CppVar* var = new CppVar("bool", n->name);
        std::string code;
        //// Unary ////
        if (n->op == BoolOp::Op::NOT) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            code = var->def() + " = !" + arg0->use() + ";";
            _curFun->addBody(code);
        //// Binary ////
        } else if (n->op >= BoolOp::Op::AND &&
                   n->op <= BoolOp::Op::DISTINCT) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            if (n->op == BoolOp::Op::AND) {
                code = var->def() + " = " + 
                       arg0->use() + " && " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::OR) {
                code = var->def() + " = " + 
                       arg0->use() + " || " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::XOR) {
                code = var->def() + " = " + 
                       arg0->use() + " ^ " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::XNOR) {
                code = var->def() + " = !( " + 
                       arg0->use() + " ^ " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::NAND) {
                code = var->def() + " = !(" + 
                       arg0->use() + " && " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::NOR) {
                code = var->def() + " = !(" + 
                       arg0->use() + " || " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::IMPLY) {
                code = var->def() + " = !" + 
                       arg0->use() + " || " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::SLT) {
                code = var->def() + " = " + 
                       arg0->use() + " < " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::SGT) {
                code = var->def() + " = " + 
                       arg0->use() + " > " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::SLE) {
                code = var->def() + " = " + 
                       arg0->use() + " <= " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::SGE) {
                code = var->def() + " = " + 
                       arg0->use() + " >= " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::ULT) {
                code = var->def() + " = (unsigned)" + 
                       arg0->use() + " < (unsigned)" + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::UGT) {
                code = var->def() + " = (unsigned)" + 
                       arg0->use() + " > (unsigned)" + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::ULE) {
                code = var->def() + " = (unsigned)" + 
                       arg0->use() + " <= (unsigned)" + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::UGE) {
                code = var->def() + " = (unsigned)" + 
                       arg0->use() + " >= (unsigned)" + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::EQUAL) {
                code = var->def() + " = (" + 
                       arg0->use() + " == " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::DISTINCT) {
                code = var->def() + " = (" + 
                       arg0->use() + " != " + arg1->use() + ");";
            }
            _curFun->addBody(code);
        //// Ternary ////
        } else if (n->op == BoolOp::Op::IF) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->name);
            code = var->def() + " = (" + arg0->use() + ") ? (" + 
                   arg1->use() + ") : (" + arg2->use() + ");";
            _curFun->addBody(code);
        } else {
            ILA_ASSERT(false, "Unknown bool op.");
        }
        return var;
    }

    CppVar* CppSimGen::getBvVarCpp(const BitvectorVar* n)
    {
        // FIXME This should not happen?
        // More types for longer bitwidth.
        CppVar* var = NULL;
        if (n->type.bitWidth <= (int)sizeof(int)) {
            var = new CppVar("int", n->name);
        } else {
            var = new CppVar("long", n->name);
        }
        std::string code = var->def() + ";";
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getBvConstCpp(const BitvectorConst* n)
    {
        CppVar* var = NULL;
        if (n->type.bitWidth <= (int)sizeof(int)) {
            var = new CppVar("int", n->name);
        } else {
            var = new CppVar("long", n->name);
        }
        std::string code = var->def() + " = " + n->vstr() + ";";
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getBvOpCpp(const BitvectorOp* n)
    {
        CppVar* var = NULL;
        if (n->type.bitWidth <= (int)sizeof(int)) {
            var = new CppVar("int", n->name);
        } else {
            var = new CppVar("long", n->name);
        }
        std::string code;
        //// Unary ////
        if (n->op >= BitvectorOp::Op::NEGATE && 
            n->op <= BitvectorOp::Op::EXTRACT) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            if (n->op == BitvectorOp::Op::NEGATE) {
                code = var->def() + " = -" + arg0->use() + ";";
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                code = var->def() + " = ~" + arg0->use() + ";";
            } else if (n->op == BitvectorOp::Op::LROTATE) {
                // TODO
            } else if (n->op == BitvectorOp::Op::RROTATE) {
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
            } else if (n->op == BitvectorOp::Op::S_EXT) {
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
            }
            _curFun->addBody(code);
        //// Binary ////
        } else if (n->op >= BitvectorOp::Op::ADD &&
                   n->op <= BitvectorOp::Op::READMEM) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            if (n->op == BitvectorOp::Op::ADD) {
                code = "";
            } else if (n->op == BitvectorOp::Op::SUB) {
            } else if (n->op == BitvectorOp::Op::AND) {
            } else if (n->op == BitvectorOp::Op::OR) {
            } else if (n->op == BitvectorOp::Op::XOR) {
            } else if (n->op == BitvectorOp::Op::XNOR) {
            } else if (n->op == BitvectorOp::Op::NAND) {
            } else if (n->op == BitvectorOp::Op::NOR) {
            } else if (n->op == BitvectorOp::Op::SDIV) {
            } else if (n->op == BitvectorOp::Op::UDIV) {
            } else if (n->op == BitvectorOp::Op::SREM) {
            } else if (n->op == BitvectorOp::Op::UREM) {
            } else if (n->op == BitvectorOp::Op::SMOD) {
            } else if (n->op == BitvectorOp::Op::SHL) {
            } else if (n->op == BitvectorOp::Op::LSHR) {
            } else if (n->op == BitvectorOp::Op::ASHR) {
            } else if (n->op == BitvectorOp::Op::MUL) {
            } else if (n->op == BitvectorOp::Op::CONCAT) {
            } else if (n->op == BitvectorOp::Op::GET_BIT) {
            } else if (n->op == BitvectorOp::Op::READMEM) {
            }
            _curFun->addBody(code);
        //// Ternary ////
        } else if (n->op >= BitvectorOp::Op::IF) {
        } else {
            ILA_ASSERT(false, "Unknown bool op.");
        }
        return var;
    }

    CppVar* CppSimGen::getMemVarCpp(const MemVar* n)
    {
        CppVar* var = new CppVar("type_mem", n->name);
        std::string code = var->def() + ";";
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getMemConstCpp(const MemConst* n)
    {
        CppVar* var = new CppVar("type_mem", n->name);
        std::string code = var->def() + ";";
        _curFun->addBody(code);
        setMemValue(var, n->memvalues);
        return var;
    }

    CppVar* CppSimGen::getMemWrCpp(const MemWr* n)
    {
        // TODO
        return NULL;
    }
        
    // ---------------------------------------------------------------------- //
    void CppSimGen::defMemClass(std::ostream& out) const
    {
        // TODO
        /*
        template <class T>
        class type_mem
        {
        private:
            std::map<int, T> _map;
            T _def_val;
        public: 
            type_mem(T def = 0)
                : _def_val(def)
            {
            }
            ~type_mem() {}

            ...
        };
        */
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::setMemValue(CppVar* var, MemValues val)
    {
        // TODO
        /*
        out << "[ ";
        for (auto p : val.values) {
            out << " " << std::hex << "0x" << p.first
                << " : " << "0x" << p.second;
        }
        out << " default : 0x" << std::hex << val.def_value << std::dec << " ]";
        */
    }

    // ---------------------------------------------------------------------- //
    template <class T>
    void CppSimGen::checkAndInsert(std::map<std::string, T*>& mp,
                                   const std::string& name,
                                   T* var)
    {
        auto it = mp.find(name);
        if (it == mp.end()) {
            ILA_ASSERT(false, "Variable " + name + " has been defined.");
        }
        mp[name] = var;
    }

    CppVar* CppSimGen::findVar(CppVarMap& mp, const std::string& name)
    {
        auto it = mp.find(name);
        ILA_ASSERT(it != mp.end(), "Variable " + name + " not defined yet.");
        return it->second;
    }

}
