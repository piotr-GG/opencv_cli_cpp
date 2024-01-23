#include "include/eroder.h"
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

void Eroder::process_image(std::vector<std::string> args){
    std::cout << "Processing image in Eroder" << std::endl;
}

bool Eroder::process_args(std::vector<std::string> args){
    return false;
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
            return;
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
