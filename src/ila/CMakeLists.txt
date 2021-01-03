# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/expr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/expr_const.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/expr_op.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/expr_var.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/func.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/sort.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast/sort_value.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/ast_hub.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/hash_ast.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/instr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/instr_lvl_abs.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/object.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/symbol.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/transition.cc
)
