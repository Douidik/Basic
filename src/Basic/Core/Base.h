#ifndef BASIC_BASE_H
#define BASIC_BASE_H

#include <memory>
#include <filesystem>

using namespace std::string_literals;
namespace fs = std::filesystem;

/**
 *	Defining Macros
 */

/* Configuration Macros */
#if defined(NDEBUG)
#define BSC_RELEASE
#else
#define BSC_DEBUG
#endif

/* Platform Macros */
#if defined(_WIN32)
#define BSC_WINDOWS_OS
#elif defined(__linux__)
#define BSC_LINUX_OS
#elif defined(__APPLE__)
#define BSC_MAC_OS
#define BSC_UNSUPPORTED_OS
#else
#define BSC_UNKNOWN_OS
#define BSC_UNSUPPORTED_OS
#endif

/* Debug-break */
#if !defined(BSC_UNSUPPORTED_OS) && defined(BSC_DEBUG)
#if defined(BSC_WINDOWS_OS)
#define BSC_DEBUGBREAK() __debugbreak()
#elif defined(BSC_LINUX_OS)
#include <csignal>
#define BSC_DEBUGBREAK() raise(SIGTRAP)
#endif
#else
#define BSC_DEBUGBREAK()
#endif

/* Asserting and error */
#if defined(BSC_DEBUG)
#define BSC_ASSERT(x, ...) if(!static_cast<bool>(x)) { BSC_LOG_ERROR(__VA_ARGS__); BSC_DEBUGBREAK(); }
#define BSC_ASSERT_WARN(x, ...)  if(!static_cast<bool>(x)) { BSC_LOG_ERROR(__VA_ARGS__); }
#define BSC_ERROR(...) BSC_LOG_ERROR(__VA_ARGS__); BSC_DEBUGBREAK()
#else
#define BSC_ASSERT(x, ...)
#define BSC_ERROR(...)
#endif

/*
 * Defining Types
 */

using byte = char;
using ubyte = unsigned char;
using uint = unsigned int;

#endif //BASIC_BASE_H