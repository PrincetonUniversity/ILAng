# path = root/src/eq-check

file(GLOB EQCHECK_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

#set(EXT_LIBRARIES ${Z3_LIBRARY} util ila)

add_library(eqcheck OBJECT ${EQCHECK_SOURCES}) # Compile sources into an object
#add_dependencies(eqcheck ila util)
#target_link_libraries(eqcheck ${EXT_LIBRARIES})

