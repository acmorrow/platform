#ifndef PLATFORM_ARCH_HPP
#define PLATFORM_ARCH_HPP

#include <platform/utility.hpp>

#define PLATFORM_ARCH_UKNOWN 0
#define PLATFORM_ARCH_AMD64 0
#define PLATFORM_ARCH_ARM64 0
#define PLATFORM_ARCH_THUMB 0
#define PLATFORM_ARCH_MIPS 0
#define PLATFORM_ARCH_ARM 0
#define PLATFORM_ARCH_PPC 0
#define PLATFORM_ARCH_X86 0

#if defined(__amd64__)  || \
    defined(__amd64)    || \
    defined(__x86_64__) || \
    defined(__x86_64)   || \
    defined(_M_X64)     || \
    defined(_M_AMD64)
  #undef PLATFORM_ARCH_AMD64
  #define PLATFORM_ARCH_AMD64 1
#elif defined(__aarch64__)
  #undef PLATFORM_ARCH_ARM64
  #define PLATFORM_ARCH_ARM64 1
#elif defined(__thumb__) || \
      defined(_M_ARMT)
  #undef PLATFORM_ARCH_THUMB
  #define PLATFORM_ARCH_THUMB 1
#elif defined(__mips__)
  #undef PLATFORM_ARCH_MIPS
  #define PLATFORM_ARCH_MIPS 1
#elif defined(__arm__) || \
      defined(_M_ARM)
  #undef PLATFORM_ARCH_ARM
  #define PLATFORM_ARCH_ARM 1
#elif defined(__powerpc)     || \
      defined(__powerpc__)   || \
      defined(__powerpc64__) || \
      defined(__POWERPC__)   || \
      defined(__ppc__)       || \
      defined(__ppc64__)     || \
      defined(_M_PPC)
  #undef PLATFORM_ARCH_PPC
  #define PLATFORM_ARCH_PPC 1
#elif defined(__i386__) || \
      defined(__i486__) || \
      defined(__i586__) || \
      defined(__i686__) || \
      defined(_M_IX86)  || \
      defined(__THW_INTEL__)
  #undef PLATFORM_ARCH_X86
  #define PLATFORM_ARCH_X86 1
#else
  #undef PLATFORM_ARCH_UNKNOWN
  #define PLATFORM_ARCH_UNKNOWN 1
#endif /* defined(__amd64__) */

namespace platform {
inline namespace v1 {
namespace arch {

enum class arch_type {
  unknown,
  arm64,
  amd64,
  thumb,
  mips,
  arm,
  ppc,
  x86
};

using is_unknown = utility::boolean<PLATFORM_ARCH_UNKNOWN>;
using is_amd64 = utility::boolean<PLATFORM_ARCH_AMD64>;
using is_arm64 = utility::boolean<PLATFORM_ARCH_ARM64>;
using is_thumb = utility::boolean<PLATFORM_ARCH_THUMB>;
using is_mips = utility::boolean<PLATFORM_ARCH_MIPS>;
using is_arm = utility::boolean<PLATFORM_ARCH_ARM>;
using is_ppc = utility::boolean<PLATFORM_ARCH_PPC>;
using is_x86 = utility::boolean<PLATFORM_ARCH_X86>;

using unknown = utility::enumeration<arch_type, arch_type::unknown>;
using amd64 = utility::enumeration<arch_type, arch_type::amd64>;
using arm64 = utility::enumeration<arch_type, arch_type::arm64>;
using thumb = utility::enumeration<arch_type, arch_type::thumb>;
using mips = utility::enumeration<arch_type, arch_type::mips>;
using arm = utility::enumeration<arch_type, arch_type::arm>;
using ppc = utility::enumeration<arch_type, arch_type::ppc>;
using x86 = utility::enumeration<arch_type, arch_type::x86>;

using current = utility::match_t<
  std::pair<is_unknown, unknown>,
  std::pair<is_amd64, amd64>,
  std::pair<is_arm64, arm64>,
  std::pair<is_thumb, thumb>,
  std::pair<is_mips, mips>,
  std::pair<is_arm, arm>,
  std::pair<is_ppc, ppc>,
  std::pair<is_x86, x86>
>;

}}} /* namespace platform::v1::arch */

#endif /* PLATFORM_ARCH_HPP */
