#ifndef __HORNDB_HPP_DEFINED__
#define __HORNDB_HPP_DEFINED__

#include <string>
#include <assert.h>
#include <map>
#include <set>

#include <type.hpp>
#include <common.hpp>
#include <ast.hpp>
#include <ast/node.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/python.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    class HornNode;
    class HornClause;

    typedef HornNode hn_t;
    typedef hn_t* hnptr_t;
    typedef std::pair <hnptr_t, bool> hnptr_b_t;
    typedef std::set <hnptr_b_t> hnptr_set_t;
    //typedef std::vector <hnptr_t> hnptr_vec_t;
    //typedef std::set <hnptr_t> hnptr_set_t;

    typedef HornClause hc_t;
    typedef HornClause* hcptr_t;

    // ---------------------------------------------------------------------- //
    class HornNode
    {
    private:
        // node name.
        std::string _name;
        // node type.
        std::string _type;
        // execution - constraint in horn clause.
        std::string _exec;
        // predicate - predicate in horn clause.
        std::string _pred;
        // node id.
        unsigned _id;
        // initialized.
        bool _init;

    public:
        // ctor.
        HornNode();
        // ctor.
        HornNode(const unsigned& id);
        // dtor.
        virtual ~HornNode();

        // get node name.
        const std::string& getName() const;
        // get node type.
        const std::string& getType() const;
        // get execution.
        const std::string& getExec() const;
        // get predicate.
        const std::string& getPred() const;
        // get node id.
        const unsigned& getId() const;
        // check if initialized.
        bool isInit() const;

        // set node name.
        void setName(const std::string& s);
        // set node type.
        void setType(const std::string& s);
        // set execution.
        void setExec(const std::string& s);
        // set predicate.
        void setPred(const std::string& s);
        // set node id.
        void setId(const unsigned& i);
        // set initialized.
        void setInit();

    };

    // ---------------------------------------------------------------------- //
    class HornClause
    {
    private:
        // input vars.
        hnptr_set_t _inputs;
        // output vars.
        hnptr_set_t _outputs;
        // clause body.
        hnptr_set_t _body;
        // clause head.
        hnptr_b_t _head;
        
    public:
        // ctor.
        HornClause();
        // dtor.
        virtual ~HornClause();

        // add one node to body.
        void addBody(hnptr_t n, bool l = true);
        // add one node to head.
        void setHead(hnptr_t n, bool l = true);
        // add one input var (horn node).
        void addInput(hnptr_t n, bool l = true);
        // add one output var (horn node).
        void addOutput(hnptr_t n, bool l = true);
        // set input vars.
        void setInput(hnptr_set_t nVec);
        // set output vars.
        void setOutput(hnptr_set_t nVec);

        // output the clause to stream.
        void print(std::ostream& out);
    };

    // ---------------------------------------------------------------------- //
    class HornCtx
    {
    private:
        // mapping from ast node to horn node.
        std::map <nptr_t, hnptr_t> _nodes;
        // set of horn clauses.
        std::set <hcptr_t> _clauses;
        // horn node count for id.
        unsigned _nodeCnt;
        // current horn clause.
        hcptr_t _curHc;

    public:
        // ctor.
        HornCtx();
        // dtor.
        virtual ~HornCtx();

        // get horn node from ast node, create a new node if not found.
        hnptr_t getHornNode (nptr_t n);
        // create new horn clause and add to the set of clauses.
        hcptr_t addHornClause ();
        // get id for horn node.
        unsigned getHornId (hnptr_t n);
        // output all to stream.
        void print (std::ostream& out);

    private:
        // release created objects.
        void clear ();
    };
}

#endif /* __HORNDB_HPP_DEFINED__ */
