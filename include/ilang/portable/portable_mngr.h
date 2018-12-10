/// \file
/// The object to export and import ILA portable in JSON format.

#ifndef ILA_PORTABLE_MNGR_H__
#define ILA_PORTABLE_MNGR_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <memory>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

/// \namespace ilang
namespace ilang {

/// \brief The class for exporting and importing ILA portable in JSON format.
class IlaPortableMngr {
public:
  /// Pointer type for normal use of IlaPortableMngr.
  typedef std::shared_ptr<IlaPortableMngr> IlaPortableMngrPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Default constructor.
  IlaPortableMngr();
  /// Default destructor.
  ~IlaPortableMngr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new IlaPortableMngr. Used for hiding implementation
  /// specific type details.
  static IlaPortableMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Export the ILA model to the file.
  /// \param[in] fileName the output file name for the exported ILA portable.
  /// \return Return true if export complete successfully.
  bool ExportToFile(const std::string& fileName) const;

  /// \brief Import the portable from the file and create the ILA model.
  /// \param[in] fileName the input file name for the ILA portable.
  /// \return The pointer to the ILA model, NULL if fail importing.
  InstrLvlAbsPtr ImportFromFile(const std::string& fileName) const;

private:
  // ------------------------- MEMBERS -------------------------------------- //

  // ------------------------- HELPERS -------------------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  json GenJsonObjOfInstr(const InstrPtr* instr);

}; // class IlaPortableMngr

/// Pointer type for normal use of IlaPortableMngr.
typedef IlaPortableMngr::IlaPortableMngrPtr IlaPortableMngrPtr;

}; // namespace ilang

#endif // ILA_PORTABLE_MNGR_H__

