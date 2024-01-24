#include <string_view>
#include <array>

enum class Type
{
    type_short,
    type_int,
    type_float,
};

template <typename T>
bool process_arg(const std::array<std::string_view,2>& args, const std::array<T, 2>& limits, Type arg_type, const std::string& arg_name);