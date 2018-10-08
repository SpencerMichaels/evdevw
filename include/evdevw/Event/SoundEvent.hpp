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
  uint16_t enum_to_raw<uint16_t, SoundEventCode>(SoundEventCode code) {
    using UT = std::underlying_type_t<SoundEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  SoundEventCode raw_to_enum<SoundEventCode, uint16_t>(uint16_t code) {
    if (code < SND_MAX)
      return static_cast<SoundEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

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

bool operator==(evdevw::SoundEventCode code1, evdevw::SoundEventCode code2) {
  return evdevw::enum_to_raw<uint16_t>(code1) == evdevw::enum_to_raw<uint16_t>(code2);
}

#endif //EVDEVW_SOUNDEVENT_HPP
