#include "core/system.h"
#include "core/hle/loader/loader.h"
#include "utils/log.h"

namespace NSLoader {
namespace Core {

struct System::Impl {
    explicit Impl(System &system) {}

    void load(System &system, std::string_view filename) {
        Hle::Loader::NSOLoader loader = Hle::Loader::NSOLoader();
        loader.load(filename);
    }
};

System::System() : impl{std::make_unique<Impl>(*this)} {}

System::~System() = default;

void System::load(std::string_view filename) { impl->load(*this, filename); }

} // namespace Core
} // namespace NSLoader
