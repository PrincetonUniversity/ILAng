# path = root/src/ref-rel

file(GLOB RR_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

set(EXT_LIBRARIES ${Z3_LIBRARY} ila util)

add_library(rr ${RR_SOURCES}) # Compile all sources into a library.
add_dependencies(rr ila util)
target_link_libraries(rr ${EXT_LIBRARIES})

