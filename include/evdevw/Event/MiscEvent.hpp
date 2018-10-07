#ifndef EVDEVW_MISCEVENT_HPP
#define EVDEVW_MISCEVENT_HPP

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
  int enum_to_raw<int, MiscEventCode>(MiscEventCode code) {
    using UT = std::underlying_type_t<MiscEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  MiscEventCode raw_to_enum<MiscEventCode, int>(int code) {
    if (code < MSC_MAX)
      return static_cast<MiscEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

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

}

bool operator==(evdevw::MiscEventCode code1, evdevw::MiscEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_MISCEVENT_HPP
