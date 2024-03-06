#include <memory>

namespace NSLoader {
namespace Hle {

class System {
  public:
    explicit System();

    ~System();

    void load();

  private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

} // namespace Hle
} // namespace NSLoader
