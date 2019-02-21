cmake_minimum_required(VERSION 3.12)
project(OOP_nanotekspice_2018)

add_compile_options(-Wall -Wextra --coverage -DPROJECT_PATH="../")
set(CMAKE_CXX_STANDARD 20)

include_directories(src/component/gates src/component/circuits src/component src/pin src/parser src .)
include_directories(tests/src)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE tests tests/src/*.cpp)
add_executable(OOP_nanotekspice_2018 ${sources} main.cpp ${tests})
target_link_libraries(OOP_nanotekspice_2018 gtest gtest_main gcov)
