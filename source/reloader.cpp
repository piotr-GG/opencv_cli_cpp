#include "include/reloader.h"
#include "include/img_container.h"

void Reloader::process_image(std::vector<std::string> args)
{
    std::cout << "Processing image in Reloader" << std::endl;

    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Reloader::process_args(arg_vector);
    if(process_result)
    {
        std::string image_path = ImgContainer::get_image_path();
        if(image_path != "")
        {
            ImgContainer::load_image(image_path);
        }
        else
        {
            std::cout << "ERROR: Please first load an image!" << std::endl;
        }
    }
    else
    {
        std::cout << "ERROR: Couldn't process image due to wrong input arguments!" << std::endl;
    }
}

bool Reloader::process_args(std::vector<std::string> args)
{
    if(args.size() > 0)
    {
        std::cout << "ERROR: Reload doesn't take any input arguments!" << std::endl;
        return false;
    }
    return true;
}