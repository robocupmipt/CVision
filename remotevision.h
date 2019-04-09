#pragma once
#include "kernelcv.h"


class RemoteVision : public AL::ALModule {
 public:
  RemoteVision(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

  void virtual init();

  void DetectBall();
  template <typename T=std::string>
  T SmallLog(const std::string text, size_t deep_level, bool is_reply=false) const;

 private:
  KernelCV kernel_;
};
