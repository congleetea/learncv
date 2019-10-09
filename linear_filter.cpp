#include <opencv2/opencv.hpp>

cv::Mat src_img, dst_img1, dst_img2, dst_img3;
int box_val = 3;
int blur_val = 3;
int gs_val = 3;

static void OnBoxFilter(int, void*) {
  cv::boxFilter(src_img, dst_img1, -1, cv::Size(box_val+1, box_val+1));
  cv::imshow("box", dst_img1);
}

static void OnBlurFilter(int, void*) {
  cv::blur(src_img, dst_img2, cv::Size(blur_val+1, blur_val+1));
  cv::imshow("blur", dst_img2);
}

static void OnGsFilter(int, void*) {
  cv::GaussianBlur(src_img, dst_img3, cv::Size(gs_val*2+1, gs_val*2+1), 0, 0);
  cv::imshow("gs", dst_img3);
}

int main() {
  src_img = cv::imread("../../images/beauty.jpg");
  cv::imshow("src", src_img);

  dst_img1 = src_img.clone();
  dst_img2 = src_img.clone();
  dst_img3 = src_img.clone();

  cv::namedWindow("box", 1);
  cv::createTrackbar("kernal", "box", &box_val, 40, OnBoxFilter);
  OnBoxFilter(box_val, 0);
  cv::imshow("box", dst_img1);

  cv::namedWindow("blur", 1);
  cv::createTrackbar("kernal", "blur", &blur_val, 40, OnBlurFilter);
  OnBlurFilter(blur_val, 0);
  cv::imshow("blur", dst_img2);

  cv::namedWindow("gs", 1);
  cv::createTrackbar("kernal", "gs", &gs_val, 40, OnGsFilter);
  OnBlurFilter(gs_val, 0);
  cv::imshow("gs", dst_img3);

  cv::waitKey(0); 
  return 0;
}
