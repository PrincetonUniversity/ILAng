/// \file
/// The source for the class Instr.

#include "ila/instr.h"

namespace ila {

typedef Instr::InstrLvlAbsPtr InstrLvlAbsPtr;

Instr::Instr(const std::string& name, ExprMngrPtr expr_mngr) {
  // update name if specified
  if (name != "")
    set_name(name);
  // update ast simplifier if specified
  if (expr_mngr) {
    expr_mngr_ = expr_mngr;
    simplify_ = true;
  } else {
    expr_mngr = NULL;
    simplify_ = false;
  }
  // initialization for other components
  updates_.clear();
}

Instr::~Instr(){};

InstrPtr Instr::New(const std::string& name, ExprMngrPtr expr_mngr) {
  return std::make_shared<Instr>(name, expr_mngr);
}

bool Instr::has_view() const { return has_view_; }

bool Instr::has_simplify() const { return simplify_; }

InstrLvlAbsPtr Instr::host() const { return host_; }

void Instr::set_view(bool v) { has_view_ = v; }

void Instr::set_simplify(bool s) { simplify_ = s; }

void Instr::set_mngr(const ExprMngrPtr mngr) {
  ILA_NOT_NULL(mngr);
  expr_mngr_ = mngr;
}

void Instr::set_host(const InstrLvlAbsPtr host) { host_ = host; }

void Instr::SetDecode(const ExprPtr decode) {
  ILA_ERROR_IF(decode_ != NULL)
      << "Decode for " << name()
      << "has been assigned. Use ForceSetDecode to overwrite.\n";

  if (decode_ == NULL) {
    ForceSetDecode(decode);
  }
}

void Instr::ForceSetDecode(const ExprPtr decode) {
  ILA_NOT_NULL(decode); // setting NULL pointer to decode function
  ILA_CHECK(decode->is_bool()) << "Decode must have Boolean sort.\n";

  decode_ = expr_mngr_->Simplify(decode, simplify_);
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
  ExprPtr sim_update = expr_mngr_->Simplify(update, simplify_);
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

