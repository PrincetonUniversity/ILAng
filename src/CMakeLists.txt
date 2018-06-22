# path = root/src/

add_subdirectory(util)
add_subdirectory(ila)
add_subdirectory(verify)
add_subdirectory(eq-check)
add_subdirectory(mcm)
if (python_api)
    add_subdirectory(python-api)
endif (python_api)
#add_subdirectory(translator)
#add_subdirectory(engine)
#add_subdirectory(synthesis)

set(ILA_TOOL ila++)
file (GLOB TOP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")
add_library(${ILA_TOOL} ${TOP_SOURCES} 
  $<TARGET_OBJECTS:util> 
  $<TARGET_OBJECTS:ila> 
  $<TARGET_OBJECTS:verify> 
  $<TARGET_OBJECTS:eqcheck>
  $<TARGET_OBJECTS:mcm>
  )
add_dependencies(${ILA_TOOL} glog::glog)
target_link_libraries(${ILA_TOOL} glog::glog ${Z3_LIBRARY})

install(TARGETS ${ILA_TOOL}
        LIBRARY DESTINATION lib)


