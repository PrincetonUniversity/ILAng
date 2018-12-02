// lib.cc
// Synopsis: implementation of the library

#include <ila++.h>
#include <iostream>
#include <simple/lib.h>

void Foo() {
  auto m = ilang::Ila("bar");

  std::cout << "Hello from " << m << " in the lib." << std::endl;

  return;
}
