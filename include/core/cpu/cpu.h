#include "core/system.h"
#include "nsloader.h"

namespace NSLoader {
namespace Core {
namespace Cpu {

class Cpu {
    public:
        explicit Cpu(System& system);
        ~Cpu();

        Cpu(const Cpu &other) = delete;
        Cpu(Cpu &&other) = delete;

    private:
        System& system;
};

}
} // namespace Core
} // namespace NSLoader
