# path = root/src/

add_subdirectory(util)
add_subdirectory(ila)
add_subdirectory(eq-check)
#add_subdirectory(python_api)
#add_subdirectory(translator)
#add_subdirectory(engine)
#add_subdirectory(synthesis)

set(ILA_TOOL ilatools)
file (GLOB TOP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
add_library(${ILA_TOOL} ${TOP_SOURCES})
add_dependencies(${ILA_TOOL} util ila)
target_link_libraries(${ILA_TOOL} util ila)

