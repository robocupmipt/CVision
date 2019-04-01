#include "cameraholder.h"

CameraHolder::CameraHolder(const CameraConfig& cfg, boost::shared_ptr<AL::ALBroker> broker_) :
    b_detect_(cfg), g_detect_(cfg), m_detect_(cfg),
    cfg_(cfg), camera_proxy_(broker_) {
  SubscribeCamera();
}


void CameraHolder::DetectBall(bool use_debug) {
  UpdateImage();

  std::string path = "imgs/" + cfg_.name;
  if (use_debug) {
    cv::imwrite(path + "(before).jpg", last_img_);
  }

  auto balls = b_detect_.Detect(cv::Mat(last_img_.clone()));

  cv::Mat img_with_balls(last_img_.clone());
  for (auto& ball : balls) {
    cv::rectangle(img_with_balls, ball, cv::Scalar( 0, 255, 255 ));
  }

  if (use_debug) {
    cv::imwrite(path + "(after).jpg", img_with_balls);
  }
}

/********* PRIVATE SPACE *********/


void CameraHolder::SubscribeCamera() {
  cfg_.camera_client = camera_proxy_.subscribeCamera(cfg_.name,
                                                     cfg_.id,
                                                     cfg_.resolution,
                                                     cfg_.colorspaces,
                                                     cfg_.fps);
}

void CameraHolder::UpdateImage() {
  AL::ALValue al_img;
  try {
#ifdef CVISION_IS_REMOTE
    al_img = camera_proxy_.getImageRemote(cfg_.camera_client);
#else
    al_img = camera_proxy_.getImageLocal(cfg_.camera_client);
#endif
  } catch (std::exception e) {
    std::cerr << "ERROR: YOU NED TO RESTART ROBOT BECAUSE CAMERA IS DEAD\n" << e.what() << std::endl;
    return;
  }
  cv::Mat img_header = cv::Mat(cfg_.resolution_size, CV_8UC3);
  img_header.data = (uchar*) al_img[6].GetBinary();
  camera_proxy_.releaseImage(cfg_.camera_client);

  last_img_ = img_header;
}