#pragma once
#include "config.h"
#include <alvision/alvisiondefinitions.h>

CameraConfig LOWER_CAMERA("lower camera", AL::kBottomCamera, AL::k4VGA, AL::kRGBColorSpace, 30);
CameraConfig UPPER_CAMERA("upper_camera", AL::kTopCamera,    AL::k4VGA, AL::kRGBColorSpace, 30);