#include "include/brightener.h"
#include "include/img_container.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "include/process.h"
#include "include/arg_parser.h"
#include <string>

void Brightener::process_image(std::vector<std::string> args){
    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Brightener::process_args(arg_vector);
    if(process_result){
        std::cout << "Processing image!" << std::endl;
        cv::Mat image = ImgContainer::get_image();
        cv::Mat new_image = brighten_image(&image);
        ImgContainer::set_image(new_image);
        std::cout << "Processing done!" << std::endl;
    } else {
        std::cout << "Couldn't process image due to wrong input arguments" << std::endl;
    }
}

bool Brightener::process_args(std::vector<std::string> args){
    bool result;
    if(args.size() % 2 != 0) 
    {
        std::cout << "ERROR: Wrong number of input arguments!" << std::endl;
        return false;
    }

    for(int i = 0; i < args.size(); i+=2)
    {
        std::array<std::string, 2>  arg_vec = std::array<std::string, 2> {args[i], args[i+1]};
        if(arg_vec[0] == "-a" || arg_vec[0] == "--alpha")
        {
            result = process_arg<double>(arg_vec, Brightener::getAlphaLimits(), "alpha");
            if(result) Brightener::setAlpha(stof(arg_vec[1]));
            else return false;
        }

        if(args[i] == "-b" || args[i] == "--beta")
        {
            result = process_arg<int>(arg_vec, Brightener::getBetaLimits(), "beta");
            if(result) Brightener::setBeta(stoi(arg_vec[1]));
            else return false;
        }
    }
    return true;
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

std::array<double, 2> Brightener::getAlphaLimits(){
    return this->alpha_limits;
}

std::array<int, 2> Brightener::getBetaLimits(){
    return this->beta_limits;
}

cv::Mat Brightener::brighten_image(cv::Mat* src_img){
    std::cout << "Alpha: " << this->getAlpha() << std::endl;
    std::cout << "Beta: " << this->getBeta() << std::endl;

    cv::Mat new_image  = cv::Mat::zeros(src_img->size(), src_img->type());
    for(int y = 0; y < src_img->rows; y++){
        for(int x = 0; x < src_img->cols; x++){
            for(int c = 0; c < src_img->channels(); c++){
                new_image.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(this->getAlpha()*src_img->at<cv::Vec3b>(y,x)[c] + this->getBeta());
            }
        }
    }
    return new_image;
}


