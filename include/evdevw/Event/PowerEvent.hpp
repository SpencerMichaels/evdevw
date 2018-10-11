#ifndef EVDEVW_POWEREVENT_HPP
#define EVDEVW_POWEREVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class PowerEventCode {
  };

  template <>
  struct convert_enum<PowerEventCode> : public _convert_enum_impl<PowerEventCode, uint16_t, 0> {};

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

#endif //EVDEVW_POWEREVENT_HPP
