# path = root/src/ila

add_subdirectory(ast)   # build ast lib

file(GLOB ILA_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cc")

add_library(ila ${ILA_SOURCES}) # Compile all sources into a library.
add_dependencies(ila ast)       # ila uses the 'ast', add dep.
target_link_libraries(ila ast)  # Link the library 'ast'.

#install(TARGETS ila DESTINATION lib)
#install(FILES "${CMAKE_SOURCE_DIR}/include/ila/ila.h" DESTINATION include)

