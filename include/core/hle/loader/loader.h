#pragma once

#include "core/hle/kernel/proc.h"

namespace NSLoader {
namespace Core {
namespace Hle {
namespace Loader {

class NSOLoader {
  public:
    explicit NSOLoader();

    ~NSOLoader();

    std::optional<Kernel::KProcess> load(std::string_view filename);
};

} // namespace Loader
} // namespace Hle
} // namespace Core
} // namespace NSLoader
