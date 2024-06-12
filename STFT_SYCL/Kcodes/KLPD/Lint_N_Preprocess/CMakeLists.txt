cmake_minimum_required(VERSION 3.0.0)
project(Lint_N_Preprocess VERSION 0.1.0 LANGUAGES C CXX)
#include_directories(${CMAKE_SOURCE_DIR}/include/)
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
