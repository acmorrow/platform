.. _platform-intrinsic-component:

Compiler Intrinsics
===================

.. default-domain:: cpp

Compiler intrinsics are useful in that they usually compile down to the minimal
assembly instructions. Most common are functions to byteswap, rotate bits, or
mark a section of code as unreachable. Intrinsics for specific SIMD
implementations (for example SSE or NEON) are not within the scope of
MNMLSTC Platform.

.. namespace:: platform::intrinsic

.. function:: std::uint64_t byteswap (std::uint64_t value)
              std::uint32_t byteswap (std::uint32_t value)
              std::uint16_t byteswap (std::uint16_t value)
              std::int64_t byteswap (std::int64_t value)
              std::int32_t byteswap (std::int32_t value)
              std::int16_t byteswap (std::int16_t value)

   :noexcept: ``true``

   Returns an integer the same type as *value*, with its bytes in the reverse
   order. This function is useful for swapping bytes to convert from
   big to little endian.

.. function:: std::uint64_t rotate_right (std::uint64_t value, int shift)
              std::uint32_t rotate_right (std::uint32_t value, int shift)

   :noexcept: ``true``

   Rotates bits in *value* to the right *shift* bits.

.. function:: std::uint64_t rotate_left (std::uint64_t value, int shift)
              std::uint32_t rotate_left (std::uint32_t value, int shift)

   :noexcept: ``true``

   Rotates bits in *value* to left *shift* bits.

.. function:: void unreachable ()

   :noexcept: ``true``

   When this function is called, the compiler will either insert code that
   causes undefined behavior (most likely a segfault), or call
   ``std::_Exit(EXIT_FAILURE)`` if the compiler does not support this kind
   of intrinsic. This function is marked as ``[[noreturn]]``.
