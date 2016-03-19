#ifndef __AST_NODE_HPP_DEFINED__
#define __AST_NODE_HPP_DEFINED__

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <z3++.h>
#include <assert.h>
#include <type.hpp>

namespace ila 
{
    class Node {
        static int totalObjCnt;
    private:
        void _initName();
    public:
        // member variables.
        std::string name;
        int id;
        NodeType type;

        // default constructor.
        Node()
          : id(totalObjCnt++)
          , type(NodeType())
        { 
            _initName();
        }

        // constructor.
        Node(NodeType t) 
          : id(totalObjCnt++)
          , type(t) 
        {
            _initName();
        }

        virtual ~Node();

        void doSomething();
        virtual Node* clone() const;
        virtual Node* complement() const;
        virtual Node* negate() const;
    };
}

#endif
