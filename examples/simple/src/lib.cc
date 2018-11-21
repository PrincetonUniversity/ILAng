// lib.cc

#include "simple/lib.h"
#include <ilang/ila++.h>
#include <iostream>

void Foo() {
  std::cout << "Hello from lib" << std::endl;

  auto m = IlaRef("bar");
}
