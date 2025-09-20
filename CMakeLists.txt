cmake_minimum_required(VERSION 4.0)
project(BankAppQt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(BankAppQt src/main.cpp
        src/main.cpp
        include/pch.hpp
)
target_link_libraries(BankAppQt
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

