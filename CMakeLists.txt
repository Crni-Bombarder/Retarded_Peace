cmake_minimum_required(VERSION 2.6)

#Declaration du projet

project(Retarded_Peace)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

set(EXECUTABLE_OUTPUT_PATH bin)
add_compile_options(-std=c++11)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


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

add_executable(
        test_windowPalier0
        src/palier0/testWindow.cpp
)

add_executable(
        test_displayPalier0
        src/palier0/testDisplay.cpp
)

add_executable(
        palier0
        src/palier0/main.cpp
)

add_executable(
        test_unitPalier1
        src/palier1/testunit.cpp
)

add_library(SOURCES src/color.cpp
                    src/image.cpp
                    src/window.cpp
                    src/tile.cpp
                    src/map.cpp
                    src/vector_image.cpp
                    src/rect.cpp
                    src/terrain.cpp
                    src/display.cpp
                    src/game.cpp
                    src/unit.cpp
                    src/typeunit.cpp
                    src/genericinfantry.cpp
                    src/genericartillery.cpp
                    src/player.cpp)

target_link_libraries(SOURCES ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(test_opencv ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(test_colorPalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(test_imagePalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(test_tilePalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(test_mapPalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(test_vectorimagePalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(test_windowPalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(test_displayPalier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
target_link_libraries(palier0 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)

target_link_libraries(test_unitPalier1 ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} SOURCES)
