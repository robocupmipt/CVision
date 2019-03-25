#include "config.h"

class GoalDetector {
 public:
  BaseDetector(const CameraConfig& cfg);

  virtual AL::ALValue Detect(cv::InputArray image);

  CameraConfig config_;
};