/// \file
/// Source code for the class VarContainer and its derived classes.

#include <ilang/ila/var_container.h>
#include <ilang/ila/ast_hub.h>

namespace ilang {

VarContainerPtr VarContainer::Make(const std::string& name, const SortPtr& t) {
  std::string prefix = name + "_";  // also makes name a bit more private if last variable.
  switch (t->uid()) {
    case AstUidSort::kBool:
      return VarContainerPtr{new VarPrimitive{asthub::NewBoolVar(name)}};
    case AstUidSort::kBv:
      return VarContainerPtr{new VarPrimitive{asthub::NewBvVar(name, t->bit_width())}};
    case AstUidSort::kMem:
      return VarContainerPtr{new VarPrimitive{asthub::NewMemVar(name, t->addr_width(), t->data_width())}};
    case AstUidSort::kVec: 
      {
        vector_container vc {};
        for (int i = 0; i != t->vec_size(); ++i) {
          vc.push_back(Make(prefix + std::to_string(i) + "_", t->data_atom()));
        }
        return VarContainerPtr{new VarVector{t, std::move(vc)}};
      }
    case AstUidSort::kStruct:
      {
        struct_container sc {};
        for (auto& [name, type] : t->members()) {
          sc.push_back({name, Make(prefix + name + "_", type)});
        }
        return VarContainerPtr{new VarStruct(t, std::move(sc))};
      }
    default:
      ILA_ASSERT(false) << "can't make VarContainer: recieved unknown type";
      return nullptr;
  }
}

VarContainerPtr VarContainer::from_primitive_expr(const ExprPtr& p) {
  return VarContainerPtr{new VarPrimitive{p}};
}

ExprPtr VarContainer::to_primitive_expr() {
  invalid_operation_error_("conversion to primitive expr");
  return {nullptr};
}

VarContainerPtr VarContainer::nth(size_t idx) {
  invalid_operation_error_("vector element access");
  return {nullptr};
}

size_t VarContainer::size() const {
  invalid_operation_error_("getting vector size");
  return 0;
}

const VarContainer::vector_container& VarContainer::elements() {
  invalid_operation_error_("getting vector elements");
  return empty_vec_;
}

std::vector<VarContainerPtr> VarContainer::order_preserving_partition(
  size_t n_parts, std::function<size_t(size_t)> which_part
) {
  invalid_operation_error_("partitioning");
  return empty_vec_;
}


VarContainerPtr VarContainer::member(const std::string& name) {
  invalid_operation_error_("struct member access");
  return {nullptr};
}

const VarContainer::struct_container& VarContainer::members() {
  invalid_operation_error_("getting struct members");
  return empty_struct_;
}


/* VarPrimitive */

VarPrimitive::VarPrimitive(ExprPtr var):  VarContainer(var->sort()), impl_ {var} {}

void VarPrimitive::visit_with(const VarContainer::visitor& visit) { visit(this); }

/* VarVector */

VarVector::VarVector(const SortPtr& t, vector_container&& elems): 
  VarContainer(t), impl_ {elems} {}

void VarVector::visit_with(const VarContainer::visitor& visit) {
  visit(this);
  for (auto& elem : impl_) {
    elem->visit_with(visit);
  }
}

VarContainerPtr VarVector::nth(size_t idx) { 
  ILA_ASSERT (idx < impl_.size()) << " array access out of bounds";
  return impl_[idx];
}

std::vector<VarContainerPtr> VarVector::order_preserving_partition(
    size_t n_parts, std::function<size_t(size_t)> which_part
) {
  std::vector<vector_container> parts(n_parts);
  for (int i = 0; i != size(); ++i) {
    size_t index = which_part(i);
    ILA_ASSERT(index >= 0 && index < n_parts) << "partition function out of bounds";
    parts[index].push_back(impl_[i]);
  }
  std::vector<VarContainerPtr> result;
  for (int i = 0; i != n_parts; ++i) {
    auto s = Sort::MakeVectorSort(sort()->data_atom(), parts[i].size());
    result.emplace_back(new VarVector{s, std::move(parts[i])});
  }
  return result;
}

/* VarStruct */

VarStruct::VarStruct(const SortPtr& t, struct_container&& members): 
  VarContainer(t), impl_ {members} {}

void VarStruct::visit_with(const visitor& visit) {
  visit(this);
  for (auto& [_, elem] : impl_) {
    elem->visit_with(visit);
  }
}

VarContainerPtr VarStruct::member(const std::string& name) {
  for (auto& [n, elem] : impl_) {
    if (n == name) return elem;
  }
  ILA_ASSERT(false) << "member '" + name + "' not found";
  return nullptr;
}

}