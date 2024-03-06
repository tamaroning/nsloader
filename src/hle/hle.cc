#include "hle/hle.h"
#include "utils/log.h"
#include "hle/loader/loader.h"

namespace NSLoader {
namespace Hle {

struct System::Impl {
    explicit Impl(System &system) {}

    void load(System &system, std::string_view filename) {
        Loader::NSOLoader loader = Loader::NSOLoader();
        loader.load(filename);
    }
};

System::System() : impl{std::make_unique<Impl>(*this)} {}

System::~System() = default;

void System::load(std::string_view filename) { impl->load(*this, filename); }

} // namespace Hle
} // namespace NSLoader
