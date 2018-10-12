#ifndef EVDEVW_REPEATEVENT_HPP
#define EVDEVW_REPEATEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class RepeatEventCode {
    Delay = REP_DELAY,
    Period = REP_PERIOD,
  };

  DECLARE_ENUM_CONVERTER(RepeatEventCode, uint16_t, REP_MAX);
  DECLARE_EVENT_TYPE(EV_REP, RepeatEvent, RepeatEventCode, int);

}

#endif //EVDEVW_REPEATEVENT_HPP
