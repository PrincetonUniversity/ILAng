# ---------------------------------------------------------------------------- #
# TARGET
# object library ${ILANG_LIB_OBJ_VLOG_IN}
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_OBJ_VLOG_IN} OBJECT
  verilog_parse.cc
)

target_compile_features(${ILANG_LIB_OBJ_VLOG_IN} PUBLIC cxx_std_11)

target_include_directories(${ILANG_LIB_OBJ_VLOG_IN}
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

