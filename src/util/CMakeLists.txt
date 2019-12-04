# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/log.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/str_util.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/fs.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/posix_emu.cc
)

