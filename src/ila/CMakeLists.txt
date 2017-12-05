# path = root/src/ila

file(GLOB ILA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
  "${CMAKE_CURRENT_SOURCE_DIR}/ast/*.cc"
  )

add_library(ila ${ILA_SOURCES}) # Compile all sources into a library.
add_dependencies(ila glog::glog)
target_link_libraries(ila glog::glog)

#install(TARGETS ila DESTINATION lib)
#install(FILES "${CMAKE_SOURCE_DIR}/include/ila/ila.h" DESTINATION include)

