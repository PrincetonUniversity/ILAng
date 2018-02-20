/// \file
/// Source for the class Func

#include "ila/ast/func.h"
#include "ila/expr_fuse.h"
#include "util/log.h"

namespace ila {

Func::Func(const FuncConfig& config)
    : Ast(config.name_), out_(config.out_), args_(config.args_) {}

Func::~Func() {}

FuncPtr Func::New(const std::string& name, const Sort& out) {
  return std::make_shared<Func>(FuncConfig(name, out, {}));
}

FuncPtr Func::New(const std::string& name, const Sort& out, const Sort& arg0) {
  return std::make_shared<Func>(FuncConfig(name, out, {arg0}));
}

FuncPtr Func::New(const std::string& name, const Sort& out, const Sort& arg0,
                  const Sort& arg1) {
  return std::make_shared<Func>(FuncConfig(name, out, {arg0, arg1}));
}

FuncPtr Func::New(const std::string& name, const Sort& out,
                  const std::vector<Sort>& args) {
  return std::make_shared<Func>(FuncConfig(name, out, args));
}

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

