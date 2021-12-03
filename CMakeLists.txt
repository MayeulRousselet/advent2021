cmake_minimum_required(VERSION 3.1...3.22)

project(
  AdventOfCode
  VERSION 1.0
  LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS "-ftemplate-depth=2048")

add_executable(advent main.cpp day1.cpp day2.cpp)