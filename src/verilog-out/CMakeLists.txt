# ---------------------------------------------------------------------------- #
# TARGET
# object library ${ILANG_LIB_OBJ_VLOG_OUT}
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_OBJ_VLOG_OUT} OBJECT
  verilog_gen.cc
)

target_compile_features(${ILANG_LIB_OBJ_VLOG_OUT} PUBLIC cxx_std_11)

target_include_directories(${ILANG_LIB_OBJ_VLOG_OUT} 
  PRIVATE ${PROJECT_SOURCE_DIR}/include
)

