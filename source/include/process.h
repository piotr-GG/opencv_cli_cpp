#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

int process(std::string command_string);
std::vector<std::string> split(std::string s, std::string delimiter);
std::string to_lower(std::string input_string);
std::string to_upper(std::string input_string);
bool is_number(const std::string& s);
bool is_convertible_to_float(const std::string& s);
bool has_valid_extens(const std::string& file_name);
bool is_in_array(const std::string_view& arg, const std::string possible_vals[]);
template <typename T>
bool argumentInRange(T arg_val, const std::array<T, 2>& limits){
    return arg_val >= limits[0] && arg_val <= limits[1];
}