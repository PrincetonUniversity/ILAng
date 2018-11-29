# ---------------------------------------------------------------------------- #
# z3
#
#   TARGET z3::z3
#   SOURCE https://github.com/Z3Prover/z3.git
#   PATH   N/A
# ---------------------------------------------------------------------------- #
find_package(Z3 4.5.0 REQUIRED)


# ---------------------------------------------------------------------------- #
# Google Log
#
#   TARGET glog::glog
#   SOURCE https://github.com/google/glog.git
#   PATH   extern/glog
# ---------------------------------------------------------------------------- #
# find installed package 
find_package(glog QUIET)

# embed to build tree if not installed
if(NOT GLOG_FOUND)

  # fetch from git
  if(${ILANG_FETCH_DEPS})

    execute_process(
      COMMAND ${GIT_EXECUTABLE} submodule update --init glog
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE GIT_SUBMOD_RESULT
    )

    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
    endif()

  endif() # ILANG_FETCH_DEPS

  # embedded build
  add_subdirectory(glog)

endif() # GLOG_FOUND


# ---------------------------------------------------------------------------- #
# JSON Library
# 
#   TARGET nlohmann_json::nlohmann_json
#   SOURCE https://github.com/nlohmann/json.git
#   PATH   extern/json-lib
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_JSON})

  # find installed package
  find_package(nlohmann_json QUIET)

  # embed to build tree if not installed
  if(NOT NLOHMANN_JSON_FOUND)

    # fetch from git
    if(${ILANG_FETCH_DEPS})

      execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init json-lib
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMOD_RESULT
      )

      if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
      endif()

    endif() # ILANG_FETCH_DEPS

    # embedded build
    set(JSON_BuildTests OFF CACHE INTERNAL "")
    add_subdirectory(json-lib)

  endif() # NLOHMANN_JSON_FOUND

endif() # ILANG_BUILD_JSON


# ---------------------------------------------------------------------------- #
# Verilog Parser
# 
#   TARGET verilogparser::verilogparser
#   SOURCE https://github.com/Bo-Yuan-Huang/verilog-parser.git
#   PATH   extern/vlog-parser
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_VLOG})

  # find installed package
  find_package(verilogparser QUIET)
  
  # embed to build tree if not installed
  if(NOT VERILOGPARSER_FOUND)

    # fetch from git
    if(${ILANG_FETCH_DEPS})

      execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init vlog-parser
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMOD_RESULT
      )

      if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
      endif()

    endif() # ILANG_FETCH_DEPS

    # embedded build
    add_subdirectory(vlog-parser)

  endif() # VERILOGPARSER_FOUND

endif() # ILANG_BUILD_VLOG


# ---------------------------------------------------------------------------- #
# Boost
#
#   TARGET 
#   SOURCE
#   PATH
# ---------------------------------------------------------------------------- #
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


# ---------------------------------------------------------------------------- #
# Python
#
#   TARGET 
#   SOURCE
#   PATH
# ---------------------------------------------------------------------------- #
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


# ---------------------------------------------------------------------------- #
# Template-based ILA Synthesis
#
#   TARGET  ilasynth::ilasynth
#   SOURCE  https://github.com/PrincetonUniversity/ILA-Synthesis-Python.git
#   PATH    extern/tmpl-synth
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_SYNTH})

  # find installed package
  find_package(ilasynth QUIET)

  # embed to build tree if not installed
  if(NOT ILASYNTH_FOUND)

    # fetch from git
    if(${ILANG_FETCH_DEPS})

      execute_process(
        COMMAND ${GIT_EXECUTABLE} submodule update --init tmpl-synth
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        RESULT_VARIABLE GIT_SUBMOD_RESULT
      )

      if(NOT GIT_SUBMOD_RESULT EQUAL "0")
        message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
      endif()

    endif() # ILANG_FETCH_DEPS

    # embedded build
    add_subdirectory(tmpl-synth)

  endif() # ILASYNTH_FOUND

endif() # ILANG_BUILD_SYNTH


# ---------------------------------------------------------------------------- #
# Google Test
#
#   TARGET  N/A
#   SOURCE  https://github.com/abseil/googletest
#   PATH    extern/googletest
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_TEST)

  if(${ILANG_FETCH_DEPS})

    # fetch from git
    execute_process(
      COMMAND ${GIT_EXECUTABLE} submodule update --init googletest
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      RESULT_VARIABLE GIT_SUBMOD_RESULT
    )

    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "Submodule update failed with ${GIT_SUBMOD_RESULT}")
    endif()

  else() 

    # check has been downloaded
    if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/googletest/CMakeLists.txt")
        message(FATAL_ERROR "googletest submodule was not downloaded.")
    endif() 

  endif() # ILANG_FETCH_DEPS

endif()

