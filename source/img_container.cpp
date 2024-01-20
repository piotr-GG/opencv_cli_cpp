#include "include/img_container.h"
#include <opencv2/opencv.hpp>

cv::Mat ImgContainer::image;

void ImgContainer::load_image(cv::String name){
    cv::Mat image;
    image = cv::imread(name, cv::IMREAD_COLOR);

    if (!image.data)
    {
        return;
    } 
    ImgContainer::set_image(image);
}
void  ImgContainer::set_image(cv::Mat image){
    ImgContainer::image = image;
}
cv::Mat ImgContainer::get_image(){
    return ImgContainer::image;
}

void ImgContainer::show_image(){
    cv::namedWindow("Display Image", cv::WINDOW_NORMAL);
    cv::imshow("Display Image", ImgContainer::image);
    cv::waitKey(0);
}