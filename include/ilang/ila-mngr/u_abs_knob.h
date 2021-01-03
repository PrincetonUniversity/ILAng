/// \file
/// A collection of ILA helpers.

#ifndef ILANG_ILA_MNGR_U_ABS_KNOB_H__
#define ILANG_ILA_MNGR_U_ABS_KNOB_H__

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

/// \namespace absknob
namespace absknob {
/****************************************************************************/
/// Add all dependent vars of the expr to the set.
void InsertVar(const ExprPtr& e, ExprSet& vars);
/// Get the set of all dependent vars of the expr.
ExprSet GetVar(const ExprPtr& e);

/****************************************************************************/
/// Add all state vars of the host (excluding child) to the set.
void InsertStt(const InstrCnstPtr instrs, ExprSet& stts);
/// Add all state vars of the host (including child) to the set.
void InsertSttTree(const InstrCnstPtr instrs, ExprSet& stts);

/****************************************************************************/
/// Add all vars of the ILA (excluding child) to the set.
void InsertVar(const InstrLvlAbsCnstPtr& m, ExprSet& vars);
/// Add all state vars of the ILA (excluding child) to the set.
void InsertStt(const InstrLvlAbsCnstPtr& m, ExprSet& stts);
/// Add all input vars of the ILA (excluding child) to the set.
void InsertInp(const InstrLvlAbsCnstPtr& m, ExprSet& inps);
/// Add all vars of the ILA (including child) to the set.
void InsertVarTree(const InstrLvlAbsCnstPtr& top, ExprSet& vars);
/// Add all state vars of the ILA (including child) to the set.
void InsertSttTree(const InstrLvlAbsCnstPtr& top, ExprSet& stts);
/// Add all input vars of the ILA (including child) to the set.
void InsertInpTree(const InstrLvlAbsCnstPtr& top, ExprSet& inps);

/// Get the set of all vars of the ILA (excluding child).
ExprSet GetVar(const InstrLvlAbsCnstPtr& m);
/// Get the set of all state vars of the ILA (excluding child).
ExprSet GetStt(const InstrLvlAbsCnstPtr& m);
/// Get the set of all input vars of the ILA (excluding child).
ExprSet GetInp(const InstrLvlAbsCnstPtr& m);
/// Get the set of all vars of the ILA (including child).
ExprSet GetVarTree(const InstrLvlAbsCnstPtr& top);
/// Get the set of all state vars of the ILA (including child).
ExprSet GetSttTree(const InstrLvlAbsCnstPtr& top);
/// Get the set of all input vars of the ILA (including child).
ExprSet GetInpTree(const InstrLvlAbsCnstPtr& top);

/// Add all instructions of the ILA (excluding child) to the set.
void InsertInstr(const InstrLvlAbsCnstPtr& m, InstrVec& instrs);
/// Add all instructions of the ILA (including child) to the set.
void InsertInstrTree(const InstrLvlAbsCnstPtr& top, InstrVec& instrs);

/// Get the set of instructions of the ILA (excluding child).
InstrVec GetInstr(const InstrLvlAbsCnstPtr& m);
/// Get the set of instructions of the ILA (including child).
InstrVec GetInstrTree(const InstrLvlAbsCnstPtr& top);

/****************************************************************************/
/// \brief Rewrite an expression by replacing based on the rule.
/// - If leaves contain non-var nodes, will replace with no further traverse.
ExprPtr Rewrite(const ExprPtr& e, const ExprMap& rule);

/// \brief Rewrite an instruction by replacing based on the rule.
void RewriteInstr(const InstrCnstPtr instr_src, const InstrPtr& instr_dst,
                  const ExprMap& expr_map);

/// \brief Flatten the given ILA, the initial conditions will be added to the
/// top the child instructions will also be added to the top, but their
/// (hierarchical) valid conditions will be added to their decode condition
/// Some usage hint: this function is intended to generate an ILA for Verilog
/// generator or other verification model generator. You can first use
/// ExtrDeptModl to extract the dependent model and use this to flatten the
/// that model and send to the generator
void FlattenIla(const InstrLvlAbsPtr& ila_ptr_);

/// \brief Return a new ILA that contains the dependant instructions and
/// child-ILAs of an instruction (defined by sub-programs).
InstrLvlAbsPtr ExtrDeptModl(const InstrPtr& instr, const std::string& name);

/// Copy and ILA (including child).
InstrLvlAbsPtr CopyIlaTree(const InstrLvlAbsCnstPtr& src,
                           const std::string& dst_name);

/****************************************************************************/
/// Duplicate input vars from src to dst while updating the mapping.
void DuplInp(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
             ExprMap& expr_map);
/// Duplicate state vars from src to dst while updating the mapping.
void DuplStt(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
             ExprMap& expr_map);
/// Duplicate fetch from src to dst if defined (rewritten w.r.t. mapping).
ExprPtr DuplFetch(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
                  const ExprMap& expr_map);
/// Duplicate valid from src to dst if defined (rewritten w.r.t. mapping).
ExprPtr DuplValid(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
                  const ExprMap& expr_map);
/// Duplicate initial conditions from src to dst (rewritten w.r.t. mapping).
void DuplInit(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst,
              const ExprMap& expr_map);
/// Duplicate an instruction to dst (rewritten w.r.t. mapping).
InstrPtr DuplInstr(const InstrCnstPtr instr_src, const InstrLvlAbsPtr& dst,
                   const ExprMap& expr_map, const CnstIlaMap& ila_map);
/// Duplicate instruction sequence to dst. NOT IMPLEMENTED YET.
void DuplInstrSeq(const InstrLvlAbsCnstPtr& src, const InstrLvlAbsPtr& dst);

}; // namespace absknob

} // namespace ilang

#endif // ILANG_ILA_MNGR_U_ABS_KNOB_H__
