#ifndef PLATFORM_INTRINSIC_HPP
#define PLATFORM_INTRINSIC_HPP

#include <platform/compiler.hpp>

#include <cstdlib>
#include <cstdint>

#if PLATFORM_COMPILER_MSVC
  #include <xmmintrin.h>

  #define PLATFORM_INTRINSIC_PREFETCH_WRITE(p, l) _mm_prefetch(p, l)
  #define PLATFORM_INTRINSIC_PREFETCH_READ(p, l) _mm_prefetch(p, l)

  #define PLATFORM_INTRINSIC_ROTATE_LEFT64(x, s) _rotl64(x, s)
  #define PLATFORM_INTRINSIC_ROTATE_LEFT32(x, s) _rotl(x, s)

  #define PLATFORM_INTRINSIC_BYTESWAP64 _byteswap_uint64
  #define PLATFORM_INTRINSIC_BYTESWAP32 _byteswap_ulong
  #define PLATFORM_INTRINSIC_BYTESWAP16 _byteswap_ushort

  #define PLATFORM_INTRINSIC_UNREACHABLE [] { __assume(false); }

#elif PLATFORM_COMPILER_CLANG || PLATFORM_COMPILER_GCC
  #define PLATFORM_INTRINSIC_PREFETCH_WRITE(p, l) __builtin_prefetch(p, 1, l)
  #define PLATFORM_INTRINSIC_PREFETCH_READ(p, l) __builtin_prefetch(p, 0, l)

  #define PLATFORM_INTRINSIC_ROTATE_LEFT64(x, s) \
    [=] { return (x << s) | (x >> (64 - s)); }()

  #define PLATFORM_INTRINSIC_ROTATE_LEFT32(x, s) \
    [=] { return (x << s) | (x >> (32 - s)); }()

  #define PLATFORM_INTRINSIC_BYTESWAP64 __builtin_bswap64
  #define PLATFORM_INTRINSIC_BYTESWAP32 __builtin_bswap32
  #define PLATFORM_INTRINSIC_BYTESWAP16 __builtin_bswap16

  #define PLATFORM_INTRINSIC_UNREACHABLE __builtin_unreachable
#else

  #define PLATFORM_INTRINSIC_PREFETCH_WRITE(x, y) [] noexcept {}()
  #define PLATFORM_INTRINSIC_PREFETCH_READ(x, y) [] noexcept {}()

  #define PLATFORM_INTRINSIC_ROTATE_LEFT64(x, s) \
    [=] { return (x << s) | (x >> (64 - s)); }()

  #define PLATFORM_INTRINSIC_ROTATE_LEFT32(x, s) \
    [=] { return (x << s) | (x >> (32 - s)); }()


  #define PLATFORM_INTRINSIC_BYTESWAP64 \
    [] (::std::uint64_t value) noexcept { \
      return ((x & UINT64_C(0x00000000000000FF)) << 56) | \
             ((x & UINT64_C(0x000000000000FF00)) << 40) | \
             ((x & UINT64_C(0x0000000000FF0000)) << 24) | \
             ((x & UINT64_C(0x00000000FF000000)) <<  8) | \
             ((x & UINT64_C(0x000000FF00000000)) >>  8) | \
             ((x & UINT64_C(0x0000FF0000000000)) >> 24) | \
             ((x & UINT64_C(0x00FF000000000000)) >> 40) | \
             ((x & UINT64_C(0xFF00000000000000)) >> 56);  \
    }

  #define PLATFORM_INTRINSIC_BYTESWAP32 \
    [] (::std::uint32_t value) noexcept { \
      return ((x & UINT32_C(0x000000FF)) << 24) | \
             ((x & UINT32_C(0x0000FF00)) <<  8) | \
             ((x & UINT32_C(0x00FF0000)) >>  8) | \
             ((x & UINT32_C(0xFF000000)) >> 24); \
    }

  #define PLATFORM_INTRINSIC_BYTESWAP16 \
    [] (::std::uint16_t value) noexcept { \
      return ((value & UINT16_C(0x00FF) << 8) | \
             ((value & UINT16_C(0xFF00) >> 8);  \
    }

#define PLATFORM_INTRINSIC_UNREACHABLE [] { ::std::_Exit(EXIT_FAILURE); }

#endif /* PLATFORM_COMPILE_MSVC */

namespace platform {
inline namespace v1 {
namespace intrinsic {

enum class locality : int {
  none = 0,
  low = 1,
  medium = 2,
  high = 3
};

inline void prefetchw (char const* ptr, locality loc) noexcept {
  PLATFORM_INTRINSIC_PREFETCH_WRITE(
    ptr,
    static_cast<typename std::underlying_type<locality>::type>(loc)
  );
}

inline void prefetch (char const* ptr, locality loc) noexcept {
  PLATFORM_INTRINSIC_PREFETCH_READ(
    ptr,
    static_cast<typename std::underlying_type<locality>::type>(loc)
  );
}

inline void prefetchw (void const* ptr, locality loc) noexcept {
  return prefetchw(ptr, loc);
}

inline void prefetch (void const* ptr, locality loc) noexcept {
  return prefetch(reinterpret_cast<char const*>(ptr), loc);
}

inline std::uint32_t rotate_left (std::uint64_t value, int shift) {
  return PLATFORM_INTRINSIC_ROTATE_LEFT64(value, shift);
}

inline std::uint32_t rotate_left (std::uint32_t value, int shift) {
  return PLATFORM_INTRINSIC_ROTATE_LEFT32(value, shift);
}

inline std::uint64_t byteswap (std::uint64_t value) noexcept {
  return PLATFORM_INTRINSIC_BYTESWAP64(value);
}

inline std::uint32_t byteswap (std::uint32_t value) noexcept {
  return PLATFORM_INTRINSIC_BYTESWAP32(value);
}

inline std::uint16_t byteswap (std::uint16_t value) noexcept {
  return PLATFORM_INTRINSIC_BYTESWAP16(value);
}

inline std::int64_t byteswap (std::int64_t val) noexcept {
  return static_cast<std::int64_t>(byteswap(static_cast<std::uint64_t>(val)));
}

inline std::int32_t byteswap (std::int32_t val) noexcept {
  return static_cast<std::int32_t>(byteswap(static_cast<std::uint32_t>(val)));
}

inline std::int16_t byteswap(std::int16_t val) noexcept {
  return static_cast<std::int16_t>(byteswap(static_cast<std::int16_t>(val)));
}

[[noreturn]] inline void unreachable () noexcept {
  PLATFORM_INTRINSIC_UNREACHABLE();
}

}}} /* namespace platform::v1::intrinsic */

#endif /* PLATFORM_INTRINSIC_HPP */
