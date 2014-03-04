#ifndef PLATFORM_SIMD_HPP
#define PLATFORM_SIMD_HPP

#include <platform/compiler.hpp>
#include <platform/arch.hpp>

#define PLATFORM_SIMD_SSE42 0
#define PLATFORM_SIMD_SSE41 0
#define PLATFORM_SIMD_SSSE3 0
#define PLATFORM_SIMD_NEON 0
#define PLATFORM_SIMD_SSE3 0
#define PLATFORM_SIMD_SSE2 0
#define PLATFORM_SIMD_SSE 0
#define PLATFORM_SIMD_AVX 0

#if defined(__AVX__)
  #undef PLATFORM_SIMD_AVX
  #define PLATFORM_SIMD_AVX 1
#endif /* defined(__AVX__) */

#if defined(__SSE4_2__)
  #undef PLATFORM_SIMD_SSE42
  #define PLATFORM_SIMD_SSE42 1
#endif /* defined(__SSE4_2__) */

#if defined(__SSE4_1__)
  #undef PLATFORM_SIMD_SSE41
  #define PLATFORM_SIMD_SSE41 1
#endif /* defined(__SSE4_1__) */

#if defined (__SSSE3__)
  #undef PLATFORM_SIMD_SSSE3
  #define PLATFORM_SIMD_SSSE 1
#endif /* defined(__SSSE3__) */

#if defined(__SSE3__)
  #undef PLATFORM_SIMD_SSE3
  #define PLATFORM_SIMD_SSE3 1
#endif /* defined(__SSE3__) */

#if defined(__SSE2__)
  #undef PLATFORM_SIMD_SSE2
  #define PLATFORM_SIMD_SSE2 1
#endif /* defined(__SSE2__) */

#if defined(__SSE__)
  #undef PLATFORM_SIMD_SSE
  #define PLATFORM_SIMD_SSE 1
#endif /* defined(__SSE__) */

#if defined(__ARM_NEON__)
  #undef PLATFORM_SIMD_NEON
  #define PLATFORM_SIMD_NEON 1
#endif /* defined(__ARM_NEON__) */

#if defined(_M_IX86_FP)
  #if _M_IX86_FP >= 1
    #undef PLATFORM_SIMD_SSE
    #define PLATFORM_SIMD_SSE 1
  #endif /* _M_IX86_FP > 0 */

  #if _M_IX86_FP == 2
    #undef PLATFORM_SIMD_SSE2
    #define PLATFORM_SIMD_SSE2 1
  #endif /* _M_IX86_FP == 2 */
#endif /* defined(_M_IX86_FP) */

namespace platform {
inline namespace v1 {
namespace simd {

enum class simd_type {
  sse42,
  sse41,
  ssse3,
  neon,
  sse3,
  sse2,
  sse,
  avx
};

using is_sse42 = utility::boolean<PLATFORM_SIMD_SSE42>;
using is_sse41 = utility::boolean<PLATFORM_SIMD_SSE41>;
using is_ssse3 = utility::boolean<PLATFORM_SIMD_SSSE3>;
using is_neon = utility::boolean<PLATFORM_SIMD_NEON>;
using is_sse3 = utility::boolean<PLATFORM_SIMD_SSE3>;
using is_sse2 = utility::boolean<PLATFORM_SIMD_SSE2>;
using is_sse = utility::boolean<PLATFORM_SIMD_SSE>;
using is_avx = utility::boolean<PLATFORM_SIMD_AVX>;

using sse42 = utility::enumeration<simd_type, simd_type::sse42>;
using sse41 = utility::enumeration<simd_type, simd_type::sse41>;
using ssse3 = utility::enumeration<simd_type, simd_type::ssse3>;
using neon = utility::enumeration<simd_type, simd_type::neon>;
using sse3 = utility::enumeration<simd_type, simd_type::sse3>;
using sse2 = utility::enumeration<simd_type, simd_type::sse2>;
using sse = utility::enumeration<simd_type, simd_type::sse>;
using avx = utility::enumeration<simd_type, simd_type::avx>;

}}} /* namespace platform::v1::simd */

#endif /* PLATFORM_SIMD_HPP */
