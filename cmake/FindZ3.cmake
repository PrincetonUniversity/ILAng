# FindZ3.cmake
# Finds the z3 library
#
# This will define the following variables
#
#   Z3_FOUND
#   Z3_INCLUDE_DIRS
#   Z3_LIBRARIES
#   Z3_VERSION
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

find_program(Z3_EXEC
  NAMES z3
  PATH_SUFFIXES z3
)

mark_as_advanced(Z3_FOUND Z3_INCLUDE_DIR Z3_LIBRARY Z3_EXEC)

if("${CMAKE_SYSTEM_NAME}" MATCHES "[Ww]indows")

  find_package(Z3
    REQUIRED
    CONFIG
    # `NO_DEFAULT_PATH` is set so that -DZ3_DIR has to be passed to find Z3.
    # This should prevent us from accidentally picking up an installed
    # copy of Z3. This is here to benefit Z3's build system when building
    # this project. When making your own project you probably shouldn't
    # use this option.
    NO_DEFAULT_PATH
  )

  set(Z3_INCLUDE_DIR ${Z3_CXX_INCLUDE_DIRS})
  set(Z3_LIBRARY ${Z3_LIBRARIES})
  set(Z3_VERSION ${Z3_VERSION_STRING})

else()

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(Z3 DEFAULT_MSG 
    Z3_INCLUDE_DIR 
    Z3_LIBRARY
  )

endif()

if(Z3_FOUND)

  execute_process(
    COMMAND ${Z3_EXEC} --version > ${Z3_VERSION_FILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    OUTPUT_VARIABLE Z3_VERSION
  )
  set(Z3_VERSION_REGEX "^Z3 version (.+)$")
  string(REGEX REPLACE ${Z3_VERSION_REGEX} "\\1" Z3_VERSION "${Z3_VERSION}")

endif()

message(STATUS "Z3 version: ${Z3_VERSION}")
message(STATUS "Z3 lib dir: ${Z3_LIBRARY}")
message(STATUS "Z3 include dir: ${Z3_INCLUDE_DIR}")

# create imported target z3::z3
if(Z3_FOUND AND NOT TARGET z3::z3)
  add_library(z3::z3 INTERFACE IMPORTED)
  set_target_properties(z3::z3 PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${Z3_INCLUDE_DIR}")
  set_target_properties(z3::z3 PROPERTIES
    INTERFACE_LINK_LIBRARIES "${Z3_LIBRARY}")
endif()

