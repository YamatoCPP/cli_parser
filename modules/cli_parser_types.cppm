export module cli_parser:types;

import std;

export namespace ymt {

/// @brief std::nullopt or option value
using option_t = std::optional<std::string_view>;

/// @brief value type
using value_t = std::optional<std::variant<int, double, std::string>>;

template <typename t>
concept option_value_c = std::is_same_v<int, t> 
                      || std::is_same_v<double, t>
                      || std::is_same_v<std::string, t>;

}