# path = root/src/backend

file(GLOB BACKEND_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(backend OBJECT ${BACKEND_SOURCES}) # Compile sources into an object

