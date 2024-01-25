#pragma once
#include "transform.h"

class Smoother: public Transform
{
    public:
        void process_image(std::vector<std::string> args);
        bool process_args(std::vector<std::string> args);
        cv::Mat smooth_image(cv::Mat* src_img);

        void setKernelSize(short val);
        short getKernelSize();

        std::array<short, 2> getKernelLimits();

    private:
        short kernel_size = 1;
        const std::array<short, 2> kernel_limits = {1, 31};
};