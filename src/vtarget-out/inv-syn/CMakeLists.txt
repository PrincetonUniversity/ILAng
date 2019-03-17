# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #

target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/cex_extract.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_obj.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_syn.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_syn_cegar.cc
)


