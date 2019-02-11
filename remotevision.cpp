#include "remotevision.h"

RemoteVision::RemoteVision(boost::shared_ptr <ALBroker> broker, const std::string &name) :
    AL::ALModule(broker, name),
    kernel_(broker) {}

void RemoteVision::init() {
  return;
}