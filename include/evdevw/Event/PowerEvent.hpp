#ifndef EVDEVW_POWEREVENT_HPP
#define EVDEVW_POWEREVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class PowerEventCode {
  };

  DECLARE_ENUM_CONVERTER(PowerEventCode, uint16_t, 0);
  DECLARE_EVENT_TYPE(EV_PWR, PowerEvent, PowerEventCode, int);

}

#endif //EVDEVW_POWEREVENT_HPP
