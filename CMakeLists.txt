cmake_minimum_required(VERSION 2.6)

#Declaration du projet

project(Retarded_Peace)

set(EXECUTABLE_OUTPUT_PATH bin)
add_compile_options(-std=c++11)

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

add_executable(
    test_imagePalier0
    src/palier0/testImage.cpp
)

add_executable(
        test_tilePalier0
        src/palier0/testTile.cpp
)

add_executable(
        test_mapPalier0
        src/palier0/testMap.cpp
)

add_executable(
        test_vectorimagePalier0
        src/palier0/testVectorimage.cpp
)

add_library(SOURCES src/color.cpp src/image.cpp src/window.cpp src/tile.cpp src/map.cpp src/vector_image.cpp)

target_link_libraries(SOURCES ${OpenCV_LIBS})
target_link_libraries(test_opencv ${OpenCV_LIBS})
target_link_libraries(test_colorPalier0 ${OpenCV_LIBS} SOURCES)
target_link_libraries(test_imagePalier0 ${OpenCV_LIBS} SOURCES)
target_link_libraries(test_tilePalier0 ${OpenCV_LIBS} SOURCES)
target_link_libraries(test_mapPalier0 ${OpenCV_LIBS} SOURCES)
target_link_libraries(test_vectorimagePalier0 ${OpenCV_LIBS} SOURCES)
