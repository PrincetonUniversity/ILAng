# ---------------------------------------------------------------------------- #
# source
# ---------------------------------------------------------------------------- #
# This is the SyGuS for CVC4

target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/sygus_inv_parse.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sim_trace_extract.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_cex_extract.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sygus_base.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sygus_chc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sygus_dp.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_inv_sygus.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/datapoint.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/datapoint_inv_prune.cc
)



