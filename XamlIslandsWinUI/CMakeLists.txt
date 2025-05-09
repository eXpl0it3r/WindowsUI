cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME XamlIslandsApp)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Windows 10 SDK support
set(CMAKE_SYSTEM_VERSION 10.0)

# Add the project with the specified sources
project(${PROJECT_NAME})

# Source files
set(SOURCE_FILES
    src/main.cpp
    src/App.cpp
    src/App.h
    src/MainWindow.cpp
    src/MainWindow.h
)

# Create the executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

# Set the C++ preprocessor definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE
    _UNICODE
    UNICODE
    WINRT_LEAN_AND_MEAN
)

# Set include directories for the project
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link against required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    windowsapp.lib
    user32.lib
    gdi32.lib
    comctl32.lib
)

# Installation rules
install(TARGETS ${PROJECT_NAME} DESTINATION bin)