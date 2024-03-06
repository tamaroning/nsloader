#include "utils/log.h"

namespace NSLoader {
namespace Hle {

class Loader {
  public:
    explicit Loader();

    ~Loader();

    void load(std::string_view filename);
};

} // namespace Hle
} // namespace NSLoader
