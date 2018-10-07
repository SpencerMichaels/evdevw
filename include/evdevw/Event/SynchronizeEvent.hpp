#ifndef EVDEVW_SYNCHRONIZEEVENT_HPP
#define EVDEVW_SYNCHRONIZEEVENT_HPP

namespace evdevw {

  enum class SynchronizeEventCode {
    Report = SYN_REPORT,
    Config = SYN_CONFIG,
    MtReport = SYN_MT_REPORT,
    Dropped = SYN_DROPPED,
  };

  template <>
  int enum_to_raw<int, SynchronizeEventCode>(SynchronizeEventCode code) {
    using UT = std::underlying_type_t<SynchronizeEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  SynchronizeEventCode raw_to_enum<SynchronizeEventCode, int>(int code) {
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

}

bool operator==(evdevw::SynchronizeEventCode code1, evdevw::SynchronizeEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_SYNCHRONIZEEVENT_HPP
