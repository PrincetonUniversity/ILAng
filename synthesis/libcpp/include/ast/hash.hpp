// --------------------------------------------------------------
//
// Utilities for hashing nodes.
//
// --------------------------------------------------------------
#ifndef __AST_HASH_HPP_DEFINED__
#define __AST_HASH_HPP_DEFINED__

#include <boost/functional/hash.hpp>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

#include <boost/shared_ptr.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/python.hpp>

#include <ast.hpp>

namespace ila
{
    std::size_t hash_value(const Node& n);
    std::size_t hash_value(const NodeType & ntype);
    std::size_t compute_hash_value(const NodeType & ntype);

    template<typename T>
    void choice_hash_combine(std::size_t& seed, const ChoiceExpr<T>* c)
    {
        const ReadSlice* rs = dynamic_cast<const ReadSlice*>(c);
        const WriteSlice* ws = dynamic_cast<const WriteSlice*>(c);

        if (rs != NULL) {
            boost::hash_combine(seed, 103002410);
            boost::hash_combine(seed, rs->bitvec.get());
            boost::hash_combine(seed, rs->width);
            boost::hash_combine(seed, rs->increment);
        } else if (ws != NULL) {
            boost::hash_combine(seed, 1505753267);
            boost::hash_combine(seed, ws->bitvec.get());
            boost::hash_combine(seed, ws->data.get());
            boost::hash_combine(seed, ws->increment);
        }
        boost::hash_combine(seed, c->getName());
    }

    template<class T> struct NodeHash;
    template<> struct NodeHash<const Node*>
    {
        size_t operator()(const Node* n) const
        {
            return hash_value(*n);
        }
    };

    template<class T> struct NodeEqual;
    template<> struct NodeEqual<const Node*>
    {
        bool operator()(const Node* l, const Node* r) const
        {
            return l->equal(r);
        }
    };
}

#endif
