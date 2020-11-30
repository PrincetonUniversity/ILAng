/// \file
/// Containers for ILA variables

#ifndef ILANG_ILA_VAR_CONTAINERS_H__
#define ILANG_ILA_VAR_CONTAINERS_H__

#include<ilang/ila/symbol.h>
#include<ilang/ila/ast/sort.h>
#include<ilang/ila/ast/expr.h>
#include<ilang/ila/instr_lvl_abs.h>
#include<ilang/util/log.h>

namespace ilang {

/// Defines type constructors for use in producing complex state/input objects.
namespace types {
  typedef SortPtr Type;

  /// Returns the boolean type.
  inline Type Bool() { return Sort::MakeBoolSort(); }
  /// Returns a type representing a bitvector of the given size.
  inline Type Bitvector(size_t nbits) { return Sort::MakeBvSort(nbits); }
  /// Returns a type representing a memory bank with given width addresses,
  /// each address representing a bitvector of given width data.
  inline Type Memory(size_t addr_width, size_t data_width) { return Sort::MakeMemSort(addr_width, data_width); }
  /// Returns a type representing a vector of given size with elements
  /// of the given type.
  inline Type Vector(size_t size, const Type& elem_type) { return Sort::MakeVectorSort(elem_type, size); }
  /// Returns a type representing a struct whose members have the given types,
  /// as determined by the list of (member_name, member_type) pairs given as input. 
  inline Type Struct(const std::initializer_list<std::pair<std::string, Type>>& members) { 
    return Sort::MakeStructSort(members); 
  }
};

struct VCVisitor;

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
  
  typedef VCVisitor visitor;

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
  static VarContainerPtr Make(const types::Type& t, const std::string& name);

  /// Destroys a VarContainer.
  ~VarContainer()=default;

  /// Returns the type of object this container represents.
  const types::Type& type() { return type_; }

  /// Returns the type of container used to manage this object.
  virtual ContainerType container_type() const = 0;

  /// Returns true if this container is a primitive wrapper
  virtual bool is_primitive() const { return false; }

  /// Returns true if this container is a vector
  virtual bool is_vector() const { return false; }

  /// Returns true if this container is a structure
  virtual bool is_struct() const { return false; }

  /// Visits the object with the given visitor (https://en.wikipedia.org/wiki/Visitor_pattern).
  virtual void visit_with(visitor& v)=0;
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

  /// If this container is a struct, returns the given member.
  virtual VarContainerPtr member(const std::string& name);
  /// If this container is a struct, returns the underlying implementation.
  virtual const struct_container& members();
  // [HACK] see the elements() function above.

protected:
  VarContainer(const types::Type& type): type_ {type} {}

  /// Produces an error that the given operation is invalid for the
  /// given type of container.
  inline void invalid_operation_error_(const char* op_name) const {
    ILA_ASSERT(false) << "can't perform " << op_name << " on a container of type " << container_typename_();
  }

  /// Returns the name of this container class, for invalid_operation_error_.
  virtual const char* container_typename_() const = 0;

private:
  types::Type type_;
  inline static const vector_container empty_vec_ {};
  inline static const struct_container empty_struct_ {};
};

typedef VarContainer::VarContainerPtr VarContainerPtr;


/// A wrapper for a primitive state/input variable.
class VarPrimitive: public VarContainer {

  friend VarContainer;

public:
  ~VarPrimitive()=default;

  void visit_with(visitor& v) override;
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
  void visit_with(visitor& v) override;
  ContainerType container_type() const override { return ContainerType::vector; }
  bool is_vector() const override { return true; }

  VarContainerPtr nth(size_t idx) override;
  size_t size() const override { return impl_.size(); }
  const vector_container& elements() override { return impl_; }

protected:
  VarVector(const types::Type& t, vector_container&& elems);
  const char* container_typename_() const override { return "vector"; }

private:
  vector_container impl_;
};


/// A struct of state/input variables.
struct VarStruct: public VarContainer {

  friend VarContainer;

  void visit_with(visitor& v) override;
  ContainerType container_type() const override { return ContainerType::structure; }
  bool is_struct() const override { return true; }

  VarContainerPtr member(const std::string& name) override;
  const struct_container& members() override { return impl_; }

protected:
  VarStruct(const types::Type& t, struct_container&& elems);
  const char* container_typename_() const override { return "struct"; }

private:
  struct_container impl_;
};

struct VCVisitor {
  VCVisitor()=default;
  ~VCVisitor()=default;
  virtual void visit(VarPrimitive& vc) {};
  virtual void visit(VarVector& vc) {};
  virtual void visit(VarStruct& vc) {};
};

} // namespace ilang

#endif // ILANG_ILA_VAR_CONTAINERS_H__