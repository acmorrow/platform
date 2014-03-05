.. _platform-simd-component:

SIMD Component
==============

.. default-domain:: cpp

SIMD support varies per platform, however with recent technology trends, the
two major ones are SSE (and all versions related to it) and NEON. The SIMD
component provides detection for which are guaranteed to be available by the
compiler. Unlike the other components contained within MNMLSTC Platform,
the SIMD component does not provide a 'current' type in the namespace. This
is due to multiple levels of SSE support being available. (That is a machine
that supports SSE2 also inherently supports SSE). Regardless, types and
macro are provided for as much SIMD support as is possible on x86/amd64 or
ARM processors. No attempts are made to check for Altivec support at this time.

.. namespace:: platform::simd

All of the macros provided have a value of *0* by default.

.. c:macro:: PLATFORM_SIMD_SSE42

   When compiling for an x86 or amd64 processor with SSE 4.2 support, this macro
   will have a value of *1*.

.. c:macro:: PLATFORM_SIMD_SSE41

   When compiling for an x86 or amd64 processor with SSE 4.1 support, this macro
   will have a value of *1*.

.. c:macro:: PLATFORM_SIMD_SSSE3

   When compiling for an x86 or amd64 processor with SSSE3 support, this macro
   will have a value of *1*.

.. c:macro:: PLATFORM_SIMD_NEON

   When compiling for an ARM processor with NEON support, this macro will have
   a value of *1*.

.. c:macro:: PLATFORM_SIMD_SSE3

   When compiling for an x86 or amd64 processor with SSE3 support, this macro
   will have a value of *1*.

.. c:macro:: PLATFORM_SIMD_SSE2

   When compiling for an x86 or amd64 processor with SSE2 support, this macro
   will have a value of *1*.

.. c:macro:: PLATFORM_SIMD_SSE

   When compiling for an x86 or amd64 processor with SSE support, this macro
   will have a value of *1*

.. c:macro:: PLATFORM_SIMD_AVX

   When compiling for an amd64 processor with AVX support, this macro will have
   a value of *1*.

.. class:: simd_type

   This is an ``enum class`` containing the following members:

   * sse42
   * sse41
   * ssse3
   * neon
   * sse3
   * sse2
   * sse
   * avx

   This type should be used for paramters to functions to allow for compile and
   runtime selection of code paths.

.. type:: is_sse42
          is_sse41
          is_ssse3
          is_neon
          is_sse3
          is_sse2
          is_sse
          is_avx

   These types are equivalent to either ``std::true_type`` or
   ``std::false_type`` depending on whether or not the corresponding macro is
   1 or 0.

.. type:: sse42
          sse41
          ssse3
          neon
          sse3
          sse2
          sse
          avx

   These values are of the type ``std::integral_constant<simd_type, V>`` where
   ``V`` is the value contained within the enum class :class:`simd_type`.
