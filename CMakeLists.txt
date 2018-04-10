cmake_minimum_required(VERSION 2.6)

#Declaration du projet

project(Retarded_Peace)

set(EXECUTABLE_OUTPUT_PATH bin)

include_directories(include)

file(
        GLOB_RECURSE
        source_files
        src/*
        include/*
)

#Declaration des executables

add_executable(
  test_opencv
  src/test_opencv/main.cpp
)
