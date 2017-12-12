/// \file
/// Unit test for class Symbol.

#include "ila/symbol.h"
#include "test_util.h"

namespace ila {

TEST(Symbol, NumConstruct) {
  Symbol sym0, sym1, sym2;
  int sym0_int = sym0.ToInt();
  int sym1_int = sym1.ToInt();
  std::string sym2_str = sym2.Str();

  EXPECT_GT(sym1_int, sym0_int);

  std::string msg = "";
  GET_STDOUT_MSG((std::cout << sym2), msg);
  EXPECT_EQ(sym2_str, msg);
}

TEST(Symbol, StringConstruct) {
  Symbol sym("symbol_name");
  std::shared_ptr<Symbol> sym_ptr = std::make_shared<Symbol>("ptr_name");
  Symbol sym_copy = sym;

  EXPECT_EQ("symbol_name", sym.Str());
  EXPECT_EQ(sym.Str(), sym_copy.Str());
  EXPECT_EQ("ptr_name", sym_ptr->Str());

  std::string msg = "";
  GET_STDERR_MSG(sym.ToInt(), msg);
  EXPECT_FALSE(msg.empty());
  // EXPECT_THROW(sym.ToInt(), std::invalid_argument);
}

} // namespace ila

