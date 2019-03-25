#pragma once
#include "balldetector.h"
#include "configdefinitions.h"

BallDetector::BallDetector(const CameraConfig &cfg) : config_(cfg) {std::vector <std::string> BALL_FINDER_FILES({"data/bottom_cascade.xml", "other_cascade.xml", "top_cascade.xml"});
  for (auto path : BALL_FINDER_FILES) {
    cv::CascadeClassifier curr_finder;
    assert(curr_finder.load(path));

    ball_finders_.push_back(curr_finder);
  }
}

AL::ALValue BallDetector::Detect(cv::Mat image) {AL::ALValue res;

  for (auto& finder : ball_finders_) {
    std::vector<cv::Rect> curr_balls;
    finder.detectMultiScale(image, curr_balls);
    for (auto& ball : curr_balls) {
      res.arrayPush(Rect2ALValue(ball));
    }
  }

  return AL::ALValue(res);
}


/********* PRIVATE SPACE *********/


AL::ALValue BallDetector::Rect2ALValue(const cv::Rect& ball) {
  float x = ball.x;
  float y = ball.y;
  float h = ball.height;
  float w = ball.width;
  return AL::ALValue::array(x + w / 2, y + h / 2, (w + h) / 4);
}