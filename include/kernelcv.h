#pragma once
#include "cameraholder.h"

#include "channels.h"
#include "custom.h"
#include "message.h"

using namespace message;

class KernelCV {
 public:
  KernelCV(boost::shared_ptr <AL::ALBroker> broker_);

  std::vector <Point> DetectBalls();

  void StartModule();

 private:
  void SendLoop();

 private:
  std::vector <CameraConfig> cfgs_;
  std::vector <CameraHolder> cameras_;
  Message<MessageType<Send>, MessageType<Receive>> message_;
};
