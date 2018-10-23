// The ILA for the NVDLA planar data processor (PDP)

#include "ila++.h"
#include "z3++.h"
#include <iostream>

using namespace ila;

void GenPdpIla() { std::cout << "Generate PDP ILA model.\n"; }

int main() {
  try {
    GenPdpIla();
  } catch (...) {
    std::cout << "unexpected error.\n";
  }

  return 0;
}
