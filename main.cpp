#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define DELAY 1
#define ESC_KEY 27

int main() {
    CascadeClassifier cascade;
    cascade.load("../haarcascade_frontalface_default.xml");
    VideoCapture capture;
    capture.open("../splean.mp4");
    if (!capture.isOpened()){
        printf("Incorrect capture name.\n"); return 1;
    }
    namedWindow("video");
    char key = -1;
    Mat image, gray;
    vector<Rect> objects;
// получение кадра видеопотока
    capture >> image;
    while (image.data != 0 && key != ESC_KEY)
    {
        cvtColor(image, gray, CV_BGR2GRAY);
        cascade.detectMultiScale(gray, objects);
        for (int i = 0; i < objects.size(); i++)
        {
            rectangle(image,
                      Point(objects[i].x, objects[i].y),
                      Point(objects[i].x+objects[i].width,
                            objects[i].y+objects[i].height),
                      CV_RGB(255, 0, 0), 2);
        }
        imshow("video", image);
        key = waitKey(DELAY);
        capture >> image;
        gray.release();
        objects.clear();
    }
    capture.release();
    return 0;
}