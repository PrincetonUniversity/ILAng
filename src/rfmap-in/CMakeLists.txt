# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/verilog_rfmap.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/rfmap_typecheck.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/rfexpr_to_smt.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/rfexpr_shortcut.cc
)

