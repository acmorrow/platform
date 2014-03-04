.. _platform-compiler-component:

Compiler Definitions
====================

.. default-domain:: cpp

As one might be aware, C++ compilers come in all shapes and sizes with a
varying amount of vendor support and behavior. As such, from time to time,
one must perform a preprocessor directive to check which compiler is
working on a given translation unit. The compiler component provides such
preprocessor definitions, while also providing several types for use in
SFINAE expressions.

.. namespace:: platform::compiler

All of the macros provided have a value of *0* by default.

.. c:macro:: PLATFORM_COMPILER_UNKNOWN

   When using a compiler that MNMLSTC Platform does not know of, this
   macro will have the value *1*.

.. c:macro:: PLATFORM_COMPILER_CLANG

   When using the LLVM C++ Compiler known as "Clang", this macro will have
   a value of *1*.

.. c:macro:: PLATFORM_COMPILER_INTEL

   When using the Intel C++ Compiler, this macro will have a value of *1*.

.. c:macro:: PLATFORM_COMPILER_MSVC

   When using the Microsoft Visual C++ Compiler, this macro will have a value
   of 1.

.. c:macro:: PLATFORM_COMPILER_EKO

   When using the Pathscale C++ Compiler, this macro will have a value of 1.

.. c:macro:: PLATFORM_COMPILER_GCC

   When using the Gnu C++ Compiler (Also known as "g++"), this macro will have
   a value of 1.

.. c:macro:: PLATFORM_COMPILER_GHS

   When using the Greenhill Software C++ Compiler, this macro will have a value
   of 1.

.. c:macro:: PLATFORM_COMPILER_IBM

   When using the IBM C++ Compiler (XL C++), this macro will have a value of 1.

.. class:: compiler_type

   This is an ``enum class`` containing the following members:

    * unknown
    * clang
    * intel
    * msvc
    * eko
    * gcc
    * ghs
    * ibm

   This type should be used for parameters to functions, with the intention
   of performing compile time selection of the correct function via
   :type:`current`.

.. type:: is_unknown
          is_clang
          is_intel
          is_msvc
          is_eko
          is_gcc
          is_ibm

   These types are equivalent to either ``std::true_type`` or
   ``std::false_type`` depending on whether or not the corresponding
   macro is 1 or 0.

.. type:: unknown
          clang
          intel
          msvc
          eko
          gcc
          ibm

   These values are of the type ``std::integral_constant<compiler_type, V>``,
   where ``V`` is the value contained within the enum class
   :class:`compiler_type`.

.. type:: current

   This is an integral constant value equivalent to whichever ``is_*``
   parameter evaluates to ``std::true_type``.
