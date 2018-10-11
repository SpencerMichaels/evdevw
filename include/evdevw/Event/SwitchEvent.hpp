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
  struct convert_enum<SwitchEventCode> : public _convert_enum_impl<SwitchEventCode, uint16_t, SW_MAX> {};

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

#endif //EVDEVW_SWITCHEVENT_HPP
