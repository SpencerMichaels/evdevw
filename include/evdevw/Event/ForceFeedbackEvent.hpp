#ifndef EVDEVW_FORCEFEEDBACKEVENT_HPP
#define EVDEVW_FORCEFEEDBACKEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class ForceFeedbackEventCode {
    Rumble = FF_RUMBLE,
    Periodic = FF_PERIODIC,
    Constant = FF_CONSTANT,
    Spring = FF_SPRING,
    Friction = FF_FRICTION,
    Damper = FF_DAMPER,
    Inertia = FF_INERTIA,
    Ramp = FF_RAMP,
    EffectMin = FF_EFFECT_MIN,
    EffectMax = FF_EFFECT_MAX,
    Square = FF_SQUARE,
    Triangle = FF_TRIANGLE,
    Sine = FF_SINE,
    SawUp = FF_SAW_UP,
    SawDown = FF_SAW_DOWN,
    Custom = FF_CUSTOM,
    WaveformMin = FF_WAVEFORM_MIN,
    WaveformMax = FF_WAVEFORM_MAX,
    Gain = FF_GAIN,
    Autocenter = FF_AUTOCENTER,
    MaxEffects = FF_MAX_EFFECTS,
  };

  template <>
  struct convert_enum<ForceFeedbackEventCode> : public _convert_enum_impl<ForceFeedbackEventCode, uint16_t, FF_MAX> {};

  struct ForceFeedbackEvent : public Event<EV_FF, ForceFeedbackEventCode> {
    ForceFeedbackEvent(ForceFeedbackEventCode code, Value value)
      : Event(code, value)
    {
    }

    ForceFeedbackEvent(struct input_event event)
      : Event(event)
    {
    }
  };

  template <>
  struct event_from_event_code<ForceFeedbackEventCode > {
    using type = ForceFeedbackEvent;
  };

}

#endif //EVDEVW_FORCEFEEDBACKEVENT_HPP
