cmake_minimum_required(VERSION 3.22.1)
project(tuigol)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME}
    src/main.cpp
    # src/gol.cpp
    # src/graphics.cpp
)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

