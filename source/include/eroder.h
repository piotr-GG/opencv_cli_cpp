#pragma once
#include "transform.h"

class Eroder: public Transform
{
    public:
        void process_image(std::vector<std::string> args);
        bool process_args(std::vector<std::string> args);
        cv::Mat erode_image(cv::Mat* src_img);

        void setElement(short val);
        short getElement();

        void setKernelSize(short val);
        short getKernelSize();

        std::array<short, 2> getElementLimits();
        std::array<short, 2> getKernelLimits();

    private:
        short element = 1;
        short kernel_size = 3;
        const std::array<short, 2> element_limits = {0, 2};
        const std::array<short, 2> kernel_limits = {1, 21};
};