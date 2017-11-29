# Specify the minimum version for CMAKE
cmake_minimum_required (VERSION 2.6)

# Project name
project (ila_infra)

# compile type
set (CMAKE_BUILD_TYPE Debug)
add_definitions ("-std=c++11 -fPIC")

if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR ) 
  message (FATAL_ERROR "In-source builds are not allowed.")
endif ()

# add path for custom modules
set (CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
  )

# prefer linking with shared libraries
set (CMAKE_FIND_LIBRARY_SUFFIXES ".so" ${CMAKE_FIND_LIBRARY_SUFFIXES})
# prefer generating shared libraries
set (BUILD_SHARED_LIBS ON)

# find z3 library
find_package (Z3 REQUIRED)
if (Z3_FOUND)
  include_directories (${Z3_INCLUDE_DIR})
else ()
  set (Z3_LIBRARY "")
endif ()

option (BUILD_PYTHON_API "Use Boost to build Python API" OFF)

if (BUILD_PYTHON_API)
  add_definitions ("-DBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT")
  add_definitions ("-DBOOST_NO_CXX11_NUMERIC_LIMITS=1")
  add_definitions ("-DDISABLE_ICE_DEPRECATION_WARNINGS")

  set (CUSTOM_BOOST_ROOT "" CACHE PATH "Path to custom boost installation.")
  if (CUSTOM_BOOST_ROOT)
    set (BOOST_ROOT ${CUSTOM_BOOST_ROOT})
    set (Boost_NO_SYSTEM_PATHS "ON")
  endif ()

  set (Boost_USE_STATIC_LIBS OFF)
  find_package (Boost 1.57.0 REQUIRED python)
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

endif (BUILD_PYTHON_API)

# set path for compiled executable and libraries 
set (EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set (LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")

# include the header files
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include")

# build each source
add_subdirectory (src)

