#pragma once
#include "config.h"
#include "geometry.h"

class BallDetector {
 public:
  BallDetector(const CameraConfig& cfg);

  std::vector <Point> Detect(const cv::Mat& image);

 private:
  Point Rect2Point(const cv::Rect& r) const;

 private:
  const CameraConfig cfg_;
  std::vector <cv::CascadeClassifier> ball_finders_;
};