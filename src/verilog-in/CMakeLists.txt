# path = root/src/verilog-in

add_subdirectory(verilog-parser)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/verilog-parser/src)

file(GLOB VERILOG_IN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(verilogin OBJECT ${VERILOG_IN_SOURCES})

