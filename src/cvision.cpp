#pragma once
#include "cvision.h"

CVision::CVision(boost::shared_ptr <AL::ALBroker> broker, const std::string &name) :
    ALModule(broker, name),
    kernel_(broker) {}