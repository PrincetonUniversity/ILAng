# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_NAME} ilang++.cc)
add_library(${PROJECT_NAME}::${ILANG_LIB_NAME} ALIAS ${ILANG_LIB_NAME})

##
## source files
##
add_subdirectory(ila)
add_subdirectory(mcm)
add_subdirectory(target-json)
add_subdirectory(target-sc)
add_subdirectory(util)
add_subdirectory(verification)
add_subdirectory(verilog-in)
add_subdirectory(verilog-out)
add_subdirectory(vtarget-out)
add_subdirectory(smt-inout)

if(${ILANG_BUILD_SYNTH})
  add_subdirectory(target-itsy)
endif()

##
## compile features/options
##
target_compile_features(${ILANG_LIB_NAME} PUBLIC cxx_std_11)

set_property(
  TARGET ${ILANG_LIB_NAME}
  PROPERTY POSITION_INDEPENDENT_CODE ON
)

if(${CMAKE_COMPILER_IS_GNUCXX})

  ## if(${CMAKE_PROJECT_NAME} MATCHES ${PROJECT_NAME})
  ##   if(${CMAKE_BUILD_TYPE} MATCHES Debug)
  ##     target_compile_options(${ILANG_LIB_NAME} PRIVATE "-Wall")
  ##   endif()
  ## endif()

  if(${ILANG_BUILD_COV})
    target_compile_options(${ILANG_LIB_NAME} PUBLIC "-fprofile-arcs")
    target_compile_options(${ILANG_LIB_NAME} PUBLIC "-ftest-coverage")
  endif()

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
## gcov 
##
if(${ILANG_BUILD_COV})
  if(${CMAKE_COMPILER_IS_GNUCXX})
    target_link_libraries(${ILANG_LIB_NAME} PUBLIC gcov)
  endif()
endif()

##
## z3
##
if(NOT TARGET z3::z3)
  find_package(Z3 REQUIRED)
endif()

target_link_libraries(${ILANG_LIB_NAME} PUBLIC z3::z3)

if(${Z3_VERSION} VERSION_LESS 4.6.0)
  set(Z3_LEGACY_API TRUE)
else()
  set(Z3_LEGACY_API FALSE)
endif()

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
if(NOT TARGET nlohmann_json::nlohmann_json)
  find_package(nlohmann_json REQUIRED)
endif()

if (${ILANG_BUILD_TEST} OR ${ILANG_INSTALL_DEV}) 
  target_link_libraries(${ILANG_LIB_NAME} PUBLIC nlohmann_json::nlohmann_json)
else()
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)
endif()

##
## verilog parser
##
if(NOT TARGET verilogparser::verilogparser)
  find_package(verilogparser REQUIRED)
endif()

if (${ILANG_BUILD_TEST} OR ${ILANG_INSTALL_DEV}) 
  target_link_libraries(${ILANG_LIB_NAME} PUBLIC verilogparser::verilogparser)
else()
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE verilogparser::verilogparser)
endif()

##
## vcd parser
##
if(NOT TARGET vcdparser::vcdparser)
  find_package(vcdparser REQUIRED)
endif()

if (${ILANG_BUILD_TEST} OR ${ILANG_INSTALL_DEV}) 
  target_link_libraries(${ILANG_LIB_NAME} PUBLIC vcdparser::vcdparser)
else()
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE vcdparser::vcdparser)
endif()

##
## smt parser
##
if(NOT TARGET smtparser::smtparser)
  find_package(smtparser REQUIRED)
endif()

if (${ILANG_BUILD_TEST} OR ${ILANG_INSTALL_DEV}) 
  target_link_libraries(${ILANG_LIB_NAME} PUBLIC smtparser::smtparser)
else()
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE smtparser::smtparser)
endif()

##
## template-based synthesis
##
if(${ILANG_BUILD_SYNTH})

  if(NOT TARGET ilasynth::ilasynth)
    find_package(ilasynth REQUIRED)
  endif()

  target_link_libraries(${ILANG_LIB_NAME} PRIVATE ilasynth::ilasynth) 

endif()

if(${ILANG_BUILD_SYNTH})
  set(SYNTH_INTERFACE TRUE)
else()
  set(SYNTH_INTERFACE FALSE)
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

if(${ILANG_INSTALL_DEV})

  install(
    DIRECTORY ${ILANG_INCLUDE_BUILD_DIR}/ilang
    DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}
  )

else()

  install(
    FILES ${ILANG_INCLUDE_BUILD_DIR}/ilang/ilang++.h
    DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}/ilang
  )

  install(
    FILES ${ILANG_INCLUDE_BUILD_DIR}/ilang/util/log.h
    DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}/ilang/util
  )

endif()

