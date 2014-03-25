add_custom_target(check COMMAND ${CMAKE_TEST_COMMAND})
find_package(unittest REQUIRED NO_CMAKE_BUILDS_PATH)

include_directories(${UNITTEST_INCLUDE_DIR})

#------------------------------------------------------------------------------
# Executable Section
#------------------------------------------------------------------------------
add_executable(test-os "${TEST_SOURCE_DIR}/os.cpp")

#------------------------------------------------------------------------------
# Test Section
#------------------------------------------------------------------------------
add_test(os test-os)

#------------------------------------------------------------------------------
# Dependency Section
#------------------------------------------------------------------------------
add_dependencies(check test-os)
