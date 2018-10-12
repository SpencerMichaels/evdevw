#ifndef EVDEVW_LEDEVENT_HPP
#define EVDEVW_LEDEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

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

  enum class LedEventValue {
    On = LIBEVDEV_LED_ON,
    Off = LIBEVDEV_LED_OFF,
  };

  DECLARE_ENUM_CONVERTER(LedEventCode, uint16_t, LED_MAX);
  //DECLARE_ENUM_CONVERTER(LedEventValue, libevdev_led_value, (libevdev_led_value)0);
  DECLARE_ENUM_CONVERTER(LedEventValue, int, 0);
  DECLARE_EVENT_TYPE(EV_LED, LedEvent, LedEventCode, LedEventValue);

}

#endif //EVDEVW_LEDEVENT_HPP
