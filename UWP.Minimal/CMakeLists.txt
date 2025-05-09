cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME UWP.Minimal)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Windows 10 SDK support
set(CMAKE_SYSTEM_VERSION 10.0)

# Add the project with the specified sources
project(${PROJECT_NAME})

# Source files
set(SOURCE_FILES
    src/App.cpp
    src/App.h
    src/MainPage.cpp
    src/MainPage.h
    src/pch.cpp
    src/pch.h
)

# XAML files (needs to be preprocessed)
set(XAML_FILES
    src/App.xaml
    src/MainPage.xaml
)

# Create the executable
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES} ${XAML_FILES})

# Set target properties for UWP
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_WINRT_COMPONENT TRUE)

# Set the app as a Universal Windows app
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "WindowsApp"
    VS_GLOBAL_APPLICATIONTYPE_REV "10.0"
    VS_GLOBAL_APPCONTAINERPACKAGE "true"
)

# Set the app manifest
set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_WINRT_MANIFEST "src/Package.appxmanifest"
)

# Make sure to link against the required libraries
target_link_libraries(${PROJECT_NAME} PRIVATE
    WindowsApp.lib
)

# Installation rules
install(TARGETS ${PROJECT_NAME} DESTINATION bin)