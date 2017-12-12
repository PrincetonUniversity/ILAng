# path = root/src/

add_subdirectory(util)
add_subdirectory(ila)
#add_subdirectory(python_api)
#add_subdirectory(translator)
#add_subdirectory(engine)
#add_subdirectory(synthesis)

file (GLOB CTX_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
add_library(ilatools ${CTX_SOURCES}) 
add_dependencies(ilatools util ila)
target_link_libraries(ilatools util ila)

