#include <cv.h>
#include <highgui.h>

#include <iostream>
#include <string>

#define H_SCREEN 200
#define W_SCREEN 200
#define H_OBJECT 50
#define W_OBJECT 50
#define X_OBJECT 20
#define Y_OBJECT 10

using namespace cv;

using namespace std;

int main(int argc, char const *argv[]) {
  String imageName("src/test_opencv/textures/test.jpg");
  Mat screen = Mat(H_SCREEN, W_SCREEN, CV_8UC3);
  Mat object;
  object = imread(imageName, IMREAD_COLOR);
  if(object.empty())
  {
    cout << "Erreur de chargement de l'image" << endl;
    return -1;
  }
  resize(object, object, Size(H_OBJECT, W_OBJECT));
  object.copyTo(screen(Rect(X_OBJECT, Y_OBJECT, object.cols, object.rows)));
  namedWindow("Test Window", WINDOW_AUTOSIZE);
  imshow("Test Window", screen);
  waitKey(0);
  return 0;
}
