# path = root/src/

if (verilog-in)
  add_subdirectory(verilog-in)
endif (verilog-in)
add_subdirectory(util)
add_subdirectory(ila)
add_subdirectory(backend)
#add_subdirectory(translator)
if (python_api)
    add_subdirectory(python-api)
endif (python_api)

set(ILA_TOOL_OBJECTS 
    $<TARGET_OBJECTS:util> 
    $<TARGET_OBJECTS:ila> 
    $<TARGET_OBJECTS:backend> 
    #$<TARGET_OBJECTS:translator>
    )

if (verilog-in)
  set (ILA_TOOL_OBJECTS ${ILA_TOOL_OBJECTS} $<TARGET_OBJECTS:verilogin>)
  set (ILA_TOOL_OBJECTS ${ILA_TOOL_OBJECTS} $<TARGET_OBJECTS:verilogparser>)
endif (verilog-in)


set(ILA_TOOL ila++)
file (GLOB TOP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(${ILA_TOOL} ${TOP_SOURCES} ${ILA_TOOL_OBJECTS})

add_dependencies(${ILA_TOOL} glog::glog)
target_link_libraries(${ILA_TOOL} glog::glog ${Z3_LIBRARY})

install(TARGETS ${ILA_TOOL}
        LIBRARY DESTINATION lib)


