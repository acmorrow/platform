#ifndef PLATFORM_UTILITY_HPP
#define PLATFORM_UTILITY_HPP

#include <type_traits>
#include <utility>

namespace platform {
inline namespace v1 {
namespace utility {

template <class T, T val> using enumeration = std::integral_constant<T, val>;

template <class... Args> struct match;

template <class T>
struct match<T> : std::conditional<
  std::is_same<typename T::first_type, std::true_type>::value,
  typename T::second_type,
  void
> { };

template <class T, class... Args>
struct match<T, Args...> : std::conditional<
  std::is_same<typename T::first_type, std::true_type>::value,
  typename T::second_type,
  typename match<Args...>::type
> { };

template <bool value> using boolean = std::integral_constant<bool, value>;
template <class... Args> using match_t = typename match<Args...>::type;


}}} /* namespace platform::v1::utility */

#endif /* PLATFORM_UTILITY_HPP */
