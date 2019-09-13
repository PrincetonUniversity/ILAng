# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/verilog_parse.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/verilog_analysis.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/verilog_const_parser.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/verilog_analysis_wrapper.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vlog_parser_util.cc
)

