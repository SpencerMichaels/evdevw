#ifndef EVDEVW_REPEATEVENT_HPP
#define EVDEVW_REPEATEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class RepeatEventCode {
    Delay = REP_DELAY,
    Period = REP_PERIOD,
  };

  template <>
  struct convert_enum<RepeatEventCode> : public _convert_enum_impl<RepeatEventCode, uint16_t, REP_MAX> {};

  struct RepeatEvent : public Event<EV_REP, RepeatEventCode> {
    RepeatEvent(RepeatEventCode code, Value value)
      : Event(code, value)
    {
    }

    RepeatEvent(struct input_event event)
      : Event(event)
    {
    }
  };

  template <>
  struct event_from_event_code<RepeatEventCode > {
    using type = RepeatEvent;
  };

}

#endif //EVDEVW_REPEATEVENT_HPP
