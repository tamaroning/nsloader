#pragma once

#include "nsloader.h"

namespace NSLoader {
namespace Hle {

class System {
  public:
    explicit System();

    ~System();

    void load(std::string_view filename);

  private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace Hle
} // namespace NSLoader
