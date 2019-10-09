#include <opencv2/opencv.hpp>

int main() {
  // cv::Mat src_img = cv::imread("/home/congleetea/gitlab/qinglu/images/beauty.jpg");
  cv::Mat src_img = cv::imread("../../images/beauty.jpg");
  cv::imshow("src_img", src_img);

  cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15,15));
  cv::Mat ero_img;
  cv::erode(src_img, ero_img, element);
  cv::imshow("erosion", ero_img);

  cv::Mat jun_img;
  cv::blur(src_img, jun_img, cv::Size(7,7));
  cv::imshow("jun_img", jun_img);

  cv::Mat dst_img, edge, gray_img;
  // dst_img.create(src_img.size(), src_img.type());
  cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);
  cv::imshow("gray", gray_img);
  cv::blur(gray_img, edge, cv::Size(3,3));
  cv::imshow("blur", edge);
  cv::Canny(edge, edge, 3, 9, 3);
  cv::imshow("canny", edge);
  cv::waitKey(0);

  return 0;
}
