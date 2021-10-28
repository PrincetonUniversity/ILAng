# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/smt_switch_itf.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/z3_expr_adapter.cc
)
