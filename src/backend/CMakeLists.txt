# ---------------------------------------------------------------------------- #
# TARGET
# object library ${ILANG_LIB_OBJ_VERIF}
# ---------------------------------------------------------------------------- #
add_library(${ILANG_LIB_OBJ_VERIF} OBJECT 
  abs_knob.cc
  eq_check_crr.cc
  legacy_bmc.cc
  rewrite_expr.cc
  rewrite_ila.cc
  unroller.cc
)

target_compile_features(${ILANG_LIB_OBJ_VERIF} PUBLIC cxx_std_11)

target_include_directories(${ILANG_LIB_OBJ_VERIF} 
  PRIVATE ${PROJECT_SOURCE_DIR}/include
) 

target_link_libraries(${ILANG_LIB_OBJ_VERIF}
  PUBLIC z3::z3
  PRIVATE $<TARGET_OBJECTS:${ILANG_LIB_OBJ_UTIL}>
  PRIVATE $<TARGET_OBJECTS:${ILANG_LIB_OBJ_ILA}>
)

