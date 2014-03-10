.. _using-mnmlstc-platform:

Using MNMLSTC Platform
======================

.. default-domain:: cpp

This section of the documentation details examples on how to use
MNMLSTC Platform within a project. As MNMLSTC Platform does not require
a configuration step, and is header only, installation is as simple as letting
CMake's install target being run.

Host to Network
---------------

For this example, we will use the endian component combined with the
intrinsic component to implement the hton function that is used
in network programming::

    #include <platform/intrinsic.hpp>
    #include <platform/endian.hpp>

    #include <type_traits>
    #include <cstdint>

    template <class T>
    [[gnu::always_inline]]
    inline T hton (T value, platform::endian::little) noexcept {
      return platform::intrinsic::byteswap(value);
    }

    template <class T>
    [[gnu::always_inline]]
    inline T hton (T value, platform::endian::big) noexcept { return value; }

    template <class T>
    [[gnu::always_inline]]
    inline T hton (T value) noexcept  {
      ::hton(value, platform::endian::current { });
    }

When ``hton`` is called, it will use the :type:`current`
instance to select (at compile time) which of the implementations to use.
Because we are inlining these functions, the overhead is neglible (and in the
mystical "sufficiently optimizing compiler" there would be none)
