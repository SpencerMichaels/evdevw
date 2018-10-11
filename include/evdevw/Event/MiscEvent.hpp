#ifndef EVDEVW_MISCEVENT_HPP
#define EVDEVW_MISCEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class MiscEventCode {
    Serial = MSC_SERIAL,
    Pulseled = MSC_PULSELED,
    Gesture = MSC_GESTURE,
    Raw = MSC_RAW,
    Scan = MSC_SCAN,
    Timestamp = MSC_TIMESTAMP,
  };

  template <>
  struct convert_enum<MiscEventCode> : public _convert_enum_impl<MiscEventCode, uint16_t, MSC_MAX> {};

  struct MiscEvent : public Event<EV_MSC, MiscEventCode> {
    MiscEvent(MiscEventCode code, Value value)
      : Event(code, value)
    {
    }

    MiscEvent(struct input_event event)
      : Event(event)
    {
    }
  };

  template <>
  struct event_from_event_code<MiscEventCode> {
    using type = MiscEvent;
  };

}

#endif //EVDEVW_MISCEVENT_HPP
