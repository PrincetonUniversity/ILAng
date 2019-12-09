/// \file Invariant CNF
/// to hold ABC's output
// Hongce Zhang

#ifndef INV_CNF_H__
#define INV_CNF_H__

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>

namespace ilang {

/// \brief Class of CNF
class InvariantInCnf {
public:
  // Type definitions
  /// literal : complement, var, bit-idx
  typedef std::tuple<bool, std::string, unsigned> literal;
  /// clause : ordered literals   (l1 & l2 & l3)
  typedef std::vector<literal> clause;
  /// inv : clauses ~(c1 | c2 | c3) : clause_hash -> clause
  typedef std::unordered_map<std::string, clause> cnf_t;

  // helper functions
  /// literal to string
  static std::string Lit2Str(const literal& l);
  /// make clause ordered
  static void CanonicalizeClause(clause& c);
  /// clause to string
  static std::string Clause2Str(const clause& c);
  /// some list of vars to clause
  static void VarsToClause(const std::set<std::string>& vars, clause& out);

public:
  /// export for wky-enhance
  void ExportInCnfFormat(std::ostream& os) const;
  /// export for wky-bv
  void ExportInCociFormat(std::ostream& os) const;
  /// load from file
  void ImportFromFile(std::istream& os);

public:
  // members function : insert clause
  /// warning c will be changed (re-ordered)
  void InsertClause(clause& c);

  // insert clause (from another clause, so no need to reorder)
  void InsertClauseNoReorder(const clause& c);

  // members function : insert clause if it does not exist before
  /// warning c will be changed
  void InsertClauseNewerFromReference(clause& c, const InvariantInCnf& ref);

  // members function : insert the incremental clauses
  /// will check if duplication exists
  void InsertClauseIncremental(const InvariantInCnf& ref);

  /// access function: get all cnfs
  const cnf_t& GetCnfs() const { return _cnf_; }
  /// clear all cnfs
  void Clear();

protected:
  // members
  /// the invariant in CNF form
  cnf_t _cnf_;

}; // class InvariantInCnf

}; // namespace ilang

#endif // INVSYN_INTERFACE

#endif // INV_CNF_H__
