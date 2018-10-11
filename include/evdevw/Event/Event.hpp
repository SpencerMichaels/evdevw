#ifndef EVDEVW_EVENT_HPP
#define EVDEVW_EVENT_HPP

#include <libevdev/libevdev.h>

#include "../Utility.hpp"

namespace evdevw {

  template <uint16_t _type, typename _Code>
  struct Event {
  public:
    using Code = _Code;
    using Value = int;

    static const int type = _type;

  public:
    Event(Code code, Value value)
      : _code(code), _value(value)
    {
    }

    Event(struct input_event event)
        : _code(raw_to_enum<Code>(event.code)), _value(event.value)
    {
      if (event.type != type)
        throw std::runtime_error("Event type mismatch!");
    }

    Event(uint16_t raw_code, Value value)
      : _code(raw_to_enum<Code>(raw_code)), _value(value)
    {
    }

    bool operator==(const Event &other) const {
      return is_code(other._code);
    }

    bool is_code(Code code) const {
      return code == _code;
    }

    Code get_code() const {
      return _code;
    }

    Value get_value() const {
      return _value;
    }

    std::string get_type_name() const {
      return libevdev_event_type_get_name(type);
    }
    std::string get_code_name() const {
      return libevdev_event_code_get_name(type, enum_to_raw(_code));
    }

  private:
    Code _code;
    Value _value;
  };


  template <typename E>
  std::string get_type_name() {
    return libevdev_event_type_get_name(E::type);
  }

  template <typename E>
  std::string get_code_name(typename E::Code code) {
    return libevdev_event_code_get_name(E::type, enum_to_raw(code));
  }

}

#endif //EVDEVW_EVENT_HPP
