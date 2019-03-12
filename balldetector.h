#pragma once
#include "config.h"


class BallDetector {
 public:
  BallDetector(const CameraConfig& cfg);

  AL::ALValue Detect(cv::Mat image);

 private:
  CameraConfig config_;
};