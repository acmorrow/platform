Overview
========

MNMLSTC Platform is a small C++11 header library intended to provide a set of
C preprocessor defines as well as type traits to allow a developer to determine
the current platform, architecture, endianess, and operating system they
are compiling for. It is nearly equivalent to Boost.Predef, but is not
compatible with it.

Information on installing and using MNMLSTC Platform can be found in its
`documentation <http://mnmlstc.github.io/platform>`_.

MNMLSTC Platform is released under the Apache 2.0 License

Basic Example
-------------

Below is a basic example on how to use MNMLSTC Platform::

    #include <platform/intrinsic.hpp>
    #include <platform/endian.hpp>

    #include <cstdint>

    namespace {
      inline std::uint32_t network_to_host (
        std::uint32_t value,
        platform::endian::big
      ) noexcept { return value; }

      inline std::uint32_t network_to_host (
        std::uint32_t value,
        platform::endian::little
      ) noexcept { return platform::intrinsic::byteswap(value); }

      inline std::uint32_t host_to_network (
        std::uint32_t value,
        platform::endian::big
      ) noexcept { return value; }

      inline std::uint32_t host_to_network (
        std::uint32_t value,
        platform::endian::little
      ) noexcept { return platform::intrinsic::byteswap(value); }
    }

    inline std::uint32_t network_to_host (std::uint32_t value) noexcept {
      return ::network_to_host(value, platform::endian::current);
    }

Requirements
------------

MNMLSTC Platform requires the following:

 * A C++11 compliant compiler
 * `CMake 2.8.12 <http://cmake.org>`_
 * `MNMLSTC Unittest <https://github.com/mnmlstc/unittest>`_
 * `Sphinx Documentation Generator <http://sphinx-doc.org>`_
 * `Cloud Sphinx Theme <https://pypi.python.org/pypi/cloud_sptheme>`_

MNMLSTC Unittest is only necessary if building and running the unit tests.

Sphinx and the Cloud Sphinx Theme are only necessary if generating
documentation manually.
