#include "core/hle/kernel/proc_memory.h"
#include "nsloader.h"

namespace NSLoader {
namespace Core {
namespace Kernel {

KProcMemory::KProcMemory() : mem() {}

KProcMemory::~KProcMemory() {}

u8 *KProcMemory::data() {
    assert(mem.data() != nullptr);
    return mem.data();
}

std::size_t KProcMemory::size() const { return mem.size(); }

void KProcMemory::resize(std::size_t sz) { mem.resize(sz); }

} // namespace Kernel
} // namespace Core
} // namespace NSLoader
