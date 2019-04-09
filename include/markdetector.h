#pragma once
#include "config.h"


class MarkDetector {
 public:
  MarkDetector(const CameraConfig& cfg);

  AL::ALValue Detect(cv::Mat image);

 private:
  CameraConfig config_;
};