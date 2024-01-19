#include "include/transform.h"

void Transform::invoke(){
    if(typeid(this).name() == "Dilater"){
        std::cout << "Yyyy eee yyy" << std::endl;
    }
}