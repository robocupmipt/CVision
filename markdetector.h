#include "opencv2/core.hpp"
#include "opencv2/objdetect.hpp"
#include "basedetector.h"


class MarkDetector : public BaseDetector {
 public:
  AL::ALValue Detect(cv::InputArray image);
 private:
};