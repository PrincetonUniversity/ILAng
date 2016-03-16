#ifndef __UTIL_H_DEFINED__
#define __UTIL_H_DEFINED__

#define ILA_ASSERT(b, msg) ila_assert(b, msg, __FILE__, __LINE__)
namespace ila {
    void ila_assert(bool b, const char* msg, const char* file, int line);
};

#endif // __UTIL_H_DEFINED__

