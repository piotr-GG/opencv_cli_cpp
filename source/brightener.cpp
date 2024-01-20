#include "include/brightener.h"

void Brightener::process_image(std::vector<std::string> args){
    std::cout << "Processing image in Brightener" << std::endl;

    std::vector<std::string> arg_vector = std::vector<std::string>(args.begin()+1, args.begin() + args.size());
    Brightener::process_args(arg_vector);
    for(auto i: args){
        std::cout << i << std::endl;
    }
}

void Brightener::process_args(std::vector<std::string> args){

}