#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void imageCallback0(const sensor_msgs::ImageConstPtr& msg) {
  cv::imshow("Endoscopica", cv_bridge::toCvShare(msg, "bgr8")->image);
  cv::waitKey(30);
}
void imageCallback1(const sensor_msgs::ImageConstPtr& msg) {
  cv::imshow("IP1", cv_bridge::toCvShare(msg, "bgr8")->image);
  cv::waitKey(30);
}
void imageCallback2(const sensor_msgs::ImageConstPtr& msg) {
  cv::imshow("IP2", cv_bridge::toCvShare(msg, "bgr8")->image);
  cv::waitKey(30);
}
int main(int argc, char **argv) {
  ros::init(argc, argv, "image_listener");
  ros::NodeHandle n;
  cv::namedWindow("Endoscopica");
  namedWindow("IP1", WINDOW_NORMAL );
  namedWindow("IP2", WINDOW_NORMAL );

  resizeWindow("IP1", 640, 480);
  resizeWindow("IP2", 640, 480);
  cv::startWindowThread(); // recommended
  image_transport::ImageTransport it(n);
  image_transport::Subscriber sub0 = it.subscribe("chatter0",1,imageCallback0);
  image_transport::Subscriber sub1 = it.subscribe("chatter1",1,imageCallback1);
  image_transport::Subscriber sub2 = it.subscribe("chatter2",1,imageCallback2);
  ros::spin();
  cv::destroyWindow("Endoscopica");
  cv::destroyWindow("IP1");
  cv::destroyWindow("IP2");
  return 0;
}
