#pragma once

#include "kernalcv.h"


class RemoteVision : public AL::ALModule {
 public:
  RemoteVision(boost::shared_ptr<AL::ALBroker> pBroker, const std::string& pName);

  void virtual init();

 private:
  KernelCV kernel_;
};