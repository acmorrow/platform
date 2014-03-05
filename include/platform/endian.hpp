#ifndef PLATFORM_ENDIAN_HPP
#define PLATFORM_ENDIAN_HPP

#include <platform/utility.hpp>

#define PLATFORM_ENDIAN_UNKNOWN 0
#define PLATFORM_ENDIAN_LITTLE 0
#define PLATFORM_ENDIAN_BIG 0

#if defined(__LITTLE_ENDIAN__) || \
    defined(__ARMEL__)         || \
    defined(__THUMBEL__)       || \
    defined(__AARCH64EL__)     || \
    defined(_MIPSEL)           || \
    defined(__MIPSEL)          || \
    defined(__MIPSEL__)        || \
    defined(__amd64__)         || \
    defined(__amd64)           || \
    defined(__x86_64__)        || \
    defined(__x86_64)          || \
    defined(_M_X64)            || \
    defined(_M_AMD64)          || \
    defined(__i386__)          || \
    defined(__i486__)          || \
    defined(__i586__)          || \
    defined(__i686__)          || \
    defined(_M_IX86)           || \
    defined(__THW_INTEL__)
  #undef PLATFORM_ENDIAN_LITTLE
  #define PLATFORM_ENDIAN_LITTLE 1
#elif defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__)        || \
    defined(__THUMBEB__)      || \
    defined(__AARCH64EB__)    || \
    defined(_MIPSEB)          || \
    defined(__MIPSEB)         || \
    defined(__MIPSEB__)       || \
    defined(__powerpc)        || \
    defined(__powerpc__)      || \
    defined(__powerpc64__)    || \
    defined(__POWERPC__)      || \
    defined(__ppc__)          || \
    defined(__ppc64__)        || \
    defined(__M_PPC)
  #undef PLATFORM_ENDIAN_BIG
  #define PLATFORM_ENDIAN_BIG 1
#else
  #undef PLATFORM_ENDIAN_UNKNOWN
  #define PLATFORM_ENDIAN_UNKNOWN 1
#endif /* defined(__LITTLE_ENDIAN__) */

namespace platform {
inline namespace v1 {
namespace endian {

enum class endian_type {
  unknown,
  little,
  big
};

using is_unknown = utility::boolean<PLATFORM_ENDIAN_UNKNOWN>;
using is_little = utility::boolean<PLATFORM_ENDIAN_LITTLE>;
using is_big = utility::boolean<PLATFORM_ENDIAN_BIG>;

using unknown = utility::enumeration<endian_type, endian_type::unknown>;
using little = utility::enumeration<endian_type, endian_type::little>;
using big = utility::enumeration<endian_type, endian_type::big>;

using current = utility::match_t<
  std::pair<is_unknown, unknown>,
  std::pair<is_little, little>,
  std::pair<is_big, big>
>;

}}} /* namespace platform::v1::endian */

#endif /* PLATFORM_ENDIAN_HPP */
