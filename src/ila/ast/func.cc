/// \file
/// Source for the class Func

#include <ilang/ila/ast/func.h>

#include <ilang/ila/ast_hub.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

namespace ilang {

Func::Func(const std::string& name, const SortPtr out,
           const std::vector<SortPtr>& args)
    : Ast(name), out_(out), args_(args) {}

Func::~Func() {}

FuncPtr Func::New(const std::string& name, const SortPtr out) {
  return FuncPtr(new Func(name, out, {})); // not make_shared due to vector
}

FuncPtr Func::New(const std::string& name, const SortPtr out,
                  const SortPtr arg0) {
  return FuncPtr(new Func(name, out, {arg0})); // not make_shared due to vector
}

FuncPtr Func::New(const std::string& name, const SortPtr out,
                  const SortPtr arg0, const SortPtr arg1) {
  return FuncPtr(new Func(name, out, {arg0, arg1})); // not make_shared
}

FuncPtr Func::New(const std::string& name, const SortPtr out,
                  const std::vector<SortPtr>& args) {
  return FuncPtr(new Func(name, out, args)); // not make_shared due to vector
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
  auto range = out()->GetZ3Sort(ctx);
  std::vector<z3::sort> domains;
  for (size_t i = 0; i != arg_num(); i++) {
    domains.push_back(arg(i)->GetZ3Sort(ctx));
  }
  auto prefix = (host()) ? host()->name().str() : "";
  auto f_name = name().format_str(prefix);
  return z3::function(f_name.c_str(), arg_num(), domains.data(), range);
}

std::ostream& Func::Print(std::ostream& out) const {
  return out << "Func." << name();
}

} // namespace ilang
