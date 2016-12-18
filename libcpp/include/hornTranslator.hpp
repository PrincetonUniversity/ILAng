#ifndef __HORNTRANSLATOR_HPP_DEFINED__
#define __HORNTRANSLATOR_HPP_DEFINED__

#include <cassert>

#include <unordered_map>
#include <vector>
#include <memory>

#include <z3++.h>
#include <util.hpp>
#include <smt.hpp>

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
       // eval if node n is ITE node.
       bool isITE (nptr_t n);

    };
}

#endif /* __HORNTRANSLATOR_HPP_DEFINED__ */
