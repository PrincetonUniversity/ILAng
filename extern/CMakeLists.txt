# ---------------------------------------------------------------------------- #
# External dependencies
#   z3
#   Boost
#   Python
#   glog
#   json
#   verilog-parser
#
#   googletest (in test)
#   gflag (optional)
#   doxygen (optional)
# ---------------------------------------------------------------------------- #
##
## z3
##
find_package(Z3 REQUIRED)

##
## Boost
##
if(ILANG_BUILD_PYAPI)
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
if(ILANG_BUILD_PYAPI)
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

else()
  add_subdirectory(glog)

endif() 

##
## json
##
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/json/CMakeLists.txt")
  message(FATAL_ERROR "nlohmann_json submodule was not downloaded.")

else()
  set(JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory(json)

endif() 

##
## verilog-parser
##
if(ILANG_BUILD_VLOG)

  if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/verilog-parser/CMakeLists.txt")
    message(FATAL_ERROR "verilog-parser submodule was not downloaded.")

  else()
    add_subdirectory(verilog-parser)

  endif() # submodule exist

endif() # ILANG_BUILD_VLOG

