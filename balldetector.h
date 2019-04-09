#pragma once
#include "config.h"


class BallDetector {
 public:
  BallDetector(const CameraConfig& cfg);

  AL::ALValue Detect(const cv::Mat& image);

 private:
  AL::ALValue Rect2Point(const cv::Rect& r) const;

 private:
  const CameraConfig cfg_;
  std::vector <cv::CascadeClassifier> ball_finders_;
};