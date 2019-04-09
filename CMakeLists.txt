# Copyright (C) 2011 Aldebaran Robotics
cmake_minimum_required(VERSION 2.6.4 FATAL_ERROR)

# Define the name of the project
project(remotevision)

# This include enable you to use qibuild framework
find_package(qibuild)


# Create a list of source files
set(_srcs
        src/balldetector.cpp
        src/markdetector.cpp
        src/goaldetector.cpp
        src/cameraholder.cpp
        src/kernelcv.cpp
        src/remotevision.cpp
        main.cpp
        )

# Add a compile flag because code changes a little bit
# when we are compiling an executable
# This will let you use #ifdef HELLOWORLD_IS_REMOTE
# in the C++ code
add_definitions( " -DCVISION_IS_REMOTE ")

# Create an executable
qi_create_bin(remotevision ${_srcs})

# Tell CMake that sayhelloworld depends on ALCOMMON and
# ALPROXIES.
# This will set the libraries to link sayhelloworld with,
# the include paths, and so on

target_include_directories(remotevision PUBLIC "include")
target_include_directories(remotevision PUBLIC "lib")
qi_use_lib(remotevision ALCOMMON ALPROXIES ALVISION OPENCV3_CORE OPENCV3_HIGHGUI OPENCV3_IMGCODECS OPENCV3_IMGPROC OPENCV3_OBJDETECT )