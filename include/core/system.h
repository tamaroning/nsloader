#pragma once

#include "nsloader.h"

namespace NSLoader {
namespace Core {

class System {
  public:
    explicit System();

    ~System();

    void start(std::string_view filename);

  private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace Core
} // namespace NSLoader
