# Find Z3

set(Z3_ROOT "" CACHE PATH "Root of Z3 compiled source tree.")

if (DEFINED Z3_SOURCE_DIR)
  include ("${Z3_SOURCE_DIR}/cmake/PackageOptions.cmake")
  set (Z3_LIBRARY z3-static-lib)
else()

  find_path(Z3_INCLUDE_DIR NAMES api/z3.h PATHS ${Z3_ROOT}/src)
  find_library(Z3_LIBRARY NAMES z3 PATHS ${Z3_ROOT})
endif()

include (FindPackageHandleStandardArgs)
find_package_handle_standard_args(Z3
  REQUIRED_VARS Z3_LIBRARY Z3_INCLUDE_DIR)

mark_as_advanced(Z3_LIBRARY Z3_INCLUDE_DIR)
