#pragma once
#include "remotevision.h"


RemoteVision::RemoteVision(boost::shared_ptr <AL::ALBroker> broker, const std::string &name) :
    AL::ALModule(broker, name),
    kernel_(broker),
    image_buf_(nullptr) {}

void RemoteVision::init() {
  while (true) {
    std::string command(SmallLog("ENTER command", 1, true));
    if (command == "SHOW") {
      ShowImage();
    }
    else if (command == "SNAP") {
      SnapImage();
    }
    else if (command == "OPEN") {
      OpenImage();
    }
    else if (command == "SAVE") {
      SaveImage();
    }
  }
}

void RemoteVision::ShowImage() {
  SmallLog("Now you can see the last image", 2);

  if (image_buf_ == nullptr) {
    SmallLog("ERROR: There is no image", 2);
    return;
  }

  cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE); // Create a window for display.
  cv::imshow("Display window", *image_buf_);
}

void RemoteVision::SnapImage() {
  SmallLog("Now you can get image from robot camera", 2);

  int cam_num(SmallLog<int>("ENTER: camera index (0 for lower, 1 for upper):", 3, true));
  SetBuff(kernel_.GetImageFromCamera(cam_num));
}

void RemoteVision::OpenImage() {
  return;
}

void RemoteVision::SaveImage() {
  SmallLog("Now you can save image to file", 2);

  if (image_buf_ == nullptr) {
    SmallLog("ERROR: There is no image", 2);
    return;
  }

  std::string path(SmallLog("ENTER: path to save file", 2, true));
  kernel_.PrintImageToFile(*image_buf_, path);
}

template <typename T>
T RemoteVision::SmallLog(const std::string text, size_t deep_level, bool is_reply) const {
  std::string request = "";
  for (size_t i = 0; i < deep_level; ++i) {
    request += "--";
  }

  std::cout << request + "> " + text << std::endl;
  if (is_reply) {
    T ans;
    std::cout << request + "| ";
    std::cin >> ans;
    return ans;
  }
  return T();
}


/*------- PRIVAT SPACE ---------*/


void RemoteVision::SetBuff(const cv::Mat& img) {
  if (image_buf_ != nullptr) {
    delete  image_buf_;
  }

  image_buf_ = new cv::Mat(img);
}

void RemoteVision::ReleaseBuff() {
  delete image_buf_;
  image_buf_ = nullptr;
}