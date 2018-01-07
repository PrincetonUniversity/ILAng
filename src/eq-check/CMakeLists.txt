# path = root/src/eq-check

file(GLOB EQCHECK_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

set(EXT_LIBRARIES ${Z3_LIBRARY} ila util)

add_library(eqcheck ${EQCHECK_SOURCES}) # Compile all sources into a library.
add_dependencies(eqcheck ila util)
target_link_libraries(eqcheck ${EXT_LIBRARIES})

