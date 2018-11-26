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
add_subdirectory(backend)
add_subdirectory(verilog-out)

if(${ILANG_BUILD_VLOG})
  add_subdirectory(verilog-in)
endif()

if(${ILANG_BUILD_JSON})
  add_subdirectory(json-inout)
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

##
## external dependencies
##
find_package(Z3 REQUIRED) # need to call here to see the imported target
target_link_libraries(${ILANG_LIB_NAME} PUBLIC z3::z3)

target_link_libraries(${ILANG_LIB_NAME} PUBLIC glog::glog)

if(${ILANG_BUILD_VLOG})
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE verilogparser::verilogparser)
endif()

if(${ILANG_BUILD_JSON})
  find_package(nlohmann_json QUIET)
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)
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
  DIRECTORY ${ILANG_INCLUDE_BUILD_DIR}/ilang
  DESTINATION ${ILANG_INCLUDE_INSTALL_DIR}
)

