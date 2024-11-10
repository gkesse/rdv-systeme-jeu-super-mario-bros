cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED COMPONENTS
Widgets
)

add_executable(ReadyMario
main.cpp
mario.qrc
)

target_link_libraries (ReadyMario
Qt5::Widgets
)
