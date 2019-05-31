#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
using namespace std;
using namespace cv;

int main(int argc, char **argv) {
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle n;
  image_transport::ImageTransport it(n); // new
  image_transport::Publisher pub0 = it.advertise("chatter0", 1);
  cv::VideoCapture cap0(0);
  if(!cap0.isOpened()) return 1;
  cv::Mat frame0;
  sensor_msgs::ImagePtr msg0; // will be copy

  image_transport::Publisher pub1 = it.advertise("chatter1", 1);
  cv::VideoCapture cap1("http://admin:@192.168.1.101/videostream.cgi?[?rate=6]");
  if(!cap1.isOpened()) return 1;
  cv::Mat frame1;
  sensor_msgs::ImagePtr msg1; // will be copy

  image_transport::Publisher pub2 = it.advertise("chatter2", 1);
  cv::VideoCapture cap2("http://admin:@192.168.1.102/videostream.cgi?[?rate=6]");
  if(!cap2.isOpened()) return 1;
  cv::Mat frame2;
  sensor_msgs::ImagePtr msg2; // will be copy


  ros::Rate loop_rate(1000);
  while (n.ok()) {
    cap0 >> frame0;
    cap1 >> frame1;
    cap2 >> frame2;
    if(!frame0.empty()) {
      msg0 = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame0).toImageMsg();
      pub0.publish(msg0);
  	}
    if(!frame1.empty()) {
      msg1 = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame1).toImageMsg();
      pub1.publish(msg1);
  	}
    if(!frame2.empty()) {
      msg2 = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame2).toImageMsg();
      pub2.publish(msg2);
  	}
    ros::spinOnce();
    loop_rate.sleep();
  }
  	return 0;
}
