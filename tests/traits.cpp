#define CATCH_CONFIG_MAIN
#include <platform/compiler.hpp>
#include <platform/endian.hpp>
#include <platform/arch.hpp>
#include <platform/simd.hpp>
#include <platform/os.hpp>
#include <catch.hpp>

TEST_CASE("compiler") {
  constexpr auto is_void = std::is_same<
    platform::compiler::current,
    void
  >::value;
  constexpr auto is_unknown = platform::compiler::is_unknown::value;
  CHECK_FALSE(is_unknown);
  CHECK_FALSE(is_void);
}

TEST_CASE("endian") {
  constexpr auto is_void = std::is_same<platform::endian::current, void>::value;
  constexpr auto is_unknown = platform::endian::is_unknown::value;
  CHECK_FALSE(is_unknown);
  CHECK_FALSE(is_void);
}

TEST_CASE("arch") {
  constexpr auto is_void = std::is_same<platform::arch::current, void>::value;
  constexpr auto is_unknown = platform::arch::is_unknown::value;
  CHECK_FALSE(is_unknown);
  CHECK_FALSE(is_void);
}

TEST_CASE("os") {
  constexpr auto is_void = std::is_same<platform::os::current, void>::value;
  constexpr auto is_unknown = platform::os::is_unknown::value;
  CHECK_FALSE(is_unknown);
  CHECK_FALSE(is_void);
}
