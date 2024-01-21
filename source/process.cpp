#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include "include/process.h"
#include "include/transform.h"

int process(std::string command_string){
    std::vector<std::string> parsed_cmd = split(command_string, " ");
    if (!parsed_cmd.empty()){
        if(to_upper(parsed_cmd[0]) == "EXIT") return 0;
        else{
            Transformation parsed_enum = translate_string(to_upper(parsed_cmd[0]));
            if(parsed_enum != Transformation::Wrong_choice){
                Transform* action = Transform::make_transformation(parsed_enum);
                action->process_image(parsed_cmd);
            }
            else {
                std::cout << "THERE IS NO SUCH COMMAND!" << std::endl;
            }
        }
    }
    return 1;
}

std::vector<std::string> split(std::string s, std::string delimiter){
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while((pos_end = s.find(delimiter, pos_start)) != std::string::npos){
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

std::string to_lower(std::string input_string){
    for(int i=0; i < input_string.length(); i++){
        input_string[i] = tolower(input_string[i]);
    }
    return input_string;
}

std::string to_upper(std::string input_string){
    for(int i=0; i < input_string.length(); i++){
        input_string[i] = toupper(input_string[i]);
    }
    return input_string;
}

bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while(it != s.end() && (std::isdigit(*it))) ++it;
    return !s.empty() && it == s.end();
}

bool is_convertible_to_float(const std::string& s){
    try{
        float result = std::stof(s);
        return true;
    } catch (std::exception& e){
        return false;
    }
}