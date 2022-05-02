// #include "opencv2/opencv.hpp"
// #include <opencv2/core.hpp>
#include <opencv2/video/video.hpp>
// #include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
// #include <stdio.h>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    VideoCapture cap(0);
    if (cap.isOpened()){
        cout << "Error opening webcam" <<endl;
    }

    int frame_width = cap.get(CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CAP_PROP_FRAME_HEIGHT);
    
    VideoWriter video("webcam.avi",VideoWriter::fourcc('M','J','P','G'),30, Size(frame_width,frame_height),true);

    while (1){
        Mat frame;
        cap >> frame;
        if (frame.empty())
            break;
        video.write(frame);
        imshow("webcam",frame);

        char c =(char)waitKey(1);
        if (c ==27)
            break;


    }
    cap.release();
    video.release();
    
    destroyAllWindows();
    return 0;
}