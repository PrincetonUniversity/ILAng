cmake_minimum_required(VERSION 3.8)

# ---------------------------------------------------------------------------- #
# PROJECT
# name version language
# ---------------------------------------------------------------------------- #
project(pdp_high VERSION 1.0 LANGUAGES CXX)

# ---------------------------------------------------------------------------- #
# VARIABLE
# alias and configurations
# ---------------------------------------------------------------------------- #
set(PDP_HIGH_TARGET ${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# ---------------------------------------------------------------------------- #
# External dependencies
# ---------------------------------------------------------------------------- #
##
## ilang
##
find_package(ilang REQUIRED)

##
## Python (required if CMake version < 3.12)
##
if(${CMAKE_VERSION} VERSION_LESS 3.12)

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
add_executable(${PDP_HIGH_TARGET} 
  app/main.cc
  src/pdp.cc
)

target_include_directories(${PDP_HIGH_TARGET} PRIVATE include)

target_link_libraries(${PDP_HIGH_TARGET} ilang::ilang)

