cmake_minimum_required(VERSION 3.5.0)
project(ReadyMario VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS
Widgets
Network
Sql
)

set(UI_FILES
about_dialog.cpp
loginwindow.cpp
)

QT5_WRAP_UI(UI_FILES)

add_executable(ReadyMario
main.cpp
mainwindow.cpp
settings.cpp
view.cpp
title.cpp
weatherstation.cpp
database.cpp
${UI_FILES}
mario.qrc
)

target_link_libraries (ReadyMario
Qt5::Widgets
Qt5::Network
Qt5::Sql
)
