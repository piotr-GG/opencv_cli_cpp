#include <string_view>
#include <array>

enum class Type
{
    type_short,
    type_int,
    type_double,
};

template <typename T>
bool process_arg(const std::array<std::string,2>& args, const std::array<T, 2>& limits, const std::string& arg_name);