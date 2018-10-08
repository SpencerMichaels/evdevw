# Introduction

`evdevw` is a header-only `libevdev` wrapper written in modern C++. It covers
all of the current version of `libevdev`.

In general, `evdevw` mirrors the `libevdev` API quite closely, but there are a
few minor divergences.
* Events (`EV_SYN`, `EV_KEY`, etc.) have been split into separate types,
    rather than relying on a single event struct with a type ID as
    `libevdev` does.
* Enums and defines for event codes, input properties, and so on have been
    made into strongly-typed enums, with names generally unchanged except for
    (a) removing prefixes and (b) changing `ALL CAPS` to `CamelCase`. There
    are two exceptions.
  * Both `KEY_*` and `BTN_*` values correspond to `KeyEventCode`. Multiple
      values of the two types have the same names except for their prefix;
      for this reason , `BTN_*` values retain their prefix as `Button*`.
  * The names of a few key enum values would have started with a number
      once the prefix was removed; in these cases, a leading underscore was added.
      So, for instance, `KEY_0` is represented by `KeyEventCode::_0`.
      
## Example Code

The code below is a translation of the example on [libevdev's main page](
https://www.freedesktop.org/wiki/Software/libevdev/).
      
```C++
#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <evdevw.hpp>

int main() {
  auto fd = open("/dev/input/event0", O_RDONLY|O_NONBLOCK);

  try {
    auto evdev = evdevw::Evdev::create_from_fd(fd);

    std::cout << "Input device name: \"" << evdev->get_name() << "\"" << std::endl;

    std::cout << "Input device ID: bus " << evdev->get_id_bustype()
              << " vendor "  << evdev->get_id_vendor()
              << " product " << evdev->get_id_product()
              << std::endl;

    if (!evdev->has_event_type<evdevw::RelativeEvent>()) {
      if (!evdev->has_event_code(evdevw::KeyEventCode::ButtonLeft)) {
        std::cerr << "This device does not look like a mouse" << std::endl;
        exit(1);
      }
    }

    // next_event() returns a std::optional, which will be empty if there was
    // no event to return. On error, an Exception will be thrown.
    while (true) {
      auto event_any_opt = evdev->next_event({ evdevw::ReadFlag::Normal });
      if (event_any_opt) {
        std::visit(evdevw::util::overloaded {
          [](const auto &event) {
            std::cout << "Event: "
                      << event.get_type_name() << " "
                      << event.get_code_name() << " "
                      << event.get_value()
                      << std::endl;
          }
        }, *event_any_opt);
      }
    }

  } catch (const evdevw::Exception &e) {
    std::cerr << "Error: " << std::strerror(e.get_error()) << std::endl;
  }
}
```
