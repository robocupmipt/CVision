#pragma once

#include "kernelcv.h"


class RemoteVision : public AL::ALModule {
 public:
  RemoteVision(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

  void virtual init();

 private:
  KernelCV kernel_;
};