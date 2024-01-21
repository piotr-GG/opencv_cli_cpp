#include "include/show_img.h"
#include "include/img_container.h"

void ShowImg::process_image(std::vector<std::string> args){
    ImgContainer::show_image();
}

bool ShowImg::process_args(std::vector<std::string> args){
    return false;
}

