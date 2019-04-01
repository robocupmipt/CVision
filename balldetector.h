#pragma once
#include "config.h"


class BallDetector {
 public:
  BallDetector(const CameraConfig& cfg);

  std::vector<cv::Rect> Detect(const cv::Mat& image);

 private:
  cv::Mat ToGray(const cv::Mat& img) const;

 private:
  const CameraConfig cfg_;
  std::vector <cv::CascadeClassifier> ball_finders_;
};