#pragma once
#include "core/hle/kernel/proc.h"
#include "core/system.h"
#include "nsloader.h"

namespace NSLoader {
namespace Core {
namespace Cpu {

class CpuCallbacks;

class Cpu {
  public:
    explicit Cpu(System &system);
    ~Cpu();

    Cpu(const Cpu &other) = delete;
    Cpu(Cpu &&other) = delete;

    void run(Kernel::KProcess &proc, u64 ticks);

  private:
    System &system;
    u64 tpidr_el0 = 0;
    u64 tpidrro_el0 = 0;
    CpuCallbacks *cb = nullptr;
};

} // namespace Cpu
} // namespace Core
} // namespace NSLoader
