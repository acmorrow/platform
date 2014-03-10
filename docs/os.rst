.. _platform-os-component:

Operating System Definitions
============================

.. default-domain:: cpp

There are a "variety" of operating systems in todays world. The quotes are
there to denote sarcasm. We're down to about 3 main big desktop operating
systems and about the same 3 for mobile. There's a few outliers, but MNMLSTC
Platform does not currently care about them. The OS component for
MNMLSTC Platform provides the preprocessor definitions and SFINAE types to
allow one to determine which operating system is currently being compiled as
the target.

.. namespace:: platform::os

All of the macros provided have a value of *0* by default.

.. c:macro:: PLATFORM_OS_UNKNOWN

   When targeting an operating system that MNMLSTC Platform does not understand,
   this macro will have the value *1*.

.. c:macro:: PLATFORM_OS_WINDOWS

   When targeting Windows 32-bit or 64-bit platforms, this macro will have the
   value *1*.

.. c:macro:: PLATFORM_OS_ANDROID

   When targeting the Android Operating System, this macro will have the value
   *1*.

.. c:macro:: PLATFORM_OS_FREEBSD

   When targeting the FreeBSD Operating System, this macro will have the value
   *1*.

.. c:macro:: PLATFORM_OS_OPENBSD

   When targeting the OpenBSD Operating System, this macro will have the value
   *1*.

.. c:macro:: PLATFORM_OS_NETBSD

   When targeting the NetBSD Operating System, this macro will have the value
   *1*.

.. c:macro:: PLATFORM_OS_DRAGON

   When targeting the DragonBSD Operating System, this macro will have the
   value *1*.

.. c:macro:: PLATFORM_OS_MACOSX

   When targeting Mac OS X, this macro will have the value *1*.

.. c:macro:: PLATFORM_OS_LINUX

   When targeting a Linux kernel, this macro will have the value *1*.

.. c:macro:: PLATFORM_OS_IOS

   When targeting iOS, this macro will have the value *1*.

.. class:: os_type

   This is an ``enum class`` containing the following members:

    * unknown
    * windows
    * android
    * freebsd
    * openbsd
    * netbsd
    * dragon
    * macosx
    * linux
    * ios

  This type should be used for runtime based calls and parameters to functions.
  If a compile time value can be used, it is recommended to use those instead
  in conjunction with :type:`current`.

.. type:: is_unknown 
          is_windows 
          is_android 
          is_freebsd 
          is_openbsd 
          is_netbsd
          is_dragon
          is_macosx
          is_linux
          is_ios

   These types are equivalent to either ``std::true_type`` or
   ``std::false_type``, depending on whether the corresponding macro is
   *1* or *0*.

.. type:: unknown
          windows
          android
          freebsd
          openbsd
          netbsd
          dragon
          macosx
          linux
          ios

   These are of the type ``std::integral_constant<os_type, V>`` where ``V`` is
   the value contained within the enum class :class:`os_type`.

.. type:: current

   This is an integral constant value whose value is equivalent to the
   currently targeted os within :class:`os_type`.
