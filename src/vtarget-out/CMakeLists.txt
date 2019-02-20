# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/directive.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/gen_util.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/var_extract.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_impl.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_cosa.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_jasper.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_yosys.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_syn.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vlg_mod.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/absmem.cc
)

