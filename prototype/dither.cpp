#include <stdio.h>
#include <stdint.h>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;
uint32  hex_colors[]={0x92215F , 0x590C68,0x000828 };

cv::Mat src; 
cv::Mat dst;
char window_name[] = "Dithering  Demo";
int find_closest_paltte(){
  return 0;
}
int dither(cv::data,size_t rows,size_t cols){
  return 0;
}

int main(){
  cv::namedWindow( window_name, cv::WINDOW_AUTOSIZE );
  src =cv::imread("dog.jpeg",cv::IMREAD_COLOR);

  if (src ==NULL){
    perror("Error while opening image");
    return 1;
  }
  size_t rows =src.rows;
  size_t cols=src.cols;
  
  return 0;
}
