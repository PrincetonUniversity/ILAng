#include <util.hpp>
#include <exception.hpp>
#include <boost/python.hpp>

#include <string>
#include <string.h>

namespace ila {

    // ---------------------------------------------------------------------- //
    void ila_assert(bool b, const char* msg, const char* file, int line)
    {
        if (!b) {
            size_t sz = strlen(msg) + strlen(file) + 48;
            char* buf = new char[sz];
            snprintf(buf, sz-1, "error %s line %d: %s", file, line, msg);
            std::string str(buf);
            delete [] buf;

            throw PyILAException(PyExc_RuntimeError, str);
        }
    }

    void ila_assert(bool b, const std::string& msg, const char* file, int line)
    {
        if (!b) {
            size_t sz = msg.size() + strlen(file) + 48;
            char* buf = new char[sz];
            snprintf(buf, sz-1, "error %s line %d: %s", file, line, msg.c_str());
            std::string str(buf);
            delete [] buf;

            throw PyILAException(PyExc_RuntimeError, str);
        }
    }

    // ---------------------------------------------------------------------- //
    boost::multiprecision::cpp_int cpp_int_from_pylong(
        const boost::python::long_& l)
    {
        std::string lstr = boost::python::extract<std::string>(l);
        return boost::lexical_cast<boost::multiprecision::cpp_int>(lstr);
    }
}
