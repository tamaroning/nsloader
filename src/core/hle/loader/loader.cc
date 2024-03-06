#include "core/hle/loader/loader.h"
#include "core/hle/loader/nso.h"
#include "nsloader.h"
#include "utils/log.h"
#include "utils/mmapped_file.h"

namespace NSLoader {
namespace Core {
namespace Hle {
namespace Loader {

NSOLoader::NSOLoader() {}

NSOLoader::~NSOLoader() {}

void NSOLoader::load(std::string_view filename) {
    Utils::debug("Load {}", filename);

    Utils::MmappedFile mfile(filename.data());

    const u8 *addr = mfile.get_address();

    // Check magic "NSO0"
    if (addr[0] != 'N' || addr[1] != 'S' || addr[2] != 'O' || addr[3] != '0') {
        Utils::critical("Invalid magic %c%c%c%c", addr[0], addr[1], addr[2],
                        addr[3]);
        exit(EXIT_FAILURE);
    }

    const NSOHeader *nso_header = reinterpret_cast<const NSOHeader *>(addr);

    const NSOSegmentHeader rodata_header = nso_header->segments[RODATA_SHNDX];
    std::string rodata(addr + rodata_header.offset,
                       addr + rodata_header.offset + rodata_header.size);

    Utils::unimplemented("load");
    Utils::debug("Load completed.");
}

} // namespace Loader
} // namespace Hle
} // namespace Core
} // namespace NSLoader
