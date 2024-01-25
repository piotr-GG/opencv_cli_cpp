#include "include/smoother.h"
#include "include/process.h"
#include "include/arg_parser.h"
#include "include/img_container.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

void Smoother::process_image(std::vector<std::string> args){
    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Smoother::process_args(arg_vector);
    if(process_result)
    {
        std::cout << "Processing image!\n";
        cv::Mat image = ImgContainer::get_image();
        cv::Mat new_image = Smoother::smooth_image(&image);
        ImgContainer::set_image(new_image);
        std::cout << "Processing done!\n";
    }
    else
    {
        std::cout << "Couldn't process image due to wrong input arguments\n";
    }
}


bool Smoother::process_args(std::vector<std::string> args){
    bool result;
    if(args.size() % 2 != 0)
    {
        std::cout << "ERROR: Wrong number of input arguments!" << std::endl;
        return false;
    }
    for(int i = 0; i < args.size(); i+=2)
    {
        std::array<std::string, 2> arg_vec = std::array<std::string, 2>{args[i], args[i+1]};
        std::string possible_mnemonics[] = {"-el",  "--element"};
        if(is_in_array(arg_vec[0], possible_mnemonics))
        {
            result = process_arg<short>(arg_vec, Smoother::getKernelLimits(), "kernel");
            if(result) Smoother::setKernelSize(stoi(arg_vec[1]));
            else return false;
        }
    }
    return true;
}

cv::Mat Smoother::smooth_image(cv::Mat* src_img)
{
    cv::Mat output_img = src_img->clone();
    short kernel_size = this->getKernelSize();
    cv::GaussianBlur(*src_img, output_img, cv::Size(kernel_size, kernel_size), 0, 0);
}

void Smoother::setKernelSize(short val)
{
    this->kernel_size = val;
}

short Smoother::getKernelSize()
{
    return this->kernel_size;
}

std::array<short, 2> Smoother::getKernelLimits()
{
    return this->kernel_limits;
}
