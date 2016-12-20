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
        std::string _exec;
        // set of input (dependent) vars.
        std::set <hvptr_t> _ins;
        // set of output vars.
        std::set <hvptr_t> _outs;

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
        const std::string& getExec () const;
        // get var predicate.
        std::string getPred () const;
        // get var relation.
        std::string getRel () const;

        // ------------------------------------------------------------------ //
        // set var name.
        void setName (const std::string& s);
        // set var type.
        void setType (const std::string& s);
        // set constraints for var execution.
        void setExec (const std::string& s);
        // add dependent input var.
        void addInVar (hvptr_t v);
        // add output var.
        void addOutVar (hvptr_t v);
        // merge dependent input vars.
        void mergeInVars (hvptr_t v);
        // merge output vars.
        void mergeOutVars (hvptr_t v);
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
    };

    // ---------------------------------------------------------------------- //
    class HornDB
    {
    private:
        // set of variables.
        std::set <hvptr_t> _vars;
        // set of rules (predicates).
        std::set <hvptr_t> _rules;
        // set of horn clauses.
        std::set <hcptr_t> _clauses;

    public:
        // ctor.
        HornDB ();
        // dtor.
        virtual ~HornDB ();

        // ------------------------------------------------------------------ //
        // add one variable to the set.
        void addVar (hvptr_t v);
        // denote a rule to the set.
        void addRule (hvptr_t v);
        // add a clause to the set.
        void addClause (hcptr_t c);

        // ------------------------------------------------------------------ //
        // output to stream.
        void print (std::ostream& out);
    };

    // ---------------------------------------------------------------------- //
    class HornTranslator
    {
    private:
        Abstraction* _abs;
        // horn clause data base.
        HornDB* _db;

    public:
        // ctor;
        HornTranslator (Abstraction* abs);
        // dtor.
        virtual ~HornTranslator ();

        // ------------------------------------------------------------------ //
        // convert whole abs to horn clauses.
        void transAll (const std::string& fileName);
        // convert one ast node to horn clauses.
        void transOne (NodeRef* node, const std::string& fileName);

        // ------------------------------------------------------------------ //
        // Traverse and generate horn clauses in depth-first order.
        void depthFirstTraverse (nptr_t n);

        // ------------------------------------------------------------------ //
        // This will be used by depthFirstVisit.
        void operator() (nptr_t n);

    private:
        // ------------------------------------------------------------------ //
        // eval if node n is an ITE node.
        bool isITE (nptr_t n);

        // ------------------------------------------------------------------ //
        // set horn var for bool var.
        void setBoolVarHorn (const BoolVar* n, hvptr_t hv);
    };
}

#endif /* __HORN_HPP_DEFINED__ */
