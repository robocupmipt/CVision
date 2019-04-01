#include <stdio.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, char** argv ) {
  if ( argc != 2 )
  {
    printf("usage: DisplayImage.out <Image_Path>\n");
    return -1;
  }

  cv::Mat image;
  image = cv::imread( argv[1], 1 );

  if ( !image.data )
  {
    printf("No image data \n");
    return -1;
  }

  cv::Mat gray_img;
  cv::cvtColor(image, gray_img, cv::COLOR_BGR2GRAY);

  cv::imwrite("GRAY.jpg", gray_img);

  return 0;
}