#ifndef EVDEVW_SYNCHRONIZEEVENT_HPP
#define EVDEVW_SYNCHRONIZEEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class SynchronizeEventCode {
    Report = SYN_REPORT,
    Config = SYN_CONFIG,
    MtReport = SYN_MT_REPORT,
    Dropped = SYN_DROPPED,
  };

  template <>
  uint16_t enum_to_raw<uint16_t, SynchronizeEventCode>(SynchronizeEventCode code) {
    using UT = std::underlying_type_t<SynchronizeEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  SynchronizeEventCode raw_to_enum<SynchronizeEventCode, uint16_t>(uint16_t code) {
    if (code < SYN_MAX)
      return static_cast<SynchronizeEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct SynchronizeEvent : public Event<EV_SYN, SynchronizeEventCode> {
    SynchronizeEvent(SynchronizeEventCode code, Value value)
    : Event(code, value)
    {
    }

    SynchronizeEvent(struct input_event event)
        : Event(event)
    {
    }
  };

  template <>
  struct event_from_event_code<SynchronizeEventCode> {
    using type = SynchronizeEvent;
  };

}

bool operator==(evdevw::SynchronizeEventCode code1, evdevw::SynchronizeEventCode code2) {
  return evdevw::enum_to_raw<uint16_t>(code1) == evdevw::enum_to_raw<uint16_t>(code2);
}

#endif //EVDEVW_SYNCHRONIZEEVENT_HPP
