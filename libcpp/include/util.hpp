#ifndef __UTIL_H_DEFINED__
#define __UTIL_H_DEFINED__

#include <string>
#include <boost/python.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#define ILA_ASSERT(b, msg) ila_assert(b, msg, __FILE__, __LINE__)
namespace ila {
    // ---------------------------------------------------------------------- //
    void ila_assert(bool b, const char* msg, const char* file, int line);
    void ila_assert(bool b, const std::string& msg, const char* file, int line);

    // ---------------------------------------------------------------------- //
    boost::multiprecision::cpp_int to_cpp_int(
        const boost::python::object& l);
    boost::python::object to_pyint(
        const boost::multiprecision::cpp_int& i);
    boost::python::object to_pyint(
        const std::string& s);
};

#endif // __UTIL_H_DEFINED__

