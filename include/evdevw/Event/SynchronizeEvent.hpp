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

  DECLARE_ENUM_CONVERTER(SynchronizeEventCode, uint16_t, SYN_MAX);
  DECLARE_EVENT_TYPE(EV_SYN, SynchronizeEvent, SynchronizeEventCode, int);

}

#endif //EVDEVW_SYNCHRONIZEEVENT_HPP
