#include "ila++.h"

using namespace ila;

int main() {
  // ILA
  Ila ila("top");
  auto reg = ila.NewBvState("reg", 8);

  return 0;
}

