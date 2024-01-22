#include "include/img_container.h"
#include <opencv2/opencv.hpp>

//Initialization of static class variables
cv::Mat ImgContainer::image;
std::string ImgContainer::image_path = "";

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

void ImgContainer::set_image_path(const std::string& image_path){
    ImgContainer::image_path = image_path;
}

cv::Mat ImgContainer::get_image(){
    return ImgContainer::image;
}

std::string ImgContainer::get_image_path(){
    return ImgContainer::image_path;
}

void ImgContainer::show_image(){
    cv::namedWindow("Display Image", cv::WINDOW_NORMAL);
    cv::imshow("Display Image", ImgContainer::image);
    cv::waitKey(0);
}

