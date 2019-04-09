#pragma once
#include "config.h"


const CameraConfig LOWER_CAMERA("lower camera", AL::kBottomCamera, AL::k4VGA, AL::kBGRColorSpace, 30, {"data/bottom_cascade.xml", "data/other_cascade.xml", "data/top_cascade.xml"});
const CameraConfig UPPER_CAMERA("upper_camera", AL::kTopCamera,    AL::k4VGA, AL::kBGRColorSpace, 30, {"data/bottom_cascade.xml", "data/other_cascade.xml", "data/top_cascade.xml"});

