cmake_minimum_required(VERSION 3.9.6)

if(${CMAKE_VERSION} VERSION_LESS 3.14)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.14)
endif()


# ---------------------------------------------------------------------------- #
# PROJECT
# name version language
# ---------------------------------------------------------------------------- #
project(ilang VERSION     1.1.4
              LANGUAGES   CXX
)


# ---------------------------------------------------------------------------- #
# OPTION
# build configuration
# ---------------------------------------------------------------------------- #
option(ILANG_FETCH_DEPS  "Fetch source of dependencies at config time."      ON)
option(ILANG_BUILD_DOCS  "Build documentations."                            OFF)
option(ILANG_BUILD_SYNTH "Build the synthesis engine."                      OFF)
option(ILANG_INSTALL_DEV "Install dev features."                            OFF)
option(ILANG_EXPORT_PACKAGE "Export CMake package if enabled."              OFF)
option(ILANG_COVERITY    "Build for Coverity static analysis."              OFF)
option(BUILD_SHARED_LIBS "Build shared libraries."                           ON)
option(ILANG_BUILD_INVSYN "Build invariant synthesis feature."               ON)
option(ILANG_BUILD_SWITCH "Build smt-switch interface."                     OFF)
option(ILANG_BUILD_COSIM "Build QEMU-based co-simulation support."          OFF)

include(CMakeDependentOption)

cmake_dependent_option(ILANG_BUILD_TEST "Build unit tests."                  ON
  "PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME" OFF)

cmake_dependent_option(ILANG_BUILD_COV  "Build with coverage flags."        OFF
  "CMAKE_BUILD_TYPE MATCHES Debug AND CMAKE_COMPILER_IS_GNUCXX"             OFF)


# ---------------------------------------------------------------------------- #
# VARARIABLE
# alias and configurations
# ---------------------------------------------------------------------------- #
set(ILANG_TARGET_NAME                ${PROJECT_NAME}) 
set(ILANG_CONFIG_INSTALL_DIR         "lib/cmake/${PROJECT_NAME}" CACHE INTERNAL "")
set(ILANG_INCLUDE_INSTALL_DIR        "include")
set(ILANG_INCLUDE_BUILD_DIR          "${PROJECT_SOURCE_DIR}/include")
set(ILANG_TARGETS_EXPORT_NAME        "${PROJECT_NAME}Targets")
set(ILANG_CMAKE_CONFIG_TEMPLATE      "cmake/config.cmake.in")
set(ILANG_CMAKE_CONFIG_DIR           "${CMAKE_CURRENT_BINARY_DIR}")
set(ILANG_CMAKE_PROJECT_TARGETS_FILE "${PROJECT_NAME}Targets.cmake")

set(ILANG_CMAKE_VERSION_CONFIG_FILE  
  "${ILANG_CMAKE_CONFIG_DIR}/${PROJECT_NAME}ConfigVersion.cmake")

set(ILANG_CMAKE_PROJECT_CONFIG_FILE  
  "${ILANG_CMAKE_CONFIG_DIR}/${PROJECT_NAME}Config.cmake")

if(${BUILD_SHARED_LIBS})
  set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
  set(CMAKE_MACOSX_RPATH TRUE)
endif()

# ---------------------------------------------------------------------------- #
# External dependencies
# ---------------------------------------------------------------------------- #
##
## Make sure that custom modules can be found.
##
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

##
## git submodules
##
if(${ILANG_FETCH_DEPS})

  find_package(Git REQUIRED)

  if(NOT EXISTS "${PROJECT_SOURCE_DIR}/.git")
    message(FATAL_ERROR "Submodule info not found.")
  endif()

endif()

##
## Third-party packages
##
add_subdirectory(extern)


# ---------------------------------------------------------------------------- #
# TARGET
# library target
# ---------------------------------------------------------------------------- #
set(ILANG_LIB_NAME ${ILANG_TARGET_NAME})

add_subdirectory(src)


# ---------------------------------------------------------------------------- #
# TARGET
# Making the executable
# ---------------------------------------------------------------------------- #


# ---------------------------------------------------------------------------- #
# INSTALL
# project related
# ---------------------------------------------------------------------------- #
##
## forward version for find_package
##
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  ${ILANG_CMAKE_VERSION_CONFIG_FILE} 
  COMPATIBILITY AnyNewerVersion
)

##
## cmake config
##
configure_file(
  ${ILANG_CMAKE_CONFIG_TEMPLATE}
  ${ILANG_CMAKE_PROJECT_CONFIG_FILE}
  @ONLY
)

install(
  FILES ${ILANG_CMAKE_PROJECT_CONFIG_FILE} ${ILANG_CMAKE_VERSION_CONFIG_FILE}
  DESTINATION ${ILANG_CONFIG_INSTALL_DIR}
)

##
## project export
##
install(
  EXPORT ${ILANG_TARGETS_EXPORT_NAME}
  DESTINATION ${ILANG_CONFIG_INSTALL_DIR}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${ILANG_CMAKE_PROJECT_TARGETS_FILE}
)

export(
  TARGETS ${ILANG_LIB_NAME}
  NAMESPACE ${PROJECT_NAME}::
  FILE ${ILANG_CMAKE_PROJECT_TARGETS_FILE}
)

if(${ILANG_EXPORT_PACKAGE})
  export(PACKAGE ${PROJECT_NAME})
endif()


# ---------------------------------------------------------------------------- #
# UNINSTALL
# uninstall files listed in install_manifest.txt
# ---------------------------------------------------------------------------- #
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake"
    IMMEDIATE @ONLY
  )

  add_custom_target(uninstall
    COMMAND 
      ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake/cmake_uninstall.cmake
  )

endif()


# ---------------------------------------------------------------------------- #
# Unit tests
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_TEST})

  enable_testing()
  add_subdirectory(test)

endif()


# ---------------------------------------------------------------------------- #
# Documents
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_DOCS})
  add_subdirectory(docs)
endif()

