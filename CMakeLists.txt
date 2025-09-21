cmake_minimum_required(VERSION 3.10) # Updated to a more modern version
project(BankAppQt)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find pkg-config and libsodium
find_package(PkgConfig REQUIRED)
pkg_check_modules(SODIUM REQUIRED libsodium)

# Find Qt6 components
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

# Define the executable
add_executable(BankAppQt
        src/main.cpp
        include/pch.hpp
        src/login_signup.cpp
        include/Qt_DB_Utils.hpp
        src/Qt_DB_Utils.cpp
        include/login_signup.hpp
)

# Link libraries
target_link_libraries(BankAppQt
        PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Sql
        ${SODIUM_LIBRARIES}
)

# Include directories for libsodium
target_include_directories(BankAppQt
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${SODIUM_INCLUDE_DIRS}
)

# Apply any additional compiler flags from libsodium
target_compile_options(BankAppQt
        PRIVATE
        ${SODIUM_CFLAGS_OTHER}
)