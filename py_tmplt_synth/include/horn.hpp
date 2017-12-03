#ifndef __HORN_HPP_DEFINED__
#define __HORN_HPP_DEFINED__

#include <string>
#include <map>
#include <set>

#include <type.hpp>
#include <ast.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    class HornVar;
    class HornLiteral;
    class HornClause;
    class HornDB;
    class HornTranslator;

    typedef HornVar*     hvptr_t;
    typedef HornLiteral* hlptr_t;
    typedef HornClause*  hcptr_t;

    // ---------------------------------------------------------------------- //
    class HornVar
    {
    private:
        // var id.
        unsigned _id;
        // var name.
        std::string _name;
        // var type.
        std::string _type;
        // constraint for var.
        std::set <std::string> _exec;
        // set of input (dependent) vars.
        std::map <std::string, hvptr_t> _ins;
        // set of output vars.
        std::set <hvptr_t> _outs;
        // var is const.
        bool _const;
        // var level.
        int _lvl;
        // non-deterministic value.
        std::string _nd;

    public:
        // ctor.
        HornVar (const unsigned& id);
        // dtor.
        virtual ~HornVar ();

        // ------------------------------------------------------------------ //
        // get var id.
        const unsigned& getId () const;
        // get var name.
        const std::string& getName () const;
        // get var type.
        const std::string& getType () const;
        // get var execution constraints.
        const std::set <std::string>& getExec () const;
        // get var predicate.
        std::string getPred () const;
        // get var relation.
        std::string getRel () const;
        // check if is constant.
        bool isConst () const;

        // ------------------------------------------------------------------ //
        // set var name.
        void setName (std::string s);
        // set var type.
        void setType (std::string s);
        // set constraints for var execution.
        void setExec (std::string s);
        // erase execution.
        void eraseExec ();
        // add dependent input var.
        void addInVar (hvptr_t v);
        // add output var.
        void addOutVar (hvptr_t v);
        // merge dependent input vars.
        void mergeInVars (hvptr_t v);
        // merge output vars.
        void mergeOutVars (hvptr_t v);
        // set to be constant.
        void setConst ();
        // get var level.
        const int& getLevel () const;
        // set var level.
        void setLevel (const int& lvl);
        // get the number of input vars.
        size_t getInNum () const;
        // get the number of output vars.
        size_t getOutNum () const;
        // get the input var set.
        const std::map <std::string, hvptr_t>& getInSet () const;
        // get the output var set.
        const std::set <hvptr_t>& getOutSet () const;
        // get the first output var.
        hvptr_t getOutVar () const;

        // ------------------------------------------------------------------ //
        // set non-deterministic value.
        void setNd (const std::string& nd);
        // get non-deterministic value.
        const std::string& getNd () const;
        // check if is nd.
        bool isNd () const;
    };

    // ---------------------------------------------------------------------- //
    class HornLiteral
    {
    private:
        // var of the literal.
        hvptr_t _var;
        // sign of the literal.
        bool _sign;
        // the literal is a relation, else, a constraint.
        bool _rel;

    public:
        // ctor.
        HornLiteral (hvptr_t v, bool r = false, bool s = true);
        // dotr.
        virtual ~HornLiteral ();

        // ------------------------------------------------------------------ //
        // get the predicate, with sign considered.
        std::string getPred () const;
        // get the set of execution, with sign considered.
        std::set <std::string> getExec () const;
        // get the var.
        hvptr_t getVar () const;
        // get the sign.
        bool getSign () const;
        // check if it is a predicate.
        bool isRel () const;
    };

    // ---------------------------------------------------------------------- //
    class HornClause
    {
    private:
        // horn clause body.
        std::set <hlptr_t> _body;
        // horn clause head.
        hlptr_t _head;

    public:
        // ctor.
        HornClause ();
        // dtor.
        virtual ~HornClause ();

        // ------------------------------------------------------------------ //
        // add one literal to the body.
        void addBody (hlptr_t l);
        // set the literal to the head.
        void setHead (hlptr_t l);

        // ------------------------------------------------------------------ //
        // output the clause to stream.
        void print (std::ostream& out);
    };

    // ---------------------------------------------------------------------- //
    class HornRewriter
    {
    private:
        // translator
        HornTranslator* _tr;
        // predicate
        hvptr_t _pred;
        // var mapping from predicate input var to state.
        std::map <hvptr_t, std::string> _mapIS;
        // var mapping from predicate output var to state.
        std::map <hvptr_t, std::string> _mapOS;
        // var mapping from state to input.
        std::map <std::string, hvptr_t> _mapSI;
        // var mapping from state to output.
        std::map <std::string, hvptr_t> _mapSO;

    public:
        // ctor.
        HornRewriter (HornTranslator* tr, hvptr_t p);
        // dtor.
        virtual ~HornRewriter ();

        // configure predicate output arguments to state. Set up _mapVS.
        void configOutput (const std::string& state, hvptr_t arg);
        // configure predicate input argument as the original predicate.
        void configInput ();
        // update rewrite mapping for states.
        void update (const std::string& state, hvptr_t inArg, hvptr_t outArg);
        // rewrite predicate with specified rules.
        std::string rewrite (char inType, int inSuff, char outType, int outSuff);
        // add the rule of rewriting to the clause.
        void addRewriteRule (hcptr_t C, char aType, int aSuff, 
                                        char bType, int bSuff);
        // get rewrited horn var.
        hvptr_t getRewriteVar (char inTy, int inSu, char outTy, int outSu);

    };

    // ---------------------------------------------------------------------- //
    class HornDB
    {
    private:
        // set of variables.
        std::map <std::string, hvptr_t> _vars;
        // set of relations (predicates).
        std::set <hvptr_t> _rels;
        // set of horn clauses.
        std::set <hcptr_t> _clauses;
        // set of horn clauses for instruction wrapping.
        std::set <hcptr_t> _wrapClauses;

    public:
        // ctor.
        HornDB ();
        // dtor.
        virtual ~HornDB ();

        // ------------------------------------------------------------------ //
        // add one variable to the set.
        void addVar (hvptr_t v);
        // denote a rel to the set.
        void addRel (hvptr_t v);
        // add a clause to the set.
        void addClause (hcptr_t c);
        // add a clause to the instruction wrapping set.
        void addWrapClause (hcptr_t c);
        // remove a var from the set.
        void removeVar (const std::string& n);
        // remove a rel from the set.
        void removeRel (hvptr_t v);

        // ------------------------------------------------------------------ //
        // output whole to stream.
        void print (std::ostream& out);

    private:
        // output var declaration to stream.
        void declareVar (std::ostream& out);
        // output rel declaration to stream.
        void declareRel (std::ostream& out);
        // output clauses to stream.
        void declareClause (std::ostream& out);
        // output wrap clauses to stream.
        void declareWrapClause (std::ostream& out);

        // collector for duplicated ast nodes.
        std::set <hvptr_t> _dupls;
    };

    // ---------------------------------------------------------------------- //
    class HornTranslator
    {
    private:
        // name for the translator. (prefix for variables)
        std::string _name;
        // pointer to the abstraction.
        Abstraction* _abs;
        // horn clause data base.
        HornDB* _db;
        // translate ITE as new clause or a node.
        bool _iteAsNode;
        // translate bitvectors as Int.
        bool _bvAsInt;
        // max bitvector length.
        int _bvMaxSize;

    public:
        // ctor;
        HornTranslator (Abstraction* abs, const std::string& name);
        // dtor.
        virtual ~HornTranslator ();

        // ------------------------------------------------------------------ //
        // convert whole abs to horn clauses and output to file.
        void hornifyAll (const std::string& fileName);
        // convert one ast node to horn clauses.
        hvptr_t hornifyNode (NodeRef* node, const std::string& ruleName);
        // convert abstraction to horn clauses. (Interleave/Blocking)
        void generateMapping (const std::string& type);
        // export horn clause to file.
        void exportHorn (const std::string& fileName);
        // set _iteAsNode.
        void setIteAsNode (bool iteAsNode);
        // set _bvAsInt.
        void setBvAsInt (bool bvAsInt);

        // ------------------------------------------------------------------ //
        // create an instruction with name i, and decode d.
        void addInstr (const std::string& i, NodeRef* d);
        // add next state function n for state s to (child-)instruction i.
        void addNext (const std::string& i, const std::string& s, NodeRef* n);
        // create a child-instruction with name c, and decode d to instr i.
        void addChildInstr (const std::string& c, const std::string& i, 
                            NodeRef* d);

        // ------------------------------------------------------------------ //
        // Traverse and generate horn clauses in depth-first order.
        void depthFirstTraverse (nptr_t n);
        // This will be used by depthFirstVisit.
        void operator() (nptr_t n);

    private:
        // var id count.
        unsigned _varCnt;
        // mapping from node to var (for internal var with ast node)
        std::map <nptr_t, hvptr_t> _nVarMap;
        // mapping from string to var (for top level var without ast node)
        std::map <std::string, hvptr_t> _sVarMap;
        // current working clause.
        hcptr_t _curHc;

        // structure for an instruction.
        struct Instr_t {
            std::string                     _name;
            hvptr_t                         _decodeFunc;
            std::map <std::string, hvptr_t> _nxtFuncs;
            std::set <std::string>          _childInstrs;
        };

        // sets of states.
        std::set <std::string> _states;
        // sets of instructions.
        std::map <std::string, struct Instr_t*> _instrs;
        // sets of child-instructions.
        std::map <std::string, struct Instr_t*> _childs;

        // ------------------------------------------------------------------ //
        // get horn var for the node; create if not exist.
        hvptr_t getVar (nptr_t n);
        // get horn var for the name; create if not exist.
        hvptr_t getVar (const std::string& s);
        // create a clause with the specified head.
        hcptr_t addClause (hvptr_t v = NULL);
        // initialize horn var from a node; Ex. _name, _exec, _outs.
        void initVar (hvptr_t v, nptr_t n);
        // initialize horn var from a node (model bitvector as BitVec).
        void initVarBv (hvptr_t v, nptr_t n);
        // initialize horn var from a node (model bitvector as Int).
        void initVarInt (hvptr_t v, nptr_t n);
        // initialize horn var from a name; _name.
        void initVar (hvptr_t v, const std::string& s);
        // get equal node.
        hvptr_t getEqVar (hvptr_t a, hvptr_t b);
        // get condition node.
        hvptr_t getConVar (hvptr_t c);

        // ------------------------------------------------------------------ //
        // eval if node n is an ITE node.
        bool isITE (nptr_t n) const;

        // ------------------------------------------------------------------ //
        // init horn var context: _name, _type, _exec, _ins, and _outs.
        // init horn var for BoolOp.
        void initBoolOp (const BoolOp* n, hvptr_t v);
        // init horn var for BoolVar.
        void initBoolVar (const BoolVar* n, hvptr_t v);
        // init horn var for BoolConst.
        void initBoolConst (const BoolConst* n, hvptr_t v);
        // init horn var for BitvectorOp.
        void initBvOp (const BitvectorOp* n, hvptr_t v);
        // init horn var for BitvectorVar.
        void initBvVar (const BitvectorVar* n, hvptr_t v);
        // init horn var for BitvectorConst.
        void initBvConst (const BitvectorConst* n, hvptr_t v);
        // init horn var for MemOp.
        void initMemOp (const MemOp* n, hvptr_t v);
        // init horn var for MemVar.
        void initMemVar (const MemVar* n, hvptr_t v);
        // init horn var for MemConst.
        void initMemConst (const MemConst* n, hvptr_t v);
        // init horn var for FuncVar.
        void initFuncVar (const FuncVar* n, hvptr_t v);

        // ------------------------------------------------------------------ //
        // if _bvAsNode is true: model bitvector as Int.
        // init horn var context: _name, _type, _exec, _ins, and _outs.
        // init horn var for BoolOp if bv as Int.
        void initBoolOpInt (const BoolOp* n, hvptr_t v);
        // init horn var for BoolVar if bv as Int.
        void initBoolVarInt (const BoolVar* n, hvptr_t v);
        // init horn var for BoolConst if bv as Int.
        void initBoolConstInt (const BoolConst* n, hvptr_t v);
        // init horn var for BitvectorOp if bv as Int.
        void initBvOpInt (const BitvectorOp* n, hvptr_t v);
        // init horn var for BitvectorVar if bv as Int.
        void initBvVarInt (const BitvectorVar* n, hvptr_t v);
        // init horn var for BitvectorConst if bv as Int.
        void initBvConstInt (const BitvectorConst* n, hvptr_t v);
        // init horn var for MemOp if bv as Int.
        void initMemOpInt (const MemOp* n, hvptr_t v);
        // init horn var for MemVar if bv as Int.
        void initMemVarInt (const MemVar* n, hvptr_t v);
        // init horn var for MemConst if bv as Int.
        void initMemConstInt (const MemConst* n, hvptr_t v);
        // init horn var for FuncVar if bv as Int.
        void initFuncVarInt (const FuncVar* n, hvptr_t v);

        // ------------------------------------------------------------------ //
        // add constraints or relations to working horn clause.
        // add BoolOp to horn clause.
        void addBoolOp (const BoolOp* n, hvptr_t v);
        // add BoolVar to horn clause.
        void addBoolVar (const BoolVar* n, hvptr_t v);
        // add BoolConst to horn clause.
        void addBoolConst (const BoolConst* n, hvptr_t v);
        // add BitvectorOp to horn clause.
        void addBvOp (const BitvectorOp* n, hvptr_t v);
        // add BitvectorVar to horn clause.
        void addBvVar (const BitvectorVar* n, hvptr_t v);
        // add BitvectorConst to horn clause.
        void addBvConst (const BitvectorConst* n, hvptr_t v);
        // add MemOp to horn clause.
        void addMemOp (const MemOp* n, hvptr_t v);
        // add MemVar to horn clause.
        void addMemVar (const MemVar* n, hvptr_t v);
        // add MemConst to horn clause.
        void addMemConst (const MemConst* n, hvptr_t v);
        // add FuncVar to horn clause.
        void addFuncVar (const FuncVar* n, hvptr_t v);

        // ------------------------------------------------------------------ //
        // generate BvOpReadMemBlock execution - little endian
        std::string genReadMemBlkExecLit (const std::string& mem,
                                          const std::string& addr,
                                          int addrWidth, int idx) const;
        // generate BvOpReadMemBlock execution - big endian
        std::string genReadMemBlkExecBig (const std::string& mem,
                                          const std::string& addr,
                                          int addrWidth, int idx, int num) const;
        // generate MemOpStoreMemBlock execution - little endian
        std::string genStoreMemBlkExecLit (const std::string& mem,
                                           const std::string& addr,
                                           const std::string& data,
                                           int chunkSize, int chunkNum,
                                           int addrWidth, int idx) const;
        // generate MemOpStoreMemBlock execution - big endian
        std::string genStoreMemBlkExecBig (const std::string& mem,
                                           const std::string& addr,
                                           const std::string& data,
                                           int chunkSize, int chunkNum,
                                           int addrWidth, int idx) const;
        // convert value to smt2.0 bitvector format. ex. #b0000
        std::string bvToString (mp_int_t val, int width) const;
        // convert value to smt2.0 bitvector format. ex. #b0000
        std::string bvToString (int val, int width) const;
        // generate rules for MemConst.
        void genMemConstRules (const MemConst* n, hvptr_t v);

    public:
        // ------------------------------------------------------------------ //
        // create name with suffix index: name_idx
        std::string addSuffix (const std::string& name, const int& idx) const;
        // duplicate variable with suffix index
        hvptr_t copyVar (hvptr_t v, const int& idx);

    private:
        // ------------------------------------------------------------------ //
        // check if the length exceed maximum bitvector width.
        bool isLongBv (const int& w) const;

        // ------------------------------------------------------------------ //
        // generate mappings for interleave modeling.
        void generateInterleaveMapping ();
        // generate mappings for blocking modeling.
        void generateBlockingMapping ();
        // generate loop predicate.
        HornRewriter* generateLoopPredicate ();
        // generate mappings for interleave modeling for all instructions.
        void allInterleaveMapping ();
    };
}

#endif /* __HORN_HPP_DEFINED__ */
