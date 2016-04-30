#include <uinst.hpp>

namespace ila
{

    MicroInst::MicroInst(
        Abstraction& a, const nptr_t& v, const nptr_t& f, const nptr_vec_t& decs)
      : abs(a)
      , valid(v)
      , fetchExpr(f)
      , decodeExprs(decs)
    {
    }

    MicroInst::~MicroInst()
    {
    }
}

