#include "hle/loader/loader.h"
#include "utils/log.h"

namespace NSLoader {
namespace Hle {

Loader::Loader() {}

Loader::~Loader() {}

void Loader::load(std::string_view filename) {
    Utils::critical("Load {}", filename);
    Utils::unimplemented("load");
}

} // namespace Hle
} // namespace NSLoader
