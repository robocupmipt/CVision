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

  /*
   * return an image from lower camera if cam_num eq 0
   * and return from upper camera otherwise
   */
  cv::Mat GetImageFromCamera(size_t cam_num);

  void PrintImageToFile(const cv::Mat& img, const std::string& filename);

 private:
  void SubscribeCamera(CameraConfig& cfg);

 private:
  AL::ALVideoDeviceProxy camera_proxy_;
  CameraConfig upper_camera_;
  CameraConfig lower_camera_;

  BallDetector ball_up_detector_;
  BallDetector ball_down_detector_;
  MarkDetector mark_up_detector_;
  MarkDetector mark_down_detector_;
};
