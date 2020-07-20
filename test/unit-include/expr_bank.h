/// \file
/// Base class for creating a set of Expr for testing

#ifndef EXPR_BANK_H__
#define EXPR_BANK_H__

#include <vector>

#include <ilang/ila/ast_hub.h>

#include "util.h"

namespace ilang {

using namespace asthub;

template <int BV_SIZE = 8, int VAR_NUM = 16> class ExprBank {
public:
  std::vector<ExprPtr> BOOL;
  std::vector<ExprPtr> BV;
  std::vector<ExprPtr> MEM;

  ExprPtr BOOL_T = BoolConst(true);
  ExprPtr BOOL_F = BoolConst(false);
  ExprPtr BV_ZERO = BvConst(0, BV_SIZE);
  ExprPtr BV_ONE = BvConst(1, BV_SIZE);

  ExprBank() {
    for (auto i = 0; i != VAR_NUM; i++) {
      auto bool_name = "bool_" + std::to_string(i);
      BOOL.push_back(NewBoolVar(bool_name));

      auto bv_name = "bv_" + std::to_string(i);
      BV.push_back(NewBvVar(bv_name, BV_SIZE));

      auto mem_name = "mem_" + std::to_string(i);
      MEM.push_back(NewMemVar(mem_name, BV_SIZE, BV_SIZE));
    }
  }

}; // class ExprBank

} // namespace ilang

#endif // EXPR_BANK_H__
