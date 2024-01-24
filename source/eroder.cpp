#include "include/eroder.h"
#include "include/process.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void Eroder::process_image(std::vector<std::string> args){
    std::cout << "Processing image in Eroder" << std::endl;
}

bool Eroder::process_args(std::vector<std::string> args){
    for(int i = 0; i < args.size(); i+=2)
    {
        if(args[i] == "-el" || args[i] == "--element")
        {
            if(is_number(args[i+1]))
            {
                if(argumentInRange<short>(std::stoi(args[i+1]), Eroder::getElementLimits()))
                {
                    Eroder::setElement(stoi(args[i+1]));
                }
                else
                {
                    std::cout << "ERROR: Argument for element should be within " << Eroder::getElementLimits()[0] << " and " << Eroder::getElementLimits()[1] << ".\n";
                    return false;
                 }
            }
            else
            {
                std::cout << "ERROR: Wrong argument type for element. Element shall be an integer type.\n"; 
            }
        }

        
    }
}

cv::Mat Eroder::erode_image(cv::Mat* src_img)
{
    int erosion_type = 0;
    cv::Mat output_img;

    switch(Eroder::getElement()){
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
    short kernel_size = Eroder::getKernelSize();
    cv::Mat element = cv::getStructuringElement(erosion_type,
        cv::Size(2*kernel_size + 1, 2*kernel_size+1),
        cv::Point(kernel_size, kernel_size));
    cv::erode(*src_img, output_img, element);
    return output_img;
}

void Eroder::setElement(short val)
{
    this->element = val;
}

short Eroder::getElement()
{
    return this->element;
}

void Eroder::setKernelSize(short val)
{
    (*this).kernel_size = val;
}

short Eroder::getKernelSize()
{
    return (*this).kernel_size;
}

std::array<short, 2> Eroder::getElementLimits()
{
    return this->element_limits;
}

std::array<short, 2> Eroder::getKernelLimits()
{
    return this->kernel_limits;
}
