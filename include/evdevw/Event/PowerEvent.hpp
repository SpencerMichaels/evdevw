#ifndef EVDEVW_POWEREVENT_HPP
#define EVDEVW_POWEREVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class PowerEventCode {
  };

  template <>
  int enum_to_raw<int, PowerEventCode>(PowerEventCode code) {
    return 0;
  }

  template <>
  PowerEventCode raw_to_enum<PowerEventCode, int>(int code) {
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct PowerEvent : public Event<EV_PWR, PowerEventCode> {
    PowerEvent(PowerEventCode code, Value value)
      : Event(code, value)
    {
    }

    PowerEvent(struct input_event event)
      : Event(event)
    {
    }
  };

}

bool operator==(evdevw::PowerEventCode code1, evdevw::PowerEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_POWEREVENT_HPP
