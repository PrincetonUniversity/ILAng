/// \file
/// Source for the class Sort

#include <ilang/ila/ast/sort.h>

#include <ilang/util/log.h>

namespace ilang {

Sort::Sort() {}

Sort::~Sort() {}

int Sort::bit_width() const {
  ILA_ASSERT(false) << "Query bit-width from non-bit-vector sort.";
  return 0;
}

int Sort::addr_width() const {
  ILA_ASSERT(false) << "Query addr-width from non-mem sort.";
  return 0;
}

int Sort::data_width() const {
  ILA_ASSERT(false) << "Query data-width from non-mem sort.";
  return 0;
}

SortPtr Sort::MakeBoolSort() { return std::make_shared<SortBool>(); }

SortPtr Sort::MakeBvSort(const int& bit_width) {
  return std::make_shared<SortBv>(bit_width);
}

SortPtr Sort::MakeMemSort(const int& addr_width, const int& data_width) {
  return std::make_shared<SortMem>(addr_width, data_width);
}

SortPtr Sort::MakeStructSort(
  std::initializer_list<std::pair<std::string, SortPtr>> members
) { return std::make_shared<SortStruct>(members); }

SortPtr Sort::MakeVectorSort(const SortPtr& da, const int vec_size) {
  return std::make_shared<SortVector>(da, vec_size);
}

SortBool::SortBool() {}

SortBool::~SortBool() {}

z3::sort SortBool::GetZ3Sort(z3::context& ctx) const { return ctx.bool_sort(); }

z3::expr SortBool::GetZ3Expr(z3::context& ctx, const std::string& name) const {
  return ctx.bool_const(name.c_str());
}

bool SortBool::Equal(const SortPtr rhs) const { return rhs->is_bool(); }

std::ostream& SortBool::Print(std::ostream& out) const {
  return out << "Boolean";
}

SortBv::SortBv(const int& width) : bit_width_(width) {}

SortBv::~SortBv() {}

z3::sort SortBv::GetZ3Sort(z3::context& ctx) const {
  return ctx.bv_sort(bit_width_);
}

z3::expr SortBv::GetZ3Expr(z3::context& ctx, const std::string& name) const {
  return ctx.bv_const(name.c_str(), bit_width());
}

bool SortBv::Equal(const SortPtr rhs) const {
  return rhs->is_bv() && (rhs->bit_width() == bit_width_);
}

std::ostream& SortBv::Print(std::ostream& out) const {
  return out << "Bv(" << bit_width_ << ")";
}

SortMem::SortMem(const int& addr_w, const int& data_w)
    : addr_width_(addr_w), data_width_(data_w) {}

SortMem::~SortMem() {}

z3::sort SortMem::GetZ3Sort(z3::context& ctx) const {
  return ctx.array_sort(ctx.bv_sort(addr_width_), ctx.bv_sort(data_width_));
}

z3::expr SortMem::GetZ3Expr(z3::context& ctx, const std::string& name) const {
  auto addr_s = ctx.bv_sort(addr_width());
  auto data_s = ctx.bv_sort(data_width());
  auto mem_s = ctx.array_sort(addr_s, data_s);
  return ctx.constant(name.c_str(), mem_s);
}

bool SortMem::Equal(const SortPtr rhs) const {
  return rhs->is_mem() && (rhs->addr_width() == addr_width_) &&
         (rhs->data_width() == data_width_);
}

std::ostream& SortMem::Print(std::ostream& out) const {
  return out << "Mem(" << addr_width_ << ", " << data_width_ << ")";
}

SortStruct::SortStruct(
  std::initializer_list<std::pair<std::string, SortPtr>> members
): members_(members.begin(), members.end()) {}
// above, we use the range constructor in order to allow casting 
// of std::string (if necessary).

const SortPtr SortStruct::get_member_sort(const std::string& name) const {
  for (const auto& [n, sort] : members_) {
    if (n == name) return sort;
  }
  ILA_ASSERT(false) << "member not found: " << name;
  return {nullptr};
}

z3::sort SortStruct::GetZ3Sort(z3::context& ctx) const {
  // TODO: consider switching to z3 tuples
  return ctx.uninterpreted_sort(id_.c_str());
}

z3::expr SortStruct::GetZ3Expr(z3::context& ctx, const std::string& name) const {
  // TODO: figure out how to avoid producing any new z3 constants here
  //       since they should not be used.
  return ctx.constant(name.c_str(), GetZ3Sort(ctx));
}

bool SortStruct::Equal(const SortPtr rhs) const {
  if (!rhs->is_struct()) return false;
  auto ssp = cast_sort<SortStruct>(rhs);
  return members_ == ssp->members_;
}

std::ostream& SortStruct::Print(std::ostream& out) const {
  out << "{ ";
  bool first = true;
  for (auto& [name, sort] : members_) {
    if (first) first = false;
    else out << ", ";
    out << name << ": " << sort;
  }
  out << " }";
  return out;
}

SortVector::SortVector(const SortPtr& da, const int& vec_size)
  : da_ {da}, size_ {vec_size} {
  ILA_ASSERT(da) << "Can't create a vector with empty data-atom.";
}

bool SortVector::Equal(const SortPtr rhs) const {
  if (!rhs->is_vec()) return false;
  auto sv = cast_sort<SortVector>(rhs);
  return size_ == sv->size_ && da_ == sv->da_;
}

std::ostream& SortVector::Print(std::ostream& out) const {
  return out << "Array[" << size_ << "](" << da_ << ")";
}

z3::sort SortVector::GetZ3Sort(z3::context& ctx) const {
  return ctx.uninterpreted_sort(id_.c_str());
}

z3::expr SortVector::GetZ3Expr(z3::context& ctx, const std::string& name) const {
  return ctx.constant(name.c_str(), GetZ3Sort(ctx));
}

} // namespace ilang
