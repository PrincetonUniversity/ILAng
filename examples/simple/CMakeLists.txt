cmake_minimum_required(VERSION 3.8)

# ---------------------------------------------------------------------------- #
# PROJECT
# name version language
# ---------------------------------------------------------------------------- #
project(simple VERSION 1.0 LANGUAGES CXX)

# ---------------------------------------------------------------------------- #
# OPTION
# build configuration
# ---------------------------------------------------------------------------- #
option(MYPROJ_BUILD_TEST "Build unit tests if enabled."                      ON)

include(CMakeDependentOption)
cmake_dependent_option(MYPROJ_BUILD_COV 
  "Build with coverage if enabled."                                          ON
  "MYPROJ_BUILD_TEST AND CMAKE_BUILD_TYPE MATCHES Debug"                    OFF)

# ---------------------------------------------------------------------------- #
# VARIABLE
# alias and configurations
# ---------------------------------------------------------------------------- #
set(MyTarget ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# ---------------------------------------------------------------------------- #
# External dependencies
# ---------------------------------------------------------------------------- #
find_package(ilang)

##
## Python support for CMake version < 3.12
##
if(${CMAKE_VERSION} VERSION_LESS 3.12)
  find_package(PythonLibs 2.7 REQUIRED)

  if(NOT TARGET Python::Python)
    add_library(Python::Python IMPORTED INTERFACE)

    set_property(TARGET Python::Python 
      PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PYTHON_INCLUDE_DIRECTORIES}
    )

    set_property(TARGET Python::Python
      PROPERTY INTERFACE_LINK_LIBRARIES ${PYTHON_LIBRARIES}
    )
    
  endif()

endif()

# ---------------------------------------------------------------------------- #
# TARGET
# executable
# ---------------------------------------------------------------------------- #
add_executable(${MyTarget} 
  app/main.cc
  src/lib.cc
)

target_include_directories(${MyTarget} PRIVATE include)

target_link_libraries(${MyTarget} ilang::ilang)

