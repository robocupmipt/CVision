#include "kernelcv.h"

KernelCV::KernelCV(boost::shared_ptr <ALBroker> broker_) : camera_proxy_(broker_) {
  lower_camera_client_ = camera_proxy_.subscribe(LOWER_CAMERA.name, AL::kVGA, AL::kRGBColorSpace, 30);
  upper_camera_client_ = camera_proxy_.subscribe(UPPER_CAMERA.name, AL::kVGA, AL::kRGBColorSpace, 30);
}

void KernelCV::ReadImages() {
  AL::ALValue al_img;

  while (true) {
#ifdef CVISION_IS_REMOTE
    al_img = cam_proxy_->getImageRemote(camera_client_);
#else
    al_img = cam_proxy_->getImageRemote(camera_client_);
#endif

    cv::Mat img_header = cv::Mat(cv::Size(320, 240), CV_8UC3);
    img_header.data = (uchar*) al_img[6].GetBinary();
    cam_proxy_->releaseImage(camera_client_);


  }
}


cv::Mat KernelCV::GetImageFromCamera(size_t cam_num) {
  std::string camera_client = cam_num ? upper_camera_client_ : lower_camera_client_;


}

