#include <cstdlib>
#include <spdlog/spdlog.h>

constexpr int NUM_BACKTRACE_LOG = 5;

void init_logger() {
    spdlog::set_pattern("[%^%l%$] %v");
    spdlog::enable_backtrace(NUM_BACKTRACE_LOG);
}

int main(int argc, char* argv[]) {
    init_logger();
    spdlog::info("Hello, World!");
    return EXIT_SUCCESS;
}
