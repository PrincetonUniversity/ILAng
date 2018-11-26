# Findnlohmann_json.cmake
# Finds the nlohmann_json (header-only) library
#
# This will define the following variables
#
#   NLOHMANN_JSON_FOUND
#   NLOHMANN_JSON_INCLUDE_DIRS
#   NLOHMANN_JSON_LIBRARIES
#
# and the following imported targets
#
#   nlohmann_json::nlohmann_json
#

find_package(PkgConfig)
pkg_check_modules(PC_nlohmann_json QUIET nlohmann_json)

find_path(NLOHMANN_JSON_INCLUDE_DIR
  NAME json.h
  HINTS ${PC_nlohmann_json_INCLUDE_DIR} ${PC_nlohmann_json_INCLUDE_DIRS}
  PATH_SUFFIXS nlohmann
)

set(NLOHMANN_VERSION ${PC_NLOHMANN_JSON_VERSION})

mark_as_advanced(NLOHMANN_JSON_FOUND NLOHMANN_JSON_INCLUDE_DIR NLOHMANN_JSON_LIBRARY NLOHMANN_JSON_VERSION)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NLOHMANN_JSON DEFAULT_MSG 
  NLOHMANN_JSON_INCLUDE_DIR 
  NLOHMANN_JSON_LIBRARY
)

if(NLOHMANN_JSON_FOUND)
  set(NLOHMANN_JSON_INCLUDE_DIRS ${NLOHMANN_JSON_INCLUDE_DIR})
  set(NLOHMANN_JSON_LIBRARIES ${NLOHMANN_JSON_LIBRARY})
endif()

if(NLOHMANN_JSON_FOUND AND NOT TARGET nlohmann_json::nlohmann_json)
  add_library(nlohmann_json::nlohmann_json INTERFACE IMPORTED)

  set_target_properties(nlohmann_json::nlohmann_json PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${NLOHMANN_JSON_INCLUDE_DIR}")
  
endif()
