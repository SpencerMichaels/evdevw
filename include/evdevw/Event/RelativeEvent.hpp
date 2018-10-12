#ifndef EVDEVW_RELATIVEEVENT_HPP
#define EVDEVW_RELATIVEEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class RelativeEventCode {
    X = REL_X,
    Y = REL_Y,
    Z = REL_Z,
    Rx = REL_RX,
    Ry = REL_RY,
    Rz = REL_RZ,
    Hwheel = REL_HWHEEL,
    Dial = REL_DIAL,
    Wheel = REL_WHEEL,
    Misc = REL_MISC,
  };

  DECLARE_ENUM_CONVERTER(RelativeEventCode, uint16_t, REL_MAX);
  DECLARE_EVENT_TYPE(EV_REL, RelativeEvent, RelativeEventCode, int);

}

#endif //EVDEVW_RELATIVEEVENT_HPP
