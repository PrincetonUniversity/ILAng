# ---------------------------------------------------------------------------- #
# TARGET
# object library ${ILANG_LIB_OBJ_JSON_IO}
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_OBJ_JSON_IO} OBJECT
  json_parse.cc
)

target_compile_features(${ILANG_LIB_OBJ_JSON_IO} PUBLIC cxx_std_11)

target_include_directories(${ILANG_LIB_OBJ_JSON_IO} 
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${ILANG_LIB_OBJ_JSON_IO}
  PUBLIC glog::glog
  PRIVATE nlohmann_json::nlohmann_json
  PRIVATE $<TARGET_OBJECTS:${ILANG_LIB_OBJ_UTIL}>
  PRIVATE $<TARGET_OBJECTS:${ILANG_LIB_OBJ_ILA}>
)

