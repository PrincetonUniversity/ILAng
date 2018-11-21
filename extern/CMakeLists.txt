# ---------------------------------------------------------------------------- #
# External dependencies
#   z3
#   Boost
#   Python
#   glog
#   json
#   verilog-parser
#   googletest
#   gflag (optional)
#   doxygen (optional)
# ---------------------------------------------------------------------------- #
##
## z3
##
find_package(Z3 REQUIRED)

if(Z3_FOUND)
  message(STATUS "Z3 version: ${Z3_VERSION}")
else()
  message(FATAL_ERROR "Z3 package not found.")
endif()

##
## Boost
##
if(ILANG_BUILD_PYAPI)
  set(Boost_USE_STATIC_LIBS OFF)
  set(Boost_USE_MULTITHREADED ON)
  set(Boost_USE_STATIC_RUNTIME OFF)

  find_package(Boost 1.50 REQUIRED COMPONENTS python)
  
  if(Boost_FOUND)
    message(STATUS "Boost version: ${Boost_VERSION}")
  else()
    message(FATAL_ERROR "Boost::python not found.")
  endif()

  # For Boost version newer than CMake version
  if(NOT TARGET Boost::python)
    add_library(Boost::python IMPORTED INTERFACE)

    set_property(TARGET Boost::python PROPERTY
      INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR})

    set_property(TARGET Boost::python PROPERTY 
      INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES})

  endif() 

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
find_package(glog 0.3.5)

if(GLOG_FOUND)
  message(STATUS "glog version: ${GLOG_VERSION}")

else()
  message(STATUS "glog was not installed; use embedded build.")

  if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/glog/CMakeLists.txt")
    message(FATAL_ERROR "glog submodule was not downloaded.")
  else()
    add_subdirectory(glog)

  endif() # submodule exist

endif() # GLOG_FOUND

##
## json
##
if(ILANG_BUILD_JSON)
  #find_package(nlohmann_json 3.2.0)

  if (NLOHMANN_JSON_FOUND)
    message(STATUS "nlohmann_json version: ${NLOHMANN_JSON_VERSION}")

  else()
    message(STATUS "nlohmann_json not installed; use embedded build.")

    if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/json/CMakeLists.txt")
      message(FATAL_ERROR "nlohmann_json submodule was not downloaded.")
    else()
      set(JSON_BuildTests OFF CACHE INTERNAL "")
      add_subdirectory(json)
    endif() # submodule exist

  endif() # NLOHMANN_JSON_FOUND

endif() # ILANG_BUILD_JSON

##
## verilog-parser
##
if(ILANG_BUILD_VLOG)
  find_package(vlog_parser)

  if(VLOG_PARSER_FOUND)
    message(STATUS "verilog_parser version: ${VLOG_PARSER_VERSION}")

  else()
    message(STATUS "verilog_parser not installed; use embedded build")

    if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/verilog-parser/CMakeLists.txt")
      message(FATAL_ERROR "verilog_parser submodule was not downloaded.")
    else()
      add_subdirectory(verilog-parser)
    endif() # submodule exist

    # TODO check that a TARGET has been found

  endif() # VLOG_PARSER_FOUND

endif() # ILANG_BUILD_VLOG

##
## googletest
##
if(ILANG_BUILD_TEST AND (PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME))

  #enable_testing()

  #add_subdirectory(googletest googletest)

  #mark_as_advanced(
  #BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
  #gmock_build_tests gtest_build_samples gtest_build_tests
  #gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
  #)

endif() # ILANG_BUILD_TEST & current project


