/// \file The datapoint structure (for SyGuS)
/// 
// Hongce Zhang


#ifndef DATAPOINT_H__
#define DATAPOINT_H__

#include <ilang/smt-inout/smt_ast.h>

#include <string>
#include <map>
#include <vector>

namespace ilang
{
  /// \brief the data point type
  struct TraceDataPoints {
    // ------------- TYPES ---------------- //
    /// the type of values
    /// the number here will be converted to #x... / #b... when needed
    struct radix_val_t { std::string val; unsigned radix; 
      radix_val_t() {}
      radix_val_t(const std::string &v, unsigned r):val(v),radix(r){} };
    /// radix must be in 2 10 16
    typedef std::pair<radix_val_t, smt::var_type> value_t;
    /// the type of example collectors: var_name -> value
    typedef std::map<std::string,value_t> example_map_t;
    /// the type of multiple round of pos_ex
    typedef std::vector<example_map_t>  pos_t;
    // ------------- MEMBER ---------------- //
    /// The positive examples --- for different rounds (each round must contain all the ...)
    pos_t pos_ex;
    /// The negative examples
    example_map_t neg_ex;
    /// this function allows to insert the outer cegar result to this datapoint
    /// T could be CexExtractor/InvCexExtractor
    template <typename T> void SetNegEx(const T &);
    /// the same as above
    template <typename T> void AddPosEx(const T &);
    /// pos_ex.clear();
    void ClearPosEx();
  };  // struct TraceDataPoints

}; // namespace ilang

#endif // DATAPOINT_H__
