#pragma once
#include "kernelcv.h"
#include "configdefinitions.h"
#include "thread"

KernelCV::KernelCV(boost::shared_ptr <AL::ALBroker> broker_) :
    cfgs_({LOWER_CAMERA, UPPER_CAMERA}),
    message_(FROM_VISION_TO_LOCALIZATION, FROM_LOCALIZATION_TO_VISION) {
  for (auto cfg : cfgs_) {
    cameras_.push_back(CameraHolder(cfg, broker_));
  }
}

std::vector <Point> KernelCV::DetectBalls() {
  return cameras_[0].DetectBalls(true);
}

void KernelCV::StartModule() {
  std::thread receive([&]() {
    SendLoop();
  });

  receive.detach();
}


/********* PRIVATE SPACE *********/


void KernelCV::SendLoop() {
  std::cout << "start sending loop\n";

  while(true) {
    MessageType<Send> outcome_message;
    outcome_message.data.p = Point(0, 0);
    std::cout << "READY TO SEND\n";
    message_.SendMessage(outcome_message);
    std::cout << "SUCCESSFULLY SEND\n";
  }
}