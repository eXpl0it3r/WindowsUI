cmake_minimum_required(VERSION 3.20)

project(Win32.Minimal)

add_executable(${PROJECT_NAME} WIN32 src/main.cpp src/Application.hpp src/Application.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)

target_link_options(${PROJECT_NAME} PRIVATE /ENTRY:mainCRTStartup)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)