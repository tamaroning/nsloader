// SPDX-FileCopyrightText: Copyright 2018 yuzu Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "nsloader.h"
#include "swap.h"

namespace NSLoader {
namespace Core {
namespace Hle {
namespace Loader {

// https://switchbrew.org/wiki/NSO

constexpr int TEXT_SHNDX = 0;
constexpr int RODATA_SHNDX = 1;
constexpr int DATA_SHNDX = 2;

struct NSOSegmentHeader {
    u32_le offset;
    u32_le location;
    u32_le size;
    union {
        u32_le alignment;
        u32_le bss_size;
    };
};
static_assert(sizeof(NSOSegmentHeader) == 0x10);

struct NSOHeader {
    using SHA256Hash = std::array<u8, 0x20>;

    struct RODataRelativeExtent {
        u32_le data_offset;
        u32_le size;
    };

    u32_le magic;
    u32_le version;
    u32 reserved;
    u32_le flags;
    std::array<NSOSegmentHeader, 3>
        segments; // Text, RoData, Data (in that order)
    std::array<u8, 0x20> build_id;
    std::array<u32_le, 3> segments_compressed_size;
    std::array<u8, 0x1C> padding;
    RODataRelativeExtent api_info_extent;
    RODataRelativeExtent dynstr_extent;
    RODataRelativeExtent dynsyn_extent;
    std::array<SHA256Hash, 3> segment_hashes;

    bool is_segment_compressed(size_t shndx) const;
};
static_assert(sizeof(NSOHeader) == 0x100);
static_assert(std::is_trivially_copyable_v<NSOHeader>);

constexpr u32 NSO_ARGUMENT_DATA_ALLOCATION_SIZE = 0x9000;

struct NSOArgumentHeader {
    u32_le allocated_size;
    u32_le actual_size;
    u8 padding[0x18];
};
static_assert(sizeof(NSOArgumentHeader) == 0x20);

} // namespace Loader
} // namespace Hle
} // namespace Core
} // namespace NSLoader
