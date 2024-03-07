#include "core/hle/loader/loader.h"
#include "core/hle/kernel/proc.h"
#include "core/hle/kernel/proc_memory.h"
#include "core/hle/loader/nso.h"
#include "nsloader.h"
#include "utils/log.h"
#include "utils/mmapped_file.h"
#include <cstring>

namespace NSLoader {
namespace Core {
namespace Hle {
namespace Loader {

NSOLoader::NSOLoader() {}

NSOLoader::~NSOLoader() {}

std::optional<Kernel::KProcess> NSOLoader::load(std::string_view filename) {
    Utils::debug("Loading {}", filename);

    Utils::MmappedFile mfile(filename.data());

    const u8 *addr = mfile.get_address();

    // Check magic "NSO0"
    if (addr[0] != 'N' || addr[1] != 'S' || addr[2] != 'O' || addr[3] != '0') {
        Utils::critical("Invalid magic %c%c%c%c", addr[0], addr[1], addr[2],
                        addr[3]);
        return std::nullopt;
    }

    Kernel::KProcMemory program_image;

    const NSOHeader *nso_header = reinterpret_cast<const NSOHeader *>(addr);
    for (int i = 0; i < nso_header->segments.size(); i++) {
        const NSOSegmentHeader seg_header = nso_header->segments[i];
        auto loc = seg_header.location;
        auto offset = seg_header.offset;
        auto size = seg_header.size;

        program_image.resize(loc + size);
        std::memcpy(program_image.data(), addr + offset, size);
        Utils::debug("segment: address: {:#x} ({:#x} bytes)", loc, size);
    }

    Kernel::KProcess process;
    process.load_memory(std::make_unique<Kernel::KProcMemory>(program_image));

    Utils::debug("Loaded program image");
    return process;
}

} // namespace Loader
} // namespace Hle
} // namespace Core
} // namespace NSLoader
