message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

#set(LIBRARY_NAME    smtparser)

FIND_PACKAGE(BISON 3.0.4 REQUIRED)
FIND_PACKAGE(FLEX 2.5.35 REQUIRED)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(FLEX_INPUT  smtlib2flexlexer.l)
set(FLEX_OUTPUT smtlib2flexlexer.c)
set(FLEX_HEADER smtlib2flexlexer.h)

set(BISON_INPUT  smtlib2bisonparser.y)
set(BISON_OUTPUT smtlib2bisonparser.c)
set(BISON_HEADER smtlib2bisonparser.h)

# ------------------------------------------------------------------------

option(WITH_COVERAGE "If YES, build the debug executable with coverage." NO)

SET(COV_FLAGS_C     "-fprofile-arcs -ftest-coverage")
SET(COV_FLAGS_LINK  "-fprofile-arcs -ftest-coverage")

# ------------------------------------------------------------------------

if(${WITH_COVERAGE})

  message(STATUS "Building with coverage flags set.")
  SET(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${COV_FLAGS_C} -DSMT_PARSER_COVERAGE_ON")
  SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_C_FLAGS_RELEASE} ${COV_FLAGS_LINK}")

else()

  message(STATUS "NOT building with coverage.")

endif()

# ------------------------------------------------------------------------


message(STATUS "Parser Build Flags Debug:   ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "Parser Link Flags Debug:   ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
message(STATUS "Parser Build Flags Release: ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "Parser Link Flags Release: ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")

# ------------------------------------------------------------------------

add_custom_command(
  COMMAND ${BISON_EXECUTABLE}
  ARGS ${SOURCE_DIR}/${BISON_INPUT} -o ${BINARY_DIR}/${BISON_OUTPUT}
  OUTPUT ${BINARY_DIR}/${BISON_OUTPUT} ${BINARY_DIR}/${BISON_HEADER}
  WORKING_DIRECTORY ${SOURCE_DIR} #/${BISON_INPUT}
  DEPENDS ${BINARY_DIR}/${FLEX_OUTPUT} ${SOURCE_DIR}/${BISON_INPUT}
)

add_custom_command(
  COMMAND ${FLEX_EXECUTABLE}
  ARGS --never-interactive --header-file=${BINARY_DIR}/${FLEX_HEADER} -o ${BINARY_DIR}/${FLEX_OUTPUT} ${SOURCE_DIR}/${FLEX_INPUT}
  OUTPUT ${BINARY_DIR}/${FLEX_OUTPUT} ${BINARY_DIR}/${FLEX_HEADER}
  WORKING_DIRECTORY ${SOURCE_DIR} #/${FLEX_INPUT}
  DEPENDS ${SOURCE_DIR}/${FLEX_INPUT}
)

SET_SOURCE_FILES_PROPERTIES(${BINARY_DIR}/${FLEX_OUTPUT} ${BINARY_DIR}/${FLEX_HEADER} GENERATED)
SET_SOURCE_FILES_PROPERTIES(${BINARY_DIR}/${BISON_OUTPUT} ${BINARY_DIR}/${BISON_HEADER} GENERATED)

# ------------------------------------------------------------------------

set(PARSER_LIB_SRC ${BINARY_DIR}/${FLEX_OUTPUT}
                   ${BINARY_DIR}/${BISON_OUTPUT}
                   ${SOURCE_DIR}/smtlib2hashtable.c
                   ${SOURCE_DIR}/smtlib2abstractparser.c
                   ${SOURCE_DIR}/smtlib2termparser.c
                   ${SOURCE_DIR}/smtlib2utils.c
                   ${SOURCE_DIR}/smtlib2vector.c
                   ${SOURCE_DIR}/smtlib2charbuf.c
                   ${SOURCE_DIR}/smtlib2stream.c
                   ${SOURCE_DIR}/smtlib2scanner.c
)

add_library(${LIBRARY_NAME} ${PARSER_LIB_SRC})
add_library(${LIBRARY_NAME}::${LIBRARY_NAME} ALIAS ${LIBRARY_NAME})

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  if(${CMAKE_COMPILER_IS_GNUCXX})
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall)
    target_compile_options(${LIBRARY_NAME} PRIVATE -W)
  endif()
endif()

set_target_properties(${LIBRARY_NAME} PROPERTIES C_EXTENSIONS OFF)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${BINARY_DIR}>
)

install(TARGETS ${LIBRARY_NAME}
  EXPORT ${SMT_PARSER_TARGETS_EXPORT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION ${SMT_PARSER_INCLUDE_INSTALL_DIR}
)



# ------------------------------------------------------------------------
# Add FindGMP

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# ------------------------------------------------------------------------

if (SMT_PARSER_BUILD_YICES) 
  
  set(EXECUTABLE_NAME parser)

  find_package(GMP REQUIRED)

  add_executable(${EXECUTABLE_NAME} smtlib2yices.c yicesmain.c)

  target_include_directories(${EXECUTABLE_NAME} PRIVATE ${GMP_C_INCLUDES})

  if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    if(${CMAKE_COMPILER_IS_GNUCXX})
      target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall)
      target_compile_options(${EXECUTABLE_NAME} PRIVATE -W)
    endif()
  endif()

  target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})
  target_link_libraries(${EXECUTABLE_NAME} ${GMP_C_LIBRARIES})

  target_include_directories(${EXECUTABLE_NAME} 
      PRIVATE ${PROJECT_SOURCE_DIR}/include
      $<BUILD_INTERFACE:${GMP_C_INCLUDES}>
  )

  install(TARGETS ${EXECUTABLE_NAME}
    EXPORT ${SMT_PARSER_TARGETS_EXPORT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION ${SMT_PARSER_INCLUDE_INSTALL_DIR}
  )


endif()

# ------------------------------------------------------------------------


install(
  DIRECTORY ${SMT_PARSER_INCLUDE_BUILD_DIR}/smtparser
  DESTINATION ${SMT_PARSER_INCLUDE_INSTALL_DIR}
)


# ------------------------------------------------------------------------
