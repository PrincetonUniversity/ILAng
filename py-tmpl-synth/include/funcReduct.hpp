// --------------------------------------------------------------
//
// Utilities for function reduction.
// To maintain only one copy of shared nodes
//
// --------------------------------------------------------------

#ifndef __FUNCTION_REDUCTION_HPP_DEFINED__
#define __FUNCTION_REDUCTION_HPP_DEFINED__

#include <ast.hpp>
namespace ila
{
    class FuncReduction
    {
        typedef size_t FuncCode;
        // unordered_map of ...
        std::unordered_map <FuncCode, nptr_t>  func_to_node_dict;

    public:
        void ProcessAST(nptr_t & );
        void InsertOrDupNode(nptr_t & );
        void InsertOrDupNoRecursive(nptr_t &);
    };
}


#endif

