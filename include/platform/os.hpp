#ifndef PLATFORM_OS_HPP
#define PLATFORM_OS_HPP

#include <platform/utility.hpp>

#define PLATFORM_OS_UNKNOWN 0
#define PLATFORM_OS_WINDOWS 0
#define PLATFORM_OS_ANDROID 0
#define PLATFORM_OS_FREEBSD 0
#define PLATFORM_OS_OPENBSD 0
#define PLATFORM_OS_NETBSD 0
#define PLATFORM_OS_DRAGON 0
#define PLATFORM_OS_MACOSX 0
#define PLATFORM_OS_LINUX 0
#define PLATFORM_OS_IOS 0

#if defined(_WIN32) || \
    defined(_WIN64) || \
    defined(__TOS_WIN__)
  #undef PLATFORM_OS_WINDOWS
  #define PLATFORM_OS_WINDOWS 1
#elif defined(__ANDROID__)
  #undef PLATFORM_OS_ANDROID
  #define PLATFORM_OS_ANDROID 1
#elif defined(__FreeBSD__)
  #undef PLATFORM_OS_FREEBSD
  #define PLATFORM_OS_FREEBSD 1
#elif defined(__OpenBSD__)
  #undef PLATFORM_OS_OPENBSD
  #define PLATFORM_OS_OPENBSD 1
#elif defined(__NetBSD__)
  #undef PLATFORM_OS_NETBSD
  #define PLATFORM_OS_NETBSD 1
#elif defined(__DragonFly__)
  #undef PLATFORM_OS_DRAGON
  #define PLATFORM_OS_DRAGON 1
#elif defined(__APPLE__)
  #undef PLATFORM_OS_MACOSX
  #define PLATFORM_OS_MACOSX 1
#elif defined(__linux__)
  #undef PLATFORM_OS_LINUX
  #define PLATFORM_OS_LINUX 1
#else
  #undef PLATFORM_OS_UNKNOWN
  #define PLATFORM_OS_UNKNOWN 1
#endif /* defined(_WIN32) */

namespace platform {
inline namespace v1 {
namespace os {

enum class os_type {
  unknown,
  windows,
  android,
  freebsd,
  openbsd,
  netbsd,
  dragon,
  macosx,
  linux,
  ios
};

using is_unknown = utility::boolean<PLATFORM_OS_UNKNOWN>;
using is_windows = utility::boolean<PLATFORM_OS_WINDOWS>;
using is_android = utility::boolean<PLATFORM_OS_ANDROID>;
using is_freebsd = utility::boolean<PLATFORM_OS_FREEBSD>;
using is_openbsd = utility::boolean<PLATFORM_OS_OPENBSD>;
using is_netbsd = utility::boolean<PLATFORM_OS_NETBSD>;
using is_dragon = utility::boolean<PLATFORM_OS_DRAGON>;
using is_macosx = utility::boolean<PLATFORM_OS_MACOSX>;
using is_linux = utility::boolean<PLATFORM_OS_LINUX>;
using is_ios = utility::boolean<PLATFORM_OS_IOS>;

using unknown = utility::enumeration<os_type, os_type::unknown>;
using windows = utility::enumeration<os_type, os_type::windows>;
using android = utility::enumeration<os_type, os_type::android>;
using freebsd = utility::enumeration<os_type, os_type::freebsd>;
using openbsd = utility::enumeration<os_type, os_type::openbsd>;
using netbsd = utility::enumeration<os_type, os_type::netbsd>;
using dragon = utility::enumeration<os_type, os_type::dragon>;
using macosx = utility::enumeration<os_type, os_type::macosx>;
using linux = utility::enumeration<os_type, os_type::linux>;
using ios = utility::enumeration<os_type, os_type::ios>;

using current = utility::match_t<
  std::pair<is_windows, windows>,
  std::pair<is_android, android>,
  std::pair<is_freebsd, freebsd>,
  std::pair<is_openbsd, openbsd>,
  std::pair<is_netbsd, netbsd>,
  std::pair<is_dragon, dragon>,
  std::pair<is_macosx, macosx>,
  std::pair<is_linux, linux>,
  std::pair<is_ios, ios>
>;

}}} /* namespace platform::v1::os */

#endif /* PLATFORM_OS_HPP */
