#pragma once
#include "kernelcv.h"
#include "configdefinitions.h"


KernelCV::KernelCV(boost::shared_ptr <AL::ALBroker> broker_) :
    cfgs_({LOWER_CAMERA, UPPER_CAMERA}), message_(FROM_VISION_TO_LOCALIZATION, FROM_LOCALIZATION_TO_VISION){
  for (auto cfg : cfgs_) {
    cameras_.push_back(CameraHolder(cfg, broker_));
  }
}

void KernelCV::DetectBall(size_t camera_index, bool use_debug) {
  cameras_[camera_index].DetectBall(use_debug);
}
