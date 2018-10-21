# path = root/src/mcm


file(GLOB MCM_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")


add_library(mcm OBJECT ${MCM_SOURCES}) # Compile sources into an object