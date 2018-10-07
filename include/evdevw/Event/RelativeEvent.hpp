#ifndef EVDEVW_RELATIVEEVENT_HPP
#define EVDEVW_RELATIVEEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class RelativeEventCode {
    X = REL_X,
    Y = REL_Y,
    Z = REL_Z,
    Rx = REL_RX,
    Ry = REL_RY,
    Rz = REL_RZ,
    Hwheel = REL_HWHEEL,
    Dial = REL_DIAL,
    Wheel = REL_WHEEL,
    Misc = REL_MISC,
  };

  template <>
  int enum_to_raw<int, RelativeEventCode>(RelativeEventCode code) {
    using UT = std::underlying_type_t<RelativeEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  RelativeEventCode raw_to_enum<RelativeEventCode, int>(int code) {
    if (code < REL_MAX)
      return static_cast<RelativeEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct RelativeEvent : public Event<EV_REL, RelativeEventCode> {
    RelativeEvent(RelativeEventCode code, Value value)
      : Event(code, value)
    {
    }

    RelativeEvent(struct input_event event)
      : Event(event)
    {
    }
  };

}

bool operator==(evdevw::RelativeEventCode code1, evdevw::RelativeEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_RELATIVEEVENT_HPP