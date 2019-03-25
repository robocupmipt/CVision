#pragma once
#include "config.h"


class BallDetector {
 public:
  BallDetector(const CameraConfig& cfg);

  AL::ALValue Detect(cv::Mat image);

 private:
  AL::ALValue Rect2ALValue(const cv::Rect& ball);

 private:
  const CameraConfig config_;
  std::vector <cv::CascadeClassifier> ball_finders_;
};