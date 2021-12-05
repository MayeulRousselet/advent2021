cmake_minimum_required(VERSION 3.1...3.22)

project(
  AdventOfCode
  VERSION 1.0
  LANGUAGES CXX)

SET(CMAKE_CXX_FLAGS "-ftemplate-depth=2048")
set (CMAKE_CXX_STANDARD 17)

add_executable(advent main.cpp day1.cpp day2.cpp day3.cpp day4.cpp)