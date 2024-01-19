#include "include/transform.h"

class Thresholder: public Transform
{
    public:
        void process_image(std::vector<std::string> args);
};