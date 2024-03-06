#pragma once

#include "utils/log.h"

namespace NSLoader {
namespace Hle {
namespace Loader {

class NSOLoader {
  public:
    explicit NSOLoader();

    ~NSOLoader();

    void load(std::string_view filename);
};

} // namespace Loader
} // namespace Hle
} // namespace NSLoader
