#include "hle/loader/loader.h"
#include "utils/log.h"

namespace NSLoader {
namespace Hle {
namespace Loader {

NSOLoader::NSOLoader() {}

NSOLoader::~NSOLoader() {}

void NSOLoader::load(std::string_view filename) {
    Utils::critical("Load {}", filename);
    Utils::unimplemented("load");
}

} // namespace Loader
} // namespace Hle
} // namespace NSLoader
