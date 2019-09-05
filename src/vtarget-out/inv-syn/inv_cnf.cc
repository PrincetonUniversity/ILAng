/// \file Invariants in CNF
// ---Hongce Zhang


#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/util/container_shortcut.h>
#include <ilang/vtarget-out/inv-syn/inv_cnf.h>

#include <algorithm>

namespace ilang {

/// literal to string
std::string InvariantInCnf::Lit2Str(const literal & l) {
  auto idx = std::to_string(std::get<2>(l));
  return (std::get<0>(l) ? "~" : " ") + std::get<1>(l) + "[" + idx + ":" + idx + "]";
}
/// make clause ordered
void InvariantInCnf::CanonicalizeClause(clause & c) {
  std::sort(c.begin(), c.end() );
}
/// clause to string
std::string InvariantInCnf::Clause2Str(const clause & c) {
  std::string ret;
  for (auto && l : c)
    ret += " " + Lit2Str(l);
  return ret;
}

void InvariantInCnf::InsertClauseNoReorder(const clause & c) {
  auto clause_hash = Clause2Str(c);
  if (!IN(clause_hash, _cnf_)) {
    _cnf_.insert(std::make_pair(clause_hash, c));
  }
}

void InvariantInCnf::InsertClause(clause & c) {
  CanonicalizeClause(c);
  auto clause_hash = Clause2Str(c);
  if (!IN(clause_hash, _cnf_)) {
    _cnf_.insert(std::make_pair(clause_hash, c));
  }
}

void InvariantInCnf::InsertClauseNewerFromReference(clause & c, const InvariantInCnf & ref) {
  CanonicalizeClause(c);
  auto clause_hash = Clause2Str(c);
  if (!IN(clause_hash, ref._cnf_))
    _cnf_.insert(std::make_pair(clause_hash, c));
}

void InvariantInCnf::InsertClauseIncremental(const InvariantInCnf & ref) {
  for (auto && hash_clause_pair : ref._cnf_) {
    ILA_ERROR_IF (IN(hash_clause_pair.first, _cnf_) && _cnf_[hash_clause_pair.first] != hash_clause_pair.second)
     << "Conflict: same hash different clause!";
    _cnf_.insert(hash_clause_pair);
  }
}

void InvariantInCnf::Clear() {
  _cnf_.clear();
}

}; // namespace ilang
