#ifndef EVDEVW_SWITCHEVENT_HPP
#define EVDEVW_SWITCHEVENT_HPP

#include <cstdint>

#include "Event.hpp"

namespace evdevw {

  enum class SwitchEventCode {
    Lid = SW_LID,
    TabletMode = SW_TABLET_MODE,
    HeadphoneInsert = SW_HEADPHONE_INSERT,
    RfkillAll = SW_RFKILL_ALL,
    Radio = SW_RADIO,
    MicrophoneInsert = SW_MICROPHONE_INSERT,
    Dock = SW_DOCK,
    LineoutInsert = SW_LINEOUT_INSERT,
    JackPhysicalInsert = SW_JACK_PHYSICAL_INSERT,
    VideooutInsert = SW_VIDEOOUT_INSERT,
    CameraLensCover = SW_CAMERA_LENS_COVER,
    KeypadSlide = SW_KEYPAD_SLIDE,
    FrontProximity = SW_FRONT_PROXIMITY,
    RotateLock = SW_ROTATE_LOCK,
    LineinInsert = SW_LINEIN_INSERT,
    MuteDevice = SW_MUTE_DEVICE,
    PenInserted = SW_PEN_INSERTED,
  };

  template <>
  uint16_t enum_to_raw<uint16_t, SwitchEventCode>(SwitchEventCode code) {
    using UT = std::underlying_type_t<SwitchEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  SwitchEventCode raw_to_enum<SwitchEventCode, uint16_t>(uint16_t code) {
    if (code < SW_MAX)
      return static_cast<SwitchEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct SwitchEvent : public Event<EV_SW, SwitchEventCode> {
    SwitchEvent(SwitchEventCode code, Value value)
    : Event(code, value)
    {
    }

    SwitchEvent(struct input_event event)
        : Event(event)
    {
    }
  };

  template <>
  struct event_from_event_code<SwitchEventCode> {
    using type = SwitchEvent;
  };

}

bool operator==(evdevw::SwitchEventCode code1, evdevw::SwitchEventCode code2) {
  return evdevw::enum_to_raw<uint16_t>(code1) == evdevw::enum_to_raw<uint16_t>(code2);
}

#endif //EVDEVW_SWITCHEVENT_HPP
