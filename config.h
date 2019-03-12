#pragma once
#include <string>
#include <alcommon/almodule.h>
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"


struct CameraConfig {
  CameraConfig(std::string name, int id, int resolution, int colorspaces, int fps) :
    name(name),
    id(id),
    resolution(resolution),
    colorspaces(colorspaces),
    fps(fps) {}

  const std::string name;
  const int id;
  const int resolution;
  const int colorspaces;
  const int fps;
};
