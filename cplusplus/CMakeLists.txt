cmake_minimum_required(VERSION 3.1)
project(cplusplus)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -O2 -Wextra -pthread")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(serial src/serial.cpp)
target_include_directories(serial PRIVATE include)
target_link_libraries(serial PRIVATE Threads::Threads)

add_executable(threaded src/threaded.cpp)
target_include_directories(threaded PRIVATE include)
target_link_libraries(serial PRIVATE Threads::Threads)

add_executable(randomseq src/randomseq.cpp)
add_executable(runTests src/runTests.cpp)