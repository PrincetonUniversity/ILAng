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
    std::string to_string(
        const boost::python::object& l);
    boost::multiprecision::cpp_int to_cpp_int(
        const boost::python::object& l);
    boost::python::object to_pyint(
        const boost::multiprecision::cpp_int& i);
    boost::python::object to_pyint(
        const std::string& s);
    bool is_py_int(
        const boost::python::object& l);
    bool is_py_int_or_long(
        const boost::python::object& l);
};

#endif // __UTIL_H_DEFINED__

