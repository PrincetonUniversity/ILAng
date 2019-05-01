# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #


target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/loop_extern.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/yosys_chc.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/cvc4_sygus.cc
)


