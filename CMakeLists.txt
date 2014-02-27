cmake_version_required(VERSION 2.8.12)
project(platform CXX)

#------------------------------------------------------------------------------
# Modules, Variables, and Options
#------------------------------------------------------------------------------
include(CMakePackageConfigHelpers)
include(CheckCXXCompilerFlag)
include(CheckCXXSymbolExists)
include(CheckIncludeFileCXX)
include(CTest)

set(INCLUDE_INSTALL_DIR "include" CACHE INTERNAL "Header Files")
set(CMAKE_INSTALL_DIR "share/cmake/platform" CACHE INTERNAL "CMake Files")
set(DOCS_INSTALL_DIR "share/doc/mnmlstc/platform" CACHE INTERNAL "Doc Files")

set(PLATFORM_VERSION_MAJOR 1)
set(PLATFORM_VERSION_MINOR 0)
set(PLATFORM_VERSION_PATCH 0)
set(PLATFORM_VERSION_PATCH
  ${PLATFORM_VERSION_MAJOR}.${PLATFORM_VERSION_MINOR}.${PLATFORM_VERSION_PATCH}
)

set(TEST_SOURCE_DIR "${PROJECT_SOURCE_DIR}/tests")
set(TEST_BINARY_DIR "${PROJECT_BINARY_DIR}/tests")

set(DOCS_SOURCE_DIR "${PROJECT_SOURCE_DIR}/docs")
set(DOCS_BINARY_DIR "${PROJECT_BINARY_DIR}/docs")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/configure")

option(BUILD_WITH_LIBCXX "Use libc++ as stdlib" OFF)
option(BUILD_DOCS "Build documentation with Sphinx Documentation Generator")

if (APPLE AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  set(BUILD_WITH_LIBCXX ON CACHE BOOL "Use libc++ as stdlib" ON)
endif ()

#------------------------------------------------------------------------------
# Compiler Environment Check
#------------------------------------------------------------------------------
set(USE_STDLIB_LIBCXX "-stdlib=libc++")
set(USE_STD_CXX11 "-std=c++11")

set(USE_PEDANTIC) "-pedantic")

set(WARN_EVERYTHING "-Weverything")
set(WARN_NOEXCEPT "-Wnoexcept")
set(WARN_ONE_LINE "-WL")
set(WARN_ERROR "-Werror")
set(WARN_EXTRA "-Wextra")
set(WARN_ALL "-Wall")

# MSVC is technically unsupported, but this is here until they get their act
# together
if (MSVC)
  set(USE_EXCEPTIONS "/Ehsz")

  set(WARN_EVERYTHING "-Wall")
  set(WARN_ERROR "-Werror")
  set(WARN_ALL "-W4")
endif ()

if (CAN_USE_STDLIB_LIBCXX AND BUILD_WITH_LIBCXX)
  set(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} ${USE_STDLIB_LIBCXX}")
endif ()

if (CAN_USE_STD_CXX11)
  set(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} ${USE_STD_CXX11}")
endif ()

# These headers are requied
check_include_file_cxx(cstdint HAVE_CSTDINT)

if (NOT HAVE_CSTDINT)
  message(FATAL_ERROR "standard header <cstdint> could not be found")
endif ()

# These macros are required
check_cxx_symbol_exists(UINT64_C cstdint HAVE_UINT64_C_MACRO)
check_cxx_symbol_exists(UINT32_C cstdint HAVE_UINT32_C_MACRO)
check_cxx_symbol_exists(UINT16_C cstdint HAVE_UINT16_C_MACRO)

if (NOT HAVE_UINT64_C_MACRO)
  message(FATAL_ERROR "standard macro 'UINT64_C' could not be found")
endif ()

if (NOT HAVE_UINT32_C_MACRO)
  message(FATAL_ERROR "standard macro 'UINT32_C' could not be found")
endif ()

if (NOT HAVE_UINT16_C_MACRO)
  message(FATAL_ERROR "standard macro 'UINT16_C' could not be found")
endif ()
