# path = /root/src/util

file(GLOB UTIL_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(util OBJECT ${UTIL_SOURCES}) # Compile sources into an object.
#add_dependencies(util glog::glog)
#target_link_libraries(util glog::glog)

