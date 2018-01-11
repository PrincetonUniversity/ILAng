/// \file
/// The source for the class Instr.

#include "ila/instr.h"

namespace ila {

Instr::Instr(const std::string& name, bool simplify, ExprSimplifier& expr_mngr)
    : Object(name), simplify_(simplify), expr_mngr_(expr_mngr) {
  decode_ = NULL;
  has_view_ = false;
  updates_.clear();
}

Instr::~Instr() {}

bool Instr::has_view() const { return has_view_; }

void Instr::SetDecode(const ExprPtr decode) {
  ILA_ERROR_IF(decode_ != NULL)
      << "Decode for " << name()
      << "has been assigned. Use ForceSetDecode to overwrite.\n";

  if (decode_ == NULL) {
    ForceSetDecode(decode);
  }
}

void Instr::ForceSetDecode(const ExprPtr decode) {
  ILA_CHECK(decode->is_bool()) << "Decode must have Boolean sort.\n";

  ExprPtr sim_decode = NULL;

  if (simplify_) {
    sim_decode = expr_mngr_.Simplify(decode);
  } else {
    sim_decode = decode;
  }

  decode_ = sim_decode;
}

void Instr::AddUpdate(const std::string& name, const ExprPtr update) {
  auto pos = updates_.find(name);

  ILA_ERROR_IF(pos != updates_.end())
      << "Update function for " << name
      << " has been assigned. Use ForceAddUpdate to overwrite the result.\n";

  if (pos == updates_.end()) {
    ForceAddUpdate(name, update);
  }
}

void Instr::AddUpdate(const ExprPtr state, const ExprPtr update) {
  std::string name = state->name().str();
  AddUpdate(name, update);
}

void Instr::ForceAddUpdate(const std::string& name, const ExprPtr update) {
  ExprPtr sim_update = NULL;

  if (simplify_) {
    sim_update = expr_mngr_.Simplify(update);
  } else {
    sim_update = update;
  }

  updates_[name] = sim_update;
}

ExprPtr Instr::GetDecode() const { return decode_; }

ExprPtr Instr::GetUpdate(const std::string& name) const {
  auto pos = updates_.find(name);

  if (pos != updates_.end()) {
    return pos->second;
  } else {
    return NULL;
  }
}

ExprPtr Instr::GetUpdate(const ExprPtr state) const {
  std::string name = state->name().str();
  return GetUpdate(name);
}

std::ostream& Instr::Print(std::ostream& out) const {
  out << "Instr." << name();
  return out;
}

} // namespace ila

