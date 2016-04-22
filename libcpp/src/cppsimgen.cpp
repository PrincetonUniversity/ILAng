#include <cppsimgen.hpp>
#include <boost/lexical_cast.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int CppVar::varCnt = 0;

    std::string CppVar::boolStr = "bool";
    std::string CppVar::bvStr   = "int32_t";
    std::string CppVar::ubvStr  = "uint32_t";
    std::string CppVar::memStr  = "type_mem";
    std::string CppVar::voidStr = "void";

    // ---------------------------------------------------------------------- //
    CppVar::CppVar(nptr_t nptr, const std::string& name)
    {
        init(nptr);
        if (name != "") _name = name;
    }

    CppVar::CppVar(const Node* node, const std::string& name)
    {
        init(node);
        if (name != "") _name = name;
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
        if (_isConst) {
            return _val;
        } else {
            return (_name);
        }
    }

    // ---------------------------------------------------------------------- //
    void CppVar::init(nptr_t n)
    {
        init(n.get());
    }

    void CppVar::init(const Node* n)
    {
        _name = "cppVar_" + boost::lexical_cast<std::string>(varCnt++);
        if (n->type.isBool()) {
            _type = boolStr;
            _width = 0;
        } else if (n->type.isBitvector()) {
            // FIXME cases for different width
            _type = bvStr;
            _width = n->type.bitWidth;
        } else if (n->type.isMem()) {
            _type = memStr;
            _width = n->type.dataWidth;
        }

        const BoolConst* boolconst = NULL;
        const BitvectorConst* bvconst = NULL;

        if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            _isConst = true;
            _val = (boolconst->val()) ? "true" : "false";
        } else if ((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            _isConst = true;
            _val = bvconst->vstr();
        } else {
            _isConst = false;
            _val = "";
        } 
        // mem?
    }

    // ---------------------------------------------------------------------- //
    CppFun::CppFun(const std::string& name)
        : _name(name)
    {
        _ret = NULL;
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
        out << "\n\t";
        if (_ret != NULL) {
            out << _ret->_type << " " << _name << "(";
        } else {
            out << "void " << _name << "(";
        }

        for (auto i = 0; i<_args.size(); i++) {
            if (i != 0) { out <<", "; }
            out << _args[i]->def();
        }
        out << ")\n\t{\n";
    }

    void CppFun::dumpCode(std::ostream& out) const
    {
        for (unsigned i = 0; i != _codeList.size(); i++) {
            out << "\t\t" << _codeList[i] << "\n";
        }
    }

    // ---------------------------------------------------------------------- //
    CppSimGen::CppSimGen(const std::string& prefix)
        : _modelName("model_" + prefix)
    {
    }

    CppSimGen::~CppSimGen()
    {
    }

    // ---------------------------------------------------------------------- //
    CppVar* CppSimGen::addInput(const std::string& name, nptr_t nptr)
    {
        // FIXME Need to make sure name valid.
        CppVar* ip = new CppVar(nptr, name);    
        checkAndInsert(_inputs, name, ip);
        checkAndInsert(_varMap, name, ip);
        return ip;
    }

    CppVar* CppSimGen::addState(const std::string& name, nptr_t nptr)
    {
        // FIXME Need to make sure name valid.
        CppVar* var = new CppVar(nptr, name);   
        checkAndInsert(_states, name, var);
        checkAndInsert(_varMap, name, var);
        return var;
    }

    CppFun* CppSimGen::addFun(const std::string& type,
                              const std::string& name)
    {
        // Create new fun and put it in funMap.
        CppFun* fun = new CppFun(name);
        checkAndInsert(_funMap, name, fun);
        // Insert inputs and global state into the function's varmap
        // Also set the input as fun's arguments.
        CppVarMap* varMap = new CppVarMap;
        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second);
            fun->addArg(it->second);
        }
        for (auto it = _states.begin(); it != _states.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second);
        }
        _varInFun[fun] = varMap;
        return fun;
    }

    // ---------------------------------------------------------------------- //
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
        _curVar = res;
    }

    // ---------------------------------------------------------------------- //
    // Build function body with ast node.
    void CppSimGen::buildFun(CppFun* f, nptr_t nptr)
    {
        if (nptr == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        _curVarMap = it->second;
        _curFun = f;
        
        nptr->depthFirstVisit(*this);
        checkAndInsert(_varMap, nptr->name, _curVar);
        
        _curVarMap = NULL;
        _curFun = NULL;
        return;
    }

    // Set the return variable for the function.
    void CppSimGen::setFunReturn(CppFun* f, nptr_t nptr)
    {
        if (nptr == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        
        f->_ret = findVar(*(it->second), nptr->name);
    }

    // Add a variable that should be update at the end of the function.
    void CppSimGen::addFunUpdate(CppFun* f, nptr_t lhs, nptr_t rhs)
    {
        if (lhs == NULL || rhs == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        
        CppVar* argL = findVar(*(it->second), lhs->name);
        CppVar* argR = findVar(*(it->second), rhs->name);

        f->_updates.push_back(std::make_pair(argL, argR));
    }

    // Terminate the function building.
    void CppSimGen::endFun(CppFun* f)
    {
        std::string code = "NOT SPECIFIED";
        // Update the states.
        for (auto i = 0; i < f->_updates.size(); i++) {
            code = f->_updates[i].first->use() + " = " + 
                   f->_updates[i].second->use() + ";";
            f->addBody(code);
        }
        // Return the value.
        if (f->_ret != NULL) {
            code = "return " + f->_ret->use();
            f->addBody(code);
        } else {
            code = "return;";
            f->addBody(code);
        }
    }

    // ---------------------------------------------------------------------- //
    // Export all code to the output stream.
    void CppSimGen::exportAll(std::ostream& out) const
    {
        // TODO Better option: declare const outside update functions.

        // Include headers
        out << "#include <map.h>;\n";

        // Mem type class
        defMemClass(out);

        // Model class prolog
        out << "\nclass " <<  _modelName << " {\n" 
            << "{\n\n";
        
        // Comments: Node name and cpp var name mapping.
        out << "/*****************************************************\n";
        out << "Inputs:\n";
        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            out << it->first << " => " << it->second->def() << "\n";
        }
        out << "States:\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            out << it->first << " => " << it->second->def() << "\n";
        }
        out << "*****************************************************/\n";

        // Constructor/destructor
        out << "\npublic:\n"
            << "\t"  << _modelName << "() {};\n"
            << "\t~" << _modelName << "() {};\n";

        // Public: states variables
        out << "\n\t// State variables.\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            out << "\t" + it->second->def() << ";\n";
        }

        // Public: set states function?

        // Public: functions (fetch, decode, update ... etc.)
        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            it->second->dumpDef(out);
            it->second->dumpCode(out);
            out << "\t}\n";
        }

        // Model class epilog
        out << "\n};\n\n";

        // main function
        out << "int main(int argc, char* argv[])\n"
            << "{\n"
            << "\t// TODO\n"
            << "\treturn 0;\n"
            << "}\n";

    }

    // ---------------------------------------------------------------------- //
    CppVar* CppSimGen::getBoolVarCpp(const BoolVar* n)
    {
        CppVar* var = new CppVar(n);
        std::string code = var->def();
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getBoolConstCpp(const BoolConst* n)
    {
        CppVar* var = new CppVar(n);
        return var;
    }

    CppVar* CppSimGen::getBoolOpCpp(const BoolOp* n)
    {
        CppVar* var = new CppVar(n);
        std::string code = "boolOp NOT IMPLEMENTED";
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
                // TODO Change to type str
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
        CppVar* var = new CppVar(n);
        std::string code = var->def() + ";";
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getBvConstCpp(const BitvectorConst* n)
    {
        CppVar* var = new CppVar(n);
        return var;
    }

    CppVar* CppSimGen::getBvOpCpp(const BitvectorOp* n)
    {
        CppVar* var = new CppVar(n);
        std::string code = "bvOp NOT IMPLEMENTED.";
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
        CppVar* var = new CppVar(n);
        std::string code = var->def() + ";";
        _curFun->addBody(code);
        return var;
    }

    CppVar* CppSimGen::getMemConstCpp(const MemConst* n)
    {
        CppVar* var = new CppVar(n);
        std::string code = var->def() + ";";
        _curFun->addBody(code);
        setMemValue(var, n->memvalues);
        return var;
    }

    CppVar* CppSimGen::getMemWrCpp(const MemWr* n)
    {
        // TODO
        CppVar* var = new CppVar(n);
        return var;
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
        if (it != mp.end()) {
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
