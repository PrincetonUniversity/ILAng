/// \file
/// Containers for ILA variables

#ifndef ILANG_ILA_VAR_CONTAINER_H__
#define ILANG_ILA_VAR_CONTAINER_H__

#include <functional>

#include<ilang/ila/symbol.h>
#include<ilang/ila/ast/sort.h>
#include<ilang/ila/ast/expr.h>
#include<ilang/util/log.h>

namespace ilang {

/// A container holding ILA state/input variables in order to be 
/// able to represent some complex object.
class VarContainer {

public:
  /* [HACK] This is a terrible hack in order to allow pointers to 
    primitive containers to be used as ExprPtrs. 
    Because ILAng doesn't want users to cast expressions in order to 
    use their respective methods, we need to be able to use primitives 
    like Exprs.
    This will cause trouble when users try things like Instr::update-ing 
    one VarStruct using the value of another VarStruct, at which point the 
    implicit casting to Exprs means they won't notice that the operation
    is illegal until an error is thrown at runtime.
    We bear with this trouble because much of our other typechecking is 
    similarly performed at runtime and similarly produces runtime errors.
  */
 /// A pointer to a VarContainer
  struct VarContainerPtr: public std::shared_ptr<VarContainer> {
    // inherit all constructors
    using std::shared_ptr<VarContainer>::shared_ptr;
    ~VarContainerPtr()=default;
    // implicit casting hack
    inline operator ExprPtr() { return get()->to_primitive_expr(); }
    inline operator const ExprPtr() const { return get()->to_primitive_expr(); }
  };

  enum class ContainerType { primitive, vector, structure };
  
  /// The type of visitors to containers. This is sufficient because the 
  /// sort() and container_type() functions can be used to get the specific
  /// kind of object/container being referred to.
  typedef std::function<void(VarContainer* const)> visitor;
  // The visitor function accepts a VarContainer* instead of a VarContainerPtr to save
  // space during iteration. When the container is visited, it feels expensive to create a
  // new shared_ptr object for each of its children.
  // TODO: actually measure whether this makes a difference.

  // container may change, but will continue to support list access and forward iteration.
  typedef std::vector<VarContainerPtr> vector_container;
  // container may change, but will continue to support *ordered* iteration over name, container pairs.
  typedef std::vector<std::pair<std::string, VarContainerPtr>> struct_container;
  // TODO: names are available from the type, can save a ton of space if I create a custom
  // container that doesn't store string names.


  // NOTE: constructor is protected -- use Make instead.

  /// Makes a VarContainer representing a complex object of the given type, 
  /// using the given name as a prefix for the state/input variables needed to 
  /// define the object.
  static VarContainerPtr Make(const std::string& name, const SortPtr& sort);

  static VarContainerPtr from_primitive_expr(const ExprPtr& p);

  /// Destroys a VarContainer.
  ~VarContainer()=default;

  /// Returns the type of object this container represents.
  const SortPtr& sort() { return sort_; }

  /// Returns the type of container used to manage this object.
  virtual ContainerType container_type() const = 0;

  /// Returns true if this container is a primitive wrapper
  virtual bool is_primitive() const { return false; }

  /// Returns true if this container is a vector
  virtual bool is_vector() const { return false; }

  /// Returns true if this container is a structure
  virtual bool is_struct() const { return false; }

  /// Visits this object with the given visitor.
  virtual void visit_with(const visitor& visit)=0;
  // dunno if we need this much flexibility, but it's nice to have.

  /// If this container holds a primitive, returns the primitive.
  virtual ExprPtr to_primitive_expr();

  /// If this container is a vector, returns the nth element.
  virtual VarContainerPtr nth(size_t idx);
  /// If this container is a vector, returns its size.
  virtual size_t size() const;
  /// If this container is a vector, returns the underlying implementation.
  virtual const vector_container& elements();
  // [HACK] This breaks encapsulation, but we don't can't include all 
  // the vector functions. Both the vector and struct implementations
  // should support range-based for loops, but would need to implement
  // different type begin() and end() functions.
  
  /// If this container is a vector, partitions each element such that
  /// the ith element is assigned to the which_part(i)th part.
  /// The result is not a VarContainer Vector because partitions may
  /// have different size.
  virtual std::vector<VarContainerPtr> order_preserving_partition(
    size_t n_parts, std::function<size_t(size_t)> which_part
  );

  /// If this container is a struct, returns the given member.
  virtual VarContainerPtr member(const std::string& name);
  /// If this container is a struct, returns the underlying implementation.
  virtual const struct_container& members();
  // [HACK] see the elements() function above.

protected:
  VarContainer(const SortPtr& sort): sort_ {sort} {}

  /// Produces an error that the given operation is invalid for the
  /// given type of container.
  inline void invalid_operation_error_(const char* op_name) const {
    ILA_ASSERT(false) << "can't perform " << op_name << " on a container of type " << container_typename_();
  }

  /// Returns the name of this container class, for invalid_operation_error_.
  virtual const char* container_typename_() const = 0;

private:
  const SortPtr sort_;
  inline static const vector_container empty_vec_ {};
  inline static const struct_container empty_struct_ {};
};

typedef VarContainer::VarContainerPtr VarContainerPtr;


/// A wrapper for a primitive state/input variable.
class VarPrimitive: public VarContainer {

  friend VarContainer;

public:
  ~VarPrimitive()=default;

  void visit_with(const visitor& visit) override;
  ContainerType container_type() const override { return ContainerType::primitive; }
  bool is_primitive() const override { return true; }

  ExprPtr to_primitive_expr() override { return impl_; }

protected:
  VarPrimitive(ExprPtr var);
  const char* container_typename_() const override { return "primitive"; }

private:
  ExprPtr impl_;
};


/// A vector of state/input variables.
struct VarVector: public VarContainer {

  friend VarContainer;

public:
  void visit_with(const visitor& visit) override;
  ContainerType container_type() const override { return ContainerType::vector; }
  bool is_vector() const override { return true; }

  VarContainerPtr nth(size_t idx) override;
  size_t size() const override { return impl_.size(); }
  const vector_container& elements() override { return impl_; }

  std::vector<VarContainerPtr> order_preserving_partition(
    size_t n_parts, std::function<size_t(size_t)> which_part
  ) override;

protected:
  VarVector(const SortPtr& sort, vector_container&& elems);
  const char* container_typename_() const override { return "vector"; }

private:
  vector_container impl_;
};


/// A struct of state/input variables.
struct VarStruct: public VarContainer {

  friend VarContainer;

  void visit_with(const visitor& visit) override;
  ContainerType container_type() const override { return ContainerType::structure; }
  bool is_struct() const override { return true; }

  VarContainerPtr member(const std::string& name) override;
  const struct_container& members() override { return impl_; }

protected:
  VarStruct(const SortPtr& sort, struct_container&& elems);
  const char* container_typename_() const override { return "struct"; }

private:
  struct_container impl_;
};

} // namespace ilang

#endif // ILANG_ILA_VAR_CONTAINER_H__