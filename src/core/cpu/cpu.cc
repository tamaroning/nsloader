#include "core/cpu/cpu.h"
#include "core/system.h"
#include "utils/log.h"
#include <dynarmic/interface/A64/a64.h>
#include <dynarmic/interface/A64/config.h>
#include <dynarmic/interface/exclusive_monitor.h>

namespace NSLoader {
namespace Core {
namespace Cpu {

// global instances for Dynarmic
Dynarmic::A64::Jit *jit = nullptr;
Dynarmic::ExclusiveMonitor *exclusiveMonitor = nullptr;

class CpuCallbacks : public Dynarmic::A64::UserCallbacks {
  public:
    CpuCallbacks(System &system) : system(system) {}

    std::optional<std::uint32_t>
    MemoryReadCode(Dynarmic::VAddr vaddr) override {
        return MemoryRead32(vaddr);
    }

    u8 MemoryRead8(Dynarmic::VAddr vaddr) override {
        Utils::unimplemented("Read8");
    }

    u16 MemoryRead16(Dynarmic::VAddr vaddr) override {
        Utils::unimplemented("Read16");
    }

    u32 MemoryRead32(Dynarmic::VAddr vaddr) override {
        Utils::unimplemented("Rea32");
    }

    u64 MemoryRead64(Dynarmic::VAddr vaddr) override {
        Utils::unimplemented("Read64");
    }

    Dynarmic::A64::Vector MemoryRead128(Dynarmic::VAddr vaddr) override {
        Utils::unimplemented("Read128");
    }

    void MemoryWrite8(Dynarmic::VAddr vaddr, u8 value) override {
        Utils::unimplemented("Write8");
    }

    void MemoryWrite16(Dynarmic::VAddr vaddr, u16 value) override {
        Utils::unimplemented("Write16");
    }

    void MemoryWrite32(Dynarmic::VAddr vaddr, u32 value) override {
        Utils::unimplemented("Write32");
    }

    void MemoryWrite64(Dynarmic::VAddr vaddr, u64 value) override {
        Utils::unimplemented("Write64");
    }

    void MemoryWrite128(Dynarmic::VAddr vaddr,
                        Dynarmic::A64::Vector value) override {
        Utils::unimplemented("Write128");
    }

    void CallSVC(u32 svc) override { Utils::unimplemented("CallSVC"); }

    void AddTicks(u64 ticks) override {
        total_ticks += ticks;
        ticks_left -= ticks;
    }

    u64 GetTicksRemaining() override { return ticks_left < 0 ? 0 : ticks_left; }

    u64 GetCNTPCT() override { Utils::unimplemented("GetCNTPCT"); }

    void ExceptionRaised(u64 pc, Dynarmic::A64::Exception exception) override {
        switch (exception) {
        case Dynarmic::A64::Exception::WaitForInterrupt:
        case Dynarmic::A64::Exception::WaitForEvent:
        case Dynarmic::A64::Exception::SendEvent:
        case Dynarmic::A64::Exception::SendEventLocal:
        case Dynarmic::A64::Exception::Yield:
        case Dynarmic::A64::Exception::NoExecuteFault:
        default:
            Utils::unimplemented("ExceptionRaised");
        }
    }

    void InterpreterFallback(u64 pc, std::size_t num_instructions) override {
        Utils::critical(
            "Unimplemented instruction @ 0x{:X} for {} instructions ", pc,
            num_instructions);
        return;
    }

  private:
    i64 total_ticks = 0;
    i64 ticks_left = 0;
    System &system;
};

Cpu::Cpu(System &system) : system(system) {
    if (jit || exclusiveMonitor) {
        Utils::critical("Detected multiple JIT instances, this is a bug!");
    }

    // NS has actually 4 cores, but we only use 1 for simplicity
    exclusiveMonitor = new Dynarmic::ExclusiveMonitor(1);

    CpuCallbacks cb{system};

    Dynarmic::A64::UserConfig config;
    config.callbacks = &cb;
    config.define_unpredictable_behaviour = true;
    config.global_monitor = exclusiveMonitor;
    config.processor_id = 0;

    // FIXME: set the correct values
    config.tpidr_el0 = 0;
    config.tpidrro_el0 = 0;

    jit = new Dynarmic::A64::Jit(config);
}

Cpu::~Cpu() {
    delete jit;
    delete exclusiveMonitor;
};

} // namespace Cpu
} // namespace Core
} // namespace NSLoader