#pragma once
#include "cameraholder.h"

#include"Channels.h"
#include"Custom.h"
#include"Message.h"

using namespace message;

class KernelCV {
 public:
  KernelCV(boost::shared_ptr <AL::ALBroker> broker_);

  void DetectBall(size_t camera_index, bool use_debug=false);

 private:
  std::vector <CameraConfig> cfgs_;
  std::vector <CameraHolder> cameras_;
  Message<MessageType<Send>, MessageType<Receive>> message_;
};
