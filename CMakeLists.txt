cmake_minimum_required(VERSION 2.8.12)
project(platform CXX)

#------------------------------------------------------------------------------
# Modules, Variables, and Options
#------------------------------------------------------------------------------
include(CMakePackageConfigHelpers)
include(CMakeDependentOption)
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
set(PLATFORM_VERSION
  ${PLATFORM_VERSION_MAJOR}.${PLATFORM_VERSION_MINOR}.${PLATFORM_VERSION_PATCH}
)

set(TEST_SOURCE_DIR "${PROJECT_SOURCE_DIR}/tests")
set(TEST_BINARY_DIR "${PROJECT_BINARY_DIR}/tests")

set(DOCS_SOURCE_DIR "${PROJECT_SOURCE_DIR}/docs")
set(DOCS_BINARY_DIR "${PROJECT_BINARY_DIR}/docs")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/configure")

# Used by cmake-dependent-option
list(APPEND RPM_DEP "UNIX" "NOT APPLE" "BUILD_PACKAGE")
list(APPEND DEB_DEP "UNIX" "NOT APPLE" "BUILD_PACKAGE")
list(APPEND PKG_DEP "APPLE" "BUILD_PACKAGE")
list(APPEND MSI_DEP "WIN32" "BUILD_PACKAGE")

option(BUILD_WITH_LIBCXX "Use libc++ as stdlib" OFF)
option(BUILD_PACKAGE "Build packages with CPack" OFF)
option(BUILD_DOCS "Build documentation with Sphinx Documentation Generator")

cmake_dependent_option(BUILD_PACKAGE_MSI "Create an MSI" ON "${MSI_DEP}" OFF)
cmake_dependent_option(BUILD_PACKAGE_RPM "Create an RPM" ON "${RPM_DEP}" OFF)
cmake_dependent_option(BUILD_PACKAGE_DEB "Create a DEB" ON "${DEB_DEP}" OFF)
cmake_dependent_option(BUILD_PACKAGE_PKG "Create a PKG" ON "${PKG_DEP}" OFF)

if (APPLE AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
  set(BUILD_WITH_LIBCXX ON CACHE BOOL "Use libc++ as stdlib" ON)
endif ()

#------------------------------------------------------------------------------
# Compiler Environment Check
#------------------------------------------------------------------------------
set(USE_STDLIB_LIBCXX "-stdlib=libc++")
set(USE_STD_CXX11 "-std=c++11")

set(USE_PEDANTIC "-pedantic")

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

check_cxx_compiler_flag(${USE_STDLIB_LIBCXX} CAN_USE_STDLIB_LIBCXX)
check_cxx_compiler_flag(${USE_STD_CXX11} CAN_USE_STD_CXX11)

check_cxx_compiler_flag(${USE_PEDANTIC} CAN_USE_PEDANTIC)

check_cxx_compiler_flag(${WARN_EVERYTHING} CAN_WARN_EVERYTHING)
check_cxx_compiler_flag(${WARN_EXTRA} CAN_WARN_EXTRA)
check_cxx_compiler_flag(${WARN_ALL} CAN_WARN_ALL)

if (CAN_USE_STDLIB_LIBCXX AND BUILD_WITH_LIBCXX)
  set(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} ${USE_STDLIB_LIBCXX}")
endif ()

if (CAN_USE_STD_CXX11)
  set(CMAKE_REQUIRED_FLAGS "${CMAKE_REQUIRED_FLAGS} ${USE_STD_CXX11}")
endif ()

# These headers are requied
check_include_file_cxx(type_traits HAVE_TYPE_TRAITS)
check_include_file_cxx(cstdint HAVE_CSTDINT)

# Handle not having the required headers
if (NOT HAVE_TYPE_TRAITS)
  message(FATAL_ERROR "standard header <type_traits> could not be found")
endif ()

if (NOT HAVE_CSTDINT)
  message(FATAL_ERROR "standard header <cstdint> could not be found")
endif ()


# These macros are required
check_cxx_symbol_exists(UINT64_C cstdint HAVE_UINT64_C_MACRO)
check_cxx_symbol_exists(UINT32_C cstdint HAVE_UINT32_C_MACRO)
check_cxx_symbol_exists(UINT16_C cstdint HAVE_UINT16_C_MACRO)

# Handle not having the required macros
if (NOT HAVE_UINT64_C_MACRO)
  message(FATAL_ERROR "standard macro 'UINT64_C' could not be found")
endif ()

if (NOT HAVE_UINT32_C_MACRO)
  message(FATAL_ERROR "standard macro 'UINT32_C' could not be found")
endif ()

if (NOT HAVE_UINT16_C_MACRO)
  message(FATAL_ERROR "standard macro 'UINT16_C' could not be found")
endif ()

#------------------------------------------------------------------------------
# Configuration
#------------------------------------------------------------------------------
write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
  VERSION ${PLATFORM_VERSION}
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/configure/${PROJECT_NAME}-config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_DIR}"
  PATH_VARS INCLUDE_INSTALL_DIR CMAKE_INSTALL_DIR
)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_compile_options(
  $<$<BOOL:${CAN_USE_STD_CXX11}>:${USE_STD_CXX11}>
  $<$<BOOL:${CAN_WARN_ALL}>:${WARN_ALL}>
  $<$<BOOL:${CAN_WARN_NOEXCEPT}>:${WARN_NOEXCEPT}>
  $<$<BOOL:${CAN_WARN_EXTRA}>:${WARN_EXTRA}>
)

if (BUILD_TESTING)
  set(CMAKE_TEST_COMMAND ctest)
  add_subdirectory("${TEST_SOURCE_DIR}" "${TEST_BINARY_DIR}" EXCLUDE_FROM_ALL)
endif ()

if (BUILD_DOCS)
  add_subdirectory("${DOCS_SOURCE_DIR}" "${DOCS_BINARY_DIR}" EXCLUDE_FROM_ALL)
endif ()

if (BUILD_PACKAGE)
  add_subdirectory("${PACK_SOURCE_DIR}" "${PACK_BINARY_DIR}" EXCLUDE_FROM_ALL)
endif ()

#------------------------------------------------------------------------------
# Install
#------------------------------------------------------------------------------
install(FILES
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  ${PROJECT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  DESTINATION ${CMAKE_INSTALL_DIR}
)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/platform"
  DESTINATION ${INCLUDE_INSTALL_DIR}
  FILES_MATCHING PATTERN "*.hpp"
)

if (BUILD_DOCS)
  install(DIRECTORY "${DOCS_BINARY_DIR}/"
    DESTINATION ${DOCS_INSTALL_DIR}
    FILES_MATCHING
    PATTERN ".buildinfo" EXCLUDE
    PATTERN "CMakeFiles" EXCLUDE
    PATTERN ".doctrees" EXCLUDE
    PATTERN "Makefile" EXCLUDE
    PATTERN "*.cmake" EXCLUDE
    PATTERN "*"
  )
endif ()
