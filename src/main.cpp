#include <fmt/format.h>
#include <gflags/gflags.h>

#include <iostream>

const std::string template_version = "Version: {}";

DEFINE_bool(verbose, false, "show verbose message.");

int main(int argc, char** argv) {
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    if (FLAGS_verbose) {
        std::cout << fmt::format(template_version, "0.1.0") << std::endl;
    }

    return 0;
}
