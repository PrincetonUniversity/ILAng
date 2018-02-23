# path = root/src/verify

file(GLOB VERIFY_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(verify OBJECT ${VERIFY_SOURCES}) # Compile sources into an object

