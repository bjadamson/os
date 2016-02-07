#include <cppformat/format.h>
#include <iostream>
#include <string>

using Stream = std::FILE *const;

namespace display {

template<typename Stream, typename ...Args>
void
show(Stream stream, Args&&... args)
{
  fmt::print(stream, std::forward<Args&&...>(args)...);
  fmt::print(stream, "\n");
}

} // ns display

namespace os {

struct Kernel {
};

struct OS {
  constexpr static auto const Name = "TBD, MysticOS";
  constexpr static auto const Version = 0.001;

  // allow moving
  OS& operator=(OS &&) = default;

  // data owned by the OS.
  Kernel kernel;
};



auto&&
init(Stream stream, Kernel &&kernel)
{
  display::show(stream, "Kernel initialized.");
  return kernel;
}

auto&&
init(Stream stream, OS &&os)
{
  os.kernel = init(stream, std::move(os.kernel));
  display::show(stream, "Greetings and welcome to my operating sytem! We do things a bit different "
      "around here. Instead of booting up on an actual piece of hardware, we boot in a sort of "
      "virtual environment. Good architects understand how to defer decisions.\n\nWell that's "
      "exactly what were doing here. Instead of supporting any particual hardware, this OS is being "
      "developed on virtual hardware.\n\nThis virtual hardware can perform anything our OS can dream "
      "of requiring, leaving absolute freedom to the designers of the OS."
      );
  return os;
}

} // ns os

namespace virt {

auto&&
start(Stream stream, os::OS &&os)
{
  return os;
}

auto&&
init(Stream stream, os::OS &&os)
{
  display::show(stream, "Environment Initialized.");
  return os::init(stream, std::move(os));
}

} // ns virt

int
main(int main, char **argv)
{
  os::OS stack_os;

  auto &&os = virt::init(stdout, std::move(stack_os));
  os = std::move(virt::start(stdout, std::move(stack_os)));
  return 0;
}
