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
    ImgContainer::set_image_path(image_path);
    if(ImgContainer::get_image().empty()) 
    {
        while(ImgContainer::get_image().empty())
        {   
            std::cout << "ERROR: No image has been loaded.\n";
            std::cout << "Please insert image name to be loaded (type exit to exit program): ";
            image_path = get_line();
            if(image_path == "exit") return 0; 
            ImgContainer::load_image(image_path);
            ImgContainer::set_image_path(image_path);
        }
    }
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

    return 0;
}

std::string get_line(){
    std::string line;
    std::cout << "APP > " ;
    std::getline(std::cin, line);
    return line;
}