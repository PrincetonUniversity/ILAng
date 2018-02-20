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

bool Func::CheckSort(const ExprPtrVec& args) const {
  ILA_CHECK(args.size() == arg_num())
      << "Argument number mismatch: " << args.size() << " " << arg_num();
  for (size_t i = 0; i != args.size(); i++) {
    ILA_CHECK(args[i]->sort() == arg(i))
        << i << "-th Sort mismatch: " << args[i]->sort() << " " << arg(i);
  }
  return true;
}

z3::func_decl Func::GetZ3FuncDecl(z3::context& ctx) const {
  auto range = out().GetZ3Sort(ctx);
  std::vector<z3::sort> domains;
  for (size_t i = 0; i != arg_num(); i++) {
    domains.push_back(arg(i).GetZ3Sort(ctx));
  }
  // FIXME check vector works
  return z3::function(name().c_str(), arg_num(), &domains[0], range);
}

std::ostream& Func::Print(std::ostream& out) const {
  return out << "Func." << name();
}

} // namespace ila

