# path = root/src

# build libraries for all components
add_subdirectory(ila_ir)
#add_subdirectory(front_end)
#add_subdirectory(app)

# build top-level ILA infrastructure executable
#file(GLOB TOP_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src*.cc")
#add_executable(ila_infra ${TOP_SRC})
#set(EXTRA_LIBS ${EXTRA_LIBS} ila_ast ila_ir)
#target_link_libraries(ila_infra ${EXTRA_LIBS})

