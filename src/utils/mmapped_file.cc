#include "utils/mmapped_file.h"

namespace NSLoader {
namespace Utils {

MmappedFile::MmappedFile(const char *filepath)
    : map(filepath, ipc::read_only), view(map, ipc::read_only) {}

MmappedFile::~MmappedFile() {}

std::size_t MmappedFile::get_size() const { return view.get_size(); }

const void *MmappedFile::get_address() const { return view.get_address(); }

} // namespace Utils
} // namespace NSLoader
