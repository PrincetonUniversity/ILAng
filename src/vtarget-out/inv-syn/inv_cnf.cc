/// \file Invariants in CNF
// ---Hongce Zhang

#include <ilang/config.h>
#ifdef INVSYN_INTERFACE

#include <ilang/util/container_shortcut.h>
#include <ilang/util/log.h>
#include <ilang/util/str_util.h>
#include <ilang/vtarget-out/inv-syn/inv_cnf.h>

#include <algorithm>

namespace ilang {

void InvariantInCnf::VarsToClause(const std::set<std::string>& vars,
                                  clause& out) {
  for (auto&& v : vars)
    out.push_back(std::make_tuple(false, v, 0U));
}

/// literal to string
std::string InvariantInCnf::Lit2Str(const literal& l) {
  auto idx = std::to_string(std::get<2>(l));
  return (std::get<0>(l) ? "~" : " ") + std::get<1>(l) + "[" + idx + ":" + idx +
         "]";
}
/// make clause ordered
void InvariantInCnf::CanonicalizeClause(clause& c) {
  std::sort(c.begin(), c.end());
}
/// clause to string
std::string InvariantInCnf::Clause2Str(const clause& c) {
  std::string ret;
  for (auto&& l : c)
    ret += " " + Lit2Str(l);
  return ret;
}

void InvariantInCnf::InsertClauseNoReorder(const clause& c) {
  auto clause_hash = Clause2Str(c);
  if (!IN(clause_hash, _cnf_)) {
    _cnf_.insert(std::make_pair(clause_hash, c));
  }
}

void InvariantInCnf::InsertClause(clause& c) {
  CanonicalizeClause(c);
  auto clause_hash = Clause2Str(c);
  if (!IN(clause_hash, _cnf_)) {
    _cnf_.insert(std::make_pair(clause_hash, c));
  }
}

void InvariantInCnf::InsertClauseNewerFromReference(clause& c,
                                                    const InvariantInCnf& ref) {
  CanonicalizeClause(c);
  auto clause_hash = Clause2Str(c);
  if (!IN(clause_hash, ref._cnf_))
    _cnf_.insert(std::make_pair(clause_hash, c));
}

void InvariantInCnf::InsertClauseIncremental(const InvariantInCnf& ref) {
  for (auto&& hash_clause_pair : ref._cnf_) {
    ILA_ERROR_IF(IN(hash_clause_pair.first, _cnf_) &&
                 _cnf_[hash_clause_pair.first] != hash_clause_pair.second)
        << "Conflict: same hash different clause!";
    _cnf_.insert(hash_clause_pair);
  }
}

void InvariantInCnf::Clear() { _cnf_.clear(); }

/// load from file
void InvariantInCnf::ImportFromFile(std::istream& ins) {
  unsigned num_clause;
  ins >> num_clause;
  for (unsigned idx = 0; idx < num_clause; ++idx) {
    unsigned num_literal;
    ins >> num_literal;
    clause cl;
    for (unsigned lidx = 0; lidx < num_literal; ++lidx) {
      std::string s_name;
      unsigned bitslice;
      bool complemented;
      ins >> s_name >> bitslice >> complemented;
      cl.push_back(std::make_tuple(complemented, s_name, bitslice));
    }                 // for each literal
    InsertClause(cl); // put a clause
  }                   // for each clause
}

/// export for wky-enhance
void InvariantInCnf::ExportInCnfFormat(std::ostream& os) const {
  os << GetCnfs().size() << std::endl; //# of clauses
  for (auto&& clause : GetCnfs()) {
    // for each clause
    os << clause.second.size() << std::endl; //# of lterals
    for (auto&& literal : clause.second)
      // complement, var, bit-idx
      os << std::get<1>(literal) << ' ' << std::get<2>(literal) << ' '
         << std::get<0>(literal) << std::endl;
  }
}
/// export for wky-bv
void InvariantInCnf::ExportInCociFormat(std::ostream& os) const {
  std::vector<std::string> states;
  for (auto&& clause : GetCnfs()) {
    // for each clause
    for (auto&& literal : clause.second)
      // complement, var, bit-idx
      states.push_back("S_" + std::get<1>(literal));
  }
  os << "CTRL-STATE: " << Join(states, ", ") << std::endl;
  os << "DATA-OUT: " << Join(states, ", ") << std::endl << std::endl;
}

}; // namespace ilang

#endif // INVSYN_INTERFACE
