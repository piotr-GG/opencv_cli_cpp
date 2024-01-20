#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "include/open_image.h"
#include "include/process.h"
#include "include/img_container.h"

using namespace cv;

std::string get_line();

int main(int argc, char **argv)
{
    String image_path;
    int return_value;

    if(argc == 2){
        image_path = argv[1];
        std::cout << "Image path: " << image_path << std::endl;
    }

    ImgContainer::load_image(image_path);
    ImgContainer::show_image();

    for(std::string line; std::cout << "APP > " && std::getline(std::cin, line); )
    {
        if(!line.empty())
        {
            return_value = process(line);
            if(!return_value){
                return 0;
            }
        }
    }


    /*
    open_image(image_to_be_opened);
    waitKey(0);
    */
    return 0;
}

std::string get_line(){
    std::string line;
    std::cout << "APP > " ;
    std::getline(std::cin, line);
    return line;
}