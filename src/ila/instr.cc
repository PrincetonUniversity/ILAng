/// \file
/// The source for the class Instr.

#include <ilang/ila/instr.h>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/util/log.h>

namespace ilang {

Instr::Instr(const std::string& name, const InstrLvlAbsPtr& host)
    : Object(name), host_(host) {
  // initialization for other components
  updates_.clear();
}

Instr::~Instr(){};

InstrPtr Instr::New(const std::string& name, InstrLvlAbsPtr host) {
  return std::make_shared<Instr>(name, host);
}

void Instr::set_decode(const ExprPtr& decode) {
  ILA_ERROR_IF(decode_)
      << "Decode for " << name()
      << "has been assigned. Use ForceSetDecode to overwrite.";

  if (!decode_) {
    ForceSetDecode(decode);
  }
}

void Instr::set_update(const std::string& name, const ExprPtr& update) {
  auto pos = updates_.find(name);

  ILA_ERROR_IF(pos != updates_.end())
      << "Update function for " << name
      << " has been assigned. Use ForceAddUpdate to overwrite the result.";

  if (pos == updates_.end()) {
    ForceAddUpdate(name, update);
  }
}

void Instr::set_update(const ExprPtr& state, const ExprPtr& update) {
  std::string name = state->name().str();
  set_update(name, update);
}

void Instr::set_program(const InstrLvlAbsPtr& program) {
  ILA_ASSERT(!prog_) << "Child-program has been defined for " << name();
  ILA_ASSERT(program) << "NULL program.";
  prog_ = program;
}

ExprPtr Instr::update(const std::string& name) const {
  auto pos = updates_.find(name);

  if (pos != updates_.end()) {
    return pos->second;
  } else {
    return nullptr;
  }
}

ExprPtr Instr::update(const ExprPtr& state) const {
  std::string name = state->name().str();
  return update(name);
}

Instr::StateNameSet Instr::updated_states() const {
  StateNameSet ret_;
  for (const auto& pos : updates_)
    ret_.insert(pos.first);
  return ret_;
}

void Instr::ForceSetDecode(const ExprPtr& decode) {
  ILA_NOT_NULL(decode); // setting NULL pointer to decode function
  ILA_CHECK(decode->is_bool()) << "Decode must have Boolean sort.";

  decode_ = Unify(decode);
}

void Instr::ForceAddUpdate(const std::string& name, const ExprPtr& update) {
  ExprPtr sim_update = Unify(update);
  updates_[name] = sim_update;
}

std::ostream& Instr::Print(std::ostream& out) const {
  out << "Instr." << name();
  return out;
}

std::ostream& operator<<(std::ostream& out, InstrPtr i) {
  return i->Print(out);
}

std::ostream& operator<<(std::ostream& out, InstrCnstPtr i) {
  return i->Print(out);
}

ExprPtr Instr::Unify(const ExprPtr& e) { return host_ ? host_->Unify(e) : e; }

} // namespace ilang
