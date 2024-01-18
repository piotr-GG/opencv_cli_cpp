#include <iostream>
#include <opencv2/opencv.hpp>

void open_image(cv::String image_name){
    cv::Mat image;
    image = cv::imread(image_name, cv::IMREAD_COLOR);

    if (!image.data)
    {
        std::cout << "No image data!" << std::endl;
        return;
    }   else {
        std::cout << "Opening the image!" << std::endl;
    }

    cv::namedWindow("Display Image", cv::WINDOW_NORMAL);
    cv::imshow("Display Image", image);
}