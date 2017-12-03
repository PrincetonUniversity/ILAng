# path = root/ (top level CMakeLists.txt)
cmake_minimum_required(VERSION 2.8)

set(ILA_PROJECT_NAME ILA)

project(${ILA_PROJECT_NAME})
enable_language(C CXX)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

# Add path for custom modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )

# ------------------------------------------------------------------------------
# Compile flags 
# ------------------------------------------------------------------------------
# These options can be turned on/off from the 'make' command.
option(debug "Use debugging flag" ON)
option(coverage "Use coverage flag" OFF)
option(python_api "Build Python API" ON)

# Things to always include as flags. 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Set debug/coverage flags, or optimize, depending on options.
if (debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    # Coverage can only be set if -g is used.
    if (coverage)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    endif()
else ()
    set(CMAKE_CXX_FLAGS "-O3")
endif()

# ------------------------------------------------------------------------------
# Locate files
# ------------------------------------------------------------------------------
include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/external/googletest/googletest
  ${PROJECT_SOURCE_DIR}/external/googletest/googletest/include)

# ------------------------------------------------------------------------------
# Build
# ------------------------------------------------------------------------------
add_subdirectory (src)

# ------------------------------------------------------------------------------
# Test (w/ Google Test & standard CTest)
# ------------------------------------------------------------------------------
add_subdirectory (test)

# ------------------------------------------------------------------------------
# Documentation (w/ Doxygen)
# ------------------------------------------------------------------------------
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc 
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile &> doxygen.log
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
endif(DOXYGEN_FOUND)

# ------------------------------------------------------------------------------
# Google Test
# ------------------------------------------------------------------------------
add_custom_target( git_update
    COMMAND git submodule init
    COMMAND git submodule update
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR} )
add_library( googletest
    ${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest_main.cc )
add_dependencies(googletest git_update)
set_source_files_properties(${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest-all.cc  PROPERTIES GENERATED 1)
set_source_files_properties(${PROJECT_SOURCE_DIR}/external/googletest/googletest/src/gtest_main.cc PROPERTIES GENERATED 1)

# ------------------------------------------------------------------------------
# Misc
# ------------------------------------------------------------------------------
configure_file(
  "${PROJECT_SOURCE_DIR}/include/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h")
include_directories("${PROJECT_BINARY_DIR}")

# ------------------------------------------------------------------------------
# Z3
# ------------------------------------------------------------------------------
find_package (Z3 REQUIRED)
if (Z3_FOUND)
  include_directories (${Z3_INCLUDE_DIR})
else ()
  set (Z3_LIBRARY "")
endif ()

# ------------------------------------------------------------------------------
# Boost/python
# ------------------------------------------------------------------------------
if (python_api)
  add_definitions ("-DBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT")
  add_definitions ("-DBOOST_NO_CXX11_NUMERIC_LIMITS=1")
  add_definitions ("-DDISABLE_ICE_DEPRECATION_WARNINGS")

  set (CUSTOM_BOOST_ROOT "" CACHE PATH "Path to custom boost installation.")
  if (CUSTOM_BOOST_ROOT)
    set (BOOST_ROOT ${CUSTOM_BOOST_ROOT})
    set (Boost_NO_SYSTEM_PATHS "ON")
  endif ()

  set (Boost_USE_STATIC_LIBS OFF)
  find_package (Boost 1.54.0 REQUIRED python)
  IF (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIRS})
  endif ()

  find_package (PythonLibs 2.7 REQUIRED)
  if (PYTHONLIBS_FOUND)
    message (STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
    message (STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
    message (STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")
    include_directories(${PYTHON_INCLUDE_DIRS})
  elseif (NOT PYTHONLIBS_FOUND) 
    MESSAGE (FATAL_ERROR "Unable to find correct Python version.")
  endif()

endif (python_api)

