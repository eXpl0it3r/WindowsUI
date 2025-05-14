cmake_minimum_required(VERSION 3.24)

project(WTL.Minimal)

include(FetchContent)
FetchContent_Declare(
    wtl
    GIT_REPOSITORY https://git.code.sf.net/p/wtl/git
    GIT_TAG master
)
FetchContent_MakeAvailable(wtl)

add_executable(${PROJECT_NAME} WIN32 
    src/main.cpp 
    src/Application.hpp 
    src/Application.cpp
    src/Window.hpp
    src/Window.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD_REQUIRED ON)

# Use main() entry point
if(MSVC)
    target_link_options(${PROJECT_NAME} PRIVATE /ENTRY:mainCRTStartup)
else()
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,--entry=mainCRTStartup)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE ${wtl_SOURCE_DIR}/Include)

target_compile_definitions(${PROJECT_NAME} PRIVATE UNICODE _UNICODE _WTL_USE_CSTRING)

install(TARGETS ${PROJECT_NAME} DESTINATION .)