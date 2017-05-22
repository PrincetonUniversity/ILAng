#include <genCBMC.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <bitset>
#include <cmath>
#include <algorithm>

namespace ila
{


    static std::string getMask(const int& width);
    static std::string getSignExtMask(const int& width);
    static std::string getSignBit(const int& width);
    static CVerifGen::CVarMap* maskPtr = NULL;
    // ---------------------------------------------------------------------- //
    int CVar::varCnt = 0;

    std::string CVar::boolStr  = "bool";
    std::string CVar::bvStr    = "BIT_VEC";
    std::string CVar::memStr   = "type_mem";
    std::string CVar::voidStr  = "void";

    // ---------------------------------------------------------------------- //
    CVar::CVar(nptr_t nptr, const std::string& name)
    {
        init(nptr);
        if (name != "") _name = name;
    }

    CVar::CVar(const Node* node, const std::string& name)
    {
        init(node);
        if (name != "") _name = name;
    }

    CVar::CVar(int width)
    {
        memberVar = false;
        _type = bvStr;
        _width = width;
        _name = "cVar_" + boost::lexical_cast<std::string>(varCnt++);
        _isConst = false;
    }

    CVar::CVar(const std::string& name, const std::string& val)
        : _val(val), memberVar(false)
    {
        _name = "cMask_" + name + "_";
        _type = bvStr;
        _isConst = false;
    }

    CVar::CVar(const CVar* var)
        : _type(var->_type)
        , _width(var->_width)
        , _idxWidth(var->_idxWidth)
        , memberVar(var->memberVar)
    {
        _name = "cVar_" + boost::lexical_cast<std::string>(varCnt++);
        _isConst = var->_isConst;
        _val = var->_val;
    }

    CVar::~CVar()
    {
    }

    // ---------------------------------------------------------------------- //

    std::string CVar::memdef() const
    {
        ILA_ASSERT(_type == memStr, "cannot generate memdef of non-mem variable");
        return  "( " + ctype() + " ) malloc( sizeof(BV" + boost::lexical_cast<std::string>(_width)  + ") * " +
            boost::lexical_cast<std::string>( std::pow( 2, _idxWidth ) ) + " )" ;
    }
    std::string CVar::ctype() const // only for def
    {
        
        if (_type != memStr)
            return _type;
        else
            return  "BV" + boost::lexical_cast<std::string>(_width)  + " *"; 
    }

    std::string CVar::def() const
    {
        if (_name != "") {
            if(_type == memStr)
                return (ctype() + " " + _name);
            return (_type + " " + _name);
        } else {
            return (_type);
        }
    }

    std::string CVar::refDef() const
    {
        return (_type + "& " + _name);
    }

    std::string CVar::use() const
    {
        if (_isConst) {
            return _val;
        } else {
            if (!memberVar)
                return _name;
            return "( this-> "+_name + " )";
        }
    }

    std::string CVar::exactUse() const
    {
        ILA_ASSERT(_type == bvStr, "Wrong type");
        if (_isConst) {
            return _val;
        } else {
            return ("(" + _name + " & " + getMask(_width) + ")");
        }
    }

    std::string CVar::signedUse() const
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

    std::string CVar::castUse() const
    {
        ILA_ASSERT(_type == bvStr, "Wrong type");
        if (_isConst) {
            return _val;
        } else {
            return ("static_cast<unsigned>(" + _name + ")");
        }
    }
    // ---------------------------------------------------------------------- //
    void CVar::init(nptr_t n)
    {
        init(n.get());
    }

    void CVar::init(const Node* n)
    {
        memberVar = false;
        _name = "cVar_" + boost::lexical_cast<std::string>(varCnt++);
        if (n->type.isBool()) {
            _type = boolStr;
            _width = 0;
        } else if (n->type.isBitvector()) {
            _type = bvStr;
            _width = n->type.bitWidth;
        } else if (n->type.isMem()) {
            _type = memStr;
            _width = n->type.dataWidth;
            _idxWidth = n->type.addrWidth;
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
    CFun::CFun(const std::string& name)
        : _name(name)
    {
        _ret = NULL;
    }

    CFun::~CFun()
    {
    }

    // ---------------------------------------------------------------------- //
    void CFun::addArg(const CVar* arg)
    {
        _args.push_back(arg);
    }

    void CFun::addBody(const std::string& code)
    {
        _codeList.push_back(code);
    }
        
    // ---------------------------------------------------------------------- //
    // Print the function header outside the class to the output stream. (also uninterpreted functions)
    void CFun::dumpDec(std::ostream& out,
                          const std::string& modelName,
                          const int& indent, bool decl) const
    {
        std::string ind = "";
        for (int i = 0; i < indent; i++) {
            ind = ind + "\t";
        }

        std::string type = (_ret != NULL) ? _ret->_type : CVar::voidStr;
        std::string name = (modelName == "") ?  // it is an uninterpreted function ?
                           _name : (_name);//_name : (modelName + "::" + _name);
        std::string tail = (modelName == "" || decl) ? ");\n" : (")\n" + ind + "{\n");
                           
        out << ind << type << " " << name << "(";
        bool hasThis = false;
        if(modelName != "") {
            out << "struct " + modelName + "* this";
            hasThis = true;
        }
        for (unsigned i = 0; i<_args.size(); i++) {
            out << ((i == 0 && !hasThis)? "" : ", ") << _args[i]->def();
        }
        out << tail;
    }

    void CFun::dumpCode(std::ostream& out, const int& indent) const
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

    void CFun::dumpVarDec(std::ostream& out, const int& indent) const
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
    CVerifGen::CVerifGen(const std::string& prefix)
        : _modelName("model_" + prefix)
    {
    }

    CVerifGen::~CVerifGen()
    {
    }

    // ---------------------------------------------------------------------- //
    CVar* CVerifGen::addInput(const std::string& name, nptr_t nptr, bool ms)
    {
        // FIXME Need to make sure name is valid.
        CVar* ip = new CVar(nptr, name);
        checkAndInsert(_inputs, name, ip, ms);
        return ip;
    }

    CVar* CVerifGen::addState(const std::string& name, nptr_t nptr, bool ms)
    {
        // FIXME Need to make sure name is valid.
        CVar* var = new CVar(nptr, name);   
        var->memberVar = true;
        checkAndInsert(_states, name, var, ms);
        return var;
    }

    CFun* CVerifGen::addFun(const std::string& name, bool ms)
    {
        // Create new fun and put it in funMap.
        CFun* fun = new CFun(name);
        checkAndInsert(_funMap, name, fun, ms);
        // Insert inputs and global state into the function's varmap
        // Also set the input as fun's arguments.
        CVarMap* varMap = new CVarMap;
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

    CVar* CVerifGen::addFuncVar(const std::string& name, nptr_t node, bool ms)
    {
        CVar* var = new CVar(node, name);   
        checkAndInsert(_unitpFuncVarMap, name, var, ms);

        CFun* fun = new CFun(name);
        fun->_ret = new CVar(node->type.bitWidth);
        for (unsigned i = 0; i != node->type.argsWidth.size(); i++) {
            CVar* arg = new CVar(node->type.argsWidth[i]);
            fun->_args.push_back(arg);
        }
        checkAndInsert(_unitpFuncMap, name, fun, ms);
        return var;
    }

    // ---------------------------------------------------------------------- //
    void CVerifGen::operator() (const Node* n)
    {
        CVarMap::iterator it = _curVarMap->find(n->getName());
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

        CVar* res = NULL;

        //// Bool ////
        if ((boolvar = dynamic_cast<const BoolVar*>(n))) {
            res = getBoolVarC(boolvar);
        } else if ((boolconst = dynamic_cast<const BoolConst*>(n))) {
            res = getBoolConstC(boolconst);
            _localConstVar[n->getName()] = res;
        } else if ((boolop = dynamic_cast<const BoolOp*>(n))) {
            res = getBoolOpC(boolop);
        //// Bitvector ////
        } else if ((bvvar = dynamic_cast<const BitvectorVar*>(n))) {
            res = getBvVarC(bvvar);
        } else if ((bvconst = dynamic_cast<const BitvectorConst*>(n))) {
            res = getBvConstC(bvconst);
            _localConstVar[n->getName()] = res;
        } else if ((bvop = dynamic_cast<const BitvectorOp*>(n))) {
            res = getBvOpC(bvop);
        //// Mem ////
        } else if ((memvar = dynamic_cast<const MemVar*>(n))) {
            res = getMemVarC(memvar);
        } else if ((memconst = dynamic_cast<const MemConst*>(n))) {
            res = getMemConstC(memconst);
        } else if ((memop = dynamic_cast<const MemOp*>(n))) {
            res = getMemOpC(memop);
        //// Func ////
        } else if ((funcvar = dynamic_cast<const FuncVar*>(n))) {
            res = getFuncVarC(funcvar);
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
    void CVerifGen::buildFun(CFun* f, nptr_t nptr)
    {
        if (nptr == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        _curVarMap = it->second;
        _curFun = f;
        maskPtr = &_masks;
        _localConstVar.clear();
        
        depthFirstTraverse(nptr);

        // Add var decl (no global states)
        for (auto it = _curVarMap->begin(); it != _curVarMap->end(); it++) {
          if (_states.find(it->first) == _states.end() &&
              _inputs.find(it->first) == _inputs.end() && 
              _unitpFuncVarMap.find(it->first) == _unitpFuncVarMap.end() &&
              _localConstVar.find(it->first) == _localConstVar.end()
              ) {
                std::string code;
                if(it->second->_type == CVar::memStr) {
                    code = it->second->def() + " = " + it->second->memdef() + ";"; // define of variables, for memory need to take care of
                    _localArray[it->first] = it->second; // record and later may need to free it if it is not the return variable
                }
                else
                    code = it->second->def() + ";";  // define of variables
                //don't insert the same if you export to a single file (in a single update fun)
                if(std::find(_curFun->_varList.begin(),_curFun->_varList.end(),code) == _curFun->_varList.end())
                    _curFun->_varList.push_back(code);
                //else
                //    std::cout<<"red:"<<code<<std::endl;
          }
        }

        _curVarMap = NULL;
        _curFun = NULL;
        return;
    }

    // Set the return variable for the function.
    void CVerifGen::setFunReturn(CFun* f, nptr_t nptr)
    {
        if (nptr == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        
        f->_ret = findVar(*(it->second), nptr->getName());
        ILA_ASSERT(f->retSet(), "Return not set.");

        // now let's clean the _localArray
        for (auto it = _localArray.begin(); it != _localArray.end(); ++it ) {
            if( nptr->getName() == it->first ) // don't free the return variable
                continue;
            std::string code = "free( " + it->second->use() + " );";
            f->addBody(code);
        }
        _localArray.clear();
    }

    // Terminate the function building.
    void CVerifGen::endFun(CFun* f)
    {
        std::string code = "NOT SPECIFIED";
        // Update the states.
        for (unsigned i = 0; i < f->_updates.size(); i++) {
            if(f->_updates[i].first->_type == CVar::memStr) {
                code = "__CPROVER_array_copy( " + f->_updates[i].first->use() + "," +
                       f->_updates[i].second->use() + " );";
                f->addBody(code);
                code = "free( " + f->_updates[i].second->use() +" );";
                f->addBody(code);
            }
            else {
                code = f->_updates[i].first->use() + " = " + 
                       f->_updates[i].second->use() + ";";
                f->addBody(code);
            }
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
    // Add a variable that should be update at the end of the function.
    void CVerifGen::addFunUpdate(CFun* f, nptr_t lhs, nptr_t rhs)
    {
        if (lhs == NULL || rhs == NULL) { return; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        
        CVar* argL = findVar(*(it->second), lhs->getName());
        CVar* argR = findVar(*(it->second), rhs->getName());

        f->_updates.push_back(std::make_pair(argL, argR));
    }

    // Add a variable that should be update at the end of the function.
    void CVerifGen::addFunUpdate(CFun* f, nptr_t lhs, CVar* rhs)
    {
        if (lhs == NULL || rhs == NULL) { return ; }
        auto it = _varInFun.find(f);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }

        CVar* argL = findVar(*(it->second), lhs->getName());

        f->_updates.push_back(std::make_pair(argL, rhs));
    }


    CVar* CVerifGen::appFun(CFun* appFun, CFun* envFun)
    {
        auto it = _varInFun.find(envFun);
        if (it == _varInFun.end()) {
            ILA_ASSERT(false, "Function not defined yet.");
        }
        _curVarMap = it->second;

        ILA_ASSERT(appFun->_ret != NULL, 
                appFun->_name + " return value not specified");
        CVar* retVar = new CVar(appFun->_ret); // FIXME: NOTE: no allocation is needed
        (*_curVarMap)[retVar->_name] = retVar;
        
        std::string code = retVar->def() + " = " + appFun->_name + "( this";  // FIXME: need to add its struct's name
        for (unsigned i = 0; i < appFun->_args.size(); i++) {
            code = code + (", ") + appFun->_args[i]->use();
        }
        code = code + ");";
        envFun->addBody(code);

        _curVarMap = NULL;
        return retVar;
    }

    // ---------------------------------------------------------------------- //
    // Export all code to the output stream.
    void CVerifGen::exportAllToFile(const std::string& fileName) const
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

    void CVerifGen::exportAllToDir(const std::string& dirName) const
    {
        std::vector<std::string> fileNames;

        std::string commonFile = "common.h";
        std::string modelHeader = _modelName + "_class.h";

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
            std::string fileName = dirName + "/subfun_" + it->first + ".c";
            out.open(fileName.c_str());
            ILA_ASSERT(out.is_open(), "File " + fileName + " not open.");
            fileNames.push_back("subfun_" + it->first + ".c");

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
    void CVerifGen::createCommon(std::ostream& out) const
    {
        // Include headers
        out << "#include <stdint.h>\n";

        // type define
        out << "\n";
        out << "#ifndef CPP_BITVEC_TYPE\n";
        out << "#define CPP_BITVEC_TYPE\n";
        out << "typedef uint64_t " 
            << CVar::bvStr << ";\n";
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
    CVar* CVerifGen::getBoolVarC(const BoolVar* n)
    {
        CVar* var = new CVar(n);
        var->memberVar = true;
        return var;
    }

    CVar* CVerifGen::getBoolConstC(const BoolConst* n)
    {
        CVar* var = new CVar(n);
        return var;
    }

    CVar* CVerifGen::getBoolOpC(const BoolOp* n)
    {
        CVar* var = new CVar(n);
        std::string code = "boolOp NOT IMPLEMENTED";
        //// Unary ////
        if (n->op == BoolOp::Op::NOT) {
            CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            code = var->use() + " = !" + arg0->use() + ";";
            _curFun->addBody(code);
        //// Binary ////
        } else if (n->op >= BoolOp::Op::AND &&
                   n->op <= BoolOp::Op::DISTINCT) {
            CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
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
            CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
            CVar* arg2 = findVar(*_curVarMap, n->arg(2)->getName());
            code = var->use() + " = " + arg0->use() + " ? " + 
                   arg1->use() + " : " + arg2->use() + ";";
            _curFun->addBody(code);
        } else {
            ILA_ASSERT(false, "Unknown bool op.");
        }
        return var;
    }

    CVar* CVerifGen::getBvVarC(const BitvectorVar* n)
    {
        CVar* var = new CVar(n);
        var->memberVar = true;
        return var;
    }

    CVar* CVerifGen::getBvConstC(const BitvectorConst* n)
    {
        CVar* var = new CVar(n);
        return var;
    }

    CVar* CVerifGen::getBvOpC(const BitvectorOp* n)
    {
        CVar* var = new CVar(n);
        std::string code = "bvOp NOT IMPLEMENTED.";
        //// Unary ////
        if (n->op >= BitvectorOp::Op::NEGATE && 
            n->op <= BitvectorOp::Op::EXTRACT) {
            CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
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
            CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
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
//                code = getSignedCCode(var);
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
                       arg0->use() + "[" + arg1->use() + "];";
            }
        //// Ternary ////
        } else if (n->op == BitvectorOp::READMEMBLOCK) {
            ILA_ASSERT(n->nArgs() == 2, "Two parameters expected.");
            CVar* mem = findVar(*_curVarMap, n->arg(0)->getName());
            CVar* addr = findVar(*_curVarMap, n->arg(1)->getName());
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
                "%1% = (%2%[%3%] & %4%);");
            boost::format loopProlog(
                "for (int %1% = 1; %2% < %3%; %4%++) {");
            boost::format litFmt(
                "\t%1% = %2% | ((%3%[%4% + %5%] & %6%) << (%7% * %8%));");
            boost::format bigFmt(
                "\t%1% = (%2% << %3%) | (%4%[%5% + %6%] & %7%);");

            defFmt %var->use() %mem->use() %addr->use() %getMask(blxSize);
            _curFun->addBody(defFmt.str());

            CVar* idx = new CVar(32);
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
            CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
            CVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
            CVar* arg2 = findVar(*_curVarMap, n->arg(2)->getName());
            code = var->use() + " = (" + arg0->use() + ") ? " +
                   arg1->use() + " : " + arg2->use() + ";";
        } else if (n->op == BitvectorOp::Op::APPLY_FUNC) {
            CVar* fun = findVar(*_curVarMap, n->arg(0)->getName());
            std::vector<CVar*> argVec;
            for (unsigned i = 1; i != n->nArgs(); i++) {
                CVar* arg = findVar(*_curVarMap, n->arg(i)->getName());
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

    CVar* CVerifGen::getMemVarC(const MemVar* n)
    {
        CVar* var = new CVar(n);
        var->memberVar = true;
        return var;
    }

    CVar* CVerifGen::getMemConstC(const MemConst* n)
    {
        // Should update to _states and _curVarMap.
        CVar* var = NULL;
        auto it = _states.find(n->getName());
        if (it != _states.end()) {
            var = it->second;
        } else {
            var = new CVar(n);
            checkAndInsert(_states, n->getName(), var);
        }

        _memConst[var] = n;
        return var;
    }

    CVar* CVerifGen::getMemOpC(const MemOp* n) // FIXME: need to change
    {
        CVar* var = NULL; 
        CVar* arg0 = findVar(*_curVarMap, n->arg(0)->getName());
        CVar* arg1 = findVar(*_curVarMap, n->arg(1)->getName());
        CVar* arg2 = findVar(*_curVarMap, n->arg(2)->getName());

        std::string code = "MEM NOT IMPLEMENTED";
        if (n->op == MemOp::Op::STORE) {
            ILA_ASSERT(arg0->_type == CVar::memStr, 
                       "Write to non-mem variable.");
            var = new CVar(n);
            code = var->use() + " = " + var->memdef() + ";";
            _curFun->addBody(code);
            //code = var->use() + " = " + arg0->use() + ";";
            code = "__CPROVER_array_copy( " + var->use() + " , " +  arg0->use() + " );";
            _curFun->addBody(code);
            code = var->use() + "[" + arg1->use() + 
                   "] = ( " + arg2->use() + " );";
        } else if (n->op == MemOp::Op::ITE) {
            ILA_ASSERT(arg0->_type == CVar::boolStr,
                       "Condition not bool.");
            var = new CVar(n);
            code = var->use() + " = " + var->memdef() + ";";
            _curFun->addBody(code);

            boost::format memite(
                "if(%1%) \n\t__CPROVER_array_copy( %2% ,  %3%); \nelse\n\t__CPROVER_array_copy( %2% ,  %4%);");

            memite  % arg0->use() 
                    % var->use()
                    % arg1->use()
                    % arg2->use();

            code = memite.str();

        } else if (n->op == MemOp::Op::STOREBLOCK) {
            ILA_ASSERT(arg0->_type == CVar::memStr,
                        "Write to non-mem variable.");
            var = new CVar(n);
            code = var->use() + " = " + var->memdef() + ";";
            _curFun->addBody(code);

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

            CVar* idx = new CVar(32);
            CVar* chunk_i = new CVar(chunkSize);
            _curFun->addBody(chunk_i->def() + ";");
            code = "__CPROVER_array_copy( " + var->use() + " , " +  arg0->use() + " );";
            _curFun->addBody(code);
            //_curFun->addBody(var->use() + " = " + arg0->use() + ";");

            boost::format loopProlog(
                "for (int %1% = 0; %2% < %3%; %4%++) {");
            boost::format litFmt(
                "\t%1% = %2% >> (%3% * %4%);");
            boost::format bigFmt(
                "\t%1% = %2% >> ((%3% - 1 - %4%) * %5%);");
            boost::format uniFmt(
                "\t%1% = %2%;");
            boost::format writeFmt(
                "\t%1%[%2% + %3%] =(%4%);");

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

    CVar* CVerifGen::getFuncVarC(const FuncVar* n)
    {
        CVar* var = new CVar(n);
        return var;
    }
        
    bool CVerifGen::isITE(nptr_t n)
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
    void CVerifGen::defMemClass(std::ostream& out) const
    {
        std::string bvStr = CVar::bvStr;
        out<<"typedef unsigned char BV1;\n";
        out<<"typedef unsigned char BV8;\n";
        out<<"typedef unsigned short BV16;\n";
        out<<"typedef uint32_t BV32;\n";
        out<<"typedef uint64_t BV64;\n";
    }

    // ---------------------------------------------------------------------- //
    void CVerifGen::setMemConst(std::ostream& out) const
    {
        out << "\n/****************************************************/\n";
        for (auto it = _memConst.begin(); it != _memConst.end(); it++) {
            out << "\n";
            out << _modelName << "::" <<  it->first->use() << ".setDef(" 
                << it->second->memvalues.def_value << ");\n";
            for (auto p : it->second->memvalues.values) {
                out << it->first->use() 
                    << "[" << p.first << "] = ( " << p.second << ");\n";
            }
        }
        out << "/****************************************************/\n";
    }

    // ---------------------------------------------------------------------- //
    void CVerifGen::genModel(std::ostream& out) const
    {
        out << "\n/****************************************************/\n";
        out << "#ifndef " << boost::to_upper_copy<std::string>(_modelName) 
            << "_CLASS\n";
        out << "#define " << boost::to_upper_copy<std::string>(_modelName) 
            << "_CLASS\n";

        defUnitpFunc(out);

        // Model struct prolog
        out << "struct " <<  _modelName << "\n" 
            << "{\n";
        
        // States variables
        out << "\t// State variables.\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            out << "\t" << it->second->def() << ";\n";
        }
        // Model struct epilog
        out << "\n};\n";

        // Bit masks
        out << "\t// Bitvector masks.\n"; // let's make it global
        for (auto it = _masks.begin(); it != _masks.end(); it++) {
            out << it->second->def() <<  " = " <<  it->second->_val << ";\n";
        }


        // Constructor/destructor should be put in a separate file
        out << "void " << _modelName << "_init( struct "<<  _modelName <<" * this ) {\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            if(it->second->_type == CVar::memStr)
                out << "\t" + it->second->use() + " = " + it->second->memdef() + ";\n";
        }
        out << "};\n";

        out << "" << _modelName << "_destroy( struct "<<  _modelName <<" * this ) {\n";
        for (auto it = _states.begin(); it != _states.end(); it++) {
            if(it->second->_type == CVar::memStr)
                out << "\tfree( " + it->second->use() + " );\n";
        }
        out << "};\n";


        // Public: functions (fetch, decode, update ... etc.)
        out << "\t// Public functions: fetch, decode, update, ...\n";
        for (auto it = _funMap.begin(); it != _funMap.end(); it++) {
            it->second->dumpDec(out, _modelName, 0, true);  // even we give modelname, we still want it to be only declaration not definition
        }

        //setMemConst(out);
        out << "#endif\n";
        out << "/****************************************************/\n";
    }

    void CVerifGen::defUnitpFunc(std::ostream& out) const
    {
        for (auto it = _unitpFuncMap.begin(); it != _unitpFuncMap.end(); it++) {
            out << "extern ";
            it->second->dumpDec(out, "", 0);
        }
    }

    // ---------------------------------------------------------------------- //
    void CVerifGen::depthFirstTraverse(nptr_t node)
    {
        CVarMap::iterator it = _curVarMap->find(node->getName());
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

            CVar* var = new CVar(node);

            // condition
            depthFirstTraverse(node->arg(0));
            CVar* cond = findVar(*_curVarMap, node->arg(0)->getName());
            std::string condCode = "if (" + cond->use() + ") {";
            _curFun->addBody(condCode);

            // then
            depthFirstTraverse(node->arg(1));
            CVar* tExp = findVar(*_curVarMap, node->arg(1)->getName());
            std::string thenCode = var->use() + " = " + tExp->use() + ";";
            _curFun->addBody(thenCode);

            // else
            _curFun->addBody("} else {");
            depthFirstTraverse(node->arg(2));
            CVar* fExp = findVar(*_curVarMap, node->arg(2)->getName());
            std::string elseCode = var->use() + " = " + fExp->use() + ";";
            _curFun->addBody(elseCode);
            _curFun->addBody("}");

            checkAndInsert(*_curVarMap, node->getName(), var);
            _curVar = var;
        }
    }

    // ---------------------------------------------------------------------- //
    std::string CVerifGen::getSignedCCode(CVar* var)
    {
        static std::string signTempVarName = "c_signTempVar";
        static std::string unsignTempVarName = "c_unsignTempVar";
        CVar* signTempVar = NULL;
        CVar* unsignTempVar = NULL;
        std::string signStr;
        std::string unsignStr;

        auto signIt = _curVarMap->find(signTempVarName);
        if (signIt == _curVarMap->end()) {
            signTempVar = new CVar(32);
            unsignTempVar = new CVar(32);
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
    void CVerifGen::checkAndInsert(std::map<std::string, T*>& mp,
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

    CVar* CVerifGen::findVar(CVarMap& mp, const std::string& name)
    {
        auto it = mp.find(name);
        ILA_ASSERT(it != mp.end(), "Variable " + name + " not defined yet.");
        return it->second;
    }

    static std::string getMask(const int& width)
    {
        ILA_ASSERT(width > 0, "Negative width.");

        boost::format unMaskStr("((%1%)1 << %2%) - 1");
        unMaskStr % CVar::bvStr
                  % width;
        std::string val = unMaskStr.str();

        auto it = maskPtr->find(val);
        if (it == maskPtr->end()) {
            std::string name = "un_"+boost::lexical_cast<std::string>(width);
            CVar* var = new CVar(name, val);
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
            CVar* var = new CVar(name, str);
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
        std::string str = "(" + CVar::bvStr + ")1 << (" + 
            boost::lexical_cast<std::string>(width) + " - 1)";
        auto it = maskPtr->find(str);
        if (it == maskPtr->end()) {
            std::string name = "bit_"+boost::lexical_cast<std::string>(width);
            CVar* var = new CVar(name, str);
            (*maskPtr)[str] = var;
            return var->use();
        } else {
            return it->second->use();
        }
        return str;
    }

}
