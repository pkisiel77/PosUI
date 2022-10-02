cmake_minimum_required(VERSION 3.20)
project(PosUI)

set(CMAKE_CXX_STANDARD 17)

add_executable(PosUI main.cpp TUI/CursesTUI.cpp TUI/CursesTUI.h TUI/WindowsTUI.cpp TUI/WindowsTUI.h)
