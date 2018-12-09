# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ast_helper.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/axiom_helper.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/inter_ila_unroller.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/memory_model.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sc_manual.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tso_manual.cc
)

