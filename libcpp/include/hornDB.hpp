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
    class HornNode
    {
    private:
        // node name.
        std::string _name;

    public:
        // ctor.
        HornNode();
        // ctor.
        HornNode(const std::string& s);
        // ctor.
        HornNode(nptr_t n);
        // dtor.
        virtual ~HornNode();

        // get node name.
        const std::string& getName() const;
        // set node name.
        void setName(const std::string& s);
    };

    // ---------------------------------------------------------------------- //
    typedef HornNode hn_t;
    typedef hn_t* hnptr_t;
    typedef std::vector <hnptr_t> hnptr_vec_t;

    // ---------------------------------------------------------------------- //
    class HornClause
    {
    private:
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
        std::set <HornClause*> _clauses;

    public:
        // ctor.
        HornCtx();
        // dtor.
        virtual ~HornCtx();

        // get horn node from ast node, create a new node if not find.
        hnptr_t getHornForNode(nptr_t n);
        // add new horn clause to the set.
        void addHornClause(HornClause* hc);
        // output all to stream.
        void print(std::ostream& out);

    private:
        // release created objects.
        void clear();
    };
}

#endif /* __HORNDB_HPP_DEFINED__ */
