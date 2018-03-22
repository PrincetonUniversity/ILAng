# path = root/src/

add_subdirectory(util)
add_subdirectory(ila)
add_subdirectory(backend)
add_subdirectory(refinement)
add_subdirectory(translator)
if (python_api)
    add_subdirectory(python-api)
endif (python_api)

set(ILA_TOOL ila++)
file (GLOB TOP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
add_library(${ILA_TOOL} ${TOP_SOURCES} 
  $<TARGET_OBJECTS:util> 
  $<TARGET_OBJECTS:ila> 
  $<TARGET_OBJECTS:backend> 
  $<TARGET_OBJECTS:refinement>
  $<TARGET_OBJECTS:translator>
  )
add_dependencies(${ILA_TOOL} glog::glog)
target_link_libraries(${ILA_TOOL} glog::glog ${Z3_LIBRARY})

install(TARGETS ${ILA_TOOL}
        LIBRARY DESTINATION lib)


