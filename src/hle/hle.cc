#include "hle/hle.h"
#include "utils/log.h"

namespace NSLoader {
namespace Hle {

struct System::Impl {
    explicit Impl(System &system) {}

    void load(System &system) {
        // TODO:
        Utils::unimplemented("load NSO");
    }
};

System::System() : impl{std::make_unique<Impl>(*this)} {}

System::~System() = default;

void System::load() { impl->load(*this); }

} // namespace Hle
} // namespace NSLoader
