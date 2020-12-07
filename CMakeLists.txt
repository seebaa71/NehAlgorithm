cmake_minimum_required(VERSION 3.13)
project(NehAlgorithm)
set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)
set(
        SOURCE_FILES
        main.cpp
        include/job.h src/job.cpp include/functionsOfAlg.h src/functionsOfAlg.cpp)
add_executable(NehAlgorithm ${SOURCE_FILES} include/job.h src/job.cpp include/functionsOfAlg.h src/functionsOfAlg.cpp)