#ifndef EVDEVW_LEDEVENT_HPP
#define EVDEVW_LEDEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class LedValue {
    On = 0,
    Off = 1,
  };

  template <>
  libevdev_led_value enum_to_raw<libevdev_led_value, LedValue>(LedValue code) {
    switch (code) {
      case LedValue::On:
      return LIBEVDEV_LED_ON;
      case LedValue::Off:
        return LIBEVDEV_LED_OFF;
    }
  }

  template <>
  LedValue raw_to_enum<LedValue, libevdev_led_value>(libevdev_led_value code) {
    if (code < 2)
      throw std::runtime_error("Invalid value for enum type!");
    return static_cast<LedValue>(code);
  }

  enum class LedEventCode {
    Numl = LED_NUML,
    Capsl = LED_CAPSL,
    Scrolll = LED_SCROLLL,
    Compose = LED_COMPOSE,
    Kana = LED_KANA,
    Sleep = LED_SLEEP,
    Suspend = LED_SUSPEND,
    Mute = LED_MUTE,
    Misc = LED_MISC,
    Mail = LED_MAIL,
    Charging = LED_CHARGING,
  };

  template <>
  int enum_to_raw<int, LedEventCode>(LedEventCode code) {
    using UT = std::underlying_type_t<LedEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  LedEventCode raw_to_enum<LedEventCode, int>(int code) {
    if (code < LED_MAX)
      return static_cast<LedEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct LedEvent : public Event<EV_LED, LedEventCode> {
    LedEvent(LedEventCode code, Value value)
      : Event(code, value)
    {
    }

    LedEvent(struct input_event event)
      : Event(event)
    {
    }
  };

}

bool operator==(evdevw::LedEventCode code1, evdevw::LedEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_LEDEVENT_HPP
