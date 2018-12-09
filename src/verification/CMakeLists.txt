# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/abs_knob.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/eq_check_crr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/legacy_bmc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/rewrite_expr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/rewrite_ila.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/unroller.cc
)

