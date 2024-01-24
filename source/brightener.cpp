#include "include/brightener.h"
#include "include/img_container.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "include/process.h"
#include "include/arg_parser.h"
#include <string>

void Brightener::process_image(std::vector<std::string> args){
    std::cout << "Processing image in Brightener" << std::endl;

    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Brightener::process_args(arg_vector);
    if(process_result){
        cv::Mat image = ImgContainer::get_image();
        cv::Mat new_image = brighten_image(&image);
        ImgContainer::set_image(new_image);
    } else {
        std::cout << "Couldn't process image due to wrong input arguments" << std::endl;
    }
}

bool Brightener::process_args(std::vector<std::string> args){
    bool result;
    for(int i = 0; i < args.size(); i+=2){
        if(args[i] == "-a" || args[i] == "--alpha")
        {
            result = process_arg<double>(std::array<std::string_view, 2> {args[i], args[i+1]},
            Brightener::getAlphaLimits(), Type::type_float, "alpha");
            if(result) Brightener::setAlpha(stof(args[i+1]));
        }

        if(args[i] == "-b" || args[i] == "--beta")
        {
            result = process_arg<int>(std::array<std::string_view, 2> {args[i], args[i+1]},
            Brightener::getBetaLimits(), Type::type_int, "beta");
            if(result) Brightener::setBeta(stoi(args[i+1]));
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


