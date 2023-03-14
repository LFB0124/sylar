cmake_minimum_required(3.0)

project(sylar)

include_directories(include)

add_executable(sylar main.cc src/log.cc)

