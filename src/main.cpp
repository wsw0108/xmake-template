#include <argparse/argparse.hpp>
#include <fmt/format.h>

#include <iostream>

int main(int argc, char** argv) {
    std::string program_name = "app";
    std::string program_version = "0.1.0";
    argparse::ArgumentParser program(program_name, program_version, argparse::default_arguments::help);
    program.add_argument("-V", "--version")
        .action([&](const auto&) {
            std::cout << program_version << std::endl;
            std::exit(0);
        })
        .default_value(false)
        .implicit_value(true)
        .nargs(0)
        .help("prints version information and exits");

    int verbose = 0;
    program.add_argument("-v", "--verbose")
        .action([&](const auto&) { ++verbose; })
        .append()
        .default_value(false)
        .implicit_value(true)
        .nargs(0)
        .help("output verbose message");

    try {
        program.parse_args(argc, argv);
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        std::exit(1);
    }

    if (verbose > 0) {
        fmt::print("Name: {}, Version: {}\n", program_name, program_version);
    }

#ifdef VERBOSE_MESSAGE
    std::cout << "VERBOSE_MESSAGE defined" << std::endl;
#endif

    return 0;
}
