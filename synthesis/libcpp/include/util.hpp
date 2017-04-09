#ifndef __UTIL_H_DEFINED__
#define __UTIL_H_DEFINED__

#include <string>
#include <common.hpp>
#include <boost/python.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#define ILA_ASSERT(b, msg) ila_assert(b, msg, __FILE__, __LINE__)
namespace ila {
    // ---------------------------------------------------------------------- //
    void ila_assert(bool b, const char* msg, const char* file, int line);
    void ila_assert(bool b, const std::string& msg, const char* file, int line);
    void dump_trace();

    // ---------------------------------------------------------------------- //
    std::string to_string(const py::object& l);
    std::string to_string(const mp_int_t& i);
    mp_int_t to_cpp_int(const py::object& l);
    py::object to_pyint(const mp_int_t& i);
    py::object to_pyint(const std::string& s);
    bool is_py_int(const py::object& l);
    bool is_py_int_or_long(
        const py::object& l);

    // ---------------------------------------------------------------------- //
    void set_logging_level(int level);

    const int NUM_HASHTABLE_BUCKETS = 1023;
    const int NUM_HASHTABLE_BUCKETS_SMALL = 63;
};

#endif // __UTIL_H_DEFINED__

