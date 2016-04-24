#include <cppsimgen.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <bitset>

namespace ila
{
    static std::string getMask(const int& width);
    static std::string getSignBit(const int& width);
    static std::string getSignExtMask(const int& width);
    // ---------------------------------------------------------------------- //
    int CppVar::varCnt = 0;

    std::string CppVar::boolStr  = "bool";
    std::string CppVar::bvStr    = "int64_t";
    std::string CppVar::ubvStr   = "uint64_t";
    std::string CppVar::sbvStr   = "int64_t";
    std::string CppVar::memStr   = "type_mem";
    std::string CppVar::voidStr  = "void";
    std::string CppVar::maxBvVal = "UINT64_MAX";

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

    std::string CppVar::refDef() const
    {
        return (_type + "& " + _name);
    }

    std::string CppVar::use() const
    {
        if (_isConst) {
            return _val;
        } else {
            return _name;
        }
    }

    std::string CppVar::exactUse() const
    {
        if (_isConst) {
            return _val;
        } else if (_type == boolStr) {
            return _name;
        } else {
            return ("(" + _name + " & " + getMask(_width) + ")");
        }
    }

    std::string CppVar::signedUse() const
    {
        if (_isConst) {
            return _val;
        } else {
            // ((x & signbit) ? (x | signExt) : (x & mask))
            std::string str = 
                "((" + _name + " & " + getSignBit(_width) + ") ? " + 
                "(" + _name + " | " + getSignExtMask(_width) + ") : " +
                "(" + _name + " & " + getMask(_width) + "))";
            return str;
        }
    }

    std::string CppVar::unsignedUse() const
    {
        if (_isConst) {
            return _val;
        } else {
            return ("((" + ubvStr + ")" + _name + " & " + getMask(_width) + ")");
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
    // Print the function header outside the class to the output stream.
    void CppFun::dumpDec(std::ostream& out,
                          const std::string& modelName,
                          const int& indent) const
    {
        std::string ind = "";
        for (int i = 0; i < indent; i++) {
            ind = ind + "\t";
        }

        std::string type = (_ret != NULL) ? _ret->_type : CppVar::voidStr;
        std::string name = (modelName == "") ? 
                           _name : (modelName + "::" + _name);
        std::string tail = (modelName == "") ? ");" : (")\n" + ind + "{\n");
                           
        out << "\n" << ind << type << " " << name << "(";
        for (unsigned i = 0; i<_args.size(); i++) {
            if (i != 0) { out <<", "; }
            out << _args[i]->def();
        }
        out << tail;
    }

    void CppFun::dumpCode(std::ostream& out, const int& indent) const
    {
        std::string ind = "";
        for (int i = 0; i < indent; i++) {
            ind = ind + "\t";
        }
        for (unsigned i = 0; i != _codeList.size(); i++) {
            out << ind << "\t" << _codeList[i] << "\n";
        }
        out << ind << "}\n";
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
        // FIXME Need to make sure name is valid.
        CppVar* ip = new CppVar(nptr, name);    
        checkAndInsert(_inputs, name, ip);
        return ip;
    }

    CppVar* CppSimGen::addState(const std::string& name, nptr_t nptr)
    {
        // FIXME Need to make sure name is valid.
        CppVar* var = new CppVar(nptr, name);   
        checkAndInsert(_states, name, var);
        return var;
    }

    CppFun* CppSimGen::addFun(const std::string& name)
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
        const MemOp*  memop = NULL;

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
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            res = getMemOpCpp(memop);
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
        for (unsigned i = 0; i < f->_updates.size(); i++) {
            code = f->_updates[i].first->use() + " = " + 
                   f->_updates[i].second->signedUse() + ";";
            f->addBody(code);
        }
        // Return the value.
        if (f->_ret != NULL) {
            if (f->_ret->_type != CppVar::bvStr) {
                code = "return " + f->_ret->use() + ";";
            } else {
                code = "return " + f->_ret->signedUse() + ";";
            }
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
        // Include headers
        out << "#include <map>\n";
        out << "#include <stdint.h>\n";

        // Mem type class
        out << "\n/****************************************************/\n";
        out << "#ifndef TYPE_MEM_CLASS\n";
        out << "#define TYPE_MEM_CLASS\n";
        defMemClass(out);
        out << "#endif\n";
        out << "/****************************************************/\n";

        out << "\n/****************************************************/\n";
        out << "#ifndef " << boost::to_upper_copy<std::string>(_modelName) 
            << "_CLASS\n";
        out << "#define " << boost::to_upper_copy<std::string>(_modelName) 
            << "_CLASS\n";
        // Model class
        genModel(out);
        // Constant memory initialization.
        setMemConst(out);
        out << "#endif\n";
        out << "/****************************************************/\n";

        // main function
        //genMain(out);

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
                       arg0->signedUse() + " < " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::SGT) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " > " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::SLE) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " <= " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::SGE) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " >= " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::ULT) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " < " + arg1->unsignedUse() + ";";
            } else if (n->op == BoolOp::Op::UGT) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " > " + arg1->unsignedUse() + ";";
            } else if (n->op == BoolOp::Op::ULE) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " <= " + arg1->unsignedUse() + ";";
            } else if (n->op == BoolOp::Op::UGE) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " >= " + arg1->unsignedUse() + ";";
            } else if (n->op == BoolOp::Op::EQUAL) {
                code = var->def() + " = (" + 
                       arg0->exactUse() + " == " + arg1->exactUse() + ");";
            } else if (n->op == BoolOp::Op::DISTINCT) {
                code = var->def() + " = (" + 
                       arg0->exactUse() + " != " + arg1->exactUse() + ");";
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
                code = var->def() + " = -" + arg0->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                code = var->def() + " = ~" + arg0->use() + ";";
            } else if (n->op == BitvectorOp::Op::LROTATE) {
                int par0 = n->param(0);
                int total = var->_width;
                std::string l = boost::lexical_cast<std::string>(par0);
                std::string r = boost::lexical_cast<std::string>(total-par0);
                // ((x << l) | (x >> r)) & 0xff
                code = var->def() + " = ((" + 
                       arg0->unsignedUse() + " << " + l + ") | ( " + 
                       arg0->unsignedUse() + " >> " + r + ")) & " + 
                       getMask(var->_width);
            } else if (n->op == BitvectorOp::Op::RROTATE) {
                int par0 = n->param(0);
                int total = var->_width;
                std::string r = boost::lexical_cast<std::string>(par0);
                std::string l = boost::lexical_cast<std::string>(total-par0);
                // ((x << l) | (x >> r)) & 0xff
                code = var->def() + " = ((" + 
                       arg0->unsignedUse() + " << " + l + ") | ( " + 
                       arg0->unsignedUse() + " >> " + r + ")) & " + 
                       getMask(var->_width);
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
                code = var->def() + " = " + arg0->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::S_EXT) {
                code = var->def() + " = " + arg0->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
                int par0 = n->param(0);
                int par1 = n->param(1);
                std::string r = boost::lexical_cast<std::string>(par0);
                // (x >> r) & 0xfff..(-r)
                code = var->def() + " = (" + arg0->use() + " >> " + r +
                       ") & " + getMask(par1-par0) + ";";
            }
        //// Binary ////
        } else if (n->op >= BitvectorOp::Op::ADD &&
                   n->op <= BitvectorOp::Op::READMEM) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            if (n->op == BitvectorOp::Op::ADD) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " + " + arg1->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::SUB) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " - " + arg1->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::AND) {
                code = var->def() + " = " + 
                       arg0->use() + " & " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::OR) {
                code = var->def() + " = " + 
                       arg0->use() + " | " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::XOR) {
                code = var->def() + " = " + 
                       arg0->use() + " ^ " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::XNOR) {
                code = var->def() + " = ~(" + 
                       arg0->use() + " ^ " + arg1->use() + ");";
            } else if (n->op == BitvectorOp::Op::NAND) {
                code = var->def() + " = ~(" + 
                       arg0->use() + " & " + arg1->use() + ");";
            } else if (n->op == BitvectorOp::Op::NOR) {
                code = var->def() + " = ~(" + 
                       arg0->use() + " | " + arg1->use() + ");";
            } else if (n->op == BitvectorOp::Op::SDIV) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " / " + arg1->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::UDIV) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " / " + arg1->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::SREM) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " % " + arg1->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::UREM) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " % " + arg1->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::SMOD) {
                // FIXME C++ has no modulo operator, equal to % when positive
                code = var->def() + " = " + 
                       arg0->use() + " % " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::SHL) {
                code = var->def() + " = (" + 
                       arg0->use() + " << " + arg1->unsignedUse() + ") & " +
                       getMask(var->_width) + ";";
            } else if (n->op == BitvectorOp::Op::LSHR) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " >> " + arg1->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::ASHR) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " >> " + arg1->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::MUL) {
                code = var->def() + " = " + 
                       arg0->signedUse() + " * " + arg1->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::CONCAT) {
                std::string w = boost::lexical_cast<std::string>(arg1->_width);
                // |arg0| << arg1.width + |arg1|
                code = var->def() + " = (" + 
                       arg0->unsignedUse() + " << " + w + 
                       " + " + arg1->unsignedUse() + 
                       ") & " + getMask(var->_width) + ";";
            } else if (n->op == BitvectorOp::Op::GET_BIT) {
                code = var->def() + " = (" + 
                       arg0->use() + " >> " + arg1->use() + ") & 0x1;";
            } else if (n->op == BitvectorOp::Op::READMEM) {
                code = var->def() + " = " + 
                       arg0->use() + ".rd(" + arg1->unsignedUse() + ");";
            }
        //// Ternary ////
        } else if (n->op >= BitvectorOp::Op::IF) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->name);
            code = var->def() + " = (" + arg0->use() + ") ? " +
                   arg1->exactUse() + " : " + arg2->exactUse() + ";";
        } else {
            ILA_ASSERT(false, "Unknown bool op.");
        }

        if (code != "") {
            _curFun->addBody(code);
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
        // Should update to _states and _curVarMap.
        CppVar* var = NULL;
        auto it = _states.find(n->name);
        if (it != _states.end()) {
            var = it->second;
        } else {
            var = new CppVar(n);
            checkAndInsert(_states, n->name, var);
        }

        _memConst[var] = n;
        return var;
    }

    CppVar* CppSimGen::getMemOpCpp(const MemOp* n)
    {
        CppVar* var = NULL; 
        CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
        CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
        CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->name);

        std::string code = "MEM NOT IMPLEMENTED";
        if (n->op == MemOp::Op::STORE) {
            ILA_ASSERT(arg0->_type == CppVar::memStr, 
                       "Write to non-mem variable.");
            var = arg0;
            code = arg0->use() + ".wr(" + arg1->exactUse() + 
                   ", " + arg2->exactUse() + ");";
        } else if (n->op == MemOp::Op::ITE) {
            ILA_ASSERT(arg0->_type == CppVar::boolStr,
                       "Condition not bool.");
            var = new CppVar(n);
            code = var->refDef() + " = (" + 
                   arg0->use() + ") ? " + arg1->use() + 
                   " : " + arg2->use() + ";";
        } else {
            ILA_ASSERT(false, "Invalid MemOp.");
        }

        if (code != "") {
            _curFun->addBody(code);
        }

        return var;
    }
        
    // ---------------------------------------------------------------------- //
    void CppSimGen::defMemClass(std::ostream& out) const
    {
        std::string bvStr = CppVar::bvStr;
        out << "class type_mem\n";
        out << "{\n";
        out << "private:\n";
        out << "\tstd::map<" << bvStr << ", " << bvStr << "> _map;\n";
        out << "\t" << bvStr << " _def_val;\n";
        out << "public:\n";
        out << "\ttype_mem(" << bvStr << " def = 0)\n";
        out << "\t\t: _def_val(def)\n";
        out << "\t{\n";
        out << "\t}\n";
        out << "\t~type_mem() {}\n";
        out << "\n";
        out << "\tvoid setDef(" << bvStr << " def)\n";
        out << "\t{\n";
        out << "\t\t_def_val = def;\n";
        out << "\t}\n";
        out << "\n";
        out << "\tvoid wr(" << bvStr << " addr, " << bvStr << " data)\n";
        out << "\t{\n";
        out << "\t\tif (data == _def_val) {\n";
        out << "\t\t\t_map.erase(addr);\n";
        out << "\t\t} else {\n";
        out << "\t\t\t_map[addr] = data;\n";
        out << "\t\t}\n";
        out << "\t}\n";
        out << "\n";
        out << "\t" << bvStr << " rd(" << bvStr << " addr)\n";
        out << "\t{\n";
        out << "\t\tstd::map<" << bvStr << ", " << bvStr << ">::iterator it = _map.find(addr);\n";
        out << "\t\tif (it == _map.end()) {\n";
        out << "\t\t\treturn _def_val;\n";
        out << "\t\t} else {\n";
        out << "\t\t\treturn _map[addr];\n";
        out << "\t\t}\n";
        out << "\t}\n";
        out << "};\n";
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::setMemConst(std::ostream& out) const
    {
        out << "\n/****************************************************/\n";
        for (auto it = _memConst.begin(); it != _memConst.end(); it++) {
            out << "\n";
            out << _modelName << "::" <<  it->first->use() << ".setDef(" 
                << it->second->memvalues.def_value << ");\n";
            for (auto p : it->second->memvalues.values) {
                out << it->first->use() 
                    << ".wr(" << p.first << ", " << p.second << ");\n";
            }
        }
        out << "/****************************************************/\n";
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::genMain(std::ostream& out) const
    {
        // TODO
        out << "int main(int argc, char* argv[])\n"
            << "{\n"
            << "\t" << _modelName << " mod;\n" 
            << "\t// State initialization:\n"
            << "\n"
            << "\t// Feed in inputs:\n"
            << "\t/* Ex:\n"
            << "\tfor (int i = 0; i < 10; i++) {\n"
            << "\t\tmod.update();\n"
            << "\t}\n"
            << "\t*/\n"
            << "\n"
            << "\treturn 0;\n"
            << "}\n";
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::genModel(std::ostream& out) const
    {
        // Model class prolog
        out << "class " <<  _modelName << "\n" 
            << "{\n";
        
        /*
        // Comments: Node name and cpp var name mapping.
        out << "Inputs:\n";
        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            out << it->first << " => " << it->second->def() << "\n";
        }
        out << "States:\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            out << it->first << " => " << it->second->def() << "\n";
        }
        */

        // Constructor/destructor
        out << "public:\n"
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
            it->second->dumpDec(out, "", 1); 
        }

        // Model class epilog
        out << "\n};\n";

        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            it->second->dumpDec(out, _modelName, 0);
            it->second->dumpCode(out, 0);
        }

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

    static std::string getMask(const int& width)
    {
        ILA_ASSERT(width <= (int)sizeof(CppVar::cppBvType), 
                "Width exceed max length.");
        ILA_ASSERT(width > 0, "Negative width.");
        CppVar::cppBvType mask = (CppVar::cppBvType)UINTMAX_MAX;
        mask = mask << width;
        mask = ~mask;
        std::string str = boost::lexical_cast<std::string>(mask);
        return str;
    }

    static std::string getSignBit(const int& width)
    {
        ILA_ASSERT(width <= (int)sizeof(CppVar::cppBvType),
                "Width exceed max length.");
        ILA_ASSERT(width > 0, "Negative width.");
        CppVar::cppBvType bit = 1 << (width-1);
        std::string str = boost::lexical_cast<std::string>(bit);
        return str;
    }

    static std::string getSignExtMask(const int& width)
    {
        ILA_ASSERT(width <= (int)sizeof(CppVar::cppBvType),
                "Width exceed max length.");
        ILA_ASSERT(width > 0, "Negative width.");
        std::string w = boost::lexical_cast<std::string>(width);
        return ("(" + CppVar::maxBvVal + " << " + w + ")");
    }

}
