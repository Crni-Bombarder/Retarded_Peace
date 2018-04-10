COMPIL_ATTR = '-std=c++11'
OPENCV=`pkg-config --cflags --libs opencv`

test_opencv :
	g++ $(COMPIL_ATTR) -o bin/test_opencv src/test_opencv/main.cpp $(OPENCV)

palier0_all : color.o display.o game.o image.o map.o tile.o vector_image.o window.o main_palier0.o
	g++ $(COMPIL_ATTR) -o bin/palier0 build/color.o build/display.o build/game.o build/image.o build/map.o build/tile.o build/vector_image.o build/window.o build/main_palier0.o $(OPENCV)

palier0_test_color : color.o test_color0.o
	g++ $(COMPIL_ATTR) -o bin/palier0_test_color build/color.o build/test_color0.o $(OPENCV)

color.o :
	g++ $(COMPIL_ATTR) -c -o build/color.o src/color.cpp $(OPENCV)

display.o :
	g++ $(COMPIL_ATTR) -c -o build/diplay.o src/display.cpp $(OPENCV)

game.o :
	g++ $(COMPIL_ATTR) -c -o build/game.o src/game.cpp $(OPENCV)

image.o :
	g++ $(COMPIL_ATTR) -c -o build/image.o src/image.cpp $(OPENCV)

map.o :
	g++ $(COMPIL_ATTR) -c -o build/map.o src/map.cpp $(OPENCV)

tile.o :
	g++ $(COMPIL_ATTR) -c -o build/tile.o src/tile.cpp $(OPENCV)

vector_image.o :
	g++ $(COMPIL_ATTR) -c -o build/vector_image.o src/vector_image.cpp $(OPENCV)

window.o :
	g++ $(COMPIL_ATTR) -c -o build/window.o src/window.cpp $(OPENCV)

main_palier0.o :
	g++ $(COMPIL_ATTR) -c -o build/main_palier0.o src/palier0/main.cpp $(OPENCV)

test_color0.o :
	g++ $(COMPIL_ATTR) -c -o build/test_color0.o src/palier0/testColor.cpp $(OPENCV)
