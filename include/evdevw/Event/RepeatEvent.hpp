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
  uint16_t enum_to_raw<uint16_t, RepeatEventCode>(RepeatEventCode code) {
    using UT = std::underlying_type_t<RepeatEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  RepeatEventCode raw_to_enum<RepeatEventCode, uint16_t>(uint16_t code) {
    if (code < REP_MAX)
      return static_cast<RepeatEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

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

bool operator==(evdevw::RepeatEventCode code1, evdevw::RepeatEventCode code2) {
  return evdevw::enum_to_raw<uint16_t>(code1) == evdevw::enum_to_raw<uint16_t>(code2);
}

#endif //EVDEVW_REPEATEVENT_HPP
