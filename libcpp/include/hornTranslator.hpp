#ifndef __HORNTRANSLATOR_HPP_DEFINED__
#define __HORNTRANSLATOR_HPP_DEFINED__

#include <cassert>

#include <unordered_map>
#include <vector>
#include <memory>

#include <z3++.h>
#include <util.hpp>
#include <smt.hpp>
#include <logging.hpp>

#include <ast.hpp>
#include <hornDB.hpp>

namespace ila
{
    class Abstraction;
    class HornClause;
    class HornCtx;

    class HornTranslator
    {
    private:
       // abstraction to be translated.
       Abstraction* _abs;
       // horn clause context.
       HornCtx* _ctx;
       // current horn clause.
       hcptr_t _curHc;

       // -------------------------------------------------------------------- //
       // predicate prefix
       std::string _pred_prefix = "pred_";
       // bool prefix
       std::string _bool_prefix = "bool_";
       // bitvector prefix
       std::string _bv_prefix = "bv_";
       // memory prefix
       std::string _mem_prefix = "mem_";
       // function prefix
       std::string _func_prefix = "func_";

    public:
       // constructor.
       HornTranslator (Abstraction* a);
       // destructor.
       virtual ~HornTranslator();

       // -------------------------------------------------------------------- //
       // convert whole abs to horn clauses.
       void transAll (const std::string& fileName);
       // convert one node to horn clauses.
       void transOne (NodeRef* node, const std::string& fileName);

       // -------------------------------------------------------------------- //
       // Traverse and generate horn clause in depth-first order.
       void depthFirstTraverse (nptr_t n);

       // -------------------------------------------------------------------- //
       // This will be used by depthFirstVisit.
       void operator() (nptr_t n);

    private:
       // -------------------------------------------------------------------- //
       // eval if node n is ITE node.
       bool isITE (nptr_t n);

       // -------------------------------------------------------------------- //
       // generate horn node, ex. name, type, ...
       void genHornNode (hnptr_t hn, nptr_t n);
       // convert a bool variable into HornNode.
       void genBoolVarHorn (const BoolVar* n, hnptr_t hn);
       // convert a bool constant into HornNode.
       void genBoolConstHorn (const BoolConst* n, hnptr_t hn);
       // convert a bool op into HornNode.
       void genBoolOpHorn (const BoolOp* n, hnptr_t hn);
       // convert a bitvector variable into HornNode.
       void genBvVarHorn (const BitvectorVar* n, hnptr_t hn);
       // convert a bitvector constant into HornNode.
       void genBvConstHorn (const BitvectorConst* n, hnptr_t hn);
       // convert a bitvector op into HornNode.
       void genBvOpHorn (const BitvectorOp* n, hnptr_t hn);
       // convert a memory constant into HornNode.
       void genMemConstHorn (const MemConst* n, hnptr_t hn);
       // convert a memory variable into HornNode.
       void genMemVarHorn (const MemVar* n, hnptr_t hn);
       // convert a memory op into HornNode.
       void genMemOpHorn (const MemOp* n, hnptr_t hn);
       // convert a function into HornNode.
       void genFuncVarHorn (const FuncVar* n, hnptr_t hn);

    };
}

#endif /* __HORNTRANSLATOR_HPP_DEFINED__ */
