#include <cppsimgen.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <bitset>
#include <cmath>

namespace ila
{
    static std::string getMask(const int& width);
    static std::string getSignExtMask(const int& width);
    static std::string getSignBit(const int& width);
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

    CppVar::CppVar(const CppVar* var)
        : _type(var->_type)
        , _width(var->_width)
        , _idxwidth(var->_idxwidth)
    {
        _name = "cppVar_" + boost::lexical_cast<std::string>(varCnt++);
        _isConst = var->_isConst;
        _val = var->_val;
    }

    CppVar::~CppVar()
    {
    }

    // ---------------------------------------------------------------------- //

    std::string CppVar::def() const
    {
        if (_name != "") {
            return (vType() + " " + _name);
        } else {
            return (_type);
        }
    }
    
    std::string CppVar::vType() const
    {
        if (_type != memStr)
            return _type;
        else
            return _type + "<" + "BV" + boost::lexical_cast<std::string>(_width)  +"," 
                    + boost::lexical_cast<std::string>((long)(std::pow(2, _idxwidth)))
                    +">";
    }

    std::string CppVar::refDef() const
    {
        return (vType() + "& " + _name);
    }

    std::string CppVar::ctorDef() const
    {
        if (_type != memStr)
            return "";
        return _name+"(0)";
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

    std::string CppVar::signedUse() const
    {
        boost::format signUseFmt(
            "((%1% & %2%) ? (%3% | %4%) : %5%)");
        if (_isConst) {
            return _val;
        } else {
            signUseFmt % _name % getSignBit(_width)
                       % _name % getSignExtMask(_width)
                       % _name;
            return signUseFmt.str();
        }
    }

    std::string CppVar::castUse() const
    {
        ILA_ASSERT(_type == bvStr, "Wrong type");
        if (_isConst) {
            return _val;
        } else {
            return ("static_cast<unsigned>(" + _name + ")");
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
            _idxwidth = n->type.addrWidth;
        } else if (n->type.isFunc()) {
            // Not neccessary.
            _name = n->getName();
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

        std::string type = (_ret != NULL) ? _ret->vType() : CppVar::voidStr;
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

    void CppFun::dumpVarDec(std::ostream& out, const int& indent) const
    {
        std::string ind = "";
        for (int i = 0; i < indent; i++) {
            ind = ind + "\t";
        }
        for (unsigned i = 0; i != _varList.size(); i++) {
            out << ind << "\t" << _varList[i] << "\n";
        }
        return;
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
        CppVarMap::iterator it = _curVarMap->find(n->getName());
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

        checkAndInsert(*_curVarMap, n->getName(), res);
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
        
        depthFirstTraverse(nptr);

        // Add var decl (no global states)
        for (auto it = _curVarMap->begin(); it != _curVarMap->end(); it++) {
          if (_states.find(it->first) == _states.end() &&
              _inputs.find(it->first) == _inputs.end() &&
              _unitpFuncVarMap.find(it->first) == _unitpFuncVarMap.end()
             ) {
              std::string code = it->second->def() + ";";
              _curFun->_varList.push_back(code);
          }
        }

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
        
        f->_ret = findVar(*(it->second), nptr->getName());
        ILA_ASSERT(f->retSet(), "Return not set.");
    }

    // Add a variable that should be update at the end of the function.
    void CppSimGen::addFunUpdate(CppFun* f, nptr_t lhs, nptr_t rhs)
    {
        if (lhs == NULL || rhs == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        
        CppVar* argL = findVar(*(it->second), lhs->getName());
        CppVar* argR = findVar(*(it->second), rhs->getName());

        f->_updates.push_back(std::make_pair(argL, argR));
    }

    // Add a variable that should be update at the end of the function.
    void CppSimGen::addFunUpdate(CppFun* f, nptr_t lhs, CppVar* rhs)
    {
        if (lhs == NULL || rhs == NULL) { return ; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }

        CppVar* argL = findVar(*(it->second), lhs->getName());

        f->_updates.push_back(std::make_pair(argL, rhs));
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
            code = "return " + f->_ret->use() + ";";
            f->addBody(code);
        } else {
            code = "return;";
            f->addBody(code);
        }
    }

    CppVar* CppSimGen::appFun(CppFun* appFun, CppFun* envFun)
    {
        auto it = _varInFun.find(envFun);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        _curVarMap = it->second;

        ILA_ASSERT(appFun->_ret != NULL, 
                appFun->_name + " return value not specified");
        CppVar* retVar = new CppVar(appFun->_ret);
        (*_curVarMap)[retVar->_name] = retVar;
        
        std::string code = retVar->def() + " = " + appFun->_name + "(";
        for (unsigned i = 0; i < appFun->_args.size(); i++) {
            code = code + ((i == 0) ? "" : ", ") + appFun->_args[i]->use();
        }
        code = code + ");";
        envFun->addBody(code);

        _curVarMap = NULL;
        return retVar;
    }

    // ---------------------------------------------------------------------- //
    // Export all code to the output stream.
    void CppSimGen::exportAllToFile(const std::string& fileName) const
    {
        std::ofstream out(fileName.c_str());
        ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");

        // Put common headers, type def, ...
        createCommon(out);

        // Put model headers, constant memory, uninterpreted function.
        genModel(out);

        // Model member functions.
        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            it->second->dumpDec(out, _modelName, 0);
            it->second->dumpVarDec(out, 0);
            it->second->dumpCode(out, 0);
        }

        out.close();
    }

    void CppSimGen::exportAllToDir(const std::string& dirName) const
    {
        std::vector<std::string> fileNames;

        std::string commonFile = "common.hpp";
        std::string modelHeader = _modelName + "_class.hpp";

        std::ofstream out;
        // Common headers
        out.open(dirName + "/" + commonFile.c_str()); 
        ILA_ASSERT(out.is_open(), "File " + commonFile + " not open.");
        createCommon(out);
        out.close();

        // Model headers
        out.open(dirName + "/" + modelHeader.c_str());
        ILA_ASSERT(out.is_open(), "File " + modelHeader + " not open.");
        out << "#include \"" << commonFile << "\"\n";
        genModel(out);
        out.close();

        // Update functions
        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            std::string fileName = dirName + "/subfun_" + it->first + ".cpp";
            out.open(fileName.c_str());
            ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");
            fileNames.push_back("subfun_" + it->first + ".cpp");

            out << "#include \"" << commonFile << "\"\n";
            out << "#include \"" << modelHeader << "\"\n\n";
            it->second->dumpDec(out, _modelName, 0);
            it->second->dumpVarDec(out, 0);
            it->second->dumpCode(out, 0);

            out.close();
        }

        out.open(dirName + "/funlist.txt");
        out << "SRCS =";
        for (unsigned i  = 0; i < fileNames.size(); i++) {
            out << " " << fileNames[i];
        }
        out << "\n";
        out.close();
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::createCommon(std::ostream& out) const
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

    }

    // ---------------------------------------------------------------------- //
    CppVar* CppSimGen::getBoolVarCpp(const BoolVar* n)
    {
        CppVar* var = new CppVar(n);
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
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            code = var->use() + " = !" + arg0->use() + ";";
            _curFun->addBody(code);
        //// Binary ////
        } else if (n->op >= BoolOp::Op::AND &&
                   n->op <= BoolOp::Op::DISTINCT) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
            if (n->op == BoolOp::Op::AND) {
                code = var->use() + " = " + 
                       arg0->use() + " && " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::OR) {
                code = var->use() + " = " + 
                       arg0->use() + " || " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::XOR) {
                code = var->use() + " = " + 
                       arg0->use() + " ^ " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::XNOR) {
                code = var->use() + " = !( " + 
                       arg0->use() + " ^ " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::NAND) {
                code = var->use() + " = !(" + 
                       arg0->use() + " && " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::NOR) {
                code = var->use() + " = !(" + 
                       arg0->use() + " || " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::IMPLY) {
                code = var->use() + " = !" + 
                       arg0->use() + " || " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::SLT) {
                code = var->use() + " = " + 
                       arg0->signedUse() + " < " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::SGT) {
                code = var->use() + " = " + 
                       arg0->signedUse() + " > " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::SLE) {
                code = var->use() + " = " + 
                       arg0->signedUse() + " <= " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::SGE) {
                code = var->use() + " = " + 
                       arg0->signedUse() + " >= " + arg1->signedUse() + ";";
            } else if (n->op == BoolOp::Op::ULT) {
                code = var->use() + " = " + 
                       arg0->use() + " < " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::UGT) {
                code = var->use() + " = " + 
                       arg0->use() + " > " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::ULE) {
                code = var->use() + " = " + 
                       arg0->use() + " <= " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::UGE) {
                code = var->use() + " = " + 
                       arg0->use() + " >= " + arg1->use() + ";";
            } else if (n->op == BoolOp::Op::EQUAL) {
                code = var->use() + " = (" + 
                       arg0->use() + " == " + arg1->use() + ");";
            } else if (n->op == BoolOp::Op::DISTINCT) {
                code = var->use() + " = (" + 
                       arg0->use() + " != " + arg1->use() + ");";
            }
            _curFun->addBody(code);
        //// Ternary ////
        } else if (n->op == BoolOp::Op::IF) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
            CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->getName());
            code = var->use() + " = " + arg0->use() + " ? " + 
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
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            if (n->op == BitvectorOp::Op::NEGATE) {
                code = var->use() + " = -" + arg0->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::COMPLEMENT) {
                code = var->use() + " = ~" + arg0->use() + ";";
            } else if (n->op == BitvectorOp::Op::LROTATE) {
                int par0 = n->param(0);
                int total = var->_width;
                std::string l = boost::lexical_cast<std::string>(par0);
                std::string r = boost::lexical_cast<std::string>(total-par0);
                // int var = x & 0xff
                // var = ((var << l) | (var >> r)) & 0xff
                code = var->use() + " = " + arg0->exactUse() + ";";
                _curFun->addBody(code);
                code = var->use() + " = ((" + 
                       var->use() + " << " + l + ") | ( " + 
                       var->use() + " >> " + r + ")) & " + 
                       getMask(var->_width) + ";";
            } else if (n->op == BitvectorOp::Op::RROTATE) {
                int par0 = n->param(0);
                int total = var->_width;
                std::string r = boost::lexical_cast<std::string>(par0);
                std::string l = boost::lexical_cast<std::string>(total-par0);
                // int var = x & 0xff
                // var = ((var << l) | (var >> r)) & 0xff
                code = var->use() + " = " + arg0->exactUse() + ";";
                _curFun->addBody(code);
                code = var->use() + " = ((" + 
                       var->use() + " << " + l + ") | ( " + 
                       var->use() + " >> " + r + ")) & " + 
                       getMask(var->_width) + ";";
            } else if (n->op == BitvectorOp::Op::Z_EXT) {
                code = var->use() + " = " + arg0->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::S_EXT) {
                code = var->use() + " = " + arg0->signedUse() + ";";
            } else if (n->op == BitvectorOp::Op::EXTRACT) {
                int msb = n->param(0);
                int lsb = n->param(1);
                std::string r = boost::lexical_cast<std::string>(lsb);
                // (x >> r) & 0xfff..(-r)
                code = var->use() + " = (" + arg0->use() + " >> " + r +
                       ") & " + getMask(msb-lsb+1) + ";";
            }
        //// Binary ////
        } else if (n->op >= BitvectorOp::Op::ADD &&
                   n->op <= BitvectorOp::Op::READMEM) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
            if (n->op == BitvectorOp::Op::ADD) {
                code = var->use() + " = " + 
                       arg0->use() + " + " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::SUB) {
                code = var->use() + " = " + 
                       arg0->use() + " - " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
//                code = getSignedCppCode(var);
            } else if (n->op == BitvectorOp::Op::AND) {
                code = var->use() + " = " + 
                       arg0->use() + " & " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::OR) {
                code = var->use() + " = " + 
                       arg0->use() + " | " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::XOR) {
                code = var->use() + " = " + 
                       arg0->use() + " ^ " + arg1->use() + ";";
            } else if (n->op == BitvectorOp::Op::XNOR) {
                code = var->use() + " = ~(" + 
                       arg0->use() + " ^ " + arg1->use() + ");";
            } else if (n->op == BitvectorOp::Op::NAND) {
                code = var->use() + " = ~(" + 
                       arg0->use() + " & " + arg1->use() + ");";
            } else if (n->op == BitvectorOp::Op::NOR) {
                code = var->use() + " = ~(" + 
                       arg0->use() + " | " + arg1->use() + ");";
            } else if (n->op == BitvectorOp::Op::SDIV) {
                code = var->use() + " = " + 
                       arg0->signedUse() + " / " + arg1->signedUse() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::UDIV) {
                code = var->use() + " = " + 
                       arg0->use() + " / " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::SREM) {
                code = var->use() + " = " + 
                       arg0->use() + " % " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::UREM) {
                code = var->use() + " = " + 
                       arg0->use() + " % " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::SMOD) {
                // FIXME C++ has no modulo operator, equal to % when positive
                code = var->use() + " = " + 
                       arg0->use() + " % " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::SHL) {
                code = var->use() + " = " + 
                       arg0->use() + " << " + arg1->castUse() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::LSHR) {
                code = var->use() + " = " + 
                       arg0->use() + " >> " + arg1->castUse() + ";";
            } else if (n->op == BitvectorOp::Op::ASHR) {
                code = var->use() + " = " + 
                       arg0->signedUse() + " >> " + arg1->castUse() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::MUL) {
                code = var->use() + " = " + 
                       arg0->use() + " * " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::CONCAT) {
                std::string w = boost::lexical_cast<std::string>(arg1->_width);
                // |arg0| << arg1.width | |arg1|
                code = var->use() + " = (" + 
                       arg0->use() + " << " + w + 
                       ") | " + arg1->use() + ";";
                _curFun->addBody(code);
                code = var->use() + " = " + var->exactUse() + ";";
            } else if (n->op == BitvectorOp::Op::GET_BIT) {
                code = var->use() + " = (" + 
                       arg0->use() + " >> " + arg1->castUse() + ") & 0x1;";
            } else if (n->op == BitvectorOp::Op::READMEM) {
                code = var->use() + " = " + 
                       arg0->use() + ".rd(" + arg1->use() + ");";
            }
        //// Ternary ////
        } else if (n->op == BitvectorOp::READMEMBLOCK) {
            ILA_ASSERT(n->nArgs() == 2, "Two parameters expected.");
            CppVar* mem = findVar(*_curVarMap, n->arg(0)->getName());
            CppVar* addr = findVar(*_curVarMap, n->arg(1)->getName());
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
            boost::format defFmt(
                "%1% = (%2%.rd(%3%) & %4%);");
            boost::format loopProlog(
                "for (int %1% = 1; %2% < %3%; %4%++) {");
            boost::format litFmt(
                "\t%1% = %2% | ((%3%.rd(%4% + %5%) & %6%) << (%7% * %8%));");
            boost::format bigFmt(
                "\t%1% = (%2% << %3%) | (%4%.rd(%5% + %6%) & %7%);");

            defFmt %var->use() %mem->use() %addr->use() %getMask(blxSize);
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

            code = var->use() + " = " + var->exactUse() + ";";
        } else if (n->op == BitvectorOp::Op::IF) {
            CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
            CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->getName());
            code = var->use() + " = (" + arg0->use() + ") ? " +
                   arg1->use() + " : " + arg2->use() + ";";
        } else if (n->op == BitvectorOp::Op::APPLY_FUNC) {
            CppVar* fun = findVar(*_curVarMap, n->arg(0)->getName());
            std::vector<CppVar*> argVec;
            for (unsigned i = 1; i != n->nArgs(); i++) {
                CppVar* arg = findVar(*_curVarMap, n->arg(i)->getName());
                argVec.push_back(arg);
            }
            code = var->use() + " = " + fun->use() + "(";
            for (unsigned i = 0; i != argVec.size(); i++) {
                code = code + ((i == 0)? "" : ", ") + argVec[i]->use();
            }
            code = code + ");";
        } else {
            ILA_ASSERT(false, "Unknown BitvectorOp.");
        }

        if (code != "") {
            _curFun->addBody(code);
        }
        return var;
    }

    CppVar* CppSimGen::getMemVarCpp(const MemVar* n)
    {
        CppVar* var = new CppVar(n);
        return var;
    }

    CppVar* CppSimGen::getMemConstCpp(const MemConst* n)
    {
        // Should update to _states and _curVarMap.
        CppVar* var = NULL;
        auto it = _states.find(n->getName());
        if (it != _states.end()) {
            var = it->second;
        } else {
            var = new CppVar(n);
            checkAndInsert(_states, n->getName(), var);
        }

        _memConst[var] = n;
        return var;
    }

    CppVar* CppSimGen::getMemOpCpp(const MemOp* n)
    {
        CppVar* var = NULL; 
        CppVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
        CppVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
        CppVar* arg2 = findVar(*_curVarMap, n->arg(2)->getName());

        std::string code = "MEM NOT IMPLEMENTED";
        if (n->op == MemOp::Op::STORE) {
            ILA_ASSERT(arg0->_type == CppVar::memStr, 
                       "Write to non-mem variable.");
            var = new CppVar(n);
            code = var->use() + " = " + arg0->use() + ";";
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
            //     chunk_i = chunk_i & 0xff
            //     var.wr(addr+i, chunk_i);
            // }
            //     little:
            //     chunk_i = data >> (i * chunkSize);
            //     big:
            //     chunk_i = data >> ((chunkNum - 1 - i) * chunkSize);

            CppVar* idx = new CppVar(32);
            CppVar* chunk_i = new CppVar(chunkSize);
            _curFun->addBody(chunk_i->def() + ";");
            _curFun->addBody(var->use() + " = " + arg0->use() + ";");

            boost::format loopProlog(
                "for (int %1% = 0; %2% < %3%; %4%++) {");
            boost::format litFmt(
                "\t%1% = %2% >> (%3% * %4%);");
            boost::format bigFmt(
                "\t%1% = %2% >> ((%3% - 1 - %4%) * %5%);");
            boost::format uniFmt(
                "\t%1% = %2%;");
            boost::format writeFmt(
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

            uniFmt     % chunk_i->use()         // 1
                       % chunk_i->exactUse();   // 2

            writeFmt   % var->use()             // 1
                       % arg1->use()            // 2
                       % idx->use()             // 3
                       % chunk_i->use();        // 4

            _curFun->addBody(loopProlog.str());
            _curFun->addBody(isLittle ? litFmt.str() : bigFmt.str());
            _curFun->addBody(uniFmt.str());
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
        
    bool CppSimGen::isITE(nptr_t n)
    {
        const BoolOp* boolop = NULL;
        const BitvectorOp* bvop = NULL;
        const MemOp* memop = NULL;

        if ((boolop = dynamic_cast<const BoolOp*>(n.get()))) {
            return (boolop->op == BoolOp::Op::IF);
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n.get()))) {
            return (bvop->op == BitvectorOp::Op::IF);
        } else if ((memop = dynamic_cast<const MemOp*>(n.get()))) {
            return (memop->op == MemOp::Op::ITE);
        } else {
            return false;
        }
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
        out << "\ttype_mem(" << bvStr << " def"<< ", unsigned addrw, unsigned dataw)\n";
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
        out << "\n";
        out << "\tbool operator == (type_mem targ)\n";
        out << "\t{\n";
        out << "\t\treturn (_map == targ._map) & (_def_val == targ._def_val);\n";
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
    void CppSimGen::genModel(std::ostream& out) const
    {
        out << "\n/****************************************************/\n";
        out << "#ifndef " << boost::to_upper_copy<std::string>(_modelName) 
            << "_CLASS\n";
        out << "#define " << boost::to_upper_copy<std::string>(_modelName) 
            << "_CLASS\n";

        defUnitpFunc(out);

        // Model class prolog
        out << "class " <<  _modelName << "\n" 
            << "{\n";
        
        // Constructor/destructor
        out << "public:\n"
            << "\t" << _modelName << "():\n";

        bool firstLineFlag = true;
        for (auto it = _states.begin(); it != _states.end(); it ++ ) {
            if(it->second->ctorDef() == "" ) // if no ctor needed
                continue;
            if(firstLineFlag) 
                firstLineFlag = false;
            else
                out <<",\n" ;
            out << "\t" << it->second->ctorDef();
            
        }
        out << "\n" "\t{\n";
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
        }
        // Model class epilog
        out << "\n};\n";

        setMemConst(out);
        out << "#endif\n";
        out << "/****************************************************/\n";
    }

    void CppSimGen::defUnitpFunc(std::ostream& out) const
    {
        for (auto it = _unitpFuncMap.begin(); it != _unitpFuncMap.end(); it++) {
            out << "extern ";
            it->second->dumpDec(out, "", 0);
        }
    }

    // ---------------------------------------------------------------------- //
    void CppSimGen::depthFirstTraverse(nptr_t node)
    {
        CppVarMap::iterator it = _curVarMap->find(node->getName());
        if (it != _curVarMap->end()) {
            return;
        }

        if (!isITE(node)) {
            unsigned n = node->nArgs();
            for (unsigned i = 0; i != n; i++) {
                const nptr_t arg_i = node->arg(i);
                depthFirstTraverse(arg_i);
            }
            (*this)(node.get());
        } else {
            ILA_ASSERT(node->nArgs() == 3, "ITE should have 3 args");

            CppVar* var = new CppVar(node);

            // condition
            depthFirstTraverse(node->arg(0));
            CppVar* cond = findVar(*_curVarMap, node->arg(0)->getName());
            std::string condCode = "if (" + cond->use() + ") {";
            _curFun->addBody(condCode);

            // then
            depthFirstTraverse(node->arg(1));
            CppVar* tExp = findVar(*_curVarMap, node->arg(1)->getName());
            std::string thenCode = var->use() + " = " + tExp->use() + ";";
            _curFun->addBody(thenCode);

            // else
            _curFun->addBody("} else {");
            depthFirstTraverse(node->arg(2));
            CppVar* fExp = findVar(*_curVarMap, node->arg(2)->getName());
            std::string elseCode = var->use() + " = " + fExp->use() + ";";
            _curFun->addBody(elseCode);
            _curFun->addBody("}");

            checkAndInsert(*_curVarMap, node->getName(), var);
            _curVar = var;
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
        boost::format signUseFmt(
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

        boost::format unMaskStr("((%1%)1 << %2%) - 1");
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

    static std::string getSignBit(const int& width)
    {
        ILA_ASSERT(width > 0, "Negative width.");
        std::string str = "(" + CppVar::bvStr + ")1 << (" + 
            boost::lexical_cast<std::string>(width) + " - 1)";
        auto it = maskPtr->find(str);
        if (it == maskPtr->end()) {
            std::string name = "bit_"+boost::lexical_cast<std::string>(width);
            CppVar* var = new CppVar(name, str);
            (*maskPtr)[str] = var;
            return var->use();
        } else {
            return it->second->use();
        }
        return str;
    }

}
