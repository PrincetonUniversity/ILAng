# ---------------------------------------------------------------------------- #
# Google Log
#
#   TARGET glog::glog
#   SOURCE https://github.com/google/glog.git
#   PATH   extern/glog
# ---------------------------------------------------------------------------- #
# find installed package 
find_package(glog 0.4.0 QUIET)

# build from embeded subtree (in-source) 
if(NOT GLOG_FOUND)

  set(WITH_GFLAGS OFF CACHE INTERNAL "")
  add_subdirectory(glog)

endif() # GLOG_FOUND


# ---------------------------------------------------------------------------- #
# JSON Library
# 
#   TARGET nlohmann_json::nlohmann_json
#   SOURCE https://github.com/nlohmann/json.git
#   PATH   extern/json
# ---------------------------------------------------------------------------- #
# find installed package
find_package(nlohmann_json 3.6.1 QUIET)

# build from embeded subtree (in-source)
if(NOT NLOHMANN_JSON_FOUND)

  set(JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory(json)

endif() # NLOHMANN_JSON_FOUND


# ---------------------------------------------------------------------------- #
# fmt Library
# 
#   TARGET fmt::fmt
#   SOURCE https://github.com/fmtlib/fmt
#   PATH   extern/fmt
# ---------------------------------------------------------------------------- #
# find installed package
find_package(fmt 6.1.2 QUIET)

# build from embeded subtree (in-source)
if(NOT FMT_FOUND)

  set(FMT_INSTALL ON CACHE INTERNAL "")
  add_subdirectory(fmt)

endif() # FMT_FOUND


# ---------------------------------------------------------------------------- #
# VCD Parser
# 
#   TARGET vcdparser::vcdparser
#   SOURCE https://github.com/zhanghongce/verilog-vcd-parser.git
#   PATH   extern/vcd-parser
# ---------------------------------------------------------------------------- #
# find installed package
find_package(vcdparser 1.0 QUIET)

# build from embeded subtree (in-source)
if(NOT VCDPARSER_FOUND)

  set(JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory(vcd-parser)

endif() # VCDPARSER_FOUND


# ---------------------------------------------------------------------------- #
# SMT Parser
# 
#   TARGET smtparser::smtparser
#   SOURCE https://github.com/zhanghongce/smtlib2parser.git
#   PATH   extern/smt-parser
# ---------------------------------------------------------------------------- #
# find installed package
find_package(smtparser 1.0 QUIET)

# build from embeded subtree (in-source)
if(NOT SMTPARSER_FOUND)

  set(JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory(smt-parser)

endif() # SMTPARSER_FOUND

# ---------------------------------------------------------------------------- #
# Verilog Parser
# 
#   TARGET verilogparser::verilogparser
#   SOURCE https://github.com/Bo-Yuan-Huang/verilog-parser.git
#   PATH   extern/vlog-parser
# ---------------------------------------------------------------------------- #
# find installed package
find_package(verilogparser 1.1.0 QUIET)

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


# ---------------------------------------------------------------------------- #
# Template-based ILA Synthesis
#
#   TARGET  ilasynth::ilasynth
#   SOURCE  https://github.com/PrincetonUniversity/ILA-Synthesis-Python.git
#   PATH    extern/tmpl-synth
# ---------------------------------------------------------------------------- #
if(${ILANG_BUILD_SYNTH})

  # find installed package
  find_package(ilasynth 1.0 QUIET)

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
    if(${APPLE})
      set(BUILD_SHARED_LIBS FALSE CACHE BOOL "Disable shared libs in OSX" FORCE)
    endif()
    add_subdirectory(tmpl-synth)

  endif() # ILASYNTH_FOUND

endif() # ILANG_BUILD_SYNTH

