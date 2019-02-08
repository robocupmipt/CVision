#pragma once
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alproxies/alvideodeviceproxy.h>

#include "balldetector.h"
#include "markdetector.h"

namespace AL
{
  class ALBroker;
}

class KernelCV {
 public:
  KernelCV(boost::shared_ptr<AL::ALBroker> broker_);

 private:
  void ReadImages();

 private:
  AL::ALVideoDeviceProxy camera_proxy_;
  std::string first_camera_client_;
  std::string second_camera_client_;

  BallDetector ball_d_;
  MarkDetector mark_d_;

  cv::InputArray last_image_;
};
