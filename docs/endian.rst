.. _platform-endian-component:

Endian Component
================

.. default-domain:: cpp

Most processors today are either big endian or little endian. However it is
usually a pain to handle checking for each possibile preprocessor macro.
The endian component provides types and preprocessor definitions to allow a
developer to detect the endianess of their platform as well as branch code
at compile time.

.. note:: While there are some platforms that do have an endianess that
   is neither big or little (middle endian, for instance), MNMLSTC Platform
   does not support detection of them. It is recommended that you use a
   different library if you are trapped developing for such a platform.

.. namespace:: platform::endian

All macros have a default value of *0*.

.. c:macro:: PLATFORM_ENDIAN_UNKNOWN

   When the endian for a given platfom cannot be detected, this macro will have
   a value of *1*.

.. c:macro:: PLATFORM_ENDIAN_LITTLE

   When a little endian platform is detected, this macro will have a value of
   *1*.

.. c:macro:: PLATFORM_ENDIAN_BIG

   When a big endian platform is detected, this macro will have a value of *1*.

.. class:: endian_type

   An ``enum class`` with three members:

    * unknown
    * little
    * big

   It is recommended to use this type as a parameter to a function to allow
   for compile time selection of code paths, without the use of preprocessor
   ifdefs.

.. type:: is_unknown
          is_little
          is_big

   These types evaluate to either ``std::true_type`` or ``std::false_type``,
   depending on whether the corresponding macro is *1* or *0*.

.. type:: unknown
          little
          big

   These types are equivalent to ``std::integral_constant<endian_type, V>``
   where ``V`` is the value contained within the enum class
   :class:`endian_type`.

.. type:: current

   This type is an alias for the integral constant type whose ``is_*``
   equivalent is equal to ``std::true_type``.
