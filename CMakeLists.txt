cmake_minimum_required(VERSION 3.20)
project(cli_minigames VERSION 1.0.0 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/include")

add_subdirectory(src)
