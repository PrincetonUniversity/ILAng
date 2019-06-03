/// \file
/// The object to convert an abstraction from the synthesis engine to an ILA.

#ifndef ILANG_TARGET_ITSY_ABST_TO_ILA_H__
#define ILANG_TARGET_ITSY_ABST_TO_ILA_H__

#include <memory>
#include <string>
#include <vector>

#include <ilang/ila/instr_lvl_abs.h>
#include <ilasynth/abstraction.hpp>

/// \namespace ilang
namespace ilang {

/// \brief The class for converting an abstraction from the synthesis engine to
/// an ILA model.
class SynthAbsConverter {
public:
  /// Pointer type for normal use of SynAbsConverter.
  typedef std::shared_ptr<SynthAbsConverter> SynthAbsConverterPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  SynthAbsConverter();
  /// Default destructor.
  ~SynthAbsConverter();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new SynthAbsConverter. Used for hiding implementation
  /// specific type details.
  static SynthAbsConverterPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Convert an abstraction from the synthesis engine to an ILA model.
  /// \param[in] abs the abstraction model from the synthesis engine.
  /// \return pointer to the converted ILA model.
  InstrLvlAbsPtr Convert(const ilasynth::Abstraction& abs);

  /// \brief Convert an abstraction from the synthesis engine on top of an ILA.
  /// \param[in] abs the abstraction model from the synthesis engine.
  /// \param[in] ila the destination ILA to which abs will be ported.
  void Port(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

  /// \brief Convert a node from the synthesis engine to an expression in ILA.
  /// \param[in] node the node pointer from the synthesis engine.
  /// \param[in] ila the host ILA model.
  /// \return pointer to the converted expression.
  ExprPtr ConvertSynthNodeToIlangExpr(const ilasynth::nptr_t& node,
                                      const InstrLvlAbsPtr& ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The mapping from node in synthesis engine to expression.
  std::map<const ilasynth::Node*, ExprPtr> node_expr_map_;
  /// The mapping from node in synthesis engein to uninterpreted function.
  std::map<const ilasynth::Node*, FuncPtr> node_func_map_;

  /// A set of entry for decomposition.
  ExprSet decom_entry_;
  /// The mapping of entries to decomposed sub-trees.
  std::map<ExprPtr, ExprPtr> decom_match_;
  /// A set of visited (decomposed) glue (ITE) nodes.
  ExprSet decom_glue_;
  /// A set of else branch sub-trees of the decomposed glue nodes.
  ExprSet decom_else_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Reset cached internal book keeping.
  void Reset() {
    node_expr_map_.clear();
    node_func_map_.clear();
    decom_entry_.clear();
    decom_match_.clear();
    decom_glue_.clear();
    decom_else_.clear();
  }

  // ------------------------- METHODS -------------------------------------- //
  /// Define input variables in ila based on abs if not already.
  void PortInputs(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define state variables in ila based on abs if not already.
  void PortStates(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the valid function in ila based on abs.
  void PortValid(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the fetch function in ila based on abs.
  void PortFetch(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define initial condition in ila based on abs..
  void PortInits(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define uninterpreted functions from abs.
  void PortFuncs(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the set of instructions in ila based on abs.
  void PortInstructions(const ilasynth::Abstraction& abs,
                        const InstrLvlAbsPtr& ila);

  /// Syntatically decompose an expression (src) at the ITE nodes based on the
  /// set of entries. This is based on the synthesis engine implementation.
  void DecomposeExpr(const ExprPtr& src);

  /// The entry point for converting non-var nodes into expr.
  void CnvtNodeToExpr(const ilasynth::Node* n);
  /// Convert constant node into expr.
  void CnvtNodeToExprConst(const ilasynth::Node* n);
  /// Convert Boolean type operations into expr.
  void CnvtNodeToExprBoolOp(const ilasynth::Node* n);
  /// Convert Bit-vector type operations into expr.
  void CnvtNodeToExprBvOp(const ilasynth::Node* n);
  /// Convert Memory (array) type operations into expr.
  void CnvtNodeToExprMemOp(const ilasynth::Node* n);

}; // class SynthAbsConverter

/// Pointer type for normal use of SynthAbsConverter.
typedef SynthAbsConverter::SynthAbsConverterPtr SynthAbsConverterPtr;

}; // namespace ilang

#endif // ILANG_TARGET_ITSY_ABST_TO_ILA_H__
