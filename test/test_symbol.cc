/// \file
/// Unit test for class Symbol.

#include "ila/symbol.h"
#include "test_util.h"

namespace ila {

TEST(Symbol, Construct) {
  Symbol sym_default;
  Symbol sym_cstr("sym_cstr");
  Symbol sym_str("sym_str");

  Symbol sym0;
  Symbol sym1;
  EXPECT_GT(sym1.to_int(), sym0.to_int());

  std::string msg = "";
  GET_STDOUT_MSG((std::cout << sym0), msg);
  EXPECT_EQ(sym0.str(), msg);
}

TEST(Symbol, Accessors) {
  Symbol sym("symbol_name");
  Symbol sym_copy = sym;
  EXPECT_EQ(sym.str(), sym_copy.str());
  EXPECT_STREQ(sym.c_str(), sym_copy.c_str());

  Symbol sym_num;
  Symbol sym_num_copy = sym_num;
  EXPECT_EQ(sym_num.to_int(), sym_num_copy.to_int());

#ifndef NDEBUG
  std::string msg = "";
  GET_STDERR_MSG(sym.to_int(), msg);
  EXPECT_FALSE(msg.empty());
#endif // NDEBUG
}

} // namespace ila

