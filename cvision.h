#pragma once

#include "kernalcv.h"


class CVision: public AL::ALModule {
 public:
  CVision(boost::shared_ptr<AL::ALBroker> pBroker, const std::string& pName);

  AL::ALValue GetBall();

  AL::ALValue GetLines();

  AL::ALValue GetGate();

 private:
  KernelCV kernel_;
};