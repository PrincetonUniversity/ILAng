# ---------------------------------------------------------------------------- #
# source 
# ---------------------------------------------------------------------------- #
target_sources(${ILANG_LIB_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/ila_to_json_serializer.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/interface.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/json_to_ila_deserializer.cc
)

