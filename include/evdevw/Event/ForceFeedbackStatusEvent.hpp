#ifndef EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP
#define EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class ForceFeedbackStatusEventCode {
    Stopped = FF_STATUS_STOPPED,
    Playing = FF_STATUS_PLAYING,
  };

  DECLARE_ENUM_CONVERTER(ForceFeedbackStatusEventCode, uint16_t, FF_STATUS_MAX);
  DECLARE_EVENT_TYPE(EV_FF_STATUS, ForceFeedbackStatusEvent, ForceFeedbackStatusEventCode, int);

}

#endif //EVDEVW_FORCEFEEDBACKSTATUSEVENT_HPP
