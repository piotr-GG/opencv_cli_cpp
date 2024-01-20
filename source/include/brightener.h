#pragma once
#include "transform.h"

class Brightener: public Transform{
    public:
        void process_image(std::vector<std::string> args);
        void process_args(std::vector<std::string> args);
        cv::Mat brighten_image(cv::Mat* src_img);

        void setAlpha(double val);
        double getAlpha();

        void setBeta(int val);
        double getBeta();

    private:
        double alpha = 1.0;
        int beta = 0;
};

