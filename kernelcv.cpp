#pragma once
#include "kernelcv.h"
#include "configdefinitions.h"


KernelCV::KernelCV(boost::shared_ptr <AL::ALBroker> broker_) :
    camera_proxy_(broker_),
    ball_up_detector_(UPPER_CAMERA),
    ball_down_detector_(LOWER_CAMERA),
    mark_up_detector_(UPPER_CAMERA),
    mark_down_detector_(LOWER_CAMERA) {

  const int fps = 30;
  lower_camera_client_ = camera_proxy_.subscribeCamera(LOWER_CAMERA.name,
                                                       LOWER_CAMERA.id,
                                                       LOWER_CAMERA.resolution,
                                                       LOWER_CAMERA.colorspaces,
                                                       LOWER_CAMERA.fps);
  upper_camera_client_ = camera_proxy_.subscribeCamera(UPPER_CAMERA.name,
                                                       UPPER_CAMERA.id,
                                                       UPPER_CAMERA.resolution,
                                                       UPPER_CAMERA.colorspaces,
                                                       UPPER_CAMERA.fps);
}

cv::Mat KernelCV::GetImageFromCamera(size_t cam_num) {
  std::string camera_client = (cam_num ? upper_camera_client_ : lower_camera_client_);

  AL::ALValue al_img;
#ifdef CVISION_IS_REMOTE
  al_img = camera_proxy_.getImageRemote(camera_client);
#else
  al_img = camera_proxy_.getImageLocal(camera_client);
#endif

  cv::Mat img_header = cv::Mat(cv::Size(1280, 960), CV_8UC3);
  img_header.data = (uchar*) al_img[6].GetBinary();
  camera_proxy_.releaseImage(camera_client);

  return img_header;
}

void KernelCV::PrintImageToFile(const cv::Mat& img, const std::string& filename) {
  cv::imwrite(filename, img);
}

