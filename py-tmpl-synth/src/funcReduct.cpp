#include <funcReduct.hpp>
#include <ast/hash.hpp>

namespace ila
{
    void FuncReduction::ProcessAST(nptr_t & ast_ptr)
    {
        //check if BitVectorOp, BoolOp, MemOp
        // if so
        //    we go deeper
        // we rely on ...
        Node * tree = ast_ptr.get();
        auto pos = func_to_node_dict.find(tree->hash_value);
        if (pos != func_to_node_dict.end() )  {
            if(pos->second != ast_ptr)
                ast_ptr = (pos->second);
                //;
            return;
        }

        // otherwise do it here
        BoolOp*       boolop = NULL;
        BitvectorOp*  bvop   = NULL;
        MemOp*        memop  = NULL;

        if ( (boolop = dynamic_cast<BoolOp *>(tree))) {
            unsigned n = boolop->nArgs();
            for(unsigned i=0; i != n; i++) {
                ProcessAST(boolop->args[i]);
            }
        }
        else if ( (bvop = dynamic_cast<BitvectorOp *>(tree))) {
            unsigned n = bvop->nArgs();
            for(unsigned i=0; i != n; i++) {
                ProcessAST(bvop->args[i]);
            }            
        }
        else if ( (memop = dynamic_cast<MemOp *>(tree))) {
            unsigned n = memop->nArgs();
            for(unsigned i=0; i != n; i++) {
                ProcessAST(memop->args[i]);
            }            
        }
        func_to_node_dict.insert( {tree->hash_value, ast_ptr} );
        //ast_ptr.reset(tree);
    }
    void FuncReduction::InsertOrDupNode(nptr_t & ast_ptr)
    {
        Node * ast = ast_ptr.get();
        if (!ast->hash_inited)
            hash_value(*ast);
        ProcessAST(ast_ptr);
    }
    
    void FuncReduction::InsertOrDupNoRecursive(nptr_t & ast_ptr)
    {
        Node * ast = ast_ptr.get();
        if (!ast->hash_inited)
            hash_value(*ast);
        
        Node * tree = ast_ptr.get();
        auto pos = func_to_node_dict.find(tree->hash_value);
        if (pos != func_to_node_dict.end() )  {
            if(pos->second != ast_ptr)
                ast_ptr = (pos->second);
                //;
            return;
        }
        //else
        func_to_node_dict.insert( {tree->hash_value, ast_ptr} );
                
    }

}