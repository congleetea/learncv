#include <opencv2/opencv.hpp>

int main() {
  cv::VideoCapture capture(0);
  // cv::VideoCapture capture("1.avi");
  cv::Mat edges, edges1;
  while(1) {
    cv::Mat frame;
    capture >> frame;
    
    cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);
    cv::blur(edges, edges, cv::Size(7,7));
    cv::Canny(edges, edges, 0, 30, 3);
    edges1 = edges(cv::Rect(100, 100, 200, 200));
    cv::imshow("video", edges);
    cv::imshow("video_roi", edges1);
    if(cv::waitKey(30) >= 0) break;
  }
  return 0;
}
