#include <cppsimgen.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <bitset>

namespace ila
{
    static std::string getMask(const int& width);
    static std::string getSignExtMask(const int& width);
    static CppSimGen::CppVarMap* maskPtr = NULL;
    // ---------------------------------------------------------------------- //
    int CppVar::varCnt = 0;

    std::string CppVar::boolStr  = "bool";
    std::string CppVar::bvStr    = "BIT_VEC";
    std::string CppVar::memStr   = "type_mem";
    std::string CppVar::voidStr  = "void";

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

    CppVar::CppVar(int width)
    {
        _type = bvStr;
        _width = width;
        _name = "cppVar_" + boost::lexical_cast<std::string>(varCnt++);
        _isConst = false;
    }

    CppVar::CppVar(const std::string& name, const std::string& val)
        : _val(val)
    {
        _name = "cppMask_" + name + "_";
        _type = bvStr;
        _isConst = false;
    }

    CppVar::~CppVar()
    {
    }

    // ---------------------------------------------------------------------- //
    std::string CppVar::def() const
    {
        if (_name != "") {
            return (_type + " " + _name);
        } else {
            return (_type);
        }
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
        ILA_ASSERT(_type == bvStr, "Wrong type");
        if (_isConst) {
            return _val;
        } else {
            return ("(" + _name + " & " + getMask(_width) + ")");
        }
    }

    std::string CppVar::unsignedUse() const
    {
        if (_isConst) {
            return _val;
        } else {
            return ("(" + _name + " & " + getMask(_width) + ")");
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
        } else if (n->type.isFunc()) {
            // Not neccessary.
            _name = n->name;
            _type = bvStr;
            _width = n->type.bitWidth;
        } else {
            ILA_ASSERT(false, "Unknonw type.");
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
        std::string tail = (modelName == "") ? ");\n" : (")\n" + ind + "{\n");
                           
        out << ind << type << " " << name << "(";
        for (unsigned i = 0; i<_args.size(); i++) {
            out << ((i == 0)? "" : ", ") << _args[i]->def();
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
    CppVar* CppSimGen::addInput(const std::string& name, nptr_t nptr, bool ms)
    {
        // FIXME Need to make sure name is valid.
        CppVar* ip = new CppVar(nptr, name);
        checkAndInsert(_inputs, name, ip, ms);
        return ip;
    }

    CppVar* CppSimGen::addState(const std::string& name, nptr_t nptr, bool ms)
    {
        // FIXME Need to make sure name is valid.
        CppVar* var = new CppVar(nptr, name);   
        checkAndInsert(_states, name, var, ms);
        return var;
    }

    CppFun* CppSimGen::addFun(const std::string& name, bool ms)
    {
        // Create new fun and put it in funMap.
        CppFun* fun = new CppFun(name);
        checkAndInsert(_funMap, name, fun, ms);
        // Insert inputs and global state into the function's varmap
        // Also set the input as fun's arguments.
        CppVarMap* varMap = new CppVarMap;
        for (auto it = _inputs.begin(); it != _inputs.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second, ms);
            fun->addArg(it->second);
        }
        for (auto it = _states.begin(); it != _states.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second, ms);
        }
        for (auto it = _unitpFuncVarMap.begin(); 
             it != _unitpFuncVarMap.end(); it++) {
            checkAndInsert(*varMap, it->first, it->second, ms);
        }
        _varInFun[fun] = varMap;
        return fun;
    }

    CppVar* CppSimGen::addFuncVar(const std::string& name, nptr_t node, bool ms)
    {
        CppVar* var = new CppVar(node, name);   
        checkAndInsert(_unitpFuncVarMap, name, var, ms);

        CppFun* fun = new CppFun(name);
        fun->_ret = new CppVar(node->type.bitWidth);
        for (unsigned i = 0; i != node->type.argsWidth.size(); i++) {
            CppVar* arg = new CppVar(node->type.argsWidth[i]);
            fun->_args.push_back(arg);
        }
        checkAndInsert(_unitpFuncMap, name, fun, ms);
        return var;
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

        const FuncVar* funcvar = NULL;

        const BitvectorChoice* bvchoice = NULL;
        const BoolChoice* boolchoice = NULL;
        const MemChoice* memchoice = NULL;
        const WriteSlice* writeslice = NULL;
        const ReadSlice* readslice = NULL;

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
        //// Func ////
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            res = getFuncVarCpp(funcvar);
        //// Choice ////
        } else if ((boolchoice = dynamic_cast<const BoolChoice*>(n))) {
            ILA_ASSERT(false, "BoolChoice not implemented.");
        } else if ((bvchoice = dynamic_cast<const BitvectorChoice*>(n))) {
            ILA_ASSERT(false, "BitvectorChoice not implemented.");
        } else if ((memchoice = dynamic_cast<const MemChoice*>(n))) {
            ILA_ASSERT(false, "MemChoice not implemented.");
        } else if ((writeslice = dynamic_cast<const WriteSlice*>(n))) {
            ILA_ASSERT(false, "WriteSlice not implemented.");
        } else if ((readslice = dynamic_cast<const ReadSlice*>(n))) {
            ILA_ASSERT(false, "ReadSlice not implemented.");
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
        maskPtr = &_masks;
        
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
                   f->_updates[i].second->use() + ";";
            f->addBody(code);
        }
        // Return the value.
        if (f->_ret != NULL) {
            if (f->_ret->_type != CppVar::bvStr) {
                code = "return " + f->_ret->use() + ";";
            } else {
                code = "return " + f->_ret->use() + ";";
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
        out << "#include <boost/multiprecision/cpp_int.hpp>\n";

        // type define
        out << "\n";
        out << "#ifndef CPP_BITVEC_TYPE\n";
        out << "#define CPP_BITVEC_TYPE\n";
        out << "typedef boost::multiprecision::cpp_int " 
            << CppVar::bvStr << ";\n";
        out << "#endif\n";

        // Mem type class
        out << "\n/****************************************************/\n";
        out << "#ifndef TYPE_MEM_CLASS\n";
        out << "#define TYPE_MEM_CLASS\n";
        defMemClass(out);
        out << "#endif\n";
        out << "/****************************************************/\n";

        out << "\n";
        defUnitpFunc(out);

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
            code = var->def() + " = " + arg0->use() + " ? " + 
                   arg1->use() + " : " + arg2->use() + ";";
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
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                code = var->def() + " = ~" + arg0->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::LROTATE) {
                int par0 = n->param(0);
                int total = var->_width;
                std::string l = boost::lexical_cast<std::string>(par0);
                std::string r = boost::lexical_cast<std::string>(total-par0);
                // int var = x & 0xff
                // var = ((var << l) | (var >> r)) & 0xff
                code = var->def() + " = " + arg0->exactUse();
                _curFun->addBody(code);
                code = var->use() + " = ((" + 
                       var->use() + " << " + l + ") | ( " + 
                       var->use() + " >> " + r + ")) & " + 
                       getMask(var->_width);
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::RROTATE) {
                int par0 = n->param(0);
                int total = var->_width;
                std::string r = boost::lexical_cast<std::string>(par0);
                std::string l = boost::lexical_cast<std::string>(total-par0);
                // int var = x & 0xff
                // var = ((var << l) | (var >> r)) & 0xff
                code = var->def() + " = " + arg0->exactUse();
                _curFun->addBody(code);
                code = var->use() + " = ((" + 
                       var->use() + " << " + l + ") | ( " + 
                       var->use() + " >> " + r + ")) & " + 
                       getMask(var->_width);
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
                code = var->def() + " = " + arg0->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::S_EXT) {
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
                int msb = n->param(0);
                int lsb = n->param(1);
                std::string r = boost::lexical_cast<std::string>(lsb);
                // (x >> r) & 0xfff..(-r)
                code = var->def() + " = (" + arg0->use() + " >> " + r +
                       ") & " + getMask(msb-lsb+1) + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            }
        //// Binary ////
        } else if (n->op >= BitvectorOp::Op::ADD &&
                   n->op <= BitvectorOp::Op::READMEM) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            if (n->op == BitvectorOp::Op::ADD) {
                code = var->def() + " = " + 
                       arg0->use() + " + " + arg1->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::SUB) {
                code = var->def() + " = " + 
                       arg0->use() + " - " + arg1->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
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
                       arg0->use() + " / " + arg1->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::UDIV) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " / " + arg1->unsignedUse() + ";";
                _curFun->addBody(code);
                //code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::SREM) {
                code = var->def() + " = " + 
                       arg0->use() + " % " + arg1->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::UREM) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " % " + arg1->unsignedUse() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::SMOD) {
                // FIXME C++ has no modulo operator, equal to % when positive
                code = var->def() + " = " + 
                       arg0->use() + " % " + arg1->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::SHL) {
                code = var->def() + " = " + 
                       arg0->use() + " << " + arg1->unsignedUse() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::LSHR) {
                code = var->def() + " = " + 
                       arg0->unsignedUse() + " >> " + arg1->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::ASHR) {
                code = var->def() + " = " + 
                       arg0->use() + " >> " + arg1->unsignedUse() + ";";
            } else if (n->op == BitvectorOp::Op::MUL) {
                code = var->def() + " = " + 
                       arg0->use() + " * " + arg1->use() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::CONCAT) {
                std::string w = boost::lexical_cast<std::string>(arg1->_width);
                // |arg0| << arg1.width + |arg1|
                code = var->def() + " = (" + 
                       arg0->unsignedUse() + " << " + w + 
                       ") + " + arg1->unsignedUse() + ";";
                _curFun->addBody(code);
                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::GET_BIT) {
                code = var->def() + " = (" + 
                       arg0->use() + " >> " + arg1->use() + ") & 0x1;";
            } else if (n->op == BitvectorOp::Op::READMEM) {
                code = var->def() + " = " + 
                       arg0->use() + ".rd(" + arg1->use() + ");";
            }
        //// Ternary ////
        } else if (n->op == BitvectorOp::READMEMBLOCK) {
            ILA_ASSERT(n->nArgs() == 2, "Two parameters expected.");
            CppVar* mem = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* addr = findVar(*_curVarMap, n->arg(1)->name);
            ILA_ASSERT(n->nParams() == 2, "Two parameters expected.");
            int blxSize = mem->_width;
            int blxNum = n->param(0);
            endianness_t e = (endianness_t) n->param(1);
            // int64_t var = (mem.rd(addr) & 0xff);
            // for (int i = 0; i < blxNum; i++) {
            //     little:
            //     var = var | ((mem.rd(addr+i) & 0xff) << (width * i));
            //     big:
            //     var = (var << width) | (mem.rd(addr+i) & 0xff);
            // }
            // var = (var & 0x8) ? (var | 0xfff000) : var;
            static boost::format defFmt(
                "%1% = (%2%.rd(%3%) & %4%);");
            static boost::format loopProlog(
                "for (int %1% = 1; %2% < %3%; %4%++) {");
            static boost::format litFmt(
                "\t%1% = %2% | ((%3%.rd(%4% + %5%) & %6%) << (%7% * %8%));");
            static boost::format bigFmt(
                "\t%1% = (%2% << %3%) | (%4%.rd(%5% + %6%) & %7%);");

            defFmt %var->def() %mem->use() %addr->use() %getMask(blxSize);
            _curFun->addBody(defFmt.str());

            CppVar* idx = new CppVar(32);
            loopProlog %idx->use() %idx->use() %blxNum %idx->use();
            _curFun->addBody(loopProlog.str());

            if (e == LITTLE_E) {
                litFmt % var->use()         // %1% 
                       % var->use()         // %2%
                       % mem->use()         // %3%
                       % addr->use()        // %4%
                       % idx->use()         // %5%
                       % getMask(blxSize)   // %6%
                       % blxSize            // %7%
                       % idx->use();        // %8%
                code = litFmt.str();
                _curFun->addBody(code);
            } else {
                bigFmt % var->use()         // %1%
                       % var->use()         // %2%
                       % blxSize            // %3%
                       % mem->use()         // %4%
                       % addr->use()        // %5%
                       % idx->use()         // %6%
                       % getMask(blxSize);  // %7%
                code = bigFmt.str();
                _curFun->addBody(code);
            }
            _curFun->addBody("}");

            code = getSignedCppCode(var);
        } else if (n->op == BitvectorOp::Op::IF) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->name);
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->name);
            CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->name);
            code = var->def() + " = (" + arg0->use() + ") ? " +
                   arg1->use() + " : " + arg2->use() + ";";
        } else if (n->op == BitvectorOp::Op::APPLY_FUNC) {
            CppVar* fun = findVar(*_curVarMap, n->arg(0)->name);
            std::vector<CppVar*> argVec;
            for (unsigned i = 1; i != n->nArgs(); i++) {
                CppVar* arg = findVar(*_curVarMap, n->arg(i)->name);
                argVec.push_back(arg);
            }
            code = var->def() + " = " + fun->use() + "(";
            for (unsigned i = 0; i != argVec.size(); i++) {
                code = code + ((i == 0)? "" : ", ") + argVec[i]->use();
            }
            code = code + ");";
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
            var = new CppVar(n);
            code = var->def() + " = " + arg0->use() + ";";
            _curFun->addBody(code);
            code = var->use() + ".wr(" + arg1->use() + 
                   ", " + arg2->use() + ");";
        } else if (n->op == MemOp::Op::ITE) {
            ILA_ASSERT(arg0->_type == CppVar::boolStr,
                       "Condition not bool.");
            var = new CppVar(n);
            code = var->refDef() + " = (" + 
                   arg0->use() + ") ? " + arg1->use() + 
                   " : " + arg2->use() + ";";
        } else if (n->op == MemOp::Op::STOREBLOCK) {
            ILA_ASSERT(arg0->_type == CppVar::memStr,
                        "Write to non-mem variable.");
            var = new CppVar(n);
            int chunkSize = arg0->_width;
            int chunkNum = arg2->_width / chunkSize;
            ILA_ASSERT(arg2->_width % chunkSize == 0, 
                        "Block store size mismatch.");
            bool isLittle = n->endian == LITTLE_E;

            // var chunk_i;
            // Mem var = mem;
            // for (int i=0; i<chunkNum; i++) {
            //     endian dependent code 
            //     var.wr(addr+i, chunk_i);
            // }
            //     little:
            //     chunk_i = data >> (i * chunkSize);
            //     chunk_i = chunk_i.signedUse();
            //     big:
            //     chunk_i = data >> ((chunkNum - 1 - i) * chunkSize);
            //     chunk_i = chunk_i.signedUse();

            CppVar* idx = new CppVar(32);
            CppVar* chunk_i = new CppVar(chunkSize);
            _curFun->addBody(chunk_i->def() + ";");
            _curFun->addBody(var->def() + " = " + arg0->use() + ";");

            static boost::format loopProlog(
                "for (int %1% = 0; %2% < %3%; %4%++) {");
            static boost::format litFmt(
                "\t%1% = %2% >> (%3% * %4%);");
            static boost::format bigFmt(
                "\t%1% = %2% >> ((%3% - 1 - %4%) * %5%);");
            static boost::format writeFmt(
                "\t%1%.wr(%2% + %3%, %4%);");

            loopProlog % idx->use()             // 1
                       % idx->use()             // 2
                       % chunkNum               // 3
                       % idx->use();            // 4

            litFmt     % chunk_i->use()         // 1
                       % arg2->use()            // 2
                       % idx->use()             // 3
                       % chunkSize;             // 4

            bigFmt     % chunk_i->use()         // 1
                       % arg2->use()            // 2
                       % chunkNum               // 3
                       % idx->use()             // 4
                       % chunkSize;             // 5

            writeFmt   % var->use()             // 1
                       % arg1->use()            // 2
                       % idx->use()             // 3
                       % chunk_i->use();        // 4

            _curFun->addBody(loopProlog.str());
            _curFun->addBody(isLittle ? litFmt.str() : bigFmt.str());
            _curFun->addBody("\t" + getSignedCppCode(chunk_i));
            _curFun->addBody(writeFmt.str());
            code = "}";
        } else {
            ILA_ASSERT(false, "Invalid MemOp.");
        }

        if (code != "") {
            _curFun->addBody(code);
        }

        return var;
    }

    CppVar* CppSimGen::getFuncVarCpp(const FuncVar* n)
    {
        CppVar* var = new CppVar(n);
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
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::genModel(std::ostream& out) const
    {
        // Model class prolog
        out << "class " <<  _modelName << "\n" 
            << "{\n";
        
        // Constructor/destructor
        out << "public:\n"
            << "\t" << _modelName << "() {\n";
        for (auto it = _masks.begin(); it != _masks.end(); it++) {
            out << "\t\t" << it->second->use() << " = " 
                << it->second->_val << ";\n";
        }
        out << "\t};\n"
            << "\t~" << _modelName << "() {};\n";

        // Public: states variables
        out << "public:\n";
        out << "\t// State variables.\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            out << "\t" << it->second->def() << ";\n";
        }

        // Public: functions (fetch, decode, update ... etc.)
        out << "public:\n";
        out << "\t// Public functions: fetch, decode, update, ...\n";
        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            it->second->dumpDec(out, "", 1); 
        }

        out << "private:\n";
        out << "\t// Bitvector masks.\n";
        for (auto it = _masks.begin(); it != _masks.end(); it++) {
            out << "\t" << it->second->def() << ";\n";
                //<< it->second->_val << ";\n";
        }
        // Model class epilog
        out << "\n};\n";

        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            it->second->dumpDec(out, _modelName, 0);
            it->second->dumpCode(out, 0);
        }

    }

    void CppSimGen::defUnitpFunc(std::ostream& out) const
    {
        for (auto it = _unitpFuncMap.begin(); it != _unitpFuncMap.end(); it++) {
            out << "extern ";
            it->second->dumpDec(out, "", 0);
        }
    }
    // ---------------------------------------------------------------------- //
    std::string CppSimGen::getSignedCppCode(CppVar* var)
    {
        static std::string signTempVarName = "cpp_signTempVar";
        static std::string unsignTempVarName = "cpp_unsignTempVar";
        CppVar* signTempVar = NULL;
        CppVar* unsignTempVar = NULL;
        std::string signStr;
        std::string unsignStr;

        auto signIt = _curVarMap->find(signTempVarName);
        if (signIt == _curVarMap->end()) {
            signTempVar = new CppVar(32);
            unsignTempVar = new CppVar(32);
            checkAndInsert(*_curVarMap, signTempVarName, signTempVar);
            checkAndInsert(*_curVarMap, unsignTempVarName, unsignTempVar);
            signStr = signTempVar->def() + " = ";
            unsignStr = unsignTempVar->def() + " = ";
        } else {
            signTempVar = (*_curVarMap)[signTempVarName];
            unsignTempVar = (*_curVarMap)[unsignTempVarName];
            signStr = signTempVar->use() + " = ";
            unsignStr = unsignTempVar->use() + " = ";
        }

        signStr += var->use() + " | " + getSignExtMask(var->_width) + ";";
        unsignStr += var->use() + " & " + getMask(var->_width) + ";";
        _curFun->addBody(signStr);
        _curFun->addBody(unsignStr);
        static boost::format signUseFmt(
            "%1% = ((%2% >> %3%) & 0x1) ? %4% : %5%;");
        signUseFmt % var->use()
                   % var->use() 
                   % (var->_width-1) 
                   % signTempVar->use()
                   % unsignTempVar->use();
        return signUseFmt.str();
    }

    // ---------------------------------------------------------------------- //
    template <class T>
    void CppSimGen::checkAndInsert(std::map<std::string, T*>& mp,
                                   const std::string& name,
                                   T* var,
                                   bool force)
    {
        auto it = mp.find(name);
        if (it != mp.end()) {
            if (!force)
                ILA_ASSERT(false, "Variable " + name + " has been defined.");
            else 
                return;
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
        ILA_ASSERT(width > 0, "Negative width.");

        static boost::format unMaskStr("((%1%)1 << %2%) - 1");
        unMaskStr % CppVar::bvStr
                  % width;
        std::string val = unMaskStr.str();

        auto it = maskPtr->find(val);
        if (it == maskPtr->end()) {
            std::string name = "un_"+boost::lexical_cast<std::string>(width);
            CppVar* var = new CppVar(name, val);
            (*maskPtr)[val] = var;
            return var->use();
        } else {
            return it->second->use();
        }
        return val;
    }

    static std::string getSignExtMask(const int& width)
    {
        ILA_ASSERT(width > 0, "Negative width.");
        std::string str = "~" + getMask(width);
        auto it = maskPtr->find(str);
        if (it == maskPtr->end()) {
            std::string name = "sign_"+boost::lexical_cast<std::string>(width);
            CppVar* var = new CppVar(name, str);
            (*maskPtr)[str] = var;
            return var->use();
        } else {
            return it->second->use();
        }
        return str;
    }

}
