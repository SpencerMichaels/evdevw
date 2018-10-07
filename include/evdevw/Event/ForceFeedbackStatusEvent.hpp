#ifndef EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP
#define EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class ForceFeedbackStatusEventCode {
    Stopped = FF_STATUS_STOPPED,
    Playing = FF_STATUS_PLAYING,
  };

  template <>
  int enum_to_raw<int, ForceFeedbackStatusEventCode>(ForceFeedbackStatusEventCode code) {
    using UT = std::underlying_type_t<ForceFeedbackStatusEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  ForceFeedbackStatusEventCode raw_to_enum<ForceFeedbackStatusEventCode, int>(int code) {
    if (code < FF_STATUS_MAX)
      return static_cast<ForceFeedbackStatusEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct ForceFeedbackStatusEvent : public Event<EV_FF_STATUS, ForceFeedbackStatusEventCode> {
    ForceFeedbackStatusEvent(ForceFeedbackStatusEventCode code, Value value)
      : Event(code, value)
    {
    }

    ForceFeedbackStatusEvent(struct input_event event)
      : Event(event)
    {
    }
  };

}

bool operator==(evdevw::ForceFeedbackStatusEventCode code1, evdevw::ForceFeedbackStatusEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP
