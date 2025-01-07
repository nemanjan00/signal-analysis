cmake_minimum_required(VERSION 3.16)

project(SignalAnalysis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SignalAnalysis
	src/main.cpp
)

# pkg-config
find_package(PkgConfig REQUIRED)

# OpenGL

find_package(OpenGL REQUIRED)

# GLFW

find_package(glfw3 REQUIRED)
target_link_libraries(SignalAnalysis PRIVATE glfw)

# HackRF
pkg_check_modules(HACKRF REQUIRED libhackrf)
target_include_directories(SignalAnalysis PRIVATE ${HACKRF_INCLUDE_DIRS})
link_directories(${HACKRF_LIBRARY_DIRS})

# ImGUI
add_library(imgui STATIC
	imgui/imgui.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_tables.cpp
	imgui/imgui_widgets.cpp
	imgui/backends/imgui_impl_glfw.cpp	  # or SDL
	imgui/backends/imgui_impl_opengl3.cpp # or Vulkan, DX, etc.
)

target_include_directories(imgui PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/imgui
	${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
)

target_link_libraries(SignalAnalysis PRIVATE ${HACKRF_LIBRARIES} imgui glfw OpenGL::GL)
