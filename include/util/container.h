/// \file
/// Header for containers, e.g. KeyVec.

#ifndef CONTAINER_H__
#define CONTAINER_H__

#include "util/log.h"
#include <map>
#include <memory>
#include <vector>

/// \namespace ila
namespace ila {

/// KeyVecItVal
typedef enum { END, FOUND } KeyVecItVal;

/// \brief A pseudo-iterator for the key-search vector.
template <class Key, class T> class KeyVecIt {
public:
  /// Pointer type for the KeyVec iterator.
  typedef std::shared_ptr<KeyVecIt> KeyVecItPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor
  KeyVecIt() : result(KeyVecItVal::END), first(), second() {}

  // ------------------------- METHODS -------------------------------------- //
  /// Overload comparison == for pointer
  friend bool operator==(const KeyVecItPtr lhs, const KeyVecItPtr rhs) {
    return lhs->result == rhs->result;
  }
  /// Overload comparison != for pointer
  friend bool operator!=(const KeyVecItPtr lhs, const KeyVecItPtr rhs) {
    return lhs->result != rhs->result;
  }

  // ------------------------- MEMBERS -------------------------------------- //
  /// Iterator value for checking whether a data is found.
  KeyVecItVal result;
  /// Key retrived.
  Key first;
  /// Data retrived.
  T second;

}; // KeyVecIt

/// \brief The container that support key search and index access.
template <class Key, class T> class KeyVec {
public:
  /// Iterator pointer type.
  typedef std::shared_ptr<KeyVecIt<Key, T>> KeyVecItPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  KeyVec() {
    it_ = std::make_shared<KeyVecIt<Key, T>>();
    clear();
  }
  /// Default destructor.
  ~KeyVec() { clear(); }

  // ------------------------- METHODS -------------------------------------- //
  /// Push back a data member. The name MUST NOT be registerd before.
  void push_back(const Key& key, const T& data) {
    auto pos = map_.find(key);
    ILA_ASSERT(pos == map_.end()) << key << " already exists.\n";

    auto idx = vec_.size();
    vec_.push_back(data);
    map_[key] = idx;
  }

  /// Get the data by index.
  T operator[](const size_t& idx) const {
    ILA_ASSERT(idx < vec_.size()) << "Access overflow.\n";
    return vec_.at(idx);
  }

  /// Return the number of data stored.
  size_t size() const { return vec_.size(); }

  /// Return whether is empty.
  bool empty() const { return size() == 0; }

  /// Clear all stored data.
  void clear() {
    vec_.clear();
    map_.clear();
  }

  /// Return whether the key has been registered.
  KeyVecItPtr find(const Key& key) const {
    auto pos = map_.find(key);
    if (pos == map_.end())
      return end_;
    else {
      auto idx = pos->second;
      T data = vec_[idx];
      it_->result = KeyVecItVal::FOUND;
      it_->first = key;
      it_->second = data;
      return it_;
    }
  }

  /// Return END, can be used to check whether data is found.
  KeyVecItPtr end() const { return end_; }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// vector of data (used for random access with index).
  std::vector<T> vec_;
  /// the mapping of key (name) to vector index.
  std::map<Key, size_t> map_;

  /// iterator
  KeyVecItPtr it_;
  /// the END for legacy interator usage.
  static KeyVecItPtr end_;
}; // class KeyVec

/// Initialize static end interator.
template <class Key, class T>
std::shared_ptr<KeyVecIt<Key, T>>
    KeyVec<Key, T>::end_ = std::make_shared<KeyVecIt<Key, T>>();

/// \brief A map for sets.
template <class Key, class T> class MapSet {
public:
  /// Set type for data T.
  typedef std::set<T> SetT;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  MapSet() {}
  /// Default destructor.
  ~MapSet() {}

  // ------------------------- METHODS -------------------------------------- //
  /// Insert the pair into the mapping.
  void insert(const Key& k, const T& t) { map_[k].insert(t); }

  /// Return the set of T for the given key.
  SetT get(const Key& k) const {
    auto pos = map_.find(k);
    ILA_ASSERT(pos != map_.end()) << "Key " << k << " not found.";
    return pos->second;
  }

  /// Return the iterator at the starting point
  typename std::map<Key, std::set<T>>::iterator begin() { return map_.begin(); }

  /// Return the iterator at the ending point.
  typename std::map<Key, std::set<T>>::iterator end() { return map_.end(); }

private:
  /// The actual mapping.
  std::map<Key, std::set<T>> map_;

}; // class MapSet

} // namespace ila

#endif // CONTAINER_H__

