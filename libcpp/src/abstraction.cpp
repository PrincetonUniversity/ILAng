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

    // ---------------------------------------------------------------------- //
    NodeRef* Abstraction::addRegister(const std::string& name, int width)
    {
        return new NodeRef(new ila::BitvectorVar(this, name, width));
    }
}
