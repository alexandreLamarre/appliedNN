cmake_minimum_required(VERSION 3.13)
set (CMAKE_CXX_STANDARD 17)

project(appliedNeuralNetworks)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(lib/Catch2)
add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2)