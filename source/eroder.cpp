#include "include/eroder.h"

void Eroder::process_image(std::vector<std::string> args){
    std::cout << "Processing image in Eroder" << std::endl;
}

bool Eroder::process_args(std::vector<std::string> args){
    return false;
}

cv::Mat Eroder::erode_image(cv::Mat* src_img)
{
    return *src_img;
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


