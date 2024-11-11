cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS
Widgets
)

add_executable(ReadyMario
main.cpp
mainwindow.cpp
settings.cpp
mario.qrc
)

target_link_libraries (ReadyMario
Qt5::Widgets
)
