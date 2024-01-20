#pragma once
#include <opencv2/opencv.hpp>

enum class Transformation{
    Dilater,
    Eroder,
    Smoother,
    Thresholder,
    Wrong_choice
};

Transformation translate_string(std::string input);

class Transform {
    public:
        static Transform *make_transformation(Transformation choice);
        virtual void process_image(std::vector<std::string> args) = 0;
        void setImage(cv::Mat image) {
            this->image = image;
        }
        void invoke();
    protected:
        cv::Mat image;
        
};


