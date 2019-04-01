#pragma once
#include "balldetector.h"
#include "configdefinitions.h"


BallDetector::BallDetector(const CameraConfig& cfg) : cfg_(cfg) {
  std::cout << "DEBUG: \n \t cascade paths num " <<  cfg_.cascades.size();
  std::cout << std::endl;
  for (auto path : cfg_.cascades) {
    cv::CascadeClassifier curr_finder;
    curr_finder.load(path);

    ball_finders_.push_back(curr_finder);
  }
}

std::vector<cv::Rect> BallDetector::Detect(const cv::Mat& image) {
  std::vector<cv::Rect> res;

  cv::Mat gray_img;
  cv::cvtColor(image, gray_img, cv::COLOR_BGR2GRAY);

  for (auto& finder : ball_finders_) {
    std::vector<cv::Rect> curr_balls;

    finder.detectMultiScale(gray_img, curr_balls);

    cv::Rect max_ball;
    int max_h = 0;
    for (auto& ball : curr_balls) {
      if (ball.height > max_h) {
        max_ball = ball;
        max_h = ball.height;
      }

    }

    res.push_back(max_ball);
  }

  return res;
}


/*------- PRIVAT SPACE ---------*/

cv::Mat BallDetector::ToGray(const cv::Mat& img) const {
  cv::Mat gray_img;
  cv::cvtColor(img, gray_img, cv::COLOR_RGB2GRAY);

  for (int i = 0; i < gray_img.rows; ++i) {
    for (int j = 0; j < gray_img.cols; ++j) {
      gray_img.at<double>(i, j) = 0;
    }
  }
  return gray_img;
}