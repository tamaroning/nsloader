#include "utils/log.h"
#include <cstdlib>

constexpr int NUM_BACKTRACE_LOG = 5;

int main(int argc, char *argv[]) {
    Utils::init_logger();
    spdlog::info("Hello, World!");
    return EXIT_SUCCESS;
}
