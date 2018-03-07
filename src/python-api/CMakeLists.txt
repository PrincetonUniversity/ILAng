# path = root/src/python-api

file(GLOB ILAPY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

set(ILA_TOOLS ila++)
set(EXT_LIBRARIES ${Z3_LIBRARY} ${ILA_TOOLS})

add_library (ilapy "${ILAPY_SOURCES}") # Compile sources into a library.
add_dependencies(ilapy ${ILA_TOOLS})
target_link_libraries (ilapy ${EXT_LIBRARIES} ${Boost_LIBRARIES})

