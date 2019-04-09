#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alproxies/alvideodeviceproxy.h>

#include "balldetector.h"
#include "goaldetector.h"
#include "markdetector.h"

namespace AL
{
class ALBroker;
}


class CameraHolder {
 public:
  CameraHolder(const CameraConfig& cfg, boost::shared_ptr<AL::ALBroker> broker_);

  std::vector <Point> DetectBalls(bool use_debug=false);

 private:
  void SubscribeCamera();
  void UpdateImage();

 private:
  AL::ALVideoDeviceProxy camera_proxy_;
  CameraConfig cfg_;
  cv::Mat last_img_;

  BallDetector b_detect_;
  GoalDetector g_detect_;
  MarkDetector m_detect_;
};


/*
void CameraHolder::PrintImageToFile(const cv::Mat& img, const std::string& filename) {
  cv::imwrite(filename, img);
}
*/


