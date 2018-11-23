# ---------------------------------------------------------------------------- #
# TARGET
# object library
# ---------------------------------------------------------------------------- #
set(ILANG_LIB_OBJS "")

##
## util
##
set(ILANG_LIB_OBJ_UTIL util)
add_subdirectory(util)
set(ILANG_LIB_OBJS ${ILANG_LIB_OBJS} $<TARGET_OBJECTS:${ILANG_LIB_OBJ_UTIL}>)

##
## ila
##
set(ILANG_LIB_OBJ_ILA ila)
add_subdirectory(ila)
set(ILANG_LIB_OBJS ${ILANG_LIB_OBJS} $<TARGET_OBJECTS:${ILANG_LIB_OBJ_ILA}>)

##
## verif
##
set(ILANG_LIB_OBJ_VERIF verif)
add_subdirectory(backend)
set(ILANG_LIB_OBJS ${ILANG_LIB_OBJS} $<TARGET_OBJECTS:${ILANG_LIB_OBJ_VERIF}>)

##
## vlog-out
##
set(ILANG_LIB_OBJ_VLOG_OUT vlog_out)
add_subdirectory(verilog-out)
set(ILANG_LIB_OBJS ${ILANG_LIB_OBJS} $<TARGET_OBJECTS:${ILANG_LIB_OBJ_VLOG_OUT}>)

##
## vlog-in
##
if(ILANG_BUILD_VLOG)
  set(ILANG_LIB_OBJ_VLOG_IN vlog_in)
  add_subdirectory(verilog-in)
  set(ILANG_LIB_OBJS ${ILANG_LIB_OBJS} $<TARGET_OBJECTS:${ILANG_LIB_OBJ_VLOG_IN}>)
endif()

##
## json
##
if(ILANG_BUILD_JSON)
  set(ILANG_LIB_OBJ_JSON_IO json_io)
  add_subdirectory(json-inout)
  set(ILANG_LIB_OBJS ${ILANG_LIB_OBJS} $<TARGET_OBJECTS:${ILANG_LIB_OBJ_JSON_IO}>)
endif()


# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_NAME} cpp_api.cc ${ILANG_LIB_OBJS})
add_library(${PROJECT_NAME}::${ILANG_LIB_NAME} ALIAS ${ILANG_LIB_NAME})

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

if(ILANG_BUILD_VLOG)
  target_link_libraries(${ILANG_LIB_NAME} PRIVATE verilogparser::verilogparser)
endif()

if(ILANG_BUILD_JSON)
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

