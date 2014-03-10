.. _platform-arch-component:

Architecture Component
======================

.. default-domain:: cpp

The architecture component of MNMLSTC Platform provides preprocessor
definitions and types for a common set of CPU architectures. These are
specifically ARM, MIPS, Intel, and POWER processors. While there are certainly
many more architectures, these are usually found in mainframes, and MNMLSTC
Platform does not attempt to support these platforms.

.. namespace:: platform::arch

All macros have a default value of *0*.

.. c:macro:: PLATFORM_ARCH_UNKNOWN

   If the current targeted architecture is unknown, this macro will have a
   value of 1.

.. c:macro:: PLATFORM_ARCH_AMD64

   If the current targeted architecture is amd64, this macro will have a value
   of 1.

.. c:macro:: PLATFORM_ARCH_ARM64

   If the current targeted architecture is 64-bit ARM, this macro will have a
   value of 1.

.. c:macro:: PLATFORM_ARCH_THUMB

   If the current targeted architecture is ARM Thumb, this macro will have a
   value of 1.

.. c:macro:: PLATFORM_ARCH_MIPS

   If the current targeted architecture is MIPS, this macro will have a value
   of 1.

.. c:macro:: PLATFORM_ARCH_ARM

   If the current targeted architecture is 32-bit ARM, this macro will have a
   value of 1.

.. c:macro:: PLATFORM_ARCH_PPC

   If the current target architecture is a POWER processor, this macro will
   have a value of 1.

.. c:macro:: PLATFORM_ARCH_X86

   If the current target architecture is an Intel x86 processor, this macro
   will have a value of 1.

.. class:: arch_type

   An ``enum class`` with the members:

    * unknown
    * arm64
    * amd64
    * thumb
    * mips
    * arm
    * ppc
    * x86

  This type is used to create a set of integral constants that may be used
  as function parameters. It is recommended that one use the integral constant
  values over the enum class directly.

.. type:: is_unknown
          is_amd64
          is_arm64
          is_thumb
          is_mips
          is_arm
          is_ppc
          is_x86

   These types are equivalent to either ``std::true_type`` or
   ``std::false_type``, depending on their corresponding macro.

.. type:: unknown
          amd64
          arm64
          thumb
          mips
          arm
          ppc
          x86

   These are equivalent to ``std::integral_constant<arch_type, V>``, where
   ``V`` is one of the values in :class:`arch_type`.

.. type:: current

   This type is an integral constant equivalent to one whichever platform the
   user is currently targeting.
