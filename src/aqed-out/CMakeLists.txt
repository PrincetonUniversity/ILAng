# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/aqed_out.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/aqed_vlog_out.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/aqed_out_impl.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/aqed_out_util.cc
)

