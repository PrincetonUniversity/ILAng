/// \file
/// Source code for the class VarContainer and its derived classes.

#include <ilang/ila/var_container.h>
#include <ilang/ila/ast_hub.h>

namespace ilang {

VarContainerPtr VarContainer::Make(const std::string& name, const types::Type& t) {
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

VarVector::VarVector(const types::Type& t, vector_container&& elems): 
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

/* VarStruct */

VarStruct::VarStruct(const types::Type& t, struct_container&& members): 
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