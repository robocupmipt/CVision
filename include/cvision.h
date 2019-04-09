#pragma once
#include "kernelcv.h"


class CVision: public AL::ALModule {
 public:
  CVision(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

 private:
  KernelCV kernel_;
};