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
  // [TODO] actually measure whether this makes a difference.

  // container may change, but will continue to support list access and forward iteration.
  typedef std::vector<VarContainerPtr> vector_container;
  // container may change, but will continue to support *ordered* iteration over name, container pairs.
  typedef std::vector<std::pair<std::string, VarContainerPtr>> struct_container;
  // [TODO] names are available from the type, can save a ton of space if I create a custom
  // container that doesn't store string names.

  // [TODO] consider implementing a partitions as a VarContainer
  typedef std::vector<VarContainerPtr> partition;
  /// Right now partitions are not a VarContainer Vector because partitions may
  /// have different size.

  // [NOTE] constructor is protected -- use Make instead.

  /// Makes a VarContainer representing a complex object of the given type, 
  /// using the given name as a prefix for the state/input variables needed to 
  /// define the object.
  static VarContainerPtr Make(const std::string& name, const SortPtr& sort);

  /// Converts an Expr to the equivalent VarContainer Primitive
  static VarContainerPtr from_primitive_expr(const ExprPtr& p);

  /// Converts a similarly structured c++ object over ExprPtrs and VarContainerPtrs 
  /// to a VarContainerPtr.
  /// Use with extreme caution -- it's very easy to abuse, but may be better than
  /// ad-hoc construction because it does some typechecking.
  template<typename T>
  static VarContainerPtr from_cpp_obj(const SortPtr& sort, std::vector<T> obj);

  /// Converts a similarly structured c++ object over ExprPtrs and VarContainerPtrs 
  /// to a VarContainerPtr.
  /// Use with extreme caution -- it's very easy to abuse, but may be better than
  /// ad-hoc construction because it does some typechecking.
  template<typename It>
  static VarContainerPtr from_cpp_obj(const SortPtr& sort, It struct_begin, It struct_end);

  /// Converts a similarly structured c++ object over ExprPtrs and VarContainerPtrs 
  /// to a VarContainerPtr.
  /// Use with extreme caution -- it's very easy to abuse, but may be better than
  /// ad-hoc construction because it does some typechecking.
  template<typename T>
  static VarContainerPtr from_cpp_obj(const SortPtr& sort, std::vector<std::pair<std::string, T>> obj) {
    return from_cpp_obj(sort, obj.begin(), obj.end());
  }

  /// Converts a similarly structured c++ object over ExprPtrs and VarContainerPtrs 
  /// to a VarContainerPtr.
  /// Use with extreme caution -- it's very easy to abuse, but may be better than
  /// ad-hoc construction because it does some typechecking.
  template<typename T>
  static VarContainerPtr from_cpp_obj(const SortPtr& sort, std::unordered_map<std::string, T> obj) {
    return from_cpp_obj(sort, obj.begin(), obj.end());
  }

  /// Converts a similarly structured c++ object over ExprPtrs and VarContainerPtrs 
  /// to a VarContainerPtr.
  /// Use with extreme caution -- it's very easy to abuse, but may be better than
  /// ad-hoc construction because it does some typechecking.
  static inline VarContainerPtr from_cpp_obj(const SortPtr& sort, VarContainerPtr obj);

  /// Converts a similarly structured c++ object over ExprPtrs and VarContainerPtrs 
  /// to a VarContainerPtr.
  /// Use with extreme caution -- it's very easy to abuse, but may be better than
  /// ad-hoc construction because it does some typechecking.
  static inline VarContainerPtr from_cpp_obj(const SortPtr& sort, ExprPtr obj);

  // [TODO] Use templates for the containers passed to from_cpp_object.
  /* Attempts that failed: 
    1. We can't use a function over an arbitrary SortPtr, since
      the particular kind of SortPtr decides the meaning of functions like
      begin(), end(), operator[].
    2. We can't try to use the visitor pattern, taking the the object as templated 
      arguments and using overriding to change the type of SortPtr given as an
      argument to the visitor because C++ templates don't allow overriding
      templated functions.
    3. We can't cast SortPtr to the correct subtype and then call a templated
      function on that -- maybe. I treated both the sort and the object as
      templates, which causes trouble because then we need to specialize one
      and not the other.
      It may have been more correct to overload multiple functions, each for one
      SortPtr child and only leave the object as a template.
    4. Using typename std::enable_if<std::is_same<S, SortBool>::value, VarContainerPtr>::type
       and similar functions to check the type of the SortPtr after casting
       (following https://stackoverflow.com/a/21218271/5053583) may work, but I
       couldn't get it to work.
   */


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

  /// If this container is a struct, returns the given member.
  virtual VarContainerPtr member(const std::string& name);
  /// If this container is a struct, returns the underlying implementation.
  virtual const struct_container& members();
  // [HACK] see the elements() function above.

  /* Container transformers */
  /* [NOTE] 
    Q. Given that it is possible to transform one container to 
    another, why not allow ILAs to register containers after 
    they've been constructed?
    Ans. We don't want updating one state of an ILA to implicitly
    update another. This is why variables within a container are
    deliberately obfuscated (a little), and why we don't want to
    allow multiple objects of an ILA to share state variables. 
  */

  /// If this container is a vector, partitions each element such that
  /// the ith element is assigned to the which_part(i)th part.
  /// The result is not a VarContainer Vector because partitions may
  /// have different size.
  virtual partition order_preserving_partition(
    size_t n_parts, std::function<size_t(size_t)> which_part
  );

  /// If this container is a struct of vectors, s, produces a
  /// vector of structs, v, where the ith element of v is a struct
  /// constructed from the ith elements of the vectors of s.
  virtual VarContainerPtr zip();

  /// If this container is a vector of structs, v, produces 
  /// a struct of vectors, s, where the ith element of the v 
  /// is unpacked into the the ith elements of the vectors of s.
  virtual VarContainerPtr unzip();

  /// If this container is a struct, returns a struct of only
  /// the members of this container with the given names.
  virtual VarContainerPtr project(const std::vector<std::string>& names);

  /// If this container is a struct, returns a struct of only
  /// the members of this container with the given names.
  virtual VarContainerPtr project_without(
    const std::vector<std::string>& names
  );

  /// If this container is a struct, merges this and another struct
  /// into a struct with the members of both.
  /// Requires that the two structs have no members in common.
  virtual VarContainerPtr join_with(const VarContainerPtr& b);

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
  
  template<typename CT, typename T>
  friend VarContainerPtr from_cpp_obj_(const SortPtr&, T obj);

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
  
  template<typename T>
  friend VarContainerPtr from_cpp_obj_(const SortPtr&, T obj);

public:
  void visit_with(const visitor& visit) override;
  ContainerType container_type() const override { return ContainerType::vector; }
  bool is_vector() const override { return true; }

  VarContainerPtr nth(size_t idx) override;
  size_t size() const override { return impl_.size(); }
  const vector_container& elements() override { return impl_; }

  // container transformers
  partition order_preserving_partition(
    size_t n_parts, std::function<size_t(size_t)> which_part
  ) override;

  VarContainerPtr unzip() override;

protected:
  VarVector(const SortPtr& sort, vector_container&& elems);
  const char* container_typename_() const override { return "vector"; }

private:
  vector_container impl_;
};


/// A struct of state/input variables.
struct VarStruct: public VarContainer {

  friend VarContainer;
  
  template<typename CT, typename T>
  friend VarContainerPtr from_cpp_obj_(const SortPtr&, T obj);

  void visit_with(const visitor& visit) override;
  ContainerType container_type() const override { return ContainerType::structure; }
  bool is_struct() const override { return true; }

  VarContainerPtr member(const std::string& name) override;
  const struct_container& members() override { return impl_; }
  
  // container transformers
  VarContainerPtr zip() override;

  VarContainerPtr project(const std::vector<std::string>& names) override;

  VarContainerPtr project_without(
    const std::vector<std::string>& names
  ) override;

  VarContainerPtr join_with(const VarContainerPtr& b) override;

protected:
  VarStruct(const SortPtr& sort, struct_container&& elems);
  const char* container_typename_() const override { return "struct"; }

private:
  struct_container impl_;
};

template<typename T>
VarContainerPtr VarContainer::from_cpp_obj(const SortPtr& sort, std::vector<T> obj) {
  ILA_ASSERT(sort->is_vec()) << "can't convert given vector to VarContainer of sort " << sort;
  VarContainer::vector_container v {};
  for (auto& x : obj) v.push_back(VarContainer::from_cpp_obj(sort->data_atom(), x));
  ILA_ASSERT(sort->vec_size() == v.size()) << 
    "expected vector-like of size " << sort->vec_size()
    << " got size " << v.size();
  return VarContainerPtr{new VarVector{sort, std::move(v)}};
}

template<typename It>
VarContainerPtr VarContainer::from_cpp_obj(const SortPtr& sort, It map_begin, It map_end) {
  ILA_ASSERT(sort->is_struct()) << "can't convert sequence of pairs to VarContainer of sort " << sort;
  std::unordered_map<std::string, VarContainerPtr> members {};
  for (auto it = map_begin; it != map_end; ++it) {
    std::string name = it->first;
    SortPtr s = sort->get_member_sort(name);
    ILA_ASSERT(s) << "unexpected member with name " << name;
    members.emplace(name, VarContainer::from_cpp_obj(s, it->second));
  }
  VarContainer::struct_container res;
  for (auto& [name, s] : sort->members()) {
    auto x = members.find(name);
    ILA_ASSERT(x != members.end()) << "missing member named " << name;
    res.emplace_back(name, members[name]);
  }
  return VarContainerPtr{new VarStruct{sort, std::move(res)}};
}

// these functions were inlined in order to keep all the from_cpp_obj definitions together

inline VarContainerPtr VarContainer::from_cpp_obj(const SortPtr& sort, ExprPtr obj) {
  ILA_ASSERT(sort) << "expected non-null sort";
  ILA_ASSERT(bool(obj)) << "expected non-null object";
  ILA_ASSERT(sort == obj->sort()) << "expected " << sort << " got " << obj->sort();
  return from_primitive_expr(obj);
}

inline VarContainerPtr VarContainer::from_cpp_obj(const SortPtr& sort, VarContainerPtr obj) {
  ILA_ASSERT(sort) << "expected non-null sort";
  ILA_ASSERT(bool(obj)) << "expected non-null object";
  ILA_ASSERT(sort == obj->sort()) << "expected " << sort << " got " << obj->sort();
  return obj;
}

} // namespace ilang

#endif // ILANG_ILA_VAR_CONTAINER_H__