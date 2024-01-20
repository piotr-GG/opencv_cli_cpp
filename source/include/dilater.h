#pragma once
#include "transform.h"

class Dilater: public Transform{
    public:
        void process_image(std::vector<std::string> args);
};