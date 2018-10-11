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

  template <>
  struct convert_enum<SoundEventCode> : public _convert_enum_impl<SoundEventCode, uint16_t, SND_MAX> {};

  struct SoundEvent : public Event<EV_SND, SoundEventCode> {
    SoundEvent(SoundEventCode code, Value value)
      : Event(code, value)
    {
    }

    SoundEvent(struct input_event event)
      : Event(event)
    {
    }
  };

  template <>
  struct event_from_event_code<SoundEventCode> {
    using type = SoundEvent;
  };

}

#endif //EVDEVW_SOUNDEVENT_HPP
