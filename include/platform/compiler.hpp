#ifndef PLATFORM_COMPILER_HPP
#define PLATFORM_COMPILER_HPP

#include <platform/utility.hpp>

#define PLATFORM_COMPILER_UNKNOWN 0
#define PLATFORM_COMPILER_CLANG 0
#define PLATFORM_COMPILER_INTEL 0
#define PLATFORM_COMPILER_MSVC 0
#define PLATFORM_COMPILER_EKO 0
#define PLATFORM_COMPILER_GCC 0
#define PLATFORM_COMPILER_GHS 0
#define PLATFORM_COMPILER_IBM 0

#if defined(__clang__)
  #undef PLATFORM_COMPILER_CLANG
  #define PLATFORM_COMPILER_CLANG 1
#elif defined(__INTEL_COMPILER)
  #undef PLATFORM_COMPILER_INTEL
  #define PLATFORM_COMPILER_INTEL 1
#elif defined(_MSC_VER)
  #undef PLATFORM_COMPILER_MSVC
  #define PLATFORM_COMPILER_MSVC 1
#elif defined(__PATHCC__)
  #undef PLATFORM_COMPILER_EKO
  #define PLATFORM_COMPILER_EKO 1
#elif defined(__GNUC__)
  #undef PLATFORM_COMPILER_GCC
  #define PLATFORM_COMPILER_GCC 1
#elif defined(__ghs__)
  #undef PLATFORM_COMPILER_GHS
  #define PLATFORM_COMPILER_GHS 1
#elif defined(__xlc__)
  #undef PLATFORM_COMPILER_IBM
  #define PLATFORM_COMPILER_IBM 1
#else
  #undef PLATFORM_COMPILER_UNKNOWN
  #define PLATFORM_COMPILER_UNKNOWN 1
#endif /* defined(__clang__) */

namespace platform {
inline namespace v1 {
namespace compiler {

enum class compiler_type {
  unknown,
  clang,
  intel,
  msvc,
  eko,
  gcc,
  ghs,
  ibm
};

using is_unknown = utility::boolean<PLATFORM_COMPILER_UNKNOWN>;
using is_clang = utility::boolean<PLATFORM_COMPILER_CLANG>;
using is_intel = utility::boolean<PLATFORM_COMPILER_INTEL>;
using is_msvc = utility::boolean<PLATFORM_COMPILER_MSVC>;
using is_eko = utility::boolean<PLATFORM_COMPILER_EKO>;
using is_gcc = utility::boolean<PLATFORM_COMPILER_GCC>;
using is_ghs = utility::boolean<PLATFORM_COMPILER_GHS>;
using is_ibm = utility::boolean<PLATFORM_COMPILER_IBM>;

using unknown = utility::enumeration<compiler_type, compiler_type::unknown>;
using clang = utility::enumeration<compiler_type, compiler_type::clang>;
using intel = utility::enumeration<compiler_type, compiler_type::intel>;
using msvc = utility::enumeration<compiler_type, compiler_type::msvc>;
using eko = utility::enumeration<compiler_type, compiler_type::eko>;
using gcc = utility::enumeration<compiler_type, compiler_type::gcc>;
using ghs = utility::enumeration<compiler_type, compiler_type::ghs>;
using ibm = utility::enumeration<compiler_type, compiler_type::ibm>;

using current = utility::match_t<
  std::pair<is_unknown, unknown>,
  std::pair<is_clang, clang>,
  std::pair<is_intel, intel>,
  std::pair<is_msvc, msvc>,
  std::pair<is_eko, eko>,
  std::pair<is_gcc, gcc>,
  std::pair<is_ghs, ghs>,
  std::pair<is_ibm, ibm>
>;

}}} /* namespace platform::v1::compiler */

#endif /* PLATFORM_COMPILER_HPP */
