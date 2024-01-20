#include "include/transform.h"
#include "include/thresholder.h"
#include "include/dilater.h"
#include "include/eroder.h"
#include "include/smoother.h"
#include "include/brightener.h"
#include <unordered_map>

std::unordered_map<std::string, Transformation> enum_map = {
    {"DILATER", Transformation::Dilater},
    {"ERODER", Transformation::Eroder},
    {"SMOOTHER", Transformation::Smoother},
    {"THRESHOLDER", Transformation::Thresholder},
    {"BRIGHTENER", Transformation::Brightener},
};

Transform* Transform::make_transformation(Transformation choice){
    if(choice == Transformation::Thresholder){
        return new Thresholder();
    } else if (choice == Transformation::Dilater){
        return new Dilater();
    } else if (choice == Transformation::Smoother){
        return new Smoother();
    } else if (choice == Transformation::Eroder){
        return new Eroder();
    } else if (choice == Transformation::Brightener){
        return new Brightener();
    }
    return NULL;
}

Transformation translate_string(std::string input){
    std::unordered_map<std::string, Transformation>::iterator it = enum_map.find(input);
    if(it != enum_map.end()){
        return it->second;
    } else {
        return Transformation::Wrong_choice;
    }
}


void Transform::invoke(){
    if(typeid(this).name() == "Dilater"){
        std::cout << "Yyyy eee yyy" << std::endl;
    }
}

