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
# INCLUDE
# cmake helper modules 
# ---------------------------------------------------------------------------- #
include(CMakeDependentOption)


# ---------------------------------------------------------------------------- #
# OPTION
# build configuration
# ---------------------------------------------------------------------------- #
option(ILANG_EMBED_DEPS  "Embed dependent libs if packages not found."       ON)
option(ILANG_BUILD_VLOG  "Build Verilog I/O."                                ON)
option(ILANG_BUILD_JSON  "Build JSON I/O."                                   ON)
option(ILANG_BUILD_PYAPI "Build the Python interface."                       ON)

cmake_dependent_option(ILANG_FETCH_DEPS "Fetch dependecies at config time"   ON
  "ILANG_EMBED_DEPS" OFF)

cmake_dependent_option(ILANG_BUILD_TEST "Build unit tests."                  ON
  "PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME" OFF)

cmake_dependent_option(ILANG_BUILD_COV  "Build with coverage flags."         OFF
  "CMAKE_BUILD_TYPE MATCHES Debug AND ILANG_BUILD_TEST" OFF)


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
set(ILANG_LIB_NAME "${PROJECT_NAME}++")

if(${ILANG_BUILD_COV}) # FIXME only set compile features for required targets
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

add_subdirectory(src)

add_library(${PROJECT_NAME}::${ILANG_LIB_NAME} ALIAS ${ILANG_LIB_NAME})

# ---------------------------------------------------------------------------- #
# TARGET
# Python API 
# ---------------------------------------------------------------------------- #
if(ILANG_BUILD_PYAPI)
  set(ILANG_PYAPI_NAME "${PROJECT_NAME}py")
  #add_subdirectory(src/python)
  #add_subdirectory(src/python-api)
endif()

# ---------------------------------------------------------------------------- #
# TARGET
# interface target
# ---------------------------------------------------------------------------- #
#add_library(${ILANG_TARGET_NAME} INTERFACE)
#add_library(${PROJECT_NAME}::${ILANG_TARGET_NAME} ALIAS ${ILANG_TARGET_NAME})

# ---------------------------------------------------------------------------- #
# TARGET
# Making the executable
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
# Unit tests
# ---------------------------------------------------------------------------- #
if(ILANG_BUILD_TEST)
  enable_testing()
  add_subdirectory(test)
endif()

