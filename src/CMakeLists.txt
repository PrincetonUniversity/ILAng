# ---------------------------------------------------------------------------- #
# TARGET
# object library
# ---------------------------------------------------------------------------- #
##
## util
##
set(ILANG_LIB_OBJ_UTIL util)
add_subdirectory(util)

##
## ila
##
set(ILANG_LIB_OBJ_ILA ila)
add_subdirectory(ila)

##
## verif
##
set(ILANG_LIB_OBJ_VERIF verif)
add_subdirectory(backend)

##
## vlog-out
##
set(ILANG_LIB_OBJ_VLOG_OUT vlog_out)
add_subdirectory(verilog-out)

##
## vlog-in
##
if(ILANG_BUILD_VLOG)
  set(ILANG_LIB_OBJ_VLOG_IN vlog_in)
  add_subdirectory(verilog-in)
endif()

##
## json
##
if(ILANG_BUILD_JSON)
  set(ILANG_LIB_OBJ_JSON_IO json_io)
  add_subdirectory(json-inout)
endif()


# ---------------------------------------------------------------------------- #
# TARGET
# archive library 
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_NAME} cpp_api.cc)
target_compile_features(${ILANG_LIB_NAME} PUBLIC cxx_std_11)

##
## include paths
##
target_include_directories(${ILANG_LIB_NAME} 
  PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
  #PRIVATE
)


##
## object dependencies
##
target_link_libraries(${ILANG_LIB_NAME} PUBLIC ${ILANG_LIB_OBJ_UTIL})
target_link_libraries(${ILANG_LIB_NAME} PUBLIC ${ILANG_LIB_OBJ_ILA})
target_link_libraries(${ILANG_LIB_NAME} PUBLIC ${ILANG_LIB_OBJ_VERIF})
target_link_libraries(${ILANG_LIB_NAME} PUBLIC ${ILANG_LIB_OBJ_VLOG_OUT})

if(ILANG_BUILD_VLOG)
  target_link_libraries(${ILANG_LIB_NAME} PUBLIC ${ILANG_LIB_OBJ_VLOG_IN})
endif()

if(ILANG_BUILD_JSON)
  target_link_libraries(${ILANG_LIB_NAME} PUBLIC ${ILANG_LIB_OBJ_JSON_IO})
endif()

##
## external dependencies
##
target_link_libraries(${ILANG_LIB_NAME} PUBLIC  ${Z3_LIBRARY}) # FIXME use z3::z3 interface
target_link_libraries(${ILANG_LIB_NAME} PUBLIC  glog::glog)
#target_link_libraries(${ILANG_LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${ILANG_LIB_NAME} PRIVATE verilogparser)

