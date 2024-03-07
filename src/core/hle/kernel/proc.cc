#include "core/hle/kernel/proc.h"

namespace NSLoader {
namespace Core {
namespace Kernel {

/* Class representing a single kernel process */
KProcess::KProcess() {}
KProcess::~KProcess() {}

void KProcess::load_memory(std::unique_ptr<KProcMemory> memory_) {
    memory = std::move(memory_);
}

void KProcess::set_state(KProcess::State state_) { state = state_; }

KProcess::State KProcess::get_state() const { return state; }

} // namespace Kernel
} // namespace Core
} // namespace NSLoader
