#include "include/dilater.h"
#include "include/process.h"
#include "include/img_container.h"
#include "include/arg_parser.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void Dilater::process_image(std::vector<std::string> args){
    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Dilater::process_args(arg_vector);
    if(process_result)
    {
        std::cout << "Processing image!\n";
        cv::Mat image = ImgContainer::get_image();
        cv::Mat new_image = Dilater::dilate_image(&image);
        ImgContainer::set_image(new_image);
        std::cout << "Processing done!\n";
    }
    else
    {
        std::cout << "Couldn't process image due to wrong input arguments\n";
    }
}

bool Dilater::process_args(std::vector<std::string> args){
    bool result;
    if(args.size() % 2 != 0)
    {
        std::cout << "ERROR: Wrong number of input arguments!" << std::endl;
        return false;
    }

        for(int i = 0; i < args.size(); i+=2)
        {
            std::array<std::string, 2>  arg_vec = std::array<std::string, 2> {args[i], args[i+1]};
            if(arg_vec[0] == "-el" || arg_vec[0] == "--element")
            {
                
                result = process_arg<short>(arg_vec, Dilater::getElementLimits(), "element");
                if(result) Dilater::setElement(stof(arg_vec[1]));
                else return false;
            }

            if(arg_vec[0] == "-k" || arg_vec[0] == "--kernel")
            {
                
                result = process_arg<short>(arg_vec, Dilater::getKernelLimits(), "kernel");
                if(result) Dilater::setKernelSize(stof(arg_vec[1]));
                else return false;
            }
        }
    return true;
}

cv::Mat Dilater::dilate_image(cv::Mat* src_img)
{
    int erosion_type = 0;
    cv::Mat output_img;

    switch(Dilater::getElement()){
        case 0:
            erosion_type = cv::MORPH_RECT;
            break;
        case 1:
            erosion_type = cv::MORPH_CROSS;
            break;
        case 2:
            erosion_type = cv::MORPH_ELLIPSE;
            break;
        default:
            erosion_type = cv::MORPH_RECT;
            break;
    }
    short kernel_size = Dilater::getKernelSize();
    cv::Mat element = cv::getStructuringElement(erosion_type,
        cv::Size(2*kernel_size + 1, 2*kernel_size+1),
        cv::Point(kernel_size, kernel_size));
    cv::dilate(*src_img, output_img, element);
    return output_img;
}


void Dilater::setElement(short val)
{
    this->element = val;
}

short Dilater::getElement()
{
    return this->element;
}

void Dilater::setKernelSize(short val)
{
    this->kernel_size = val;
}

short Dilater::getKernelSize()
{
    return this->kernel_size;
}

std::array<short, 2> Dilater::getElementLimits()
{
    return this->element_limits;
}

std::array<short, 2> Dilater::getKernelLimits()
{
    return this->kernel_limits;
}
