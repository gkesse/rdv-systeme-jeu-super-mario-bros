cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS
Widgets
Network
)

QT5_WRAP_UI(
about_dialog.ui
)

add_executable(ReadyMario
main.cpp
mainwindow.cpp
settings.cpp
view.cpp
title.cpp
about_dialog.cpp
weatherstation.cpp
mario.qrc
)

target_link_libraries (ReadyMario
Qt5::Widgets
Qt5::Network
)
