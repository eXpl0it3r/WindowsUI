cmake_minimum_required(VERSION 3.24)

project(Win32.Minimal)

add_executable(${PROJECT_NAME} WIN32 src/main.cpp src/Application.hpp src/Application.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)

# Use main() entry point
if(MSVC)
    target_link_options(${PROJECT_NAME} PRIVATE /ENTRY:mainCRTStartup)
else()
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,--entry=mainCRTStartup)
endif()

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE)

install(TARGETS ${PROJECT_NAME} DESTINATION .)