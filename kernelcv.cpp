#pragma once
#include "kernelcv.h"
#include "configdefinitions.h"


KernelCV::KernelCV(boost::shared_ptr <AL::ALBroker> broker_) :
    camera_proxy_(broker_),
    ball_up_detector_(UPPER_CAMERA),
    ball_down_detector_(LOWER_CAMERA),
    mark_up_detector_(UPPER_CAMERA),
    mark_down_detector_(LOWER_CAMERA),
    upper_camera_(UPPER_CAMERA),
    lower_camera_(LOWER_CAMERA) {

  SubscribeCamera(upper_camera_);
  SubscribeCamera(lower_camera_);
}

cv::Mat KernelCV::GetImageFromCamera(size_t cam_num) {
  const CameraConfig& cfg = (cam_num == AL::kTopCamera ? upper_camera_: lower_camera_);

  AL::ALValue al_img;
#ifdef CVISION_IS_REMOTE
  al_img = camera_proxy_.getImageRemote(cfg.camera_client);
#else
  al_img = camera_proxy_.getImageLocal(cfg.camera_client);
#endif

  cv::Mat img_header = cv::Mat(cfg.resolution_size, CV_8UC3);
  img_header.data = (uchar*) al_img[6].GetBinary();
  camera_proxy_.releaseImage(cfg.camera_client);

  return img_header;
}

void KernelCV::PrintImageToFile(const cv::Mat& img, const std::string& filename) {
  cv::imwrite(filename, img);
}


/********* PRIVATE SPACE *********/


void KernelCV::SubscribeCamera(CameraConfig& cfg) {
  cfg.camera_client = camera_proxy_.subscribeCamera(cfg.name,
                                                    cfg.id,
                                                    cfg.resolution,
                                                    cfg.colorspaces,
                                                    cfg.fps);
}