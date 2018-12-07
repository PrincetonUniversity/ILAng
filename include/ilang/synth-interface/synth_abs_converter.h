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
  ExprPtr ConvertSynthNodeToIlangExpr(const ilasynth::Node* node,
                                      const InstrLvlAbsPtr& ila);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  /// Mapping for uninterpreted functions.
  std::map<std::string, FuncPtr> funcs_;

  /// The set of decode functions.
  std::vector<ExprPtr> decodes_;

  /// The set of next state functions.
  std::map<std::string, ExprPtr> nexts_;

  /// The mapping between synthesis engine node to ILAng expression.
  std::map<const ilasynth::Node*, ExprPtr> node_expr_map_;

  // ------------------------- HELPERS -------------------------------------- //
  /// Define input variables in ila based on abs.
  bool PortInputs(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define state variables in ila based on abs.
  bool PortStates(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the valid function in ila based on abs.
  bool PortValid(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define the fetch function in ila based on abs.
  bool PortFetch(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Define initial condition in ila based on abs.
  bool PortInits(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);

  /// Collect uninterpreted functions from abs.
  bool PortFuncs(const ilasynth::Abstraction& abs, const InstrLvlAbsPtr& ila);
  /// Collect decode functions from abs.
  bool PortDecodeFuncs(const ilasynth::Abstraction& abs,
                       const InstrLvlAbsPtr& ila);
  /// Collect next state functions from abs.
  bool PortNextStateFuncs(const ilasynth::Abstraction& abs,
                          const InstrLvlAbsPtr& ila);

  /// Convert a constant node from the synthesis engine to an expression in ILA.
  bool ConvertConstNode(const ilasynth::Node* n);
  /// Convert an op node from the synthesis engine to an expression in ILA.
  bool ConvertOpNode(const ilasynth::Node* n);

  /// Convert Bool operator from synthesis engine node to ILA expression.
  ExprPtr ConvertBoolOpNode(const ilasynth::Node* n);
  /// Convert bit-vector operator from synthesis engine node to ILA expression.
  ExprPtr ConvertBvOpNode(const ilasynth::Node* n);
  /// Convert memory operator from synthesis engine node to ILA expression.
  ExprPtr ConvertMemOpNode(const ilasynth::Node* n);

}; // class SynthAbsConverter

/// Pointer type for normal use of SynthAbsConverter.
typedef SynthAbsConverter::SynthAbsConverterPtr SynthAbsConverterPtr;

}; // namespace ilang

#endif // SYNTH_ABS_CONVERTER_H__

