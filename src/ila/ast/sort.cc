/// \file
/// Source for the class Sort

#include "ila/ast/sort.h"
#include "util/log.h"

namespace ila {

Sort::Sort()
    : type_(SortType::SORT_BOOL), bit_width_(0), addr_width_(0), data_width_(0),
      range_sort_(NULL) {
  args_sort_.clear();
}

Sort::Sort(const int& bit_width)
    : type_(SortType::SORT_BV), bit_width_(bit_width), addr_width_(0),
      data_width_(0), range_sort_(NULL) {
  args_sort_.clear();
}

Sort::Sort(const int& addr_width, const int& data_width)
    : type_(SortType::SORT_MEM), bit_width_(0), addr_width_(addr_width),
      data_width_(data_width), range_sort_(NULL) {
  args_sort_.clear();
}

Sort::Sort(const SortPtr range_sort, const SortPtrVec& args_sort)
    : type_(SortType::SORT_APP), bit_width_(0), addr_width_(0), data_width_(0),
      range_sort_(range_sort), args_sort_(args_sort) {}

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

bool Sort::is_bool() const { return (type_ == SortType::SORT_BOOL); }

bool Sort::is_bv() const { return (type_ == SortType::SORT_BV); }

bool Sort::is_mem() const { return (type_ == SortType::SORT_MEM); }

bool Sort::is_app() const { return (type_ == SortType::SORT_APP); }

std::ostream& Sort::Print(std::ostream& out) const {
  if (is_bool())
    return PrintBool(out);
  else if (is_bv())
    return PrintBv(out);
  else if (is_mem())
    return PrintMem(out);
  else if (is_app())
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

bool Sort::Equal(const Sort& lhs, const Sort& rhs) {
  if (lhs.is_bool() && rhs.is_bool()) {
    return true;
  } else if (lhs.is_bv() && rhs.is_bv()) {
    return (lhs.bit_width_ == rhs.bit_width_);
  } else if (lhs.is_mem() && rhs.is_mem()) {
    return ((lhs.addr_width_ == rhs.addr_width_) &&
            (lhs.data_width_ == rhs.data_width_));
  } else if (lhs.is_app() && rhs.is_app()) {
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
  return out << "Boolean";
}

std::ostream& Sort::PrintBv(std::ostream& out) const {
  return out << "Bv(" << bit_width_ << ")";
}

std::ostream& Sort::PrintMem(std::ostream& out) const {
  return out << "Mem(" << addr_width_ << ", " << data_width_ << ")";
}

std::ostream& Sort::PrintApp(std::ostream& out) const {
  out << "App(" << *range_sort_ << ")(";
  size_t n = num_arg();
  for (size_t i = 0; i != n; i++) {
    if (i != 0)
      out << ", ";
    out << *arg(i);
  }
  out << ")";
  return out;
}

} // namespace ila

