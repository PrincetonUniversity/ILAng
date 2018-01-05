/// \file
/// Header for containers, e.g. KeyVec

#ifndef __CONTAINER_H__
#define __CONTAINER_H__

#include "util/log.h"
#include <map>
#include <memory>
#include <vector>

namespace ila {

/// KeyVecItVal
typedef enum { END, FOUND } KeyVecItVal;

/// \brief A pseudo-iterator for the key-search vector.
template <class Key, class T> class KeyVecIt {
public:
  typedef std::shared_ptr<KeyVecIt> KeyVecItPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor for END (not found).
  KeyVecIt() : result(KeyVecItVal::END) {}
  /// Constructor for FOUND (found).
  KeyVecIt(const Key& key, const T& data)
      : result(KeyVecItVal::FOUND), first(key), second(data) {}

  /// Overload comparison ==
  friend bool operator==(const KeyVecIt& lhs, const KeyVecIt& rhs) {
    return lhs.result == rhs.result;
  }
  /// Overload comparison !=
  friend bool operator!=(const KeyVecIt& lhs, const KeyVecIt& rhs) {
    return lhs.result != rhs.result;
  }
  /// Overload comparison for pointer
  friend bool operator==(const KeyVecItPtr lhs, const KeyVecItPtr rhs) {
    return *lhs == *rhs;
  }

  /// Iterator value for checking whether a data is found.
  KeyVecItVal result;
  /// Ket retrived.
  Key first;
  /// Data retrived.
  T second;

}; // KeyVecIt

/// \brief The container that support key search and index access.
template <class Key, class T> class KeyVec {
public:
  typedef std::shared_ptr<KeyVecIt<Key, T>> KeyVecItPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  KeyVec() {
    vec_.clear();
    map_.clear();
  }
  /// Default destructor.
  ~KeyVec() {
    vec_.clear();
    map_.clear();
  }

  // ------------------------- METHODS -------------------------------------- //
  /// Return the number of data stored.
  size_t size() const { return vec_.size(); }

  /// Push back a data member. The name MUST NOT be registerd before.
  void push_back(const Key& key, const T& data) {
    auto pos = map_.find(key);
    ILA_ASSERT(pos == map_.end()) << key << " already exists.\n";

    auto idx = vec_.size();
    vec_.push_back(data);
    map_[key] = idx;
  }

  /// Get the data by index.
  T operator[](const size_t& idx) {
    ILA_ASSERT(idx < vec_.size()) << "Access overflow.\n";
    return vec_[idx];
  }

  /// Return whether the key has been registered.
  KeyVecIt<Key, T> find(const Key& key) const {
    auto pos = map_.find(key);
    if (pos == map_.end())
      return end_;
    else {
      auto idx = pos->second;
      T data = vec_[idx];
      return KeyVecIt<Key, T>(key, data);
    }
  }

  /// Return KeyVecItVal::END, can be used to check whether data is found.
  const KeyVecIt<Key, T>& end() const { return end_; }

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// vector of data (used for random access with index).
  std::vector<T> vec_;
  /// the mapping of key (name) to vector index.
  std::map<Key, size_t> map_;

  /// iterator
  KeyVecItPtr it_;
  /// the END for legacy interator usage.
  static KeyVecIt<Key, T> end_;
}; // class KeyVec

/// Initialize static end interator.
template <class Key, class T> KeyVecIt<Key, T> KeyVec<Key, T>::end_;

} // namespace ila

#endif // __CONTAINER_H__

