cmake_minimum_required(VERSION 3.24)

project(WindowsUI)

add_subdirectory(Win32.Minimal)

# MFC is only supported by MSVC
if(MSVC)
    add_subdirectory(MFC.Minimal)
endif()