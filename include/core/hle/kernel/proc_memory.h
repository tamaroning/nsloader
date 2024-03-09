#pragma once
#include "nsloader.h"

namespace NSLoader {
namespace Core {
namespace Kernel {

enum class MemoryBase : u64 {
    HomebrewEnv = 1ULL << 28,
    Stack = 1ULL << 29,
    TLS = 1ULL << 30,
    Application = 1ULL << 31,
    Heap = 1ULL << 32,
    AddressSpace = 1ULL << 36,
};

constexpr u64 PAGE_SHIFT = 12;
constexpr u64 PAGE_SIZE = 1ULL << PAGE_SHIFT;
constexpr u64 PAGE_MASK = PAGE_SIZE - 1;
constexpr u64 STACK_PAGES = 32;

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