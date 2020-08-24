# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/p_infer_child_prog_cfg.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_map_child_prog_entry.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_rewrite_conditional_store.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_rewrite_generic.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_rewrite_store_load.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_sanity_check_and_fix.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_simplify_semantic.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/p_simplify_syntactic.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/u_abs_knob.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/u_rewrite_expr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/u_rewrite_ila.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/u_unroller.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/u_unroller_smt.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/v_eq_check_crr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/v_eq_check_bmc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/v_refinement.cc
)
