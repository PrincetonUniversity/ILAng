# path = root/src/verilog-in
set (VERILOG_IN_NAME verilog_in)

# ------------------------------------------------------------------------------
# Support embedded build
# ------------------------------------------------------------------------------
execute_process(COMMAND git submodule update --init -- ./byh-verilog-parser
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(byh-verilog-parser)

# ------------------------------------------------------------------------------
# Build
# ------------------------------------------------------------------------------
file(GLOB VERILOG_IN_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(${VERILOG_IN_NAME} OBJECT ${VERILOG_IN_SOURCES})

