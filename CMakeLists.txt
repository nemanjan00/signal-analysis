cmake_minimum_required(VERSION 3.16)

project(SignalAnalysis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)

pkg_check_modules(HACKRF REQUIRED libhackrf)
target_include_directories(SignalAnalysis PRIVATE ${HACKRF_INCLUDE_DIRS})
link_directories(${HACKRF_LIBRARY_DIRS})

target_link_libraries(SignalAnalysis PRIVATE ${HACKRF_LIBRARIES})
