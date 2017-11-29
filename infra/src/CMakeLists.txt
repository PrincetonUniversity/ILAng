# path = root/src

# build libraries for all components
add_subdirectory (ila_ir)
#add_subdirectory (front_end)
#add_subdirectory (app)

# build top-level ILA infrastructure executable
#file(GLOB TOP_SRC "${CMAKE_CURRENT_SOURCE_DIR}/src*.cc")
#add_executable(ila_infra ${TOP_SRC})
#set(EXTRA_LIBS ${EXTRA_LIBS} ila_ast ila_ir)
#target_link_libraries(ila_infra ${EXTRA_LIBS})

# configure header files to pass some of the CMake settings to the source
#configure_file (
#  "${PROJECT_SOURCE_DIR}/include/ila_infra.h"
#  "${PROJECT_BINARY_DIR}/include/ila_infra.h"
#  )

# install top-level ILA infrastructure 
#install (TARGETS ila_infra DESTINATION bin)
#install (FILES "${CMAKE_SOURCE_DIR}/include/ila_infra.h" DESTINATION include)
