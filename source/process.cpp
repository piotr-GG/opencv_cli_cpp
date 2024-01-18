#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include "include/process.h"

int process(std::string command_string){
    std::vector<std::string> parsed_cmd = split(command_string, " ");
    if (!parsed_cmd.empty()){
        if(to_lower(parsed_cmd[0]) == "exit") return 0;
    }
    for(auto i: parsed_cmd){
        std::cout << i << std::endl;
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