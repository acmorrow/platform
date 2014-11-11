#define CATCH_CONFIG_MAIN
#include <platform/intrinsic.hpp>
#include <catch.hpp>

TEST_CASE("byteswap-u64") {
  std::uint64_t beef = UINT64_C(0xBEEFBEEFBEEFBEEF);
  std::uint64_t efbe = UINT64_C(0xEFBEEFBEEFBEEFBE);
  CHECK(platform::intrinsic::byteswap(beef) == efbe);
}

TEST_CASE("byteswap-i64") {
  std::int64_t lhs = INT64_C(0x0000EF1234567809);
  std::int64_t rhs = INT64_C(0x0978563412EF0000);
  CHECK(platform::intrinsic::byteswap(lhs) == rhs);
}

TEST_CASE("byteswap-u32") {
  std::uint32_t lhs = UINT32_C(0xDEADBEEF);
  std::uint32_t rhs = UINT32_C(0xEFBEADDE);
  CHECK(platform::intrinsic::byteswap(lhs) == rhs);
}

TEST_CASE("byteswap-i32") {
  std::int32_t lhs = INT32_C(0x0EADBE0F);
  std::int32_t rhs = INT32_C(0x0FBEAD0E);
  CHECK(platform::intrinsic::byteswap(lhs) == rhs);
}

TEST_CASE("byteswap-u16") {
  std::uint16_t lhs = UINT16_C(0xBEEF);
  std::uint16_t rhs = UINT16_C(0xEFBE);
  CHECK(platform::intrinsic::byteswap(lhs) == rhs);
}

TEST_CASE("byteswap-i16") {
  std::int16_t lhs = INT16_C(0x0E0A);
  std::int16_t rhs = INT16_C(0x0A0E);
  CHECK(platform::intrinsic::byteswap(lhs) == rhs);
}

TEST_CASE("rotate-right-64") {
  std::uint64_t lhs = UINT64_C(0xDEADBEEFDEADC0DE);
  std::uint64_t rhs = UINT64_C(0xDBD5B7DDFBD5B81B);
  CHECK(platform::intrinsic::rotate_right(lhs, 3) == rhs);
}

TEST_CASE("rotate-right-32") {
  std::uint32_t lhs = UINT32_C(0xDEADBEEF);
  std::uint32_t rhs = UINT32_C(0x7EF56DF7);
  CHECK(platform::intrinsic::rotate_right(lhs, 5) == rhs);
}

TEST_CASE("rotate-left-64") {
  std::uint64_t lhs = UINT64_C(0xDEADBEEFDEADC0DE);
  std::uint64_t rhs = UINT64_C(0xD5B7DDFBD5B81BDB);
  CHECK(platform::intrinsic::rotate_left(lhs, 5) == rhs);
}

TEST_CASE("rotate-left-32") {
  std::uint32_t lhs = UINT32_C(0xDEADBEEF);
  std::uint32_t rhs = UINT32_C(0xDFBD5B7D);
  CHECK(platform::intrinsic::rotate_right(lhs, 7) == rhs);
}
