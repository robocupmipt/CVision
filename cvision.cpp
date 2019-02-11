#include "cvision.h"

CVision::CVision(boost::shared_ptr <ALBroker> broker, const std::string &name) :
    ALModule(broker, name),
    kernel_(broker) {}