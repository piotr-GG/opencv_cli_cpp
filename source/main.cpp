#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "include/open_image.h"

using namespace cv;

std::string get_line();

int main(int argc, char **argv)
{
    String image_to_be_opened;

    // std::string line;
    // line = get_line();
    // while(!line.empty()){
    //     std::cout << line << std::endl;
    //     line = get_line();
    // }

    for(std::string line; std::cout << "APP > " && std::getline(std::cin, line); )
    {
        if(!line.empty())
        {
            std::cout << "ECHO " << line << std::endl;
        }
    }

    // for (std::string line; std::cout << "APP > " && std::getline(std::cin, line); )
    // {
    //     if (!line.empty()){
    //         std::cout << "ECHO " << line << std::endl;
    //     }
    // }

    /*
    if(argc != 2){
        std::cout<<"usage: DisplayImage.out <Image_Path>" << std::endl;
        std::string image_name;
        std::cout << "Podaj nazwę pliku: ";
        std::cin >> image_name;
        if (!image_name.empty()){
            image_to_be_opened = image_name;
        } else {
            image_to_be_opened = argv[1];
        }
    }


    open_image(image_to_be_opened);
    */
    waitKey(0);
    return 0;
}

std::string get_line(){
    std::string line;
    std::cout << "APP > " ;
    std::getline(std::cin, line);
    return line;
}