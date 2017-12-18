/// \file
/// Source for the class Sort

#include "ila/ast/sort.h"

namespace ila {

Sort::Sort() {
  // TODO type
}

Sort::Sort(const int& bit_width) {
  // TODO type
}

Sort::Sort(const int& addr_width, const int& data_width) {
  // TODO
}

Sort::Sort(const SortPtr range_sort, const SortPtrVec& args_sort) {
  // TODO
}

Sort::~Sort() {}

const int& Sort::bit_width() const { return bit_width_; }

const int& Sort::addr_width() const { return addr_width_; }

const int& Sort::data_width() const { return data_width_; }

const SortPtr& Sort::range_sort() const { return range_sort_; }

std::ostream& Sort::Print(std::ostream& out) const {
  // TODO
  return out;
}

} // namespace ila

