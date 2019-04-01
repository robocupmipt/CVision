#include "config.h"

class GoalDetector {
 public:
  GoalDetector(const CameraConfig& cfg);

  AL::ALValue Detect(cv::InputArray image);

  CameraConfig config_;
};