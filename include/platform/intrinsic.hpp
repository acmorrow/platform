#ifndef PLATFORM_INTRINSIC_HPP
#define PLATFORM_INTRINSIC_HPP

#include <platform/compiler.hpp>
#include <platform/arch.hpp>

#include <cstdlib>
#include <cstdint>

namespace platform {
inline namespace v1 {
namespace intrinsic {

[[gnu::always_inline]]
  inline std::uint64_t byteswap (std::uint64_t value) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _byteswap_uint64(value);
#elif PLATFORM_COMPILER_GCC || PLATFORM_COMPILER_CLANG
  return __builtin_bswap64(value);
#else
  return ((x & UINT64_C(0x00000000000000FF)) << 56) |
         ((x & UINT64_C(0x000000000000FF00)) << 40) |
         ((x & UINT64_C(0x0000000000FF0000)) << 24) |
         ((x & UINT64_C(0x00000000FF000000)) <<  8) |
         ((x & UINT64_C(0x000000FF00000000)) >>  8) |
         ((x & UINT64_C(0x0000FF0000000000)) >> 24) |
         ((x & UINT64_C(0x00FF000000000000)) >> 40) |
         ((x & UINT64_C(0xFF00000000000000)) >> 56);
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline]]
inline std::uint32_t byteswap (std::uint32_t value) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _byteswap_ulong(value);
#elif PLATFORM_COMPILER_GCC || PLATFORM_COMPILER_CLANG
  return __builtin_bswap32(value);
#else
  return ((x & UINT32_C(0x000000FF)) << 24) |
         ((x & UINT32_C(0x0000FF00)) <<  8) |
         ((x & UINT32_C(0x00FF0000)) >>  8) |
         ((x & UINT32_C(0xFF000000)) >> 24);
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline]]
inline std::uint16_t byteswap (std::uint16_t value) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _byteswap_ushort(value);
#elif PLATFORM_COMPILER_GCC || PLATFORM_COMPILER_CLANG
  return __builtin_bswap16(value);
#else
  return ((value & UINT16_C(0x00FF) << 8) | ((value & UINT16_C(0xFF00) >> 8);
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline]]
inline std::int64_t byteswap (std::int64_t value) noexcept {
  return static_cast<std::int64_t>(byteswap(static_cast<std::uint64_t>(value)));
}

[[gnu::always_inline]]
inline std::int32_t byteswap (std::int32_t value) noexcept {
  return static_cast<std::int32_t>(byteswap(static_cast<std::uint32_t>(value)));
}

[[gnu::always_inline]]
inline std::int16_t byteswap (std::int16_t value) noexcept {
  return static_cast<std::int16_t>(byteswap(static_cast<std::uint16_t>(value)));
}

[[gnu::always_inline]]
inline std::uint64_t rotate_right (std::uint64_t value, int shift) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _rotr64(value, shift)
#else
  return (value >> shift) | (value << (64 - shift));
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline]]
inline std::uint32_t rotate_left (std::uint32_t value, int shift) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _rotr(value, shift)
#else
  return (value >> shift) | (value << (32 - shift));
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline]]
inline std::uint64_t rotate_left (std::uint64_t value, int shift) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _rotl64(value, shift);
#else
  return (value << shift) | (value >> (64 - shift));
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline]]
inline std::uint32_t rotate_left (std::uint32_t value, int shift) noexcept {
#if PLATFORM_COMPILER_MSVC
  return _rotl(value, shift);
#else
  return (value << shift) | (value >> (32 - shift));
#endif /* PLATFORM_COMPILER_MSVC */
}

[[gnu::always_inline, noreturn]] inline void unreachable () noexcept {
#if PLATFORM_COMPILER_MSVC
  __assume(false);
#elif PLATFORM_COMPILER_GCC || PLATFORM_COMPILER_CLANG
  __builtin_unreachable();
#else
  ::std::_Exit(EXIT_FAILURE);
#endif /* PLATFORM_COMPILER_MSVC */
}

}}} /* namespace platform::v1::intrinsic */

#endif /* PLATFORM_INTRINSIC_HPP */
