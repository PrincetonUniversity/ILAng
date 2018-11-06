# path = root/src/json-inout
set(JSON_INOUT_NAME json_inout)

# ------------------------------------------------------------------------------
# Support both embedded and external build
# ------------------------------------------------------------------------------
if (json-external)
  find_package (nlohmann_json 3.2.0 REQUIRED)

else ()
  execute_process (COMMAND git submodule update --init -- ./nlohmann-json
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
  set (JSON_BuildTests OFF CACHE INTERNAL "")
  add_subdirectory (nlohmann-json)

endif (json-external)

# ------------------------------------------------------------------------------
# Build
# ------------------------------------------------------------------------------
file(GLOB JSON_INOUT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(${JSON_INOUT_NAME} OBJECT ${JSON_INOUT_SOURCES})

#target_link_libraries(${JSON_INOUT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${JSON_INOUT_NAME} PUBLIC nlohmann_json::nlohmann_json)

