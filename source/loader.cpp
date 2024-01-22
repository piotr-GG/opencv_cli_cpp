#include "include/loader.h"
#include "include/img_container.h"
#include <string>

void Loader::process_image(std::vector<std::string> args)
{
    std::cout << "Processing image in Loader" << std::endl;
    for(auto i : args)
    {
        std::cout << i << std::endl;
    }
    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Loader::process_args(arg_vector);
    if(process_result)
    {
        std::string file_name = arg_vector[0];
        std::cout << "Filename = " << file_name << std::endl;
        ImgContainer::load_image(file_name);
        ImgContainer::set_image_path(file_name);
    } 
    else
    {
        std::cout << "ERROR: Couldn't load image due to wrong input arguments!" << std::endl;
    }

}

bool Loader::process_args(std::vector<std::string> args)
{
    if(args.size() == 0 || args.size() > 1)
    {
        std::cout << "ERROR: Loader takes exactly one argument (file path)!" << std::endl;
        return false;
    }
    std::string file_name = args[0];
    std::string extens = file_name.substr(file_name.find(".")+1);
    
    if (!(extens == "jpg" || extens == "png" || extens == "jpeg"))
    {
        std::cout << "Extension: " << extens << std::endl;
        std::cout << "ERROR: File should have either .jpg, .jpeg or .png extension" << std::endl;
        return false;
    }
    return true;

}