/// \file
/// ILA serializer/deserializer to/from JSON format.

#ifndef ILANG_PORTABLE_SERDES_H
#define ILANG_PORTABLE_SERDES_H

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

/// \namespace ilang
namespace ilang {

/// \brief The class for serialize and deserialize ILA models to/from JSON
/// format.
class IlaSerDesMngr {
public:
  /// Pointer type for normal use of IlaSerDesMngr.
  typedef std::shared_ptr<IlaSerDesMngr> IlaSerDesMngrPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  IlaSerDesMngr();
  /// Default destructor.
  ~IlaSerDesMngr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new IlaSerDesMngr. Used for hiding implementation specific
  /// type details.
  static IlaSerDesMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Serialize the ILA model to the given file.
  /// \param[in] m the ILA model to serialize.
  /// \param[in] file_name the output file name.
  /// \return Return true if complete sucessfully.
  bool SerToFile(const InstrLvlAbsPtr& m, const std::string& file_name) const;

  /// \brief Deserialize the ILA model from the given file.
  /// \param[in] file_name the input file name.
  /// \return The pointer to the deserialized ILA model. Return NULL if fail.
  InstrLvlAbsPtr DesFromFile(const std::string& file_name) const;

  /// \brief Serialize the ILA model to a JSON object.
  /// \param[in] m the ILA model to serialize.
  /// \return Return the serialized JSON object.
  json Serialize(const InstrLvlAbsPtr& m) const;

  /// \brief Deserialize the ILA model from a JSON object.
  /// \param[in] j the input JSON object.
  /// \return The pointer to the deserialized ILA model. Return NULL if fail.
  InstrLvlAbsPTr Deserialize(const json& j) const;

  // TODO ser/des hierarchical ILA to/from multiple files

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

  // ------------------------- METHODS -------------------------------------- //

}; // class IlaSerDesMngr

/// Pointer type for normal use of IlaSerDesMngr.
typedef IlaSerDesMngr::IlaSerDesMngrPtr IlaSerDesMngrPtr;

}; // namespace ilang

#endif // ILANG_PORTABLE_SERDES_H__
