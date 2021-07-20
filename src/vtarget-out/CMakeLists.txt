# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #

add_subdirectory(inv-syn)

target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/directive.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/gen_util.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_impl.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target_as.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target_connect.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target_misc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target_cond.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/single_target_inv_syn_support.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_pono.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen_jasper.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vtarget_gen.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/vlg_mod.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/design_stat.cc
)

