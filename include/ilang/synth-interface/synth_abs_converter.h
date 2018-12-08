/// \file
/// The object to convert an abstraction from the synthesis engine to an ILA.

#ifndef SYNTH_ABS_CONVERTER_H__
#define SYNTH_ABS_CONVERTER_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <ilasynth/abstraction.hpp>
#include <memory>
#include <string>

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

  /// \brief Convert a node from the synthesis engine to an expression in ILA.
  /// \param[in] node the node pointer from the synthesis engine.
  /// \param[in] ila the host ILA model.
  /// \return pointer to the converted expression.
  ExprPtr ConvertSynthNodeToIlangExpr(const ilasynth::nptr_t& node,
                                      const InstrLvlAbsPtr& ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// The set of decode functions.
  std::vector<ExprPtr> decodes_;

  /// The set of next state functions for each state var.
  std::map<ExprPtr, ExprPtr> nexts_;

  /// The mapping from node in synthesis engine to expression.
  std::map<const ilasynth::Node*, ExprPtr> node_expr_map_;

  /// The mapping from node in synthesis engein to uninterpreted function.
  std::map<const ilasynth::Node*, FuncPtr> node_func_map_;

  // ------------------------- HELPERS -------------------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// Define input variables in ila based on abs.
  void PortInputs(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define state variables in ila based on abs.
  void PortStates(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the valid function in ila based on abs.
  void PortValid(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the fetch function in ila based on abs.
  void PortFetch(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define initial condition in ila based on abs.
  void PortInits(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

  /// Collect uninterpreted functions from abs.
  void PortFuncs(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Collect decode functions from abs.
  void PortDecodeFuncs(const ilasynth::Abstraction& abs,
                       const InstrLvlAbsPtr& ila);
  /// Collect next state functions from abs.
  void PortNextStateFuncs(const ilasynth::Abstraction& abs,
                          const InstrLvlAbsPtr& ila);

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

#endif // SYNTH_ABS_CONVERTER_H__

