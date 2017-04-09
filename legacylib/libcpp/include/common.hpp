#ifndef __COMMON_HPP_DEFINED__
#define __COMMON_HPP_DEFINED__

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/python.hpp>

namespace ila {
    namespace py = boost::python;
    typedef boost::multiprecision::cpp_int mp_int_t;
    enum endianness_t { UNKNOWN_E, LITTLE_E, BIG_E };
}
#endif
