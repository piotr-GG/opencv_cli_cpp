#include "include/transform.h"
#include "include/thresholder.h"
#include <unordered_map>

std::unordered_map<std::string, Transformation> enum_map = {
    {"DILATER", Transformation::Dilater},
    {"ERODER", Transformation::Eroder},
    {"SMOOTHER", Transformation::Smoother},
    {"THRESHOLDER", Transformation::Thresholder}
};

Transform *Transform::make_transformation(Transformation choice){
    if(choice == Transformation::Thresholder){
        return new Thresholder();
    } else if (choice == Transformation::Dilater){

    } else if (choice == Transformation::Smoother){

    } else if (choice == Transformation::Eroder){

    } else {
        return NULL;
    }
}

Transformation translate_string(std::string input){

    if(enum_map.find(input) != enum_map.end(){

    } 
}


void Transform::invoke(){
    if(typeid(this).name() == "Dilater"){
        std::cout << "Yyyy eee yyy" << std::endl;
    }
}

