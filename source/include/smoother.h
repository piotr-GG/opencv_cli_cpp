#pragma once
#include "transform.h"

class Smoother: public Transform
{
    public:
        void process_image(std::vector<std::string> args);
};