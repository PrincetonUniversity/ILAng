# path = root/src/

add_subdirectory(util)
add_subdirectory(ila)
#add_subdirectory(python_api)
#add_subdirectory(translator)
#add_subdirectory(engine)
#add_subdirectory(synthesis)

file (GLOB TOP_SOURCES "${CMAKE_CURRENT_SOUrCE_DIR}/*.cc")
add_library(ilatools ${TOP_SOURCES})
add_dependencies(ilatools util ila)
target_link_libraries(ilatools util ila)

