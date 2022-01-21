/// \file
/// Source for the c++ API.

#include <ilang/ilang++.h>

#include <ilang/config.h>
#include <ilang/ila-mngr/pass.h>
#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/ila-mngr/u_unroller.h>
#include <ilang/ila/instr_lvl_abs.h>
#include <ilang/target-itsy/interface.h>
#include <ilang/target-json/interface.h>
#include <ilang/target-sc/ilator.h>
#include <ilang/target-smt/smt_switch_itf.h>
#include <ilang/util/log.h>
#include <ilang/verilog-out/verilog_gen.h>
#include <ilang/vtarget-out/vtarget_gen.h>

#ifdef SMTSWITCH_INTERFACE
#include <smt-switch/smt.h>
#endif // SMTSWITCH_INTERFACE

namespace ilang {

/******************************************************************************/
// Configuration
/******************************************************************************/

bool UnsignedComparison = false;
void SetUnsignedComparison(bool sign) { UnsignedComparison = sign; }

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

int ExprRef::bit_width() const {
  return ptr_->is_bv() ? ptr_->sort()->bit_width() : -1;
}

int ExprRef::addr_width() const {
  return ptr_->is_mem() ? ptr_->sort()->addr_width() : -1;
}

int ExprRef::data_width() const {
  return ptr_->is_mem() ? ptr_->sort()->data_width() : -1;
}

std::string ExprRef::name() const { return ptr_->name().str(); }

ExprRef ExprRef::Load(const ExprRef& addr) const {
  auto v = asthub::Load(get(), addr.get());
  return ExprRef(v);
}

ExprRef ExprRef::Store(const ExprRef& addr, const ExprRef& data) const {
  auto v = asthub::Store(get(), addr.get(), data.get());
  return ExprRef(v);
}

ExprRef ExprRef::Load(const NumericType& addr) const {
  auto v = asthub::Load(get(), addr);
  return ExprRef(v);
}

ExprRef ExprRef::Store(const NumericType& addr, const NumericType& data) const {
  auto v = asthub::Store(get(), addr, data);
  return ExprRef(v);
}

ExprRef ExprRef::Append(const ExprRef& lsbv) const {
  auto v = asthub::Concat(get(), lsbv.get());
  return ExprRef(v);
}

ExprRef ExprRef::operator()(const int& hi, const int& lo) const {
  auto v = asthub::Extract(get(), hi, lo);
  return ExprRef(v);
}

ExprRef ExprRef::operator()(const int& idx) const {
  return asthub::Extract(get(), idx, idx);
}

ExprRef ExprRef::ZExt(const int& length) const {
  auto v = asthub::ZExt(get(), length);
  return ExprRef(v);
}

ExprRef ExprRef::SExt(const int& length) const {
  auto v = asthub::SExt(get(), length);
  return ExprRef(v);
}

void ExprRef::ReplaceArg(const int& i, const ExprRef& new_arg) {
  get()->replace_arg(i, new_arg.get());
}

void ExprRef::ReplaceArg(const ExprRef& org_arg, const ExprRef& new_arg) {
  get()->replace_arg(org_arg.get(), new_arg.get());
}

bool ExprRef::SetEntryNum(const int& num) {
  auto res = asthub::SetMemSize(get(), num);
  return res;
}

int ExprRef::GetEntryNum() {
  auto num = asthub::GetMemSize(get());
  return num;
}

ExprRef operator-(const ExprRef& a) {
  auto v = asthub::Negate(a.get());
  return ExprRef(v);
}

ExprRef operator!(const ExprRef& a) {
  auto v = asthub::Not(a.get());
  return ExprRef(v);
}

ExprRef operator~(const ExprRef& a) {
  auto v = asthub::Complement(a.get());
  return ExprRef(v);
}

ExprRef operator&(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::And(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator|(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Or(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator^(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Xor(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator<<(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Shl(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator>>(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Ashr(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Lshr(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Lshr(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator+(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Add(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator-(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Sub(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator/(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Div(a.get(), b.get());
  return ExprRef(v);
}

ExprRef SRem(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::SRem(a.get(), b.get());
  return ExprRef(v);
}

ExprRef URem(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::URem(a.get(), b.get());
  return ExprRef(v);
}

ExprRef SMod(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::SMod(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator*(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Mul(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator&(const ExprRef& a, const bool& b) {
  auto v = asthub::And(a.get(), b);
  return ExprRef(v);
}

ExprRef operator|(const ExprRef& a, const bool& b) {
  auto v = asthub::Or(a.get(), b);
  return ExprRef(v);
}

ExprRef operator^(const ExprRef& a, const bool& b) {
  auto v = asthub::Xor(a.get(), b);
  return ExprRef(v);
}

ExprRef operator<<(const ExprRef& a, const int& b) {
  auto v = asthub::Shl(a.get(), b);
  return ExprRef(v);
}

ExprRef operator>>(const ExprRef& a, const int& b) {
  auto v = asthub::Ashr(a.get(), b);
  return ExprRef(v);
}

ExprRef Lshr(const ExprRef& a, const int& b) {
  auto v = asthub::Lshr(a.get(), b);
  return ExprRef(v);
}

ExprRef operator+(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Add(a.get(), b);
  return ExprRef(v);
}

ExprRef operator-(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Sub(a.get(), b);
  return ExprRef(v);
}

ExprRef operator*(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Mul(a.get(), b);
  return ExprRef(v);
}

ExprRef operator==(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Eq(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator!=(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Ne(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator<(const ExprRef& a, const ExprRef& b) {
  auto v = UnsignedComparison ? asthub::Ult(a.get(), b.get())
                              : asthub::Lt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator>(const ExprRef& a, const ExprRef& b) {

  auto v = UnsignedComparison ? asthub::Ugt(a.get(), b.get())
                              : asthub::Gt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator<=(const ExprRef& a, const ExprRef& b) {
  auto v = UnsignedComparison ? asthub::Ule(a.get(), b.get())
                              : asthub::Le(a.get(), b.get());
  return ExprRef(v);
}

ExprRef operator>=(const ExprRef& a, const ExprRef& b) {
  auto v = UnsignedComparison ? asthub::Uge(a.get(), b.get())
                              : asthub::Ge(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Ult(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Ult(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Ugt(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Ugt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Ule(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Ule(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Uge(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Uge(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Slt(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Lt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Sgt(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Gt(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Sle(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Le(a.get(), b.get());
  return ExprRef(v);
}

ExprRef Sge(const ExprRef& a, const ExprRef& b) {
  auto v = asthub::Ge(a.get(), b.get());
  return ExprRef(v);
}

#if 0
ExprRef operator==(const ExprRef& a, const bool& b) {
  auto v = asthub::Eq(a.get(), b);
  return ExprRef(v);
}
#endif

ExprRef operator==(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Eq(a.get(), b);
  return ExprRef(v);
}

ExprRef operator!=(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Ne(a.get(), b);
  return ExprRef(v);
}

ExprRef operator<(const ExprRef& a, const NumericType& b) {
  auto v =
      UnsignedComparison ? asthub::Ult(a.get(), b) : asthub::Lt(a.get(), b);
  return ExprRef(v);
}

ExprRef operator>(const ExprRef& a, const NumericType& b) {
  auto v =
      UnsignedComparison ? asthub::Ugt(a.get(), b) : asthub::Gt(a.get(), b);
  return ExprRef(v);
}

ExprRef operator<=(const ExprRef& a, const NumericType& b) {
  auto v =
      UnsignedComparison ? asthub::Ule(a.get(), b) : asthub::Le(a.get(), b);
  return ExprRef(v);
}

ExprRef operator>=(const ExprRef& a, const NumericType& b) {
  auto v =
      UnsignedComparison ? asthub::Uge(a.get(), b) : asthub::Ge(a.get(), b);
  return ExprRef(v);
}

ExprRef Ult(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Ult(a.get(), b);
  return ExprRef(v);
}

ExprRef Ugt(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Ugt(a.get(), b);
  return ExprRef(v);
}

ExprRef Ule(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Ule(a.get(), b);
  return ExprRef(v);
}

ExprRef Uge(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Uge(a.get(), b);
  return ExprRef(v);
}

ExprRef Slt(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Lt(a.get(), b);
  return ExprRef(v);
}

ExprRef Sgt(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Gt(a.get(), b);
  return ExprRef(v);
}

ExprRef Sle(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Le(a.get(), b);
  return ExprRef(v);
}

ExprRef Sge(const ExprRef& a, const NumericType& b) {
  auto v = asthub::Ge(a.get(), b);
  return ExprRef(v);
}

ExprRef Load(const ExprRef& mem, const ExprRef& addr) {
  auto v = asthub::Load(mem.get(), addr.get());
  return ExprRef(v);
}

ExprRef Store(const ExprRef& mem, const ExprRef& addr, const ExprRef& data) {
  auto v = asthub::Store(mem.get(), addr.get(), data.get());
  return ExprRef(v);
}

ExprRef Load(const ExprRef& mem, const NumericType& addr) {
  auto v = asthub::Load(mem.get(), addr);
  return ExprRef(v);
}

ExprRef Store(const ExprRef& mem, const NumericType& addr,
              const NumericType& data) {
  auto v = asthub::Store(mem.get(), addr, data);
  return ExprRef(v);
}

ExprRef Concat(const ExprRef& msbv, const ExprRef& lsbv) {
  auto v = asthub::Concat(msbv.get(), lsbv.get());
  return ExprRef(v);
}

ExprRef Extract(const ExprRef& bv, const int& hi, const int& lo) {
  auto v = asthub::Extract(bv.get(), hi, lo);
  return ExprRef(v);
}

ExprRef SelectBit(const ExprRef& bv, const int& idx) {
  auto v = asthub::Extract(bv.get(), idx, idx);
  return ExprRef(v);
}

ExprRef ZExt(const ExprRef& bv, const int& length) {
  auto v = asthub::ZExt(bv.get(), length);
  return ExprRef(v);
}

ExprRef SExt(const ExprRef& bv, const int& length) {
  auto v = asthub::SExt(bv.get(), length);
  return ExprRef(v);
}

ExprRef LRotate(const ExprRef& bv, const int& immediate) {
  auto v = asthub::LRotate(bv.get(), immediate);
  return ExprRef(v);
}

ExprRef RRotate(const ExprRef& bv, const int& immediate) {
  auto v = asthub::RRotate(bv.get(), immediate);
  return ExprRef(v);
}

ExprRef Imply(const ExprRef& ante, const ExprRef& cons) {
  auto v = asthub::Imply(ante.get(), cons.get());
  return ExprRef(v);
}

ExprRef Ite(const ExprRef& cond, const ExprRef& t, const ExprRef& f) {
  auto v = asthub::Ite(cond.get(), t.get(), f.get());
  return ExprRef(v);
}

ExprRef BoolConst(bool val) {
  auto v = asthub::BoolConst(val);
  return ExprRef(v);
}

ExprRef BvConst(const NumericType& bv_val, const int& bit_width) {
  auto v = asthub::BvConst(bv_val, bit_width);
  return ExprRef(v);
}

ExprRef MemConst(const NumericType& def_val,
                 const std::map<NumericType, NumericType>& vals,
                 const int& addr_width, const int& data_width) {
  auto v = asthub::MemConst(MemVal(def_val, vals), addr_width, data_width);
  return ExprRef(v);
}

bool TopEqual(const ExprRef& a, const ExprRef& b) {
  return asthub::TopEq(a.get(), b.get());
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

std::string FuncRef::name() const { return ptr_->name().str(); }

FuncRef::~FuncRef() {}

ExprRef FuncRef::operator()() const {
  auto v = asthub::AppFunc(get());
  return ExprRef(v);
}

ExprRef FuncRef::operator()(const ExprRef& arg0) const {
  auto v = asthub::AppFunc(get(), arg0.get());
  return ExprRef(v);
}

ExprRef FuncRef::operator()(const ExprRef& arg0, const ExprRef& arg1) const {
  auto v = asthub::AppFunc(get(), arg0.get(), arg1.get());
  return ExprRef(v);
}

ExprRef FuncRef::operator()(const std::vector<ExprRef>& argvec) const {
  std::vector<ExprPtr> args;
  for (size_t i = 0; i != argvec.size(); i++)
    args.push_back(argvec[i].get());
  auto v = asthub::AppFunc(get(), args);
  return ExprRef(v);
}

/******************************************************************************/
// InstrRef
/******************************************************************************/
InstrRef::InstrRef(InstrPtr ptr) : ptr_(ptr) {}

InstrRef::~InstrRef() {}

void InstrRef::SetDecode(const ExprRef& decode) {
  ptr_->set_decode(decode.get());
}

ExprRef InstrRef::GetDecode() const { return ptr_->decode(); }

void InstrRef::SetUpdate(const ExprRef& state, const ExprRef& update) {
  ptr_->set_update(state.get(), update.get());
}

ExprRef InstrRef::GetUpdate(const ExprRef& state) const {
  return ptr_->update(state.get());
}

void InstrRef::SetProgram(const Ila& prog) { ptr_->set_program(prog.get()); }

void InstrRef::ExportToVerilog(std::ostream& fout) const {
  VerilogGenerator vgen(VerilogGenerator::VlgGenConfig(
      true)); // overwrite default configuration : memory is external
  vgen.ExportTopLevelInstr(ptr_);
  vgen.DumpToFile(fout);
}

void InstrRef::ExportToVerilogWithChild(std::ostream& fout) const {
  auto dept_ila_ptr = absknob::ExtrDeptModl(ptr_, ptr_->name().str() + "_ila_");
  absknob::FlattenIla(dept_ila_ptr);

  VerilogGenerator vgen(VerilogGenerator::VlgGenConfig(
      true)); // overwrite default configuration : memory is external
  vgen.ExportIla(dept_ila_ptr);
  vgen.DumpToFile(fout);
}

std::string InstrRef::name() const { return ptr_->name().str(); }

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

std::string Ila::name() const { return ptr_->name().str(); }

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

void Ila::ExportToVerilog(std::ostream& fout) const {
  VerilogGenerator vgen(VerilogGenerator::VlgGenConfig(
      true)); // overwrite default configuration : memory is external
  vgen.ExportIla(ptr_);
  vgen.DumpToFile(fout);
}

void Ila::FlattenHierarchy() { absknob::FlattenIla(ptr_); }

bool Ila::ExecutePass(const std::vector<PassID>& passes) const {
  auto status = true;
  for (const auto& id : passes) {
    switch (id) {
    case PassID::SANITY_CHECK_AND_FIX: {
      status &= pass::SanityCheckAndFix(ptr_);
      break;
    }
    case PassID::SIMPLIFY_SYNTACTIC: {
      status &= pass::SimplifySyntactic(ptr_);
      break;
    }
    case PassID::SIMPLIFY_SEMANTIC: {
      status &= pass::SimplifySemantic(ptr_);
      break;
    }
    case PassID::REWRITE_CONDITIONAL_STORE: {
      status &= pass::RewriteConditionalStore(ptr_);
      break;
    }
    case PassID::REWRITE_LOAD_FROM_STORE: {
      status &= pass::RewriteStoreLoad(ptr_);
      break;
    }
    };
  }
  return status;
}

std::ostream& operator<<(std::ostream& out, const ExprRef& expr) {
  return out << expr.get();
}

std::ostream& operator<<(std::ostream& out, const InstrRef& instr) {
  return out << instr.get();
}

std::ostream& operator<<(std::ostream& out, const Ila& ila) {
  return out << ila.get();
}

bool ExportIlaPortable(const Ila& ila, const std::string& file_name) {
  return IlaSerDesMngr::SerToFile(ila.get(), file_name);
}

Ila ImportIlaPortable(const std::string& file_name) {
  auto m = IlaSerDesMngr::DesFromFile(file_name);
  return Ila(m);
}

#ifdef SYNTH_INTERFACE
Ila ImportSynthAbstraction(const std::string& file_name,
                           const std::string& ila_name) {
  auto m = ImportSynthAbsFromFile(file_name, ila_name);
  return Ila(m);
}

void ImportChildSynthAbstraction(const std::string& file_name, Ila& parent,
                                 const std::string& ila_name) {
  auto m = ImportSynthAbsFromFileHier(file_name, parent.get(), ila_name);
  ILA_NOT_NULL(m);
  return;
}
#endif // SYNTH_INTERFACE

void ExportSysCSim(const Ila& ila, const std::string& dir_path, bool opt) {
  auto ilator = Ilator(ila.get());
  ilator.Generate(dir_path, opt);
}

IlaZ3Unroller::IlaZ3Unroller(z3::context& ctx, const std::string& suff)
    : ctx_(ctx), extra_suff_(suff) {
  univ_ = std::make_shared<MonoUnroll>(ctx);
}

IlaZ3Unroller::~IlaZ3Unroller() {}

z3::expr IlaZ3Unroller::UnrollMonoConn(const Ila& top, const int& k,
                                       const int& init) {
  auto u = std::make_shared<MonoUnroll>(ctx_, extra_suff_);
  InitializeUnroller(u);
  return u->MonoAssn(top.get(), k, init);
}

z3::expr IlaZ3Unroller::UnrollMonoFree(const Ila& top, const int& k,
                                       const int& init) {
  auto u = std::make_shared<MonoUnroll>(ctx_, extra_suff_);
  InitializeUnroller(u);
  return u->MonoNone(top.get(), k, init);
}

z3::expr IlaZ3Unroller::UnrollPathConn(const std::vector<InstrRef>& path,
                                       const int& init) {
  auto u = std::make_shared<PathUnroll>(ctx_, extra_suff_);
  InitializeUnroller(u);
  std::vector<InstrPtr> seq;
  for (size_t i = 0; i != path.size(); i++) {
    seq.push_back(path.at(i).get());
  }
  return u->PathAssn(seq, init);
}

z3::expr IlaZ3Unroller::UnrollPathSubs(const std::vector<InstrRef>& path,
                                       const int& init) {
  auto u = std::make_shared<PathUnroll>(ctx_, extra_suff_);
  InitializeUnroller(u);
  std::vector<InstrPtr> seq;
  for (auto& instr : path) {
    seq.push_back(instr.get());
  }
  return u->PathSubs(seq, init);
}

z3::expr IlaZ3Unroller::UnrollPathFree(const std::vector<InstrRef>& path,
                                       const int& init) {
  auto u = std::make_shared<PathUnroll>(ctx_, extra_suff_);
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

z3::func_decl IlaZ3Unroller::GetZ3FuncDecl(const FuncRef& f) const {
  return univ_->GetZ3FuncDecl(f.get());
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

#ifdef SMTSWITCH_INTERFACE
smt::Term ResetAndGetSmtTerm(smt::SmtSolver& solver, const ExprRef& expr,
                             const std::string& suffix) {
  solver->reset();
  auto itf = SmtSwitchItf(solver);
  return itf.GetSmtTerm(expr.get(), suffix);
}
#endif // SMTSWITCH_INTERFACE

IlaVerilogRefinementChecker::IlaVerilogRefinementChecker(
      const Ila& ila,
      const std::vector<std::string>& implementation_include_path,
      const std::vector<std::string>& implementation_srcs,
      const std::string& implementation_top_module,
      const std::string& refinement_variable_mapping,
      const std::string& refinement_conditions, 
      const std::string& output_path,
      ModelCheckerSelection backend,
      const RtlVerifyConfig& vtg_config ) {
  
  VerilogVerificationTargetGenerator checker(
    implementation_include_path,
    implementation_srcs,
    implementation_top_module,
    refinement_variable_mapping,
    refinement_conditions,
    output_path,
    ila.get(),
    backend,
    vtg_config
  );

  checker.GenerateTargets();
}

} // namespace ilang
