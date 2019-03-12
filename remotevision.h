#pragma once
#include "kernelcv.h"


class RemoteVision : public AL::ALModule {
 public:
  RemoteVision(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

  void virtual init();

  void ShowImage();

  void SnapImage();

  void OpenImage();

  void SaveImage();

  template <typename T=std::string>
  T SmallLog(const std::string text, size_t deep_level, bool is_reply=false) const;

 private:
  void SetBuff(const cv::Mat& img);

  void ReleaseBuff();

 private:
  cv::Mat* image_buf_;
  KernelCV kernel_;
};