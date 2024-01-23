#pragma once
#include "transform.h"

class Brightener: public Transform{
    public:
        void process_image(std::vector<std::string> args);
        bool process_args(std::vector<std::string> args);
        cv::Mat brighten_image(cv::Mat* src_img);

        void setAlpha(double val);
        double getAlpha();

        void setBeta(int val);
        double getBeta();

        std::array<double, 2> getAlphaLimits();
        std::array<int, 2> getBetaLimits();

    private:
        double alpha = 1.0;
        int beta = 0;
        const std::array<double,2> alpha_limits = {1.0, 3.0};
        const std::array<int,2> beta_limits = {0, 100};
};

