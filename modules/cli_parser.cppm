export module cli_parser;
export import :types;

import std;

export namespace ymt {

/// @brief cli option parser class
class cli_parser {
public:
    /// @brief constructor
    /// @param argc cli argument count
    /// @param argv cli arguments values
    cli_parser(int argc, char* argv[]);

    cli_parser(cli_parser&) = delete;
    auto operator=(cli_parser&) -> cli_parser& = delete;

    cli_parser(cli_parser&&) = default;
    auto operator=(cli_parser&&) -> cli_parser& = default;

    auto add_option(option_t short_opt, option_t long_opt) -> bool; 

private:
    /// @brief cli arguments
    std::vector<std::string> args_;
};

} // export namespace ymt
