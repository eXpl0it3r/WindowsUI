cmake_minimum_required(VERSION 3.24)

project(MFC.Minimal)

# Use MFC as static library
set(CMAKE_MFC_FLAG 2)

add_executable(${PROJECT_NAME} WIN32 src/Application.cpp src/Application.hpp src/Window.cpp src/Window.hpp src/Resource.hpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE _UNICODE _AFXDLL WINVER=0x0A00 _WIN32_WINNT=0x0A00)

target_link_options(${PROJECT_NAME} PRIVATE "/entry:wWinMainCRTStartup")

install(TARGETS ${PROJECT_NAME} DESTINATION .)