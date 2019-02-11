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
  /* return an image from lower camera if cam_num eq 0
   * and return from upper camera otherwise
   */
  cv::Mat GetImageFromCamera(size_t cam_num);

 private:
  AL::ALVideoDeviceProxy camera_proxy_;
  std::string lower_camera_client_;
  std::string upper_camera_client_;

  BallDetector ball_d_;
  MarkDetector mark_d_;

  cv::InputArray last_image_;
};
