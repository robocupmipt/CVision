#pragma once
#include "balldetector.h"
#include "configdefinitions.h"


BallDetector::BallDetector(const CameraConfig& cfg) : cfg_(cfg) {
  for (auto path : cfg_.cascades) {
    cv::CascadeClassifier curr_finder;
    curr_finder.load(path);

    ball_finders_.push_back(curr_finder);
  }
}

std::vector <Point> BallDetector::Detect(const cv::Mat& image) {
  std::vector <Point> res;

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

    res.push_back(Rect2Point(max_ball));
  }

  return res;
}


/*------- PRIVAT SPACE ---------*/


Point BallDetector::Rect2Point(const cv::Rect& r) const {
  return Point(0, 0);
}