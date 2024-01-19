#include <opencv2/opencv.hpp>

class Transform {
    public:
        virtual void process_image() = 0;
        void setImage(cv::Mat image) {
            this->image = image;
        }
        void invoke();
    protected:
        cv::Mat image;
        
};
