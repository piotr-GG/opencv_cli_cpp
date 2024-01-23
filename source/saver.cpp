#include "include/saver.h"
#include "include/process.h"
#include <filesystem>

void Saver::process_image(std::vector<std::string> args)
{
    std::cout << "Processing image in Saver" << std::endl;
    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());

    bool process_result = Saver::process_args(arg_vector);
    if(process_result)
    {
        if(check_if_file_exists(arg_vector[0]))
        {
           std::string ans;
           std::cout << "File already exists. Do you want to overwrite it? [Y/N]" << '\n';
           getline(std::cin, ans);
           if(ans == "N") return;
        }
    }
}

bool Saver::process_args(std::vector<std::string> args)
{
    if(args.size() > 1)
    {
        std::cout << "ERROR: Saver takes either no (for overwriting) or one argument (for new filename)!" << std::endl;
        return false;
    }
    if(!has_valid_extens(args[0]))
    {
        std::cout << "ERROR: File should have either .jpg, .jpeg or .png extension" << std::endl;
        return false;
    }
    return true;
}

bool Saver::check_if_file_exists(const std::string& file_name)
{
    return std::filesystem::exists(file_name);
}
