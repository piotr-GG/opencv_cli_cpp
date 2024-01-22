#pragma once
#include <opencv2/opencv.hpp>

class ImgContainer{
    public:
        static void load_image(cv::String name);
        static void set_image(cv::Mat image);
        static cv::Mat get_image();
        static void show_image();
        static void set_image_path(const std::string& image_path);
        static std::string get_image_path();
    private:
        static cv::Mat image;
        static std::string image_path;
};