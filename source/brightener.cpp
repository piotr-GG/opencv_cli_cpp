#include "include/brightener.h"
#include "include/img_container.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

void Brightener::process_image(std::vector<std::string> args){
    std::cout << "Processing image in Brightener" << std::endl;

    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    Brightener::process_args(arg_vector);
    for(auto i: args){
        std::cout << i << std::endl;
    }

    brighten_image(&(ImgContainer::get_image()));
}

void Brightener::process_args(std::vector<std::string> args){

}

void Brightener::setAlpha(double val){
    this->alpha=val;
}
double Brightener::getAlpha(){
    return this->alpha;
}

void Brightener::setBeta(int val){
    this->beta = val;
}
double Brightener::getBeta(){
    return this->beta;
}

cv::Mat Brightener::brighten_image(cv::Mat* src_img){
    cv::Mat new_image  = cv::Mat::zeros(src_img->size(), src_img->type());
    for(int y = 0; y < src_img->rows; y++){
        for(int x = 0; x < src_img->cols; x++){
            for(int c = 0; c < src_img->channels(); c++){
                new_image.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(this->getAlpha()*src_img->at<cv::Vec3b>(y,x)[c] + this->getBeta());
            }
        }
    }
    *src_img = new_image;
    return new_image;
}


