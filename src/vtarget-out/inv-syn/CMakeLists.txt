# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #


target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/cex_extract.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_obj.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_cnf.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inv_abc_parse.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/grain_inv_parse.cc
)


