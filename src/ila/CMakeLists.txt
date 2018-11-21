# ------------------------------------------------------------------------------
# TARGET
# object library ${ILANG_LIB_OBJ_ILA}
# ------------------------------------------------------------------------------
add_library(${ILANG_LIB_OBJ_ILA} OBJECT 
  ast/ast.cc
  ast/expr.cc
  ast/expr_const.cc
  ast/expr_op.cc
  ast/expr_var.cc
  ast/func.cc
  ast/sort.cc
  ast/sort_value.cc
  comp_ref_rel.cc
  expr_fuse.cc
  hash_ast.cc
  instr.cc
  instr_lvl_abs.cc
  object.cc
  symbol.cc
  transition.cc
  z3_expr_adapter.cc
)

target_compile_features(${ILANG_LIB_OBJ_ILA} PUBLIC cxx_std_11)

target_include_directories(${ILANG_LIB_OBJ_ILA} 
  PRIVATE ${PROJECT_SOURCE_DIR}/include
) 

