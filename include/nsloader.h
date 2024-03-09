#pragma once

#include <array>
#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <optional>
#include <queue>
#include <source_location>
#include <span>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace NSLoader {

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// https://stackoverflow.com/questions/8357240/how-to-automatically-convert-strongly-typed-enum-into-int
template <typename E> constexpr auto to_underlying(E e) noexcept {
    return static_cast<std::underlying_type_t<E>>(e);
}

} // namespace NSLoader
