#pragma once
#include "kernelcv.h"
#include "configdefinitions.h"


KernelCV::KernelCV(boost::shared_ptr <AL::ALBroker> broker_) :
    cfgs_({LOWER_CAMERA, UPPER_CAMERA}){
  for (auto cfg : cfgs_) {
    cameras_.push_back(CameraHolder(cfg, broker_));
  }
}

void KernelCV::DetectBall(size_t camera_index, bool use_debug) {
  cameras_[camera_index].DetectBalls(use_debug);
}