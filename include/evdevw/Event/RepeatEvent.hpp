#ifndef EVDEVW_REPEATEVENT_HPP
#define EVDEVW_REPEATEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class RepeatEventCode {
    Delay = REP_DELAY,
    Period = REP_PERIOD,
  };

  template <>
  int enum_to_raw<int, RepeatEventCode>(RepeatEventCode code) {
    using UT = std::underlying_type_t<RepeatEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  RepeatEventCode raw_to_enum<RepeatEventCode, int>(int code) {
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

}

bool operator==(evdevw::RepeatEventCode code1, evdevw::RepeatEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_REPEATEVENT_HPP
