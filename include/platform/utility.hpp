#ifndef PLATFORM_UTILITY_HPP
#define PLATFORM_UTILITY_HPP

#include <type_traits>
#include <utility>

namespace platform {
inline namespace v1 {
namespace utility {

template <class... Args> struct match;

template <class T>
struct match<T> : std::conditional<
  typename T::first_type::value,
  typename T::second_type,
  std::integral_constant<
    typename T::second_type,
    typename T::second_type::unknown
  >
> { };


template <class T, class... Args>
struct match<T, Args...> : std::conditional<
  typename T::first_type::value,
  typename T::second_type,
  typename match<Args...>::type
>;

template <class T, T val> using enumeration = std::integral_constant<T, val>;
template <bool value> using boolean = std::integral_constant<bool, value>;
template <class... Args> using match_t = typename match<Args...>::type;


}}} /* namespace platform::v1::utility */

#endif /* PLATFORM_UTILITY_HPP */
