#include <abstraction.hpp>

namespace ila
{
    // ---------------------------------------------------------------------- //
    int Abstraction::getObjId()
    {
        return objCnt++;
    }

    Abstraction::Abstraction()
      : objCnt(0)
    {
    }

    Abstraction::~Abstraction()
    {
    }
}
