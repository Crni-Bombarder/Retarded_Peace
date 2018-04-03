COMPIL_ATTR = '-std=c++11'
OPENCV=`pkg-config --cflags --libs opencv`

test_opencv :
	g++ $(COMPIL_ATTR) -o build/test_opencv src/test_opencv/main.cpp $(OPENCV)
