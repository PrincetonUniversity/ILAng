cmake_minimum_required(VERSION 3.8)

project(simple VERSION 1.0 LANGUAGES CXX)

set(MyTarget ${PROJECT_NAME})

add_executable(${MyTarget} src/main.cc)

target_include_directories(${MyTarget} PRIVATE include)

target_link_libraries(${MyTarget} ilang::ilang++)

