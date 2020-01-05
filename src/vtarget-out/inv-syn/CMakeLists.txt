# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #


target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/cex_extract.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/rel_chc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_obj.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_cnf.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_abc_parse.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_syn_cegar.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/grain_inv_parse.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_inv_chc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_inv_abc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_inv_enhance.cc
)


