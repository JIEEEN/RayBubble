cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME test)
project(${PROJECT_NAME})

set(RAYLIB_INCLUDE_DIRS /opt/homebrew/Cellar/raylib/5.0/include)
set(RAYLIB_LIBRARY /opt/homebrew/Cellar/raylib/5.0/lib/libraylib.dylib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${INCLUDE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${RAYLIB_INCLUDE_DIRS} ${INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE ${RAYLIB_LIBRARY})

target_compile_definitions(${PROJECT_NAME} PRIVATE -DPLATFORM_DESKTOP)