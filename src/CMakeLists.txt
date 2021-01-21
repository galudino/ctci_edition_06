##
##  @file       CMakeLists.txt
##  @brief      Set of instructions describing this project's sources/targets
##
##  @author     Gemuele Aludino
##  @date       28 Jun 2020
##

###########################################################################
##                                                                       ##
##  How to define a variable:                                            ##
##                                                                       ##
##  For a variable VAR_NAME,                                             ##
##  that is to have the value 'desired_value':                           ##
##                                                                       ##
##      set(VAR_NAME desired_value)                                      ##
##                                                                       ##
##  To use VAR_NAME as part of an argument,                              ##
##  such as in another variable's name or value,                         ##
##  you may do this (for a variable OTHER_NAME):                         ##
##                                                                       ##
##      set(OTHER_NAME, ${VAR_NAME}/the_other_part)                      ##
##                                                                       ##
###########################################################################

###########################################################################
##  Variables                                                            ##
###########################################################################

## --------------------------------------------------------------------- ##
## CMake version number, C++ version number
## --------------------------------------------------------------------- ##

set(CMAKE_VERSION_NUMBER "3.17.3")
set(CXX_STD "17")

## --------------------------------------------------------------------- ##
## Title for this project
## --------------------------------------------------------------------- ##

set(PROJECT_TITLE "CTCI_CPP")

## --------------------------------------------------------------------- ##
## Flags
## --------------------------------------------------------------------- ##

set(WALL "-Wall")
set(WERR "-Werror")

set(PEDANTIC "-pedantic-errors")

set(CFLAGS "${WALL} ${WERR} ${PEDANTIC}")

###########################################################################
##  Configuration                                                        ##
###########################################################################

## --------------------------------------------------------------------- ##
## CMake version
## --------------------------------------------------------------------- ##

cmake_minimum_required(VERSION "${CMAKE_VERSION_NUMBER}")

## --------------------------------------------------------------------- ##
## C++ standard (-std=c++17)
## --------------------------------------------------------------------- ##

set(CMAKE_CXX_STANDARD "${CXX_STD}")

## --------------------------------------------------------------------- ##
## Compiler flags
## --------------------------------------------------------------------- ##

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CFLAGS}")

## --------------------------------------------------------------------- ##
## Project name (access via PROJECT_NAME)
## --------------------------------------------------------------------- ##

project("${PROJECT_TITLE}")

## --------------------------------------------------------------------- ##
## Header file path (.h/.hpp/.tpp)
## --------------------------------------------------------------------- ##

include_directories("include")

## --------------------------------------------------------------------- ##
## Executables
## --------------------------------------------------------------------- ##

## Chapter 01: Arrays_and_strings
add_executable("ctci6_01_01" "01/01/main.cpp" "01/01/header.hpp" "01/01/source.cpp")
add_executable("ctci6_01_02" "01/02/main.cpp" "01/02/header.hpp" "01/02/source.cpp")
add_executable("ctci6_01_03" "01/03/main.cpp" "01/03/header.hpp" "01/03/source.cpp")
add_executable("ctci6_01_04" "01/04/main.cpp" "01/04/header.hpp" "01/04/source.cpp")
add_executable("ctci6_01_05" "01/05/main.cpp" "01/05/header.hpp" "01/05/source.cpp")
add_executable("ctci6_01_06" "01/06/main.cpp" "01/06/header.hpp" "01/06/source.cpp")
add_executable("ctci6_01_07" "01/07/main.cpp" "01/07/header.hpp" "01/07/source.cpp")
add_executable("ctci6_01_08" "01/08/main.cpp" "01/08/header.hpp" "01/08/source.cpp")
add_executable("ctci6_01_09" "01/09/main.cpp" "01/09/header.hpp" "01/09/source.cpp")

## Chapter 02: Linked Lists
add_executable("ctci6_02_01" "02/01/main.cpp" "02/01/header.hpp" "02/01/source.cpp")
add_executable("ctci6_02_02" "02/02/main.cpp" "02/02/header.hpp" "02/02/source.cpp")
add_executable("ctci6_02_03" "02/03/main.cpp" "02/03/header.hpp" "02/03/source.cpp")
add_executable("ctci6_02_04" "02/04/main.cpp" "02/04/header.hpp" "02/04/source.cpp")
add_executable("ctci6_02_05" "02/05/main.cpp" "02/05/header.hpp" "02/05/source.cpp")
add_executable("ctci6_02_06" "02/06/main.cpp" "02/06/header.hpp" "02/06/source.cpp")
add_executable("ctci6_02_07" "02/07/main.cpp" "02/07/header.hpp" "02/07/source.cpp")
add_executable("ctci6_02_08" "02/08/main.cpp" "02/08/header.hpp" "02/08/source.cpp")

## Chapter 03: Stacks and Queues
add_executable("ctci6_03_01" "03/01/main.cpp" "03/01/header.hpp" "03/01/source.cpp")
add_executable("ctci6_03_02" "03/02/main.cpp" "03/02/header.hpp" "03/02/source.cpp")
add_executable("ctci6_03_03" "03/03/main.cpp" "03/03/header.hpp" "03/03/source.cpp")
add_executable("ctci6_03_04" "03/04/main.cpp" "03/04/header.hpp" "03/04/source.cpp")
add_executable("ctci6_03_05" "03/05/main.cpp" "03/05/header.hpp" "03/05/source.cpp")
add_executable("ctci6_03_06" "03/06/main.cpp" "03/06/header.hpp" "03/06/source.cpp")

## Chapter 04: Trees and Graphs
add_executable("ctci6_04_01" "04/01/main.cpp" "04/01/header.hpp" "04/01/source.cpp")
add_executable("ctci6_04_02" "04/02/main.cpp" "04/02/header.hpp" "04/02/source.cpp")
add_executable("ctci6_04_03" "04/03/main.cpp" "04/03/header.hpp" "04/03/source.cpp")
add_executable("ctci6_04_04" "04/04/main.cpp" "04/04/header.hpp" "04/04/source.cpp")
add_executable("ctci6_04_05" "04/05/main.cpp" "04/05/header.hpp" "04/05/source.cpp")
add_executable("ctci6_04_06" "04/06/main.cpp" "04/06/header.hpp" "04/06/source.cpp")
add_executable("ctci6_04_07" "04/07/main.cpp" "04/07/header.hpp" "04/07/source.cpp")
add_executable("ctci6_04_08" "04/08/main.cpp" "04/08/header.hpp" "04/08/source.cpp")
add_executable("ctci6_04_09" "04/09/main.cpp" "04/09/header.hpp" "04/09/source.cpp")
add_executable("ctci6_04_10" "04/10/main.cpp" "04/10/header.hpp" "04/10/source.cpp")
add_executable("ctci6_04_11" "04/11/main.cpp" "04/11/header.hpp" "04/11/source.cpp")
add_executable("ctci6_04_12" "04/12/main.cpp" "04/12/header.hpp" "04/12/source.cpp")

## Chapter 05: Bit Manipulation
add_executable("ctci6_05_01" "05/01/main.cpp" "05/01/header.hpp" "05/01/source.cpp")
add_executable("ctci6_05_02" "05/02/main.cpp" "05/02/header.hpp" "05/02/source.cpp")
add_executable("ctci6_05_03" "05/03/main.cpp" "05/03/header.hpp" "05/03/source.cpp")
add_executable("ctci6_05_04" "05/04/main.cpp" "05/04/header.hpp" "05/04/source.cpp")
add_executable("ctci6_05_05" "05/05/main.cpp" "05/05/header.hpp" "05/05/source.cpp")
add_executable("ctci6_05_06" "05/06/main.cpp" "05/06/header.hpp" "05/06/source.cpp")
add_executable("ctci6_05_07" "05/07/main.cpp" "05/07/header.hpp" "05/07/source.cpp")
add_executable("ctci6_05_08" "05/08/main.cpp" "05/08/header.hpp" "05/08/source.cpp")

## Chapter 06: Math and Logic Puzzles
add_executable("ctci6_06_01" "06/01/main.cpp" "06/01/header.hpp" "06/01/source.cpp")
add_executable("ctci6_06_02" "06/02/main.cpp" "06/02/header.hpp" "06/02/source.cpp")
add_executable("ctci6_06_03" "06/03/main.cpp" "06/03/header.hpp" "06/03/source.cpp")
add_executable("ctci6_06_04" "06/04/main.cpp" "06/04/header.hpp" "06/04/source.cpp")
add_executable("ctci6_06_05" "06/05/main.cpp" "06/05/header.hpp" "06/05/source.cpp")
add_executable("ctci6_06_06" "06/06/main.cpp" "06/06/header.hpp" "06/06/source.cpp")
add_executable("ctci6_06_07" "06/07/main.cpp" "06/07/header.hpp" "06/07/source.cpp")
add_executable("ctci6_06_08" "06/08/main.cpp" "06/08/header.hpp" "06/08/source.cpp")
add_executable("ctci6_06_09" "06/09/main.cpp" "06/09/header.hpp" "06/09/source.cpp")
add_executable("ctci6_06_10" "06/10/main.cpp" "06/10/header.hpp" "06/10/source.cpp")

## Chapter 07: Object-Oriented Design
add_executable("ctci6_07_01" "07/01/main.cpp" "07/01/header.hpp" "07/01/source.cpp")
add_executable("ctci6_07_02" "07/02/main.cpp" "07/02/header.hpp" "07/02/source.cpp")
add_executable("ctci6_07_03" "07/03/main.cpp" "07/03/header.hpp" "07/03/source.cpp")
add_executable("ctci6_07_04" "07/04/main.cpp" "07/04/header.hpp" "07/04/source.cpp")
add_executable("ctci6_07_05" "07/05/main.cpp" "07/05/header.hpp" "07/05/source.cpp")
add_executable("ctci6_07_06" "07/06/main.cpp" "07/06/header.hpp" "07/06/source.cpp")
add_executable("ctci6_07_07" "07/07/main.cpp" "07/07/header.hpp" "07/07/source.cpp")
add_executable("ctci6_07_08" "07/08/main.cpp" "07/08/header.hpp" "07/08/source.cpp")
add_executable("ctci6_07_09" "07/09/main.cpp" "07/09/header.hpp" "07/09/source.cpp")
add_executable("ctci6_07_10" "07/10/main.cpp" "07/10/header.hpp" "07/10/source.cpp")
add_executable("ctci6_07_11" "07/11/main.cpp" "07/11/header.hpp" "07/11/source.cpp")
add_executable("ctci6_07_12" "07/12/main.cpp" "07/12/header.hpp" "07/12/source.cpp")

## Chapter 08: Recursion and Dynamic Programming
add_executable("ctci6_08_01" "08/01/main.cpp" "08/01/header.hpp" "08/01/source.cpp")
add_executable("ctci6_08_02" "08/02/main.cpp" "08/02/header.hpp" "08/02/source.cpp")
add_executable("ctci6_08_03" "08/03/main.cpp" "08/03/header.hpp" "08/03/source.cpp")
add_executable("ctci6_08_04" "08/04/main.cpp" "08/04/header.hpp" "08/04/source.cpp")
add_executable("ctci6_08_05" "08/05/main.cpp" "08/05/header.hpp" "08/05/source.cpp")
add_executable("ctci6_08_06" "08/06/main.cpp" "08/06/header.hpp" "08/06/source.cpp")
add_executable("ctci6_08_07" "08/07/main.cpp" "08/07/header.hpp" "08/07/source.cpp")
add_executable("ctci6_08_08" "08/08/main.cpp" "08/08/header.hpp" "08/08/source.cpp")
add_executable("ctci6_08_09" "08/09/main.cpp" "08/09/header.hpp" "08/09/source.cpp")
add_executable("ctci6_08_10" "08/10/main.cpp" "08/10/header.hpp" "08/10/source.cpp")
add_executable("ctci6_08_11" "08/11/main.cpp" "08/11/header.hpp" "08/11/source.cpp")
add_executable("ctci6_08_12" "08/12/main.cpp" "08/12/header.hpp" "08/12/source.cpp")
add_executable("ctci6_08_13" "08/13/main.cpp" "08/13/header.hpp" "08/13/source.cpp")
add_executable("ctci6_08_14" "08/14/main.cpp" "08/14/header.hpp" "08/14/source.cpp")

## Chapter 09: Scalability and Memory Limits
add_executable("ctci6_09_01" "09/01/main.cpp" "09/01/header.hpp" "09/01/source.cpp")
add_executable("ctci6_09_02" "09/02/main.cpp" "09/02/header.hpp" "09/02/source.cpp")
add_executable("ctci6_09_03" "09/03/main.cpp" "09/03/header.hpp" "09/03/source.cpp")
add_executable("ctci6_09_04" "09/04/main.cpp" "09/04/header.hpp" "09/04/source.cpp")
add_executable("ctci6_09_05" "09/05/main.cpp" "09/05/header.hpp" "09/05/source.cpp")
add_executable("ctci6_09_06" "09/06/main.cpp" "09/06/header.hpp" "09/06/source.cpp")
add_executable("ctci6_09_07" "09/07/main.cpp" "09/07/header.hpp" "09/07/source.cpp")
add_executable("ctci6_09_08" "09/08/main.cpp" "09/08/header.hpp" "09/08/source.cpp")

## Chapter 10: Sorting and Searching
add_executable("ctci6_10_01" "10/01/main.cpp" "10/01/header.hpp" "10/01/source.cpp")
add_executable("ctci6_10_02" "10/02/main.cpp" "10/02/header.hpp" "10/02/source.cpp")
add_executable("ctci6_10_03" "10/03/main.cpp" "10/03/header.hpp" "10/03/source.cpp")
add_executable("ctci6_10_04" "10/04/main.cpp" "10/04/header.hpp" "10/04/source.cpp")
add_executable("ctci6_10_05" "10/05/main.cpp" "10/05/header.hpp" "10/05/source.cpp")
add_executable("ctci6_10_06" "10/06/main.cpp" "10/06/header.hpp" "10/06/source.cpp")
add_executable("ctci6_10_07" "10/07/main.cpp" "10/07/header.hpp" "10/07/source.cpp")
add_executable("ctci6_10_08" "10/08/main.cpp" "10/08/header.hpp" "10/08/source.cpp")
add_executable("ctci6_10_09" "10/09/main.cpp" "10/09/header.hpp" "10/09/source.cpp")
add_executable("ctci6_10_10" "10/10/main.cpp" "10/10/header.hpp" "10/10/source.cpp")
add_executable("ctci6_10_11" "10/11/main.cpp" "10/11/header.hpp" "10/11/source.cpp")

## Chapter 12: C and C++
add_executable("ctci6_12_01" "12/01/main.cpp" "12/01/header.hpp" "12/01/source.cpp")
add_executable("ctci6_12_02" "12/02/main.cpp" "12/02/header.hpp" "12/02/source.cpp")
add_executable("ctci6_12_03" "12/03/main.cpp" "12/03/header.hpp" "12/03/source.cpp")
add_executable("ctci6_12_04" "12/04/main.cpp" "12/04/header.hpp" "12/04/source.cpp")
add_executable("ctci6_12_05" "12/05/main.cpp" "12/05/header.hpp" "12/05/source.cpp")
add_executable("ctci6_12_06" "12/06/main.cpp" "12/06/header.hpp" "12/06/source.cpp")
add_executable("ctci6_12_07" "12/07/main.cpp" "12/07/header.hpp" "12/07/source.cpp")
add_executable("ctci6_12_08" "12/08/main.cpp" "12/08/header.hpp" "12/08/source.cpp")
add_executable("ctci6_12_09" "12/09/main.cpp" "12/09/header.hpp" "12/09/source.cpp")
add_executable("ctci6_12_10" "12/10/main.cpp" "12/10/header.hpp" "12/10/source.cpp")
add_executable("ctci6_12_11" "12/11/main.cpp" "12/11/header.hpp" "12/11/source.cpp")

## Chapter 15: Threads and Locks
add_executable("ctci6_15_01" "15/01/main.cpp" "15/01/header.hpp" "15/01/source.cpp")
add_executable("ctci6_15_02" "15/02/main.cpp" "15/02/header.hpp" "15/02/source.cpp")
add_executable("ctci6_15_03" "15/03/main.cpp" "15/03/header.hpp" "15/03/source.cpp")
add_executable("ctci6_15_04" "15/04/main.cpp" "15/04/header.hpp" "15/04/source.cpp")
add_executable("ctci6_15_05" "15/05/main.cpp" "15/05/header.hpp" "15/05/source.cpp")
add_executable("ctci6_15_06" "15/06/main.cpp" "15/06/header.hpp" "15/06/source.cpp")
add_executable("ctci6_15_07" "15/07/main.cpp" "15/07/header.hpp" "15/07/source.cpp")

## Chapter 16: Moderate
add_executable("ctci6_16_01" "16/01/main.cpp" "16/01/header.hpp" "16/01/source.cpp")
add_executable("ctci6_16_02" "16/02/main.cpp" "16/02/header.hpp" "16/02/source.cpp")
add_executable("ctci6_16_03" "16/03/main.cpp" "16/03/header.hpp" "16/03/source.cpp")
add_executable("ctci6_16_04" "16/04/main.cpp" "16/04/header.hpp" "16/04/source.cpp")
add_executable("ctci6_16_05" "16/05/main.cpp" "16/05/header.hpp" "16/05/source.cpp")
add_executable("ctci6_16_06" "16/06/main.cpp" "16/06/header.hpp" "16/06/source.cpp")
add_executable("ctci6_16_07" "16/07/main.cpp" "16/07/header.hpp" "16/07/source.cpp")
add_executable("ctci6_16_08" "16/08/main.cpp" "16/08/header.hpp" "16/08/source.cpp")
add_executable("ctci6_16_09" "16/09/main.cpp" "16/09/header.hpp" "16/09/source.cpp")
add_executable("ctci6_16_10" "16/10/main.cpp" "16/10/header.hpp" "16/10/source.cpp")
add_executable("ctci6_16_11" "16/11/main.cpp" "16/11/header.hpp" "16/11/source.cpp")
add_executable("ctci6_16_12" "16/12/main.cpp" "16/12/header.hpp" "16/12/source.cpp")
add_executable("ctci6_16_13" "16/13/main.cpp" "16/13/header.hpp" "16/13/source.cpp")
add_executable("ctci6_16_14" "16/14/main.cpp" "16/14/header.hpp" "16/14/source.cpp")
add_executable("ctci6_16_15" "16/15/main.cpp" "16/15/header.hpp" "16/15/source.cpp")
add_executable("ctci6_16_16" "16/16/main.cpp" "16/16/header.hpp" "16/16/source.cpp")
add_executable("ctci6_16_17" "16/17/main.cpp" "16/17/header.hpp" "16/17/source.cpp")
add_executable("ctci6_16_18" "16/18/main.cpp" "16/18/header.hpp" "16/18/source.cpp")
add_executable("ctci6_16_19" "16/19/main.cpp" "16/19/header.hpp" "16/19/source.cpp")
add_executable("ctci6_16_20" "16/20/main.cpp" "16/20/header.hpp" "16/20/source.cpp")
add_executable("ctci6_16_21" "16/21/main.cpp" "16/21/header.hpp" "16/21/source.cpp")
add_executable("ctci6_16_22" "16/22/main.cpp" "16/22/header.hpp" "16/22/source.cpp")
add_executable("ctci6_16_23" "16/23/main.cpp" "16/23/header.hpp" "16/23/source.cpp")
add_executable("ctci6_16_24" "16/24/main.cpp" "16/24/header.hpp" "16/24/source.cpp")
add_executable("ctci6_16_25" "16/25/main.cpp" "16/25/header.hpp" "16/25/source.cpp")
add_executable("ctci6_16_26" "16/26/main.cpp" "16/26/header.hpp" "16/26/source.cpp")

## Chapter 17: Hard
add_executable("ctci6_17_01" "17/01/main.cpp" "17/01/header.hpp" "17/01/source.cpp")
add_executable("ctci6_17_02" "17/02/main.cpp" "17/02/header.hpp" "17/02/source.cpp")
add_executable("ctci6_17_03" "17/03/main.cpp" "17/03/header.hpp" "17/03/source.cpp")
add_executable("ctci6_17_04" "17/04/main.cpp" "17/04/header.hpp" "17/04/source.cpp")
add_executable("ctci6_17_05" "17/05/main.cpp" "17/05/header.hpp" "17/05/source.cpp")
add_executable("ctci6_17_06" "17/06/main.cpp" "17/06/header.hpp" "17/06/source.cpp")
add_executable("ctci6_17_07" "17/07/main.cpp" "17/07/header.hpp" "17/07/source.cpp")
add_executable("ctci6_17_08" "17/08/main.cpp" "17/08/header.hpp" "17/08/source.cpp")
add_executable("ctci6_17_09" "17/09/main.cpp" "17/09/header.hpp" "17/09/source.cpp")
add_executable("ctci6_17_10" "17/10/main.cpp" "17/10/header.hpp" "17/10/source.cpp")
add_executable("ctci6_17_11" "17/11/main.cpp" "17/11/header.hpp" "17/11/source.cpp")
add_executable("ctci6_17_12" "17/12/main.cpp" "17/12/header.hpp" "17/12/source.cpp")
add_executable("ctci6_17_13" "17/13/main.cpp" "17/13/header.hpp" "17/13/source.cpp")
add_executable("ctci6_17_14" "17/14/main.cpp" "17/14/header.hpp" "17/14/source.cpp")
add_executable("ctci6_17_15" "17/15/main.cpp" "17/15/header.hpp" "17/15/source.cpp")
add_executable("ctci6_17_16" "17/16/main.cpp" "17/16/header.hpp" "17/16/source.cpp")
add_executable("ctci6_17_17" "17/17/main.cpp" "17/17/header.hpp" "17/17/source.cpp")
add_executable("ctci6_17_18" "17/18/main.cpp" "17/18/header.hpp" "17/18/source.cpp")
add_executable("ctci6_17_19" "17/19/main.cpp" "17/19/header.hpp" "17/19/source.cpp")
add_executable("ctci6_17_20" "17/20/main.cpp" "17/20/header.hpp" "17/20/source.cpp")
add_executable("ctci6_17_21" "17/21/main.cpp" "17/21/header.hpp" "17/21/source.cpp")
add_executable("ctci6_17_22" "17/22/main.cpp" "17/22/header.hpp" "17/22/source.cpp")
add_executable("ctci6_17_23" "17/23/main.cpp" "17/23/header.hpp" "17/23/source.cpp")
add_executable("ctci6_17_24" "17/24/main.cpp" "17/24/header.hpp" "17/24/source.cpp")
add_executable("ctci6_17_25" "17/25/main.cpp" "17/25/header.hpp" "17/25/source.cpp")
add_executable("ctci6_17_26" "17/26/main.cpp" "17/26/header.hpp" "17/26/source.cpp")
