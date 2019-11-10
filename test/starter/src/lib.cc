// lib.cc
// Synopsis: implementation of the library

#include <simple/lib.h>

#include <iostream>

#include <ilang/ilang++.h>

void Foo() {
  auto m = ilang::Ila("bar");

  std::cout << "Hello from " << m << " in the lib." << std::endl;

  return;
}
