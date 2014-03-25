#include <platform/os.hpp>

#include <unittest/unittest.hpp>

int main () {
  using namespace unittest;

  static_assert(
    not std::is_same<platform::os::current, void>::value,
    "Unable to match any operating system to set to current"
  );

  test("os") = {
    task("unknown") = [] { },
    task("windows") = [] { },
    task("android") = [] { },
    task("freebsd") = [] { },
    task("openbsd") = [] { },
    task("netbsd") = [] { },
    task("dragon") = [] { },
    task("macosx") = [] { },
    task("linux") = [] { },
    task("ios") = [] { }
  };

  monitor::run();
}
