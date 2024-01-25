#include "include/arg_parser.h"
#include "include/process.h"
#include <array>

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
    std::cout << "Type name " << type_name << '\n';
    std::cout << "Type name " << typeid(short).name() << '\n';
    std::cout << "Type name " << static_cast<int>(arg_type) << '\n';
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

template bool process_arg<double>(const std::array<std::string,2>& args, const std::array<double, 2>& limits, const std::string& arg_name);
template bool process_arg<int>(const std::array<std::string,2>& args, const std::array<int, 2>& limits, const std::string& arg_name);
template bool process_arg<short>(const std::array<std::string,2>& args, const std::array<short, 2>& limits, const std::string& arg_name);