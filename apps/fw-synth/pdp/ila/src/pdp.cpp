// The ILA for the NVDLA planar data processor (PDP)

#include "ila++.h"
#include "z3++.h"
#include <iostream>

using namespace ila;

void GenPdpIla() {}

int main() {
  try {
    GenPdpIla();
  } catch (...) {
    std::cout << "unexpected error.\n";
  }

  std::cout << "PDP ILA generated.\n";
  return 0;
}
