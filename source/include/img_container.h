#include <opencv2/opencv.hpp>

class ImgContainer{
    public:
        static void load_image(cv::String name);
        static void set_image(cv::Mat image);
        static cv::Mat get_image();
        static void show_image();
        static cv::Mat image;
        /*
    protected:
        static cv::Mat image;
        */
};