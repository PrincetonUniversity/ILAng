/// \file
/// Source for the refinement relation

#include "refinement/comp_ref_rel.h"

namespace ila {

RefinementMap::RefinementMap() {}

RefinementMap::~RefinementMap() {}

void RefinementMap::set_flush(const ExprPtr flush) {
  ILA_ASSERT(flush->is_bool())
      << "Flushing function should be represented as Boolean constraint.";
  flush_ = flush;
}

void RefinementMap::set_cmpl(const ExprPtr cmpl) {
  ILA_ASSERT(cmpl->is_bool())
      << "Completion should be indicated as Boolean constraint.";
  cmpl_ = cmpl;
}

void RefinementMap::set_step(const int& step) {
  ILA_ASSERT(step > 0) << "Can only be flushed positive times.";
  step_ = step;
}

RelationMap::RelationMap() {}

RelationMap::~RelationMap() {}

void RelationMap::add(const ExprPtr rel) {
  ILA_ASSERT(rel->is_bool()) << "Relation mapping should be Boolean typed.";
  rels_.push_back(rel);
  acc_ = NULL;
}

ExprPtr RelationMap::get() {
  if (acc_)
    return acc_;
  ILA_ASSERT(!rels_.empty()) << "No relation mapping defined...";

  acc_ = ExprFuse::BoolConst(true);
  for (auto it = rels_.begin(); it != rels_.end(); it++) {
    acc_ = ExprFuse::And(acc_, *it);
  }
  return acc_;
}

#if 0
RefUnit::RefUnit() { clear(); }

RefUnit::~RefUnit() { clear(); }

void RefUnit::set_app(const InstrLvlAbsPtr ila, const ExprPtr app) {
  ILA_ASSERT(app_.find(ila) == app_.end()) << "App of " << ila
                                           << " has been assigned.\n";
  app_[ila] = app;
}

void RefUnit::set_commit(const InstrLvlAbsPtr ila, const ExprPtr com) {
  ILA_ASSERT(commit_.find(ila) == commit_.end()) << "Commit of " << ila
                                                 << " has been assigned.\n";
  commit_[ila] = com;
}

void RefUnit::set_stall(const InstrLvlAbsPtr ila, const ExprPtr stall) {
  ILA_ASSERT(stall_.find(ila) == stall_.end()) << "Stall function of " << ila
                                               << " has been assigned.\n";
}

void RefUnit::add_dep(const InstrLvlAbsPtr ila) { dep_.push_back(ila); }

ExprPtr RefUnit::app(const InstrLvlAbsPtr ila) const {
  auto pos = app_.find(ila);
  ILA_ASSERT(pos != app_.end()) << "App of " << ila << " not found.\n";
  return pos->second;
}

ExprPtr RefUnit::commit(const InstrLvlAbsPtr ila) const {
  auto pos = commit_.find(ila);
  ILA_ASSERT(pos != commit_.end()) << "Commit of " << ila << "not found.\n";
  return pos->second;
}

ExprPtr RefUnit::stall(const InstrLvlAbsPtr ila) const {
  auto pos = stall_.find(ila);
  ILA_ASSERT(pos != stall_.end()) << "Stall function of " << ila
                                  << " not found.\n";
  return pos->second;
}

InstrLvlAbsPtr RefUnit::dep(const size_t& i) const { return dep_.at(i); }

size_t RefUnit::dep_num() const { return dep_.size(); }

void RefUnit::clear() {
  app_.clear();
  commit_.clear();
  stall_.clear();
  dep_.clear();
}

RefRel::RefRel(const InstrLvlAbsPtr ila_a, const InstrLvlAbsPtr ila_b)
    : ma_(ila_a), mb_(ila_b) {
  clear();
}

RefRel::~RefRel() { clear(); }

size_t RefRel::state_map_num() const { return state_maps_.size(); }

size_t RefRel::inv_num(const InstrLvlAbsPtr ila) const {
  if (ila == ma_) {
    return inv_ma_.size();
  } else {
    ILA_ASSERT(ila == mb_) << ila << " not found.\n";
    return inv_mb_.size();
  }
}

size_t RefRel::unit_num() const { return units_.size(); }

ExprPtr RefRel::state_map(const size_t& i) const { return state_maps_.at(i); }

ExprPtr RefRel::inv(const InstrLvlAbsPtr ila, const size_t& i) const {
  if (ila == ma_) {
    return inv_ma_.at(i);
  } else {
    ILA_ASSERT(ila == mb_) << ila << " not found.\n";
    return inv_mb_.at(i);
  }
}

RefUnitPtr RefRel::unit(const size_t& i) const { return units_.at(i); }

InstrLvlAbsPtr RefRel::ila(const size_t& i) const {
  if (i == 0) {
    return ma_;
  } else {
    ILA_ASSERT(i == 1) << "Can only access 0/1-th ILA.\n";
    return mb_;
  }
}

void RefRel::clear() {
  state_maps_.clear();
  inv_ma_.clear();
  inv_mb_.clear();
  units_.clear();
}
#endif

} // namespace ila

