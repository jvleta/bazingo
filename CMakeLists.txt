cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Bazingo2)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES
    src/main.cpp
    src/utils.cpp
    src/Square.cpp
    src/Column.cpp
    src/Card.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(Bazingo2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
