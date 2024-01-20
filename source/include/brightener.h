#pragma once
#include "transform.h"

class Brightener: public Transform{
    public:
        void process_image(std::vector<std::string> args);
};