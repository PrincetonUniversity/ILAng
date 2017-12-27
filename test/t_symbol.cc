/// \file
/// Unit test for class Symbol.

#include "ila/symbol.h"
#include "util_test.h"

namespace ila {

TEST(TestSymbol, Construct) {
  Symbol sym_default;

  const char* cstr_name = "stm_cstr";
  Symbol sym_cstr(cstr_name);

  std::string str_name = "sym_str";
  Symbol sym_str(str_name);

  Symbol sym_direct("sym");

  Symbol sym0;
  Symbol sym1;
  EXPECT_GT(sym1.id(), sym0.id());

  std::string msg = "";
  GET_STDOUT_MSG((std::cout << sym0), msg);
  EXPECT_EQ(sym0.str(), msg);
}

TEST(TestSymbol, Accessors) {
  Symbol sym("symbol_name");
  Symbol sym_copy = sym;

  Symbol sym_empty;
  sym_empty.set_name("assign");
  EXPECT_EQ(sym_empty.str(), "assign");

  EXPECT_EQ(sym.str(), sym_copy.str());
  EXPECT_STREQ(sym.c_str(), sym_copy.c_str());
  EXPECT_GT(sym.id(), 0);
  EXPECT_EQ(sym.id(), sym_copy.id());

  std::string msg = "";
  GET_STDERR_MSG(sym.to_int(), msg);
#ifndef NDEBUG
  EXPECT_FALSE(msg.empty());
#endif // NDEBUG
}

TEST(TestSymbol, Format) {
  Symbol sym("name");

  EXPECT_EQ("name_suf", sym.format_str("", "suf"));
  EXPECT_EQ("pre_name", sym.format_str("pre", ""));
  EXPECT_EQ("p_name_s", sym.format_str("p", "s"));
}

} // namespace ila

