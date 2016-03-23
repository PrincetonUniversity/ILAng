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

    void Abstraction::synthesize(NodeRef* expr, PyObject* pyfun)
    {
        using namespace boost::python;

        dict d;
        d["arg"] = 1;

        dict dp = call<dict>(pyfun, d);

        std::cout << "finished call." << std::endl;

        int result = extract<int>(dp["arg"]);
        std::cout << "result=" << result << std::endl;
    }
}
