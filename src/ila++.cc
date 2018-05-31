/// \file
/// Source for the c++ API.

#include "ila++.h"
#include "ila/instr_lvl_abs.h"
#include "util/log.h"
#include "verify/unroller.h"

namespace ila {

/******************************************************************************/
// SortRef
/******************************************************************************/
SortRef::SortRef(SortPtr ptr) : ptr_(ptr) {}

SortRef::~SortRef() {}

SortRef SortRef::BOOL() {
  auto s = Sort::MakeBoolSort();
  return SortRef(s);
}

SortRef SortRef::BV(const int& bit_w) {
  auto s = Sort::MakeBvSort(bit_w);
  return SortRef(s);
}

SortRef SortRef::MEM(const int& addr_w, const int& data_w) {
  auto s = Sort::MakeMemSort(addr_w, data_w);
  return SortRef(s);
}

/******************************************************************************/
// ExprRef
/******************************************************************************/
ExprRef::ExprRef(ExprPtr ptr) : ptr_(ptr) {}

ExprRef::~ExprRef() {}

ExprRef ExprRef::Load(const ExprRef& addr) const {
  auto v = ExprFuse::Load(get(), addr.get());
  return ExprRef(v);
}

ExprRef ExprRef::Store(const ExprRef& addr, const ExprRef& data) const {
  auto v = ExprFuse::Store(get(), addr.get(), data.get());
  return ExprRef(v);
}

ExprRef ExprRef::Load(const int& addr) const {
  auto v = ExprFuse::Load(get(), addr);
  return ExprRef(v);
}

ExprRef ExprRef::Store(const int& addr, const int& data) const {
  auto v = ExprFuse::Store(get(), addr, data);
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

ExprRef Load(const ExprRef& mem, const int& addr) {
  auto v = ExprFuse::Load(mem.get(), addr);
  return ExprRef(v);
}

ExprRef Store(const ExprRef& mem, const int& addr, const int& data) {
  auto v = ExprFuse::Store(mem.get(), addr, data);
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
// FuncRef
/******************************************************************************/
FuncRef::FuncRef(const std::string& name, const SortRef& range) {
  ptr_ = Func::New(name, range.get());
}

FuncRef::FuncRef(const std::string& name, const SortRef& range,
                 const SortRef& d0) {
  ptr_ = Func::New(name, range.get(), d0.get());
}

FuncRef::FuncRef(const std::string& name, const SortRef& range,
                 const SortRef& d0, const SortRef& d1) {
  ptr_ = Func::New(name, range.get(), d0.get(), d1.get());
}

FuncRef::FuncRef(const std::string& name, const SortRef& range,
                 const std::vector<SortRef>& dvec) {
  std::vector<SortPtr> args;
  for (size_t i = 0; i != dvec.size(); i++)
    args.push_back(dvec[i].get());
  ptr_ = Func::New(name, range.get(), args);
}

FuncRef::~FuncRef() {}

ExprRef FuncRef::operator()() const {
  auto v = ExprFuse::AppFunc(get());
  return ExprRef(v);
}

ExprRef FuncRef::operator()(const ExprRef& arg0) const {
  auto v = ExprFuse::AppFunc(get(), arg0.get());
  return ExprRef(v);
}

ExprRef FuncRef::operator()(const ExprRef& arg0, const ExprRef& arg1) const {
  auto v = ExprFuse::AppFunc(get(), arg0.get(), arg1.get());
  return ExprRef(v);
}

ExprRef FuncRef::operator()(const std::vector<ExprRef>& argvec) const {
  std::vector<ExprPtr> args;
  for (size_t i = 0; i != argvec.size(); i++)
    args.push_back(argvec[i].get());
  auto v = ExprFuse::AppFunc(get(), args);
  return ExprRef(v);
}

/******************************************************************************/
// InstrRef
/******************************************************************************/
InstrRef::InstrRef(InstrPtr ptr) : ptr_(ptr) {}

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

Ila::Ila(InstrLvlAbsPtr ptr) : ptr_(ptr) {}

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

size_t Ila::input_num() const { return ptr_->input_num(); }

size_t Ila::state_num() const { return ptr_->state_num(); }

size_t Ila::instr_num() const { return ptr_->instr_num(); }

size_t Ila::child_num() const { return ptr_->child_num(); }

size_t Ila::init_num() const { return ptr_->init_num(); }

ExprRef Ila::fetch() const { return ExprRef(ptr_->fetch()); }

ExprRef Ila::valid() const { return ExprRef(ptr_->valid()); }

ExprRef Ila::input(const size_t& i) const { return ExprRef(ptr_->input(i)); }

ExprRef Ila::state(const size_t& i) const { return ExprRef(ptr_->state(i)); }

InstrRef Ila::instr(const size_t& i) const { return InstrRef(ptr_->instr(i)); }

Ila Ila::child(const size_t& i) const { return Ila(ptr_->child(i)); }

ExprRef Ila::init(const size_t& i) const { return ExprRef(ptr_->init(i)); }

ExprRef Ila::input(const std::string& name) const {
  return ExprRef(ptr_->input(name));
}

ExprRef Ila::state(const std::string& name) const {
  return ExprRef(ptr_->state(name));
}

InstrRef Ila::instr(const std::string& name) const {
  return InstrRef(ptr_->instr(name));
}

Ila Ila::child(const std::string& name) const { return Ila(ptr_->child(name)); }

std::ostream& operator<<(std::ostream& out, const ExprRef& expr) {
  return out << expr.get();
}

std::ostream& operator<<(std::ostream& out, const InstrRef& instr) {
  return out << instr.get();
}

std::ostream& operator<<(std::ostream& out, const Ila& ila) {
  return out << ila.get();
}

IlaZ3Unroller::IlaZ3Unroller(z3::context& ctx) : ctx_(ctx) {
  univ_ = std::make_shared<MonoUnroll>(ctx);
}

IlaZ3Unroller::~IlaZ3Unroller() {}

void IlaZ3Unroller::SetExtraSuffix(const std::string& suff) {
  extra_suff_ = suff;
  univ_->SetExtraSuffix(suff);
}

void IlaZ3Unroller::ResetExtraSuffix() {
  extra_suff_ = "";
  univ_->ResetExtraSuffix();
}

z3::expr IlaZ3Unroller::UnrollMonoConn(const Ila& top, const int& k,
                                       const int& init) {
  auto u = std::make_shared<MonoUnroll>(ctx_);
  InitializeUnroller(u);
  return u->MonoAssn(top.get(), k, init);
}

z3::expr IlaZ3Unroller::UnrollMonoFree(const Ila& top, const int& k,
                                       const int& init) {
  auto u = std::make_shared<MonoUnroll>(ctx_);
  InitializeUnroller(u);
  return u->MonoNone(top.get(), k, init);
}

z3::expr IlaZ3Unroller::UnrollPathConn(const std::vector<InstrRef>& path,
                                       const int& init) {
  auto u = std::make_shared<PathUnroll>(ctx_);
  InitializeUnroller(u);
  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != path.size(); i++) {
    seq.push_back(path.at(i).get());
  }
  return u->PathAssn(seq, init);
}

z3::expr IlaZ3Unroller::UnrollPathFree(const std::vector<InstrRef>& path,
                                       const int& init) {
  auto u = std::make_shared<PathUnroll>(ctx_);
  InitializeUnroller(u);
  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != path.size(); i++) {
    seq.push_back(path.at(i).get());
  }
  return u->PathNone(seq, init);
}

z3::expr IlaZ3Unroller::CurrState(const ExprRef& v, const int& t) {
  return univ_->CurrState(v.get(), t);
}

z3::expr IlaZ3Unroller::NextState(const ExprRef& v, const int& t) {
  return univ_->NextState(v.get(), t);
}

z3::expr IlaZ3Unroller::GetZ3Expr(const ExprRef& v, const int& t) {
  return univ_->GetZ3Expr(v.get(), t);
}

z3::expr IlaZ3Unroller::Equal(const ExprRef& va, const int& ta,
                              const ExprRef& vb, const int& tb) {
  return univ_->Equal(va.get(), ta, vb.get(), tb);
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

