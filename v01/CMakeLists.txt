cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)

find_package(Qt5 REQUIRED COMPONENTS
Widgets
)

add_executable(ReadyMario main.cpp)

target_link_libraries (ReadyMario
Qt5::Widgets
)
