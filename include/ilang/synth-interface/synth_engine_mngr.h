/// \file
/// Header for the template-based synthesis engine interface.

#ifndef SYNTH_ENGINE_MNGR_H__
#define SYNTH_ENGINE_MNGR_H__

#include <ilang/ila/instr_lvl_abs.h>
#include <string>

/// \namespace ilang
namespace ilang {

/// \brief The class for interfacing templated-based synthesis engine.
class SynEngMngr {
public:
  /// Pointer type for normal use of SynEngMngr.
  typedef std::shared_ptr<SynEngMngr> SynEngMngrPtr;

  // ------------------------- CONSTRUCTOR/DESTRUCTOR ----------------------- //
  /// Constructor.
  SynEngMngr();
  /// Default destructor.
  ~SynEngMngr();

  // ------------------------- HELPERS -------------------------------------- //
  /// \brief Create a new SynEngMngr. Used for hiding implementation specific
  /// type details.
  static SynEngMngrPtr New();

  // ------------------------- ACCESSORS/MUTATORS --------------------------- //

  // ------------------------- METHODS -------------------------------------- //
  /// \brief Import complete exported ILA from a file.
  /// \param[in] fileName file name of the exported ILA.
  /// \return pointer to the processed ILA.
  InstrLvlAbsPtr ImportIlaFromFile(const std::string &fileName);

private:
  // ------------------------- MEMBERS -------------------------------------- //
  //

  // ------------------------- HELPERS -------------------------------------- //
  //
}; // class SynEngMngr

/// Pointer type for normal use of SynEngMngr.
typedef SynEngMngr::SynEngMngrPtr SynEngMngrPtr;

}; // namespace ilang

#endif // SYNTH_ENGINE_MNGR_H__

