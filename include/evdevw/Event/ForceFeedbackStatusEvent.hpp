#ifndef EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP
#define EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class ForceFeedbackStatusEventCode {
    Stopped = FF_STATUS_STOPPED,
    Playing = FF_STATUS_PLAYING,
  };

  template <>
  struct convert_enum<ForceFeedbackStatusEventCode> : public _convert_enum_impl<ForceFeedbackStatusEventCode, uint16_t, FF_STATUS_MAX> {};

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

  template <>
  struct event_from_event_code<ForceFeedbackStatusEventCode > {
    using type = ForceFeedbackStatusEvent;
  };

}

#endif //EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP
