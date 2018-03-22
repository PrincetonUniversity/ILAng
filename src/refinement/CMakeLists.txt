# path = root/src/refinement

file(GLOB REFINE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(refinement OBJECT ${REFINE_SOURCES}) # Compile sources into an object

