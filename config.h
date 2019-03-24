#pragma once
#include <string>
#include <alcommon/almodule.h>
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"
#include <alvision/alvisiondefinitions.h>
#include <cassert>

struct CameraConfig {
  CameraConfig(std::string name, int id, int resolution, int colorspaces, int fps) :
    name(name),
    id(id),
    resolution(resolution),
    colorspaces(colorspaces),
    fps(fps) {
      assert(resolution == AL::k16VGA && id == AL::kTopCamera);

      switch (resolution) {
          case AL::kQVGA:
              resolution_size = cv::Size(320, 240);
              break;
          case AL::kVGA:
              resolution_size = cv::Size(640, 480);
              break;
          case AL::k4VGA:
              resolution_size = cv::Size(1280, 960);
              break;
          case AL::k16VGA:
              resolution_size = cv::Size(2560, 1920);
              break;
      }
  }

  const std::string name;
  const int id;
  const int resolution;
  const int colorspaces;
  const int fps;
  std::string camera_client;
  cv::Size resolution_size;
};
