#pragma once
#include "transform.h"

class Thresholder: public Transform
{
    public:
        void process_image(std::vector<std::string> args);
        void process_args(std::vector<std::string> args);
};