# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/smt_ast.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/yosys_smt_parser.cc
)

