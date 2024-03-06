#pragma once

#include "nsloader.h"
#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/iostreams/device/mapped_file.hpp>

namespace NSLoader {
namespace Utils {

namespace ipc = boost::interprocess;

class MmappedFile {
  public:
    explicit MmappedFile(const char *filepath);
    ~MmappedFile();

    std::size_t get_size() const;
    const void *get_address() const;

  private:
    ipc::file_mapping map;
    ipc::mapped_region view;
};

} // namespace Utils
} // namespace NSLoader
