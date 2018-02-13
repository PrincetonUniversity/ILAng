# path = root/src/ila

file(GLOB ILA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/ast/*.cc"
  )

#set(EXT_LIBRARIES ${Z3_LIBRARY} util)

add_library(ila OBJECT ${ILA_SOURCES}) # Compile sources into an object.
#add_dependencies(ila util)
#target_link_libraries(ila ${EXT_LIBRARIES})

