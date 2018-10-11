#ifndef EVDEVW_LEDEVENT_HPP
#define EVDEVW_LEDEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class LedValue {
    On = LIBEVDEV_LED_ON,
    Off = LIBEVDEV_LED_OFF,
  };

  template <>
  struct convert_enum<LedValue> : public _convert_enum_impl<LedValue, libevdev_led_value, (libevdev_led_value)0> {};

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
  struct convert_enum<LedEventCode> : public _convert_enum_impl<LedEventCode, uint16_t, LED_MAX> {};

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

  template <>
  struct event_from_event_code<LedEventCode> {
    using type = LedEvent;
  };

}

#endif //EVDEVW_LEDEVENT_HPP
