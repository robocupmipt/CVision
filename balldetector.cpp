#pragma once
#include "balldetector.h"

BallDetector::BallDetector(const CameraConfig &cfg) : config_(cfg) {}

AL::ALValue BallDetector::Detect(cv::Mat image) {
  return 0;
}