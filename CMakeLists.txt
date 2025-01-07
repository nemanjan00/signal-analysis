cmake_minimum_required(VERSION 3.16)

project(SignalAnalysis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_subdirectory("core")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(SignalAnalysis
	src/main.cpp
	src/MainWindow.cpp
	src/MainWindow.h
)

set_target_properties(SignalAnalysis PROPERTIES
	AUTOMOC ON
	AUTOUIC ON
	AUTORCC ON
)

target_link_libraries(SignalAnalysis PRIVATE Qt6::Widgets)
