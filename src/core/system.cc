#include "core/system.h"
#include "core/cpu/cpu.h"
#include "core/hle/kernel/proc.h"
#include "core/hle/loader/loader.h"
#include "nsloader.h"
#include "utils/log.h"

namespace NSLoader {
namespace Core {

constexpr u64 TICKS_PER_ITER = 1000;

struct System::Impl {
  public:
    explicit Impl(System &system) : cpu{system} {}

    void run(System &system, std::string_view filename) {
        // Load the ROM as a kernel process
        Hle::Loader::NSOLoader loader = Hle::Loader::NSOLoader();
        auto proc_opt = loader.load(filename);
        if (!proc_opt.has_value()) {
            Utils::critical("Failed to load process");
            exit(EXIT_FAILURE);
        }
        Kernel::KProcess proc = std::move(proc_opt.value());

        // Run the kernel process
        Utils::debug("Running kproc");
        while (true) {
            cpu.run(proc, TICKS_PER_ITER);
        }

        Utils::unimplemented("Run kproc");
    }

    Cpu::Cpu cpu;
};

System::System() : impl(std::make_unique<Impl>(*this)) {}

System::~System() = default;

void System::run(std::string_view filename) { impl->run(*this, filename); }

} // namespace Core
} // namespace NSLoader
