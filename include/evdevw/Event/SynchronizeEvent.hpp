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
  struct convert_enum<SynchronizeEventCode> : public _convert_enum_impl<SynchronizeEventCode, uint16_t, SYN_MAX> {};

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

#endif //EVDEVW_SYNCHRONIZEEVENT_HPP
