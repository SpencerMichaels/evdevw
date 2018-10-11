#ifndef EVDEVW_RELATIVEEVENT_HPP
#define EVDEVW_RELATIVEEVENT_HPP

#include <cstdint>

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
  struct convert_enum<RelativeEventCode> : public _convert_enum_impl<RelativeEventCode, uint16_t, REL_MAX> {};

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

  template <>
  struct event_from_event_code<RelativeEventCode> {
    using type = RelativeEvent;
  };

}

#endif //EVDEVW_RELATIVEEVENT_HPP
