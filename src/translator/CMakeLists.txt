# path = root/src/translator

file(GLOB TRANS_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(translator OBJECT ${TRANS_SOURCES}) # Compile sources into an object

