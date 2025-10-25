module cli_parser;

import std;

namespace rg = std::ranges;

namespace ymt {

cli_parser::cli_parser(int argc, char* argv[]) : args_(argv, argv + argc) {}

auto cli_parser::add_option(option_t short_opt, option_t long_opt) -> bool {}

} // namespace ymt