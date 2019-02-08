#include <string>


struct CameraConfig {
  CameraConfig(std::string name) :
    name(name) {}

  std::string name;
};

CameraConfig LOWER_CAMERA("lower camera");
CameraConfig UPPER_CAMERA("upper_camera");
