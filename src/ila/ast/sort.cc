/// \file
/// Source for the class Sort

#include "ila/ast/sort.h"
#include "util/log.h"

namespace ila {

Sort::Sort() : type_(SortType::SORT_BOOL) {}

Sort::Sort(const int& bit_width)
    : type_(SortType::SORT_BV), bit_width_(bit_width) {}

Sort::Sort(const int& addr_width, const int& data_width)
    : type_(SortType::SORT_MEM), addr_width_(addr_width),
      data_width_(data_width) {}

Sort::Sort(const SortPtr range_sort, const SortPtrVec& args_sort)
    : type_(SortType::SORT_APP), range_sort_(range_sort),
      args_sort_(args_sort) {}

Sort::~Sort() {}

const int& Sort::bit_width() const { return bit_width_; }

const int& Sort::addr_width() const { return addr_width_; }

const int& Sort::data_width() const { return data_width_; }

const SortPtr Sort::range() const { return range_sort_; }

size_t Sort::num_arg() const { return args_sort_.size(); }

const SortPtr Sort::arg(const size_t& i) const {
  ILA_ASSERT(i < args_sort_.size()) << "Invalid index for argument (sort).\n";
  return args_sort_[i];
}

bool Sort::IsBool() const { return (type_ == SortType::SORT_BOOL); }

bool Sort::IsBv() const { return (type_ == SortType::SORT_BV); }

bool Sort::IsMem() const { return (type_ == SortType::SORT_MEM); }

bool Sort::IsApp() const { return (type_ == SortType::SORT_APP); }

std::ostream& Sort::Print(std::ostream& out) const {
  if (IsBool())
    return PrintBool(out);
  else if (IsBv())
    return PrintBv(out);
  else if (IsMem())
    return PrintMem(out);
  else if (IsApp())
    return PrintApp(out);
  else {
    ILA_ERROR << "Unknown type.\n";
    return out;
  }
}

std::ostream& operator<<(std::ostream& out, const Sort& s) {
  return s.Print(out);
}

bool operator==(const Sort& lhs, const Sort& rhs) {
  return Sort::Equal(lhs, rhs);
}

bool operator==(const SortPtr lhs, const SortPtr rhs) {
  return Sort::Equal(*lhs.get(), *rhs.get());
}

bool Sort::Equal(const Sort& lhs, const Sort& rhs) {
  if (lhs.IsBool() && rhs.IsBool()) {
    return true;
  } else if (lhs.IsBv() && rhs.IsBv()) {
    return (lhs.bit_width_ == rhs.bit_width_);
  } else if (lhs.IsMem() && rhs.IsMem()) {
    return ((lhs.addr_width_ == rhs.addr_width_) &&
            (lhs.data_width_ == rhs.data_width_));
  } else if (lhs.IsApp() && rhs.IsApp()) {
    if (!Equal(*lhs.range_sort_.get(), *rhs.range_sort_.get())) {
      return false;
    }
    if (lhs.num_arg() != rhs.num_arg()) {
      return false;
    }
    for (size_t i = 0; i < lhs.num_arg(); i++) {
      if (!Equal(*lhs.arg(i).get(), *rhs.arg(i).get())) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

std::ostream& Sort::PrintBool(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& Sort::PrintBv(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& Sort::PrintMem(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

std::ostream& Sort::PrintApp(std::ostream& out) const {
  ILA_ERROR << "Not implemented.\n"; // TODO
  return out;
}

} // namespace ila

