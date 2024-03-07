#include "proc_memory.h"

namespace NSLoader {
namespace Core {
namespace Kernel {

/* Class representing a single kernel process */
class KProcess {
  public:
    enum class State { Runnable, Blocked };

    explicit KProcess();

    ~KProcess();

    void load_memory(std::unique_ptr<KProcMemory> memory_);

    void set_state(State state);

    State get_state() const;

  private:
    State state = State::Blocked;
    std::unique_ptr<KProcMemory> memory = nullptr;
};

} // namespace Kernel
} // namespace Core
} // namespace NSLoader
