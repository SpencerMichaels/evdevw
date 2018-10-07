#ifndef EVDEVW_EVENT_HPP
#define EVDEVW_EVENT_HPP

#include <libevdev/libevdev.h>

#include "../Utility.hpp"

namespace evdevw {

  template <int _type, typename _Code>
  struct Event {
  public:
    using Code = _Code;
    using Value = int;

    static const int type = _type;
    static constexpr auto enum_to_raw = evdevw::enum_to_raw<_Code, int>;
    static constexpr auto raw_to_enum = evdevw::raw_to_enum<_Code, int>;

    static std::string get_name() {
      return libevdev_event_type_get_name(type);
    }
    static std::string get_code_name(Code code) {
      return libevdev_event_code_get_name(type, enum_to_raw(code));
    }

    template <typename Code>
    util::OptionalString event_code_get_name(Code code) {
      return util::raw_to_optional<std::string>(libevdev_event_code_get_name(Event::type, code));
    }

    Event(Code code, Value value)
      : code(code), value(value)
    {
    }

    Event(struct input_event event)
        : code(raw_to_enum(event.code)), value(event.value)
    {
      if (event.type != type)
        throw std::runtime_error("Event type mismatch!");
    }

    Event(int raw_code, Value value)
      : code(evdevw::raw_to_enum<_Code>(raw_code)), value(value)
    {
    }

    bool operator==(const Event &other) const {
      return is_code(other.code);
    }

    bool is_code(Code code) const {
      return code == this->code;
    }

    Code code;
    Value value;
  };

}

#endif //EVDEVW_EVENT_HPP
