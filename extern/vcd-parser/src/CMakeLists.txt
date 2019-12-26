message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")

FIND_PACKAGE(BISON 3.0.4 REQUIRED)
FIND_PACKAGE(FLEX 2.5.35 REQUIRED)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

set(FLEX_INPUT  VCDScanner.l)
set(FLEX_OUTPUT VCDScanner.cpp)
set(FLEX_HEADER VCDScanner.hpp)
set(FLEX_OBJ    VCDScanner.o)

set(BISON_INPUT  VCDParser.ypp)
set(BISON_OUTPUT VCDParser.cpp)
set(BISON_HEADER VCDParser.hpp)
set(BISON_OBJ    VCDParser.o)

# ------------------------------------------------------------------------

option(WITH_COVERAGE "If YES, build the debug executable with coverage." NO)

SET(COV_FLAGS_C     "-fprofile-arcs -ftest-coverage")
SET(COV_FLAGS_LINK  "-fprofile-arcs -ftest-coverage")

# ------------------------------------------------------------------------

if(${WITH_COVERAGE})

  message(STATUS "Building with coverage flags set.")
  SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${COV_FLAGS_C} -DVCD_PARSER_COVERAGE_ON")
  SET(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} ${COV_FLAGS_LINK}")

else()

  message(STATUS "NOT building with coverage.")

endif()

# ------------------------------------------------------------------------


message(STATUS "Parser Build Flags Debug:   ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "Parser Link Flags Debug:   ${CMAKE_EXE_LINKER_FLAGS_DEBUG}")
message(STATUS "Parser Build Flags Release: ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "Parser Link Flags Release: ${CMAKE_EXE_LINKER_FLAGS_RELEASE}")

# ------------------------------------------------------------------------

add_custom_command(
  COMMAND ${BISON_EXECUTABLE}
  ARGS -v --defines=${BINARY_DIR}/${BISON_HEADER} ${SOURCE_DIR}/${BISON_INPUT} -o ${BINARY_DIR}/${BISON_OUTPUT}
  OUTPUT ${BINARY_DIR}/${BISON_OUTPUT} ${BINARY_DIR}/${BISON_HEADER}
  WORKING_DIRECTORY ${SOURCE_DIR} #/${BISON_INPUT}
  DEPENDS ${SOURCE_DIR}/${BISON_INPUT}
)

add_custom_command(
  COMMAND ${FLEX_EXECUTABLE}
  ARGS -P VCDParser --never-interactive --header-file=${BINARY_DIR}/${FLEX_HEADER} -o ${BINARY_DIR}/${FLEX_OUTPUT} ${SOURCE_DIR}/${FLEX_INPUT}
  OUTPUT ${BINARY_DIR}/${FLEX_OUTPUT} ${BINARY_DIR}/${FLEX_HEADER}
  WORKING_DIRECTORY ${SOURCE_DIR} #/${FLEX_INPUT}
  DEPENDS ${BINARY_DIR}/${BISON_OUTPUT} ${SOURCE_DIR}/${FLEX_INPUT}
)

SET_SOURCE_FILES_PROPERTIES(${BINARY_DIR}/${FLEX_OUTPUT} ${BINARY_DIR}/${FLEX_HEADER} GENERATED)
SET_SOURCE_FILES_PROPERTIES(${BINARY_DIR}/${BISON_OUTPUT} ${BINARY_DIR}/${BISON_HEADER} GENERATED)

# ------------------------------------------------------------------------

set(PARSER_LIB_SRC ${BINARY_DIR}/${FLEX_OUTPUT}
                   ${BINARY_DIR}/${BISON_OUTPUT}
                   ${SOURCE_DIR}/VCDFile.cpp
                   ${SOURCE_DIR}/VCDFileParser.cpp
                   ${SOURCE_DIR}/VCDValue.cpp
)

add_library(${LIBRARY_NAME} ${PARSER_LIB_SRC})
add_library(${LIBRARY_NAME}::${LIBRARY_NAME} ALIAS ${LIBRARY_NAME})

if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  if(${CMAKE_COMPILER_IS_GNUCXX})
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall)
    target_compile_options(${LIBRARY_NAME} PRIVATE -W)
  endif()
endif()

#set_target_properties(${LIBRARY_NAME} PROPERTIES C_EXTENSIONS OFF)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${BINARY_DIR}>
)

# ------------------------------------------------------------------------

add_executable(${EXECUTABLE_NAME} main.cpp)


if(${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
  if(${CMAKE_COMPILER_IS_GNUCXX})
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -Wall)
    target_compile_options(${EXECUTABLE_NAME} PRIVATE -W)
  endif()
endif()

target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME})

target_include_directories(${EXECUTABLE_NAME} 
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

# ------------------------------------------------------------------------

install(TARGETS ${LIBRARY_NAME} ${EXECUTABLE_NAME}
  EXPORT ${VCD_PARSER_TARGETS_EXPORT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION ${VCD_PARSER_INCLUDE_INSTALL_DIR}
)

install(
  DIRECTORY ${VCD_PARSER_INCLUDE_BUILD_DIR}/vcdparser
  DESTINATION ${VCD_PARSER_INCLUDE_INSTALL_DIR}
)


# ------------------------------------------------------------------------
