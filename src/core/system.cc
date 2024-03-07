#include "core/system.h"
#include "core/hle/kernel/proc.h"
#include "core/hle/loader/loader.h"
#include "utils/log.h"
#include <cstdlib>

namespace NSLoader {
namespace Core {

struct System::Impl {
    explicit Impl() {}

    void start(System &system, std::string_view filename) {
        Hle::Loader::NSOLoader loader = Hle::Loader::NSOLoader();
        auto proc_opt = loader.load(filename);
        if (!proc_opt.has_value()) {
            Utils::critical("Failed to load process");
            exit(EXIT_FAILURE);
        }
        Kernel::KProcess proc = std::move(proc_opt.value());

        Utils::unimplemented("Run kproc");
    }
};

System::System() : impl() {}

System::~System() = default;

void System::start(std::string_view filename) { impl->start(*this, filename); }

} // namespace Core
} // namespace NSLoader
