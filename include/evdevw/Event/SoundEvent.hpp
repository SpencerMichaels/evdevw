#ifndef EVDEVW_SOUNDEVENT_HPP
#define EVDEVW_SOUNDEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class SoundEventCode {
    Click = SND_CLICK,
    Bell = SND_BELL,
    Tone = SND_TONE,
  };

  DECLARE_ENUM_CONVERTER(SoundEventCode, uint16_t, SND_MAX);
  DECLARE_EVENT_TYPE(EV_SND, SoundEvent, SoundEventCode, int);

}

#endif //EVDEVW_SOUNDEVENT_HPP
