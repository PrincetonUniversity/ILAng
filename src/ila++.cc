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

ExprRef ExprRef::operator()(const int& idx) const {
  return ExprFuse::Extract(get(), idx, idx);
}

ExprRef ExprRef::ZExt(const int& length) const {
  auto v = ExprFuse::ZExt(get(), length);
  return ExprRef(v);
}

ExprRef ExprRef::SExt(const int& length) const {
  auto v = ExprFuse::SExt(get(), length);
  return ExprRef(v);
}

void ExprRef::ReplaceArg(const int& i, const ExprRef& new_arg) {
  get()->replace_arg(i, new_arg.get());
}

void ExprRef::ReplaceArg(const ExprRef& org_arg, const ExprRef& new_arg) {
  get()->replace_arg(org_arg.get(), new_arg.get());
}

ExprRef operator-(const ExprRef& a) {
  auto v = ExprFuse::Negate(a.get());
  return ExprRef(v);
}

ExprRef operator!(const ExprRef& a) {
  auto v = ExprFuse::Not(a.get());
  return ExprRef(v);
}

ExprRef operator~(const ExprRef& a) {
  auto v = ExprFuse::Complement(a.get());
  return ExprRef(v);
}

ExprRef operator&(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::And(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator|(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Or(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator^(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Xor(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator<<(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Shl(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator>>(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Ashr(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Lshr(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Lshr(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator+(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Add(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator-(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Sub(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator&(const ExprRef& a, const bool& b) {
  auto v = ExprFuse::And(a.get(), b);
  return ExprRef(v);
}

ExprRef operator|(const ExprRef& a, const bool& b) {
  auto v = ExprFuse::Or(a.get(), b);
  return ExprRef(v);
}

ExprRef operator^(const ExprRef& a, const bool& b) {
  auto v = ExprFuse::Xor(a.get(), b);
  return ExprRef(v);
}

ExprRef operator<<(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Shl(a.get(), b);
  return ExprRef(v);
}

ExprRef operator>>(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Ashr(a.get(), b);
  return ExprRef(v);
}

ExprRef Lshr(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Lshr(a.get(), b);
  return ExprRef(v);
}

ExprRef operator+(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Add(a.get(), b);
  return ExprRef(v);
}

ExprRef operator-(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Sub(a.get(), b);
  return ExprRef(v);
}

ExprRef operator==(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Eq(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator!=(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Ne(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator<(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Lt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator>(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Gt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator<=(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Le(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator>=(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Ge(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Ult(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Ult(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Ugt(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Ugt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Ule(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Ule(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Uge(const ExprRef& a, const ExprRef& b) {
  auto v = ExprFuse::Uge(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator==(const ExprRef& a, const bool& b) {
  auto v = ExprFuse::Eq(a.get(), b);
  return ExprRef(v);
}

ExprRef operator==(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Eq(a.get(), b);
  return ExprRef(v);
}

ExprRef operator!=(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Ne(a.get(), b);
  return ExprRef(v);
}

ExprRef operator<(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Lt(a.get(), b);
  return ExprRef(v);
}

ExprRef operator>(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Gt(a.get(), b);
  return ExprRef(v);
}

ExprRef operator<=(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Le(a.get(), b);
  return ExprRef(v);
}

ExprRef operator>=(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Ge(a.get(), b);
  return ExprRef(v);
}

ExprRef Ult(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Ult(a.get(), b);
  return ExprRef(v);
}

ExprRef Ugt(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Ugt(a.get(), b);
  return ExprRef(v);
}

ExprRef Ule(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Ule(a.get(), b);
  return ExprRef(v);
}

ExprRef Uge(const ExprRef& a, const int& b) {
  auto v = ExprFuse::Uge(a.get(), b);
  return ExprRef(v);
}

ExprRef Load(const ExprRef& mem, const ExprRef& addr) {
  auto v = ExprFuse::Load(mem.get(), addr.get());
  return ExprRef(v);
}

ExprRef Store(const ExprRef& mem, const ExprRef& addr, const ExprRef& data) {
  auto v = ExprFuse::Store(mem.get(), addr.get(), data.get());
  return ExprRef(v);
}

ExprRef Concat(const ExprRef& msbv, const ExprRef& lsbv) {
  auto v = ExprFuse::Concat(msbv.get(), lsbv.get());
  return ExprRef(v);
}

ExprRef Extract(const ExprRef& bv, const int& hi, const int& lo) {
  auto v = ExprFuse::Extract(bv.get(), hi, lo);
  return ExprRef(v);
}

ExprRef SelectBit(const ExprRef& bv, const int& idx) {
  auto v = ExprFuse::Extract(bv.get(), idx, idx);
  return ExprRef(v);
}

ExprRef ZExt(const ExprRef& bv, const int& length) {
  auto v = ExprFuse::ZExt(bv.get(), length);
  return ExprRef(v);
}

ExprRef SExt(const ExprRef& bv, const int& length) {
  auto v = ExprFuse::SExt(bv.get(), length);
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

bool TopEqual(const ExprRef& a, const ExprRef& b) {
  return ExprFuse::TopEq(a.get(), b.get());
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

