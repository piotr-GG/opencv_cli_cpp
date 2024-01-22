#pragma once
#include "transform.h"

class Saver: public Transform
{
    public:
        void process_image(std::vector<std::string> args);
        bool process_args(std::vector<std::string> args);
        bool check_if_file_exists(const std::string& file_name);
};