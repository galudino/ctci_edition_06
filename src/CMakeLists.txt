set(PROJECT_TITLE "ctci6_edition_06")
set(CMAKE_VERSION "3.18")

set(CXX_STD "20") # C++20
set(CFLAGS "-Wall -Werror -pedantic-errors")

set(DIR_INCLUDE "./")

cmake_minimum_required(VERSION "${CMAKE_VERSION}")

set(CMAKE_CXX_STANDARD "${CXX_STD}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS}")

project("${PROJECT_TITLE}")
include_directories("${DIR_INCLUDE}")

add_subdirectory("./01") ## Chapter 01: Arrays and Strings
add_subdirectory("./02") ## Chapter 02: Linked Lists
add_subdirectory("./03") ## Chapter 03: Stacks and Queues
add_subdirectory("./04") ## Chapter 04: Trees and Graphs
add_subdirectory("./05") ## Chapter 05: Bit Manipulation
add_subdirectory("./06") ## Chapter 06: Math and Logic Puzzles
add_subdirectory("./07") ## Chapter 07: Object-Oriented Design
add_subdirectory("./08") ## Chapter 08: Recursion and Dynamic Programming
add_subdirectory("./09") ## Chapter 09: System Design and Scalability
add_subdirectory("./10") ## Chapter 10: Sorting and Searching
add_subdirectory("./12") ## Chapter 12: C and C++
add_subdirectory("./15") ## Chapter 15: Threads and Locks
add_subdirectory("./16") ## Chapter 16: Moderate
add_subdirectory("./17") ## Chapter 17: Hard
