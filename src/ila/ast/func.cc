/// \file
/// Source for the class Func

#include "ila/ast/func.h"
#include "ila/expr_fuse.h"
#include "util/log.h"

namespace ila {

Func::Func(const std::string& name, const Sort& out) : out_(out) {
  set_name(name);
}

Func::Func(const std::string& name, const Sort& out, const Sort& arg0)
    : out_(out), args_({arg0}) {
  set_name(name);
}

Func::Func(const std::string& name, const Sort& out, const Sort& arg0,
           const Sort& arg1)
    : out_(out), args_({arg0, arg1}) {
  set_name(name);
}

Func::Func(const std::string& name, const Sort& out,
           const std::vector<Sort>& args)
    : out_(out), args_(args) {
  set_name(name);
}

Func::~Func() {}

bool Func::Check(const ExprPtrVec& args) const {
  ILA_CHECK(args.size() == arg_num())
      << "Argument number mismatch: " << args.size() << " " << arg_num();
  for (size_t i = 0; i != args.size(); i++) {
    ILA_CHECK(args[i]->sort() == arg(i))
        << i << "-th Sort mismatch: " << args[i]->sort() << " " << arg(i);
  }
  return true;
}

std::ostream& Func::Print(std::ostream& out) const {
  return out << "Func." << name();
}

} // namespace ila

