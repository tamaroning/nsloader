#pragma once

#include <source_location>
#include <spdlog/spdlog.h>
#include <string>

namespace Utils {

enum class LogLevel {
    TRACE,
    DEBUG,
    INFO,
    WARN,
    // ERROR,
    CRITICAL,
    OFF
};

void core_dump();

[[noreturn]] void
unimplemented(const std::string what,
              const std::source_location loc = std::source_location::current());

void init_logger();

void set_log_file(std::string filepath);

void set_log_level(LogLevel level);

template <typename... Args>
inline void debug(fmt::format_string<Args...> fmt, Args &&...args) {
    spdlog::debug(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void critical(fmt::format_string<Args...> fmt, Args &&...args) {
    spdlog::critical(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void trace(fmt::format_string<Args...> fmt, Args &&...args) {
    spdlog::trace(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void info(fmt::format_string<Args...> fmt, Args &&...args) {
    spdlog::info(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void warn(fmt::format_string<Args...> fmt, Args &&...args) {
    spdlog::warn(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
[[noreturn]] inline void abort(fmt::format_string<Args...> fmt,
                               Args &&...args) {
    spdlog::critical(fmt, std::forward<Args>(args)...);
    spdlog::dump_backtrace();
    exit(-1);
}

} // namespace Utils
