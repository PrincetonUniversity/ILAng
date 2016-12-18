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
    typedef std::vector <hnptr_t> hnptr_vec_t;

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
        // node id.
        unsigned _id;

    public:
        // ctor.
        HornNode();
        // ctor.
        HornNode(nptr_t n);
        // ctor.
        HornNode(Node* n);
        // dtor.
        virtual ~HornNode();

        // get node name.
        const std::string& getName() const;
        // set node name.
        void setName(const std::string& s);
        // get node type.
        const std::string& getType() const;
        // set node type.
        void setType(const std::string& s);
        // get node id.
        const unsigned& getId() const;
        // set node id.
        void setId(const unsigned& i);
        

    private:
        void extractType(Node* n);
    };

    // ---------------------------------------------------------------------- //
    class HornClause
    {
    private:
        // input vars.
        hnptr_vec_t _inputs;
        // output vars.
        hnptr_vec_t _outputs;
        // clause body.
        hnptr_vec_t _body;
        // clause head.
        hnptr_t _head;
        
    public:
        // ctor.
        HornClause();
        // dtor.
        virtual ~HornClause();

        // add one node to body.
        void addBody(hnptr_t n);
        // add one node to head.
        void setHead(hnptr_t n);
        // add one input var (horn node).
        void addInput(hnptr_t n);
        // add one output var (horn node).
        void addOutput(hnptr_t n);
        // set input vars.
        void setInput(hnptr_vec_t nVec);
        // set output vars.
        void setOutput(hnptr_vec_t nVec);

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

        // get horn node from ast node, create a new node if not find.
        hnptr_t getHornForNode(nptr_t n);
        // get id for horn node.
        unsigned getHornId(hnptr_t n);
        // add new horn clause to the set.
        void addHornClause(hcptr_t hc);
        // create new horn clause to the set, and set to current clause.
        void newHornClause();
        // output all to stream.
        void print(std::ostream& out);

    private:
        // release created objects.
        void clear();
    };
}

#endif /* __HORNDB_HPP_DEFINED__ */
