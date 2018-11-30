# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_NAME} cpp_api.cc)
add_library(${PROJECT_NAME}::${ILANG_LIB_NAME} ALIAS ${ILANG_LIB_NAME})

##
## source files
##
add_subdirectory(util)
add_subdirectory(ila)
add_subdirectory(verification)
add_subdirectory(verilog-out)

if(${ILANG_BUILD_VLOG})
  add_subdirectory(verilog-in)
endif()

if(${ILANG_BUILD_JSON})
  add_subdirectory(json-inout)
endif()

if(${ILANG_BUILD_SYNTH})
  add_subdirectory(synth-interface)
endif()

##
## compile features/options
##
target_compile_features(${ILANG_LIB_NAME} PUBLIC cxx_std_11)

if(${ILANG_BUILD_COV})
  target_compile_options(${ILANG_LIB_NAME} PRIVATE -fprofile-arcs)
  target_compile_options(${ILANG_LIB_NAME} PRIVATE -ftest-coverage)
endif()

##
## include paths
##
target_include_directories(${ILANG_LIB_NAME} 
  PUBLIC 
    $<INSTALL_INTERFACE:${ILANG_INCLUDE_INSTALL_DIR}>
    $<BUILD_INTERFACE:${ILANG_INCLUDE_BUILD_DIR}>
)

# ---------------------------------------------------------------------------- #
# LINK LIBRARIES
# external dependencies
# ---------------------------------------------------------------------------- #
##
## z3
##
if(NOT TARGET z3::z3)
  find_package(Z3 REQUIRED)
endif()

target_link_libraries(${ILANG_LIB_NAME} PUBLIC z3::z3)

##
## glog
##
if(NOT TARGET glog::glog)
  find_package(glog REQUIRED)
endif()

target_link_libraries(${ILANG_LIB_NAME} PUBLIC glog::glog)

##
## json lib
##
if(${ILANG_BUILD_JSON})

  if(NOT TARGET nlohmann_json::nlohmann_json)
    find_package(nlohmann_json REQUIRED)
  endif()

  target_link_libraries(${ILANG_LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)

endif()

##
## verilog parser
##
if(${ILANG_BUILD_VLOG})

  if(NOT TARGET verilogparser::verilogparser)
    find_package(verilogparser REQUIRED)
  endif()

  target_link_libraries(${ILANG_LIB_NAME} PRIVATE verilogparser::verilogparser)

endif()

##
## template-based synthesis
##
if(${ILANG_BUILD_SYNTH})

  if(NOT TARGET ilasynth::ilasynth)
    find_package(ilasynth)
  endif()

  target_link_libraries(${ILANG_LIB_NAME} PRIVATE ilasynth::ilasynth) 

endif()

##
## Boost 
##
if(${ILANG_BUILD_PYAPI} OR ${ILANG_BUILD_SYNTH})

  set(Boost_USE_STATIC_LIBS OFF)
  set(Boost_USE_MULTITHREADED ON)
  set(Boost_USE_STATIC_RUNTIME OFF)

  find_package(Boost 1.50 REQUIRED COMPONENTS python)
  
  if(NOT TARGET Boost)

    add_library(Boost IMPORTED INTERFACE)

    set_property(TARGET Boost 
      PROPERTY INTERFACE_LINK_LIBRARIES ${Boost_LIBRARIES}
    )

    set_property(TARGET Boost 
      PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
    )

  endif() # target Boost 

  target_link_libraries(${ILANG_LIB_NAME} PRIVATE Boost)

endif()

##
## Python
##
if(${ILANG_BUILD_PYAPI} OR ${ILANG_BUILD_SYNTH})

  find_package(PythonLibs 2.7 REQUIRED)

  if(PYTHONLIBS_FOUND)
    message(STATUS "PYTHON_LIBRARIES = ${PYTHON_LIBRARIES}")
    message(STATUS "PYTHON_INCLUDE_DIRS = ${PYTHON_INCLUDE_DIRS}")
  endif() # PYTHONLIBS_FOUND

  if(NOT TARGET PythonLibs)

    add_library(PythonLibs IMPORTED INTERFACE)

    set_property(TARGET PythonLibs 
      PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${PYTHON_INCLUDE_DIRS}
    )

    set_property(TARGET PythonLibs 
      PROPERTY INTERFACE_LINK_LIBRARIES ${PYTHON_LIBRARIES}
    )

  endif() # target PythonLibs

  target_link_libraries(${ILANG_LIB_NAME} PRIVATE PythonLibs)

endif()


# ---------------------------------------------------------------------------- #
# INSTALL
# install and export lib target
# ---------------------------------------------------------------------------- #
install(
  TARGETS ${ILANG_LIB_NAME}
  EXPORT  ${ILANG_TARGETS_EXPORT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}
)

##
## include directory
##
configure_file(
  ${PROJECT_SOURCE_DIR}/src/config.h.in
  ${PROJECT_SOURCE_DIR}/include/ilang/config.h
  @ONLY
)

install(
  FILES ${ILANG_INCLUDE_BUILD_DIR}/ilang/cpp_api.h
  DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}
  RENAME ila++.h
)

if(${ILANG_INSTALL_DEV})
  install(
    DIRECTORY ${ILANG_INCLUDE_BUILD_DIR}/ilang
    DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}
  )
endif()

