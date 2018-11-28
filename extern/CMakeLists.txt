# ---------------------------------------------------------------------------- #
# External dependencies
#   Boost
#   Python
#   glog
#   json
#   verilog parser
#
#   gflag (TODO)
#   doxygen (TODO)
# ---------------------------------------------------------------------------- #
##
## Boost
##
if(${ILANG_BUILD_PYAPI})
  set(Boost_USE_STATIC_LIBS OFF)
  set(Boost_USE_MULTITHREADED ON)
  set(Boost_USE_STATIC_RUNTIME OFF)

  find_package(Boost 1.50 REQUIRED COMPONENTS python)
  
  # For Boost version newer than CMake version
  if(NOT TARGET Boost::python)
    add_library(Boost::python IMPORTED INTERFACE)

    set_property(TARGET Boost::python PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

    set_property(TARGET Boost::python PROPERTY 
      INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})

  endif() # Boost::python FOUND

endif() # ILANG_BUILD_PYAPI

##
## python
##
if(${ILANG_BUILD_PYAPI})
  find_package(PythonLibs 2.7 REQUIRED)

  if(PYTHONLIBS_FOUND)
    message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
    message(STATUS "PYTHON_EXECUTABLE = ${PYTHON_EXECUTABLE}")
    message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")

  else()
    message(FATAL_ERROR "Python libs not found.")

  endif() # PYTHONLIBS_FOUND

endif() # ILANG_BUILD_PYAPI

##
## glog
##

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/glog/CMakeLists.txt")
  message(FATAL_ERROR "glog submodule was not downloaded.")
endif() # submodule exist

##
## json
##
if(${ILANG_BUILD_JSON})

  if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/json/CMakeLists.txt")
    message(FATAL_ERROR "nlohmann_json submodule was not downloaded.")
  endif() # submodule exist

endif() # ILANG_BUILD_JSON

# ---------------------------------------------------------------------------- #
##
## verilog-parser
##
if(${ILANG_BUILD_VLOG})

  # look for system installation
  find_package(verilogparser QUIET)
  
  # embedd to build tree if not installed
  if(NOT VERILOGPARSER_FOUND)

    # fetch from git
    execute_process(
      COMMAND ${GIT_EXECUTABLE} submodule update --init vlog-parser
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE GIT_SUBMOD_RESULT
    )

    # check fetch success
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
    else()
      message(STATUS "Update submodule to ${CMAKE_CURRENT_SOURCE}.")
    endif()

    # embedded build
    add_subdirectory(vlog-parser)

  endif() # VERILOGPARSER_FOUND

endif() # ILANG_BUILD_VLOG

