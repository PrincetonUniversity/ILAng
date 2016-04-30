#ifndef _UINST_HPP_DEFINED_
#define _UINST_HPP_DEFINED_

#include <ast.hpp>

namespace ila
{
    class MicroInst
    {
    protected:
        // parent abstraction.
        Abstraction& abs;
        // fetch
        nptr_t valid;
        nptr_t fetchExpr;
        // decode
        nptr_vec_t decodeExprs;
    public:
        // constructor.
        MicroInst(Abstraction& abs,
                  const nptr_t& valid, 
                  const nptr_t& fetch,
                  const nptr_vec_t& decodes);
        // destructor.
        ~MicroInst();
    };
}

#endif
