# FindZ3.cmake
# Finds the z3 library
#
# This will define the following variables
#
#   Z3_FOUND
#   Z3_INCLUDE_DIRS
#   Z3_LIBRARIES
#
# and the following imported targets
#
#   z3::z3
# 

find_package(PkgConfig)
pkg_check_modules(PC_Z3 QUIET Z3)

find_path(Z3_INCLUDE_DIR
  NAMES z3++.h
  HINTS ${PC_Z3_INCLUDEDIR} ${PC_Z3_INCLUDE_DIRS}
  PATH_SUFFIXES z3
)

find_library(Z3_LIBRARY 
  NAMES z3 libz3
  HINTS ${PC_Z3_LIBDIR} ${PC_Z3_LIBRARY_DIRS}
  PATH_SUFFIXES z3
)

set(Z3_VERSION ${PC_Z3_VERSION})

mark_as_advanced(Z3_FOUND Z3_INCLUDE_DIR Z3_LIBRARY Z3_VERSION)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Z3 DEFAULT_MSG 
  Z3_INCLUDE_DIR 
  Z3_LIBRARY
)

if(Z3_FOUND)
  set(Z3_INCLUDE_DIRS ${Z3_INCLUDE_DIR})
  set(Z3_LIBRARIES ${Z3_LIBRARY})
endif()

# create imported target z3::z3
if(Z3_FOUND AND NOT TARGET z3::z3)
  add_library(z3::z3 INTERFACE IMPORTED)
  set_target_properties(z3::z3 PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${Z3_INCLUDE_DIR}")
  set_target_properties(z3::z3 PROPERTIES
    INTERFACE_LINK_LIBRARIES "${Z3_LIBRARY}")
endif()

