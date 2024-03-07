#pragma once

#include "nsloader.h"

namespace NSLoader {
namespace Core {
namespace Kernel {

/* Class representing a kernel process memory */
class KProcMemory {
  public:
    explicit KProcMemory();

    ~KProcMemory();

    u8 *data();
    std::size_t size() const;
    void resize(std::size_t sz);

  private:
    std::vector<u8> mem;
};

} // namespace Kernel
} // namespace Core
} // namespace NSLoader