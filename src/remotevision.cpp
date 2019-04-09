#pragma once
#include "remotevision.h"


RemoteVision::RemoteVision(boost::shared_ptr <AL::ALBroker> broker, const std::string &name) :
    AL::ALModule(broker, name),
    kernel_(broker) {}

void RemoteVision::init() {
  kernel_.StartModule();

  while (true) {
  }
}

void RemoteVision::DetectBall() {
  SmallLog("Now you cant detect ball", 2);

  int cam_num(SmallLog<int>("ENTER: camera index (0 for lower, 1 for upper):", 3, true));
  kernel_.DetectBalls();
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
