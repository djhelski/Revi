cmake_minimum_required(VERSION 3.10)
project(BinSight)
set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CAPSTONE REQUIRED capstone)

include_directories(${CAPSTONE_INCLUDE_DIRS} include)
link_directories(${CAPSTONE_LIBRARY_DIRS})

add_executable(binsight src/main.cpp src/parser.cpp src/disassembler.cpp src/cfg_generator.cpp)
target_link_libraries(binsight ${CAPSTONE_LIBRARIES})
