// lib.cc
// Synopsis: implementation of the library

#include <simple/lib.h>
#include <ilang/cpp_api.h>
#include <iostream>

void Foo() {
  auto m = ila::Ila("bar");

  std::cout << "Hello from " << m << " in the lib." << std::endl;

  return;
}
