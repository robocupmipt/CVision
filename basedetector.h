#include "config.h"

class BaseDetector {
 public:
  BaseDetector(const CameraConfig& cfg);

  virtual AL::ALValue Detect(cv::InputArray image);

  CameraConfig config_;
};