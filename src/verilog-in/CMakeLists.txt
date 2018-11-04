# path = root/src/verilog-in

execute_process(COMMAND git submodule update --init -- ./verilog-parser
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(verilog-parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/verilog-parser/src)

file(GLOB VERILOG_IN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(verilogin OBJECT ${VERILOG_IN_SOURCES})

