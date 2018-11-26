cmake_minimum_required(VERSION 3.8)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
  cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
else()
  cmake_policy(VERSION 3.12)
endif()


# ---------------------------------------------------------------------------- #
# PROJECT
# name version language
# ---------------------------------------------------------------------------- #
project(ilang VERSION     1.0 
              LANGUAGES   CXX
              #DESCRIPTION "ILAng platform for SoC Modeling and Verification"
)


# ---------------------------------------------------------------------------- #
# OPTION
# build configuration
# ---------------------------------------------------------------------------- #
option(ILANG_EMBED_DEPS  "Embed dependent libs if packages not found."       ON)
option(ILANG_BUILD_VLOG  "Build Verilog I/O."                                ON)
option(ILANG_BUILD_JSON  "Build JSON I/O."                                   ON)
option(ILANG_BUILD_PYAPI "Build the Python interface."                       ON)
option(ILANG_BUILD_DOCS  "Build documents."                                 OFF)

include(CMakeDependentOption)

cmake_dependent_option(ILANG_FETCH_DEPS "Fetch dependecies at config time"   ON
  "ILANG_EMBED_DEPS" OFF)

cmake_dependent_option(ILANG_BUILD_TEST "Build unit tests."                  ON
  "PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME" OFF)

cmake_dependent_option(ILANG_BUILD_COV  "Build with coverage flags."         OFF
  "CMAKE_BUILD_TYPE MATCHES Debug AND ILANG_BUILD_TEST" OFF)

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

if(${ILANG_BUILD_PYAPI})
  set(PYTHON_API_ENABLE TRUE)
endif()

if(${ILANG_BUILD_VLOG})
  set(VERILOG_IN_ENABLE TRUE)
endif()

if(${ILANG_BUILD_JSON})
  set(JSON_INOUT_ENABLE TRUE)
endif()


# ---------------------------------------------------------------------------- #
# External dependencies
# ---------------------------------------------------------------------------- #
##
## Update git submodules.
##
if(ILANG_FETCH_DEPS)

  find_package(Git QUIET)

  if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")

    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)

    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
    endif()

  endif()

endif()

##
## Make sure that custom modules can be found.
##
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

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
# Python API 
# ---------------------------------------------------------------------------- #
if(ILANG_BUILD_PYAPI)
  set(ILANG_PYAPI_NAME "${ILANG_TARGET_NAME}py")
  #add_subdirectory(src/python-api)
endif()


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
  COMPATIBILITY SameMajorVersion # AnyNewVersion
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

export(PACKAGE ${PROJECT_NAME})


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
  find_package(Doxygen QUIET)

  if(DOXYGEN_FOUND)
    configure_file(
      ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in
      ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
      @ONLY
    )

    add_custom_target(doc
      COMMAND 
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile &> doxygen.log
      WORKING_DIRECTORY 
        ${CMAKE_CURRENT_BIN_DIR}
      VERBATIM
    )

  endif() # DOXYGEN_FOUND

endif() # ${ILANG_BUILD_DOCS}

