#include "opencv2/opencv.hpp"
#include "ros/ros.h"

using namespace std;
using namespace cv;

int main(int argc, char** argv){
    ros::init(argc, argv, "showcam");
    ros::NodeHandle n;
    ros::Rate loop_rate(100);

    VideoCapture cap(0); // Can also use CV_CAP_ANY instead of 0
    if(!cap.isOpened()){
        cout << "Error al abrir el dispositivo" << endl;
        return -1;
    }
    //cout << "Listo" << endl;
    //double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    //double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    //cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    while(ros::ok())
    {
        Mat image;
        cap >> image; // You can also use:  cap.read(image);
        imshow("Source", image);

//
// Aqui pegaremos más código después
//

        waitKey(1); // Draw image and wait 1 milisecond
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
