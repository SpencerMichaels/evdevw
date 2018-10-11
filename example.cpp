#include <iostream>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <evdevw.hpp>

// The code below is a translation of the example on libevdev's main page:
// https://www.freedesktop.org/wiki/Software/libevdev/

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
