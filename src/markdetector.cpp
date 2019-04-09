#pragma once
#include "markdetector.h"

MarkDetector::MarkDetector(const CameraConfig &cfg) : config_(cfg) {}

AL::ALValue MarkDetector::Detect(cv::Mat image) {
  return 0;
}