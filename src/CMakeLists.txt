# path = root/src/

# ------------------------------------------------------------------------------
# sub-directories
# ------------------------------------------------------------------------------
add_subdirectory(util)
add_subdirectory(ila)
add_subdirectory(backend)

if (python-api)
    add_subdirectory(python-api)
endif (python-api)

if (verilog-in)
  add_subdirectory(verilog-in)
endif (verilog-in)

if (json-inout)
  add_subdirectory(json-inout)
endif (json-inout)


# ------------------------------------------------------------------------------
# objects
# ------------------------------------------------------------------------------
set(ILA_TOOL_OBJECTS 
    $<TARGET_OBJECTS:util> 
    $<TARGET_OBJECTS:ila> 
    $<TARGET_OBJECTS:backend> 
    )

if (verilog-in)
  set (ILA_TOOL_OBJECTS ${ILA_TOOL_OBJECTS} $<TARGET_OBJECTS:verilog_in>)
  set (ILA_TOOL_OBJECTS ${ILA_TOOL_OBJECTS} $<TARGET_OBJECTS:verilog_parser>)
endif (verilog-in)

if (json-inout)
  set (ILA_TOOL_OBJECTS ${ILA_TOOL_OBJECTS} $<TARGET_OBJECTS:json_inout>)
endif (json-inout)

# ------------------------------------------------------------------------------
# build
# ------------------------------------------------------------------------------
set(ILA_TOOL ila++)
file (GLOB TOP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(${ILA_TOOL} ${TOP_SOURCES} ${ILA_TOOL_OBJECTS})

add_dependencies(${ILA_TOOL} glog::glog)
target_link_libraries(${ILA_TOOL} glog::glog ${Z3_LIBRARY})

install(TARGETS ${ILA_TOOL}
        LIBRARY DESTINATION lib)


