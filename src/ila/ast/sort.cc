/// \file
/// Source for the class Sort

#include "ila/ast/sort.h"
#include "util/log.h"

namespace ila {

SortBase::SortBase() {}

SortBase::~SortBase() {}

int SortBase::bit_width() const {
  ILA_ASSERT(false) << "Query bit-width from non-bit-vector sort.";
  return 0;
}

int SortBase::addr_width() const {
  ILA_ASSERT(false) << "Query addr-width from non-mem sort.";
  return 0;
}

int SortBase::data_width() const {
  ILA_ASSERT(false) << "Query data-width from non-mem sort.";
  return 0;
}

bool SortBase::Equal(const SortBasePtr lhs, const SortBasePtr rhs) {
  // TODO
  return true;
}

SortBool::SortBool() {}

SortBool::~SortBool() {}

z3::sort SortBool::GetZ3Sort(z3::context& ctx) const { return ctx.bool_sort(); }

std::ostream& SortBool::Print(std::ostream& out) const {
  return out << "Boolean";
}

SortBv::SortBv(const int& width) : bit_width_(width) {}

SortBv::~SortBv() {}

z3::sort SortBv::GetZ3Sort(z3::context& ctx) const {
  return ctx.bv_sort(bit_width_);
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

std::ostream& SortMem::Print(std::ostream& out) const {
  return out << "Mem(" << addr_width_ << ", " << data_width_ << ")";
}

#if 0
Sort::Sort()
    : type_(SortType::SORT_BOOL), bit_width_(0), addr_width_(0),
      data_width_(0) {}

Sort::Sort(const int& bit_width)
    : type_(SortType::SORT_BV), bit_width_(bit_width), addr_width_(0),
      data_width_(0) {}

Sort::Sort(const int& addr_width, const int& data_width)
    : type_(SortType::SORT_MEM), bit_width_(0), addr_width_(addr_width),
      data_width_(data_width) {}

Sort::~Sort() {}

z3::sort Sort::GetZ3Sort(z3::context& ctx) const {
  if (is_bool())
    return ctx.bool_sort();
  else if (is_bv())
    return ctx.bv_sort(bit_width_);
  else {
    ILA_ASSERT(is_mem()) << "Unknown sort.";
    return ctx.array_sort(ctx.bv_sort(addr_width_), ctx.bv_sort(data_width_));
  }
}

std::ostream& Sort::Print(std::ostream& out) const {
  if (is_bool())
    return PrintBool(out);
  else if (is_bv())
    return PrintBv(out);
  else {
    ILA_ASSERT(is_mem()) << "Unknown type.";
    return PrintMem(out);
  }
}

bool Sort::Equal(const Sort& lhs, const Sort& rhs) {
  if (lhs.is_bool() && rhs.is_bool()) {
    return true;
  } else if (lhs.is_bv() && rhs.is_bv()) {
    return (lhs.bit_width_ == rhs.bit_width_);
  } else if (lhs.is_mem() && rhs.is_mem()) {
    return ((lhs.addr_width_ == rhs.addr_width_) &&
            (lhs.data_width_ == rhs.data_width_));
  } else {
    return false;
  }
}

std::ostream& operator<<(std::ostream& out, const Sort& s) {
  return s.Print(out);
}

bool operator==(const Sort& lhs, const Sort& rhs) {
  return Sort::Equal(lhs, rhs);
}

Sort Sort::MakeBoolSort() { return Sort(); }

Sort Sort::MakeBvSort(const int& bit_width) { return Sort(bit_width); }

Sort Sort::MakeMemSort(const int& addr_width, const int& data_width) {
  return Sort(addr_width, data_width);
}

std::ostream& Sort::PrintBool(std::ostream& out) const {
  return out << "Boolean";
}

std::ostream& Sort::PrintBv(std::ostream& out) const {
  return out << "Bv(" << bit_width_ << ")";
}

std::ostream& Sort::PrintMem(std::ostream& out) const {
  return out << "Mem(" << addr_width_ << ", " << data_width_ << ")";
}
#endif

} // namespace ila

