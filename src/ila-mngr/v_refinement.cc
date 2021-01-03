/// \file
/// Refinement relation for ILA vs. ILA equivalence checking.

#include <ilang/ila-mngr/v_eq_check_refinement.h>

#include <ilang/ila-mngr/u_abs_knob.h>
#include <ilang/util/log.h>

namespace ilang {

RefinementMap::RefinementMap() {}

RefinementMap::~RefinementMap() {}

void RefinementMap::set_tgt(const InstrLvlAbsPtr& tgt) {
  ILA_ASSERT(tgt);
  coi_ = tgt;
}

void RefinementMap::set_tgt(const InstrPtr& tgt) {
  ILA_ASSERT(tgt && tgt->host());
  coi_ = absknob::ExtrDeptModl(tgt, tgt->host()->name().str());
}

void RefinementMap::set_appl(const ExprPtr& appl) {
  ILA_ASSERT(appl && appl->is_bool())
      << "Apply function should be represented as Boolean constraint.";
  appl_ = appl;
}

void RefinementMap::set_flush(const ExprPtr& flush) {
  ILA_ASSERT(flush && flush->is_bool())
      << "Flushing function should be represented as Boolean constraint.";
  flush_ = flush;
}

void RefinementMap::set_cmpl(const ExprPtr& cmpl) {
  ILA_ASSERT(cmpl && cmpl->is_bool())
      << "Completion should be indicated as Boolean constraint.";
  cmpl_ = cmpl;
}

void RefinementMap::set_step_appl(const int& step) {
  ILA_ASSERT(step >= 0) << "Can only be flushed positive times.";
  step_appl_ = step;
}

void RefinementMap::set_step_orig(const int& step) {
  ILA_ASSERT(step >= 0) << "Can only be flushed positive times.";
  step_orig_ = step;
}

void RefinementMap::add_inv(const ExprPtr& inv) {
  ILA_ASSERT(inv && inv->is_bool()) << "Invariant should be Boolean.";
  invs_.push_back(inv);
}

RefinementMap::RefPtr RefinementMap::New() {
  return std::make_shared<RefinementMap>();
}

RelationMap::RelationMap() {}

RelationMap::~RelationMap() {}

void RelationMap::add(const ExprPtr& rel) {
  ILA_ASSERT(rel && rel->is_bool())
      << "Relation mapping should be Boolean typed.";
  acc_ = asthub::And(acc_, rel);
}

RelationMap::RelPtr RelationMap::New() {
  return std::make_shared<RelationMap>();
}

CompRefRel::CompRefRel(const RefPtr ref_a, const RefPtr ref_b, const RelPtr rel)
    : ref_a_(ref_a), ref_b_(ref_b), rel_(rel) {
  ILA_ASSERT(ref_a && ref_b && rel) << "Incomplete refinement relation.";
}

CompRefRel::~CompRefRel() {}

CompRefRel::CrrPtr CompRefRel::New(const RefPtr ref_a, const RefPtr ref_b,
                                   const RelPtr rel) {
  return std::make_shared<CompRefRel>(ref_a, ref_b, rel);
}

} // namespace ilang
