#ifndef __INSTRUCTION_HPP_DEFINED__
#define __INSTRUCTION_HPP_DEFINED__

#include <set>
#include <map>
#include <vector>
#include <string>
#include <boost/python.hpp>

#include <common.hpp>
#include <ast.hpp>
#include <abstraction.hpp>

namespace ila
{
    typedef std::map<std::string, nptr_t> nUpdate_t;

    class Abstraction;
    class Instruction;
    class TraceStep;
    class MemoryModel;
    class TSO;
    class SC;


/*
    class Views{
            nInstPtr_t inst;
            nViewer_t  viewers;

        public:
            // add viewers
            // add 

    };*/

    class Instruction{
            friend class Abstraction;
            friend class TraceStep;
            friend class MemoryModel;
            friend class TSO;
            friend class SC;

            // points to its own abstraction
            Abstraction * abs;

            const std::string name;
            nptr_t decodeExpr;

            // list of updates ... to mem/bit/reg
            nUpdate_t updates;  // nmap_t : name->nptr_t list

            void CheckType(const std::string& name, NodeRef* n);

        public:
            const std::string & getName() const {return name;}

            // Constructor
            Instruction(const std::string &inst_name, Abstraction * Abs);

            // Function: set decode
            void setDecode(NodeRef *de);

            // Function: get decode
            NodeRef* getDecode();

            // Set next
            void setNext(const std::string& name, NodeRef* n);

            // Get next
            NodeRef* getNext(const std::string& name) const;

            // Views 
            // no need 



    };


    struct InstRef
    {
        nInstPtr_t instPtr;

        InstRef();
        InstRef(Instruction *inst);
        InstRef(const nInstPtr_t &inst);
        InstRef(const InstRef & inst);
        ~InstRef();

        std::string getName() const;

        void setDecode(NodeRef *de);

        // Function: get decode
        NodeRef* getDecode();

        // Set next
        void setNext(const std::string& name, NodeRef* n);
        // Get next
        NodeRef* getNext(const std::string& name) const;
        //

    };

    std::ostream & operator << (std::ostream & out, const InstRef &inst);
}


#endif