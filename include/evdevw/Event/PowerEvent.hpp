#ifndef EVDEVW_POWEREVENT_HPP
#define EVDEVW_POWEREVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class PowerEventCode {
  };

  template <>
  uint16_t enum_to_raw<uint16_t, PowerEventCode>(PowerEventCode code) {
    return 0;
  }

  template <>
  PowerEventCode raw_to_enum<PowerEventCode, uint16_t>(uint16_t code) {
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

  template <>
  struct event_from_event_code<PowerEventCode> {
    using type = PowerEvent;
  };

}

bool operator==(evdevw::PowerEventCode code1, evdevw::PowerEventCode code2) {
  return evdevw::enum_to_raw<uint16_t>(code1) == evdevw::enum_to_raw<uint16_t>(code2);
}

#endif //EVDEVW_POWEREVENT_HPP
