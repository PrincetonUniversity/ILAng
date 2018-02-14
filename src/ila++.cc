/// \file
/// Source for the c++ API.

#include "ila++.h"
#include "ila/instr_lvl_abs.h"
#include "util/log.h"

namespace ila {

/******************************************************************************/
// ExprRef
/******************************************************************************/
ExprRef::ExprRef(std::shared_ptr<Expr> ptr) : ptr_(ptr) {}

ExprRef::~ExprRef() {}

ExprRef ExprRef::operator-() const {
  auto v = ExprFuse::Negate(get());
  return ExprRef(v);
}

ExprRef ExprRef::operator!() const {
  auto v = ExprFuse::Not(get());
  return ExprRef(v);
}

ExprRef ExprRef::operator~() const {
  auto v = ExprFuse::Complement(get());
  return ExprRef(v);
}

ExprRef ExprRef::operator&(const ExprRef& rhs) const {
  auto v = ExprFuse::And(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator|(const ExprRef& rhs) const {
  auto v = ExprFuse::Or(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator^(const ExprRef& rhs) const {
  auto v = ExprFuse::Xor(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator+(const ExprRef& rhs) const {
  auto v = ExprFuse::Add(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator-(const ExprRef& rhs) const {
  auto v = ExprFuse::Sub(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator&(const bool& rhs) const {
  auto v = ExprFuse::And(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator|(const bool& rhs) const {
  auto v = ExprFuse::Or(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator^(const bool& rhs) const {
  auto v = ExprFuse::Xor(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator+(const int& rhs) const {
  auto v = ExprFuse::Add(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator-(const int& rhs) const {
  auto v = ExprFuse::Sub(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator==(const ExprRef& rhs) const {
  auto v = ExprFuse::Eq(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator!=(const ExprRef& rhs) const {
  auto v = ExprFuse::Ne(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator<(const ExprRef& rhs) const {
  auto v = ExprFuse::Lt(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator>(const ExprRef& rhs) const {
  auto v = ExprFuse::Gt(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator<=(const ExprRef& rhs) const {
  auto v = ExprFuse::Le(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator>=(const ExprRef& rhs) const {
  auto v = ExprFuse::Ge(get(), rhs.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator==(const bool& rhs) const {
  auto v = ExprFuse::Eq(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator==(const int& rhs) const {
  auto v = ExprFuse::Eq(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator!=(const int& rhs) const {
  auto v = ExprFuse::Ne(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator<(const int& rhs) const {
  auto v = ExprFuse::Lt(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator>(const int& rhs) const {
  auto v = ExprFuse::Gt(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator<=(const int& rhs) const {
  auto v = ExprFuse::Le(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::operator>=(const int& rhs) const {
  auto v = ExprFuse::Ge(get(), rhs);
  return ExprRef(v);
}

ExprRef ExprRef::Load(const ExprRef& addr) const {
  auto v = ExprFuse::Load(get(), addr.get());
  return ExprRef(v);
}

ExprRef ExprRef::Store(const ExprRef& addr, const ExprRef& data) const {
  auto v = ExprFuse::Store(get(), addr.get(), data.get());
  return ExprRef(v);
}

ExprRef ExprRef::Append(const ExprRef& lsbv) const {
  auto v = ExprFuse::Concat(get(), lsbv.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator()(const int& hi, const int& lo) const {
  auto v = ExprFuse::Extract(get(), hi, lo);
  return ExprRef(v);
}

ExprRef Concat(const ExprRef& msbv, const ExprRef& lsbv) {
  auto v = ExprFuse::Concat(msbv.get(), lsbv.get());
  return ExprRef(v);
}

ExprRef Imply(const ExprRef& ante, const ExprRef& cons) {
  auto v = ExprFuse::Imply(ante.get(), cons.get());
  return ExprRef(v);
}

ExprRef Ite(const ExprRef& cond, const ExprRef& t, const ExprRef& f) {
  auto v = ExprFuse::Ite(cond.get(), t.get(), f.get());
  return ExprRef(v);
}

ExprRef BoolConst(bool val) {
  auto v = ExprFuse::BoolConst(val);
  return ExprRef(v);
}

ExprRef BvConst(const int& bv_val, const int& bit_width) {
  auto v = ExprFuse::BvConst(bv_val, bit_width);
  return ExprRef(v);
}

ExprRef MemConst(const int& def_val, const std::map<int, int>& vals,
                 const int& addr_width, const int& data_width) {
  auto v = ExprFuse::MemConst(MemVal(def_val, vals), addr_width, data_width);
  return ExprRef(v);
}

/******************************************************************************/
// InstrRef
/******************************************************************************/
InstrRef::InstrRef(std::shared_ptr<Instr> ptr) : ptr_(ptr) {}

InstrRef::~InstrRef() {}

void InstrRef::SetDecode(const ExprRef& decode) {
  ptr_->SetDecode(decode.get());
}

void InstrRef::SetUpdate(const ExprRef& state, const ExprRef& update) {
  ptr_->AddUpdate(state.get(), update.get());
}

/******************************************************************************/
// Ila
/******************************************************************************/
Ila::Ila(const std::string& name) { ptr_ = InstrLvlAbs::New(name); }

Ila::Ila(std::shared_ptr<InstrLvlAbs> ptr) : ptr_(ptr) {}

Ila::~Ila() {}

ExprRef Ila::NewBoolState(const std::string& name) {
  auto v = ptr_->NewBoolState(name);
  return ExprRef(v);
}

ExprRef Ila::NewBvState(const std::string& name, const int& bit_width) {
  auto v = ptr_->NewBvState(name, bit_width);
  return ExprRef(v);
}

ExprRef Ila::NewMemState(const std::string& name, const int& addr_width,
                         const int& data_width) {
  auto v = ptr_->NewMemState(name, addr_width, data_width);
  return ExprRef(v);
}

ExprRef Ila::NewBoolInput(const std::string& name) {
  auto v = ptr_->NewBoolInput(name);
  return ExprRef(v);
}

ExprRef Ila::NewBvInput(const std::string& name, const int& bit_width) {
  auto v = ptr_->NewBvInput(name, bit_width);
  return ExprRef(v);
}

void Ila::AddInit(const ExprRef& init) { ptr_->AddInit(init.get()); }

void Ila::SetFetch(const ExprRef& fetch) { ptr_->SetFetch(fetch.get()); }

void Ila::SetValid(const ExprRef& valid) { ptr_->SetValid(valid.get()); }

InstrRef Ila::NewInstr(const std::string& name) {
  auto i = ptr_->NewInstr(name);
  return InstrRef(i);
}

Ila Ila::NewChild(const std::string& name) {
  auto m = ptr_->NewChild(name);
  return Ila(m);
}

void LogLevel(const int& lvl) { SetLogLevel(lvl); }

void LogPath(const std::string& path) { SetLogPath(path); }

void LogToErr(bool to_err) {
  if (to_err) {
    SetToStdErr(1);
    ILA_DLOG("API_INFO") << "Log to Standard Error channel.";

  } else {
    SetToStdErr(0);
    ILA_DLOG("API_INFO") << "Log to file.";
  }
}

void EnableDebug(const std::string& tag) { DebugLog::Enable(tag); }

void DisableDebug(const std::string& tag) { DebugLog::Disable(tag); }

} // namespace ila

