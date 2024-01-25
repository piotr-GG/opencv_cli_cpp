#include "./process.h"
#include <string_view>
#include <array>

enum class Type
{
    type_short = 1,
    type_int,
    type_double,
    type_undefined = 99,
};

template <typename T>
bool process_arg(const std::array<std::string,2>& args, const std::array<T, 2>& limits, const std::string& arg_name)
{
    Type arg_type = Type::type_undefined;
    
    //Conditionals used for determining type of passed arguments (based on template specialization)
    std::string_view type_name = typeid(T).name();

    if(type_name == typeid(int).name())
    {
        arg_type = Type::type_int;
    }
    if(type_name == typeid(short).name())
    {
        arg_type = Type::type_short;
    }
    if(type_name == typeid(double).name())
    {
        arg_type = Type::type_double;
    }
    
    if(args.size() != 2) 
    {
        std::cout << "ERROR: Incorrect number of arguments passed.\n";
        return false;
    }
    
    const std::string& arg = args[0];
    const std::string& arg_val = args[1];

    bool is_convertible;
    bool is_within_limits;
    switch(arg_type)
    {
        case Type::type_double:
            is_convertible = is_convertible_to_float(arg_val);
            if(is_convertible) {
                is_within_limits = argumentInRange<T>(std::stof(arg_val), limits);
            }
            break;
        case Type::type_int:
            is_convertible = is_number(arg_val);
            if(is_convertible) {
                is_within_limits = argumentInRange<T>(std::stoi(arg_val), limits);
            }
            break;
        case Type::type_short:
            is_convertible = is_number(arg_val);
            if(is_convertible) {
                is_within_limits = argumentInRange<T>(std::stoi(arg_val), limits);
            }
            break;
        default:
            std::cerr << "ERROR: WRONG ARGUMENT PASSED FOR arg_type in ArgParser::process_arg!\n";
            return false;
    }

    if(!is_convertible)
    {
        std::cerr << "ERROR: Wrong argument type for " << arg_name << "\n";
        return false;
    }

    if((is_convertible) && (!is_within_limits))
    {
        std::cerr << "ERROR: Argument for "<< arg_name << " should be within " << limits[0] << " and " << limits[1] <<"." << std::endl;
        return false;
    }

    return is_convertible && is_within_limits;
}