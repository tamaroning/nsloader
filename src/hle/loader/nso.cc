#include "hle/loader/nso.h"

namespace NSLoader {
namespace Hle {
namespace Loader {

bool NSOHeader::is_segment_compressed(std::size_t shndx) const {
    assert(shndx < 3);
    return ((flags >> shndx) & 1) != 0;
}

} // namespace Loader
} // namespace Hle
} // namespace NSLoader