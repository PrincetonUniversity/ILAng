#include <exception.hpp>

namespace ila 
{
    // Exception translator.
    void translateILAException(PyILAException const& ex)
    {
        PyErr_SetString(ex.exception, ex.message.c_str());
    }

    // Destructor.
    PyILAException::~PyILAException() throw ()
    {
    }
}
