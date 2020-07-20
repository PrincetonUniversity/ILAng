/// \file
/// Class IlaSerDesMngr - the interface for Ser/Des ILA models.

#ifndef ILANG_TARGET_JSON_INTERFACE_H__
#define ILANG_TARGET_JSON_INTERFACE_H__

#include <string>

#include <nlohmann/json.hpp>

#include <ilang/ila/instr_lvl_abs.h>

/// \namespace ilang
namespace ilang {

using json = nlohmann::json;

/// \brief Class wrapper for the ILA portable Ser/Des interface.
class IlaSerDesMngr {
public:
  // ------------------------- METHODS -------------------------------------- //
  /// \brief Serialize the ILA model to a JSON object.
  /// \param[in] m the ILA model to serialize.
  /// \return Return the serialized JSON object.
  static json Serialize(const InstrLvlAbsPtr& m);

  /// \brief Deserialize the ILA model from a JSON object.
  /// \param[in] j the input JSON object.
  /// \return The pointer to the deserialized ILA model. Return NULL if fail.
  static InstrLvlAbsPtr Deserialize(const json& j);

  /// \brief Serialize the ILA model to the given file.
  /// \param[in] m the ILA model to serialize.
  /// \param[in] file_name the output file name.
  /// \param[in] indent the number of space to indent.
  /// \return Return true if complete sucessfully.
  static bool SerToFile(const InstrLvlAbsPtr& m, const std::string& file_name,
                        const int& indent = -1);

  /// \brief Deserialize the ILA model from the given file.
  /// \param[in] file_name the input file name.
  /// \return The pointer to the deserialized ILA model. Return NULL if fail.
  static InstrLvlAbsPtr DesFromFile(const std::string& file_name);

}; // class IlaSerDesMngr

} // namespace ilang

#endif // ILANG_TARGET_JSON_INTERFACE_H__
