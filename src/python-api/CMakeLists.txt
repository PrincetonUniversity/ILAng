# path = root/src/python-api

file(GLOB ILAPY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

set(EXT_LIBRARIES ${Z3_LIBRARY} ilatools)

add_library (ilapy "${ILAPY_SOURCES}") # Compile all sources into a library.
add_dependencies(ilapy ilatools)
target_link_libraries (ilapy ${EXT_LIBRARIES} ${Boost_LIBRARIES})

