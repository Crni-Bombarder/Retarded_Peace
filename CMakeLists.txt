cmake_minimum_required(VERSION 2.6)

#Declaration du projet

project(Retarded_Peace)

set(EXECUTABLE_OUTPUT_PATH bin)

find_package(OpenCV REQUIRED)

include_directories(src/headers)

file(
        GLOB_RECURSE
        source_files
        src/*
        src/headers/*
)

#Declaration des executables

add_executable(
  test_opencv
  src/test_opencv/main.cpp
)

add_executable(
    test_colorPalier0
    src/palier0/testColor.cpp
)

add_library(SOURCES src/color.cpp)

target_link_libraries(SOURCES ${OpenCV_LIBS})
target_link_libraries(test_opencv ${OpenCV_LIBS})
target_link_libraries(test_colorPalier0 ${OpenCV_LIBS} SOURCES)
