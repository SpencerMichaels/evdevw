#ifndef EVDEVW_ABSOLUTEEVENT_HPP
#define EVDEVW_ABSOLUTEEVENT_HPP

#include "Event.hpp"

namespace evdevw {

  enum class AbsoluteEventCode {
    X = ABS_X,
    Y = ABS_Y,
    Z = ABS_Z,
    Rx = ABS_RX,
    Ry = ABS_RY,
    Rz = ABS_RZ,
    Throttle = ABS_THROTTLE,
    Rudder = ABS_RUDDER,
    Wheel = ABS_WHEEL,
    Gas = ABS_GAS,
    Brake = ABS_BRAKE,
    Hat0x = ABS_HAT0X,
    Hat0y = ABS_HAT0Y,
    Hat1x = ABS_HAT1X,
    Hat1y = ABS_HAT1Y,
    Hat2x = ABS_HAT2X,
    Hat2y = ABS_HAT2Y,
    Hat3x = ABS_HAT3X,
    Hat3y = ABS_HAT3Y,
    Pressure = ABS_PRESSURE,
    Distance = ABS_DISTANCE,
    TiltX = ABS_TILT_X,
    TiltY = ABS_TILT_Y,
    ToolWidth = ABS_TOOL_WIDTH,
    Volume = ABS_VOLUME,
    Misc = ABS_MISC,
    MtSlot = ABS_MT_SLOT,
    MtTouchMajor = ABS_MT_TOUCH_MAJOR,
    MtTouchMinor = ABS_MT_TOUCH_MINOR,
    MtWidthMajor = ABS_MT_WIDTH_MAJOR,
    MtWidthMinor = ABS_MT_WIDTH_MINOR,
    MtOrientation = ABS_MT_ORIENTATION,
    MtPositionX = ABS_MT_POSITION_X,
    MtPositionY = ABS_MT_POSITION_Y,
    MtToolType = ABS_MT_TOOL_TYPE,
    MtBlobId = ABS_MT_BLOB_ID,
    MtTrackingId = ABS_MT_TRACKING_ID,
    MtPressure = ABS_MT_PRESSURE,
    MtDistance = ABS_MT_DISTANCE,
    MtToolX = ABS_MT_TOOL_X,
    MtToolY = ABS_MT_TOOL_Y,
  };

  template <>
  int enum_to_raw<int, AbsoluteEventCode>(AbsoluteEventCode code) {
    using UT = std::underlying_type_t<AbsoluteEventCode>;
    return static_cast<UT>(code);
  }

  template <>
  AbsoluteEventCode raw_to_enum<AbsoluteEventCode, int>(int code) {
    if (code < ABS_MAX)
      return static_cast<AbsoluteEventCode>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

  struct AbsoluteEvent : public Event<EV_ABS, AbsoluteEventCode> {
    AbsoluteEvent(AbsoluteEventCode code, Value value)
      : Event<EV_ABS, AbsoluteEventCode>(code, value)
    {
    }

    AbsoluteEvent(struct input_event event)
      : Event<EV_ABS, AbsoluteEventCode>(event)
    {
    }
  };

}

bool operator==(evdevw::AbsoluteEventCode code1, evdevw::AbsoluteEventCode code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_ABSOLUTEEVENT_HPP
