#include "utils/log.h"
#include "hle/hle.h"
#include <cstdlib>

using namespace NSLoader;

constexpr int NUM_BACKTRACE_LOG = 5;

int main(int argc, char *argv[]) {
    Utils::init_logger();

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " "
                  << "<FILE.nso>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string filename = argv[1];
    if (filename.empty()) {
        std::cerr << "No ROM specified." << std::endl;
        return EXIT_FAILURE;
    }


    Hle::System system;
    system.load();

    return EXIT_SUCCESS;
}
