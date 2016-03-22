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

    NodeRef* Abstraction::bvConstLong(boost::python::long_ l, int w)
    {
        return new NodeRef(new ila::BitvectorConst(this, l, w));
    }

    NodeRef* Abstraction::bvConstInt(int l, int w)
    {
        return new NodeRef(new ila::BitvectorConst(this, l, w));
    }
}
