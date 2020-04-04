cmake_minimum_required(VERSION 3.5)

project(app VERSION 1.0 LANGUAGES CXX)

set(PROJECT_NAME "mq-plugins")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(PLUGIN_DIR ${CMAKE_BINARY_DIR}/bin/plugins)

option(BUILD_SHARED_LIBS "Build all libraries as shared libraries instead of static" OFF)

find_package(Qt5 REQUIRED COMPONENTS Quick Core Qml)

#add_subdirectory(3rdparty)
add_subdirectory(lib)
# build "lib" then
#add_subdirectory(test)
add_subdirectory(plugins)
add_subdirectory(src)
