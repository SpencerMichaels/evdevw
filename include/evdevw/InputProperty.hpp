#ifndef EVDEVW_INPUTPROPERTY_HPP
#define EVDEVW_INPUTPROPERTY_HPP

#include "Enum.hpp"

namespace evdevw {

  enum class InputProperty {
    Pointer = INPUT_PROP_POINTER,
    Direct = INPUT_PROP_DIRECT,
    Buttonpad = INPUT_PROP_BUTTONPAD,
    SemiMt = INPUT_PROP_SEMI_MT,
    Topbuttonpad = INPUT_PROP_TOPBUTTONPAD,
    PointingStick = INPUT_PROP_POINTING_STICK,
    Accelerometer = INPUT_PROP_ACCELEROMETER,
  };

  template <>
  int enum_to_raw<int, InputProperty>(InputProperty code) {
    using UT = std::underlying_type_t<InputProperty>;
    return static_cast<UT>(code);
  }

  template <>
  InputProperty raw_to_enum<InputProperty, int>(int code) {
    return static_cast<InputProperty>(code);
  }

  std::string input_property_get_name(InputProperty input_property) {
    return libevdev_property_get_name(enum_to_raw<int>(input_property));
  }

  std::optional<InputProperty> input_property_from_name(const std::string &name) {
    auto raw_input_property = libevdev_property_from_name(name.c_str());
    if (raw_input_property < 0)
      return std::nullopt;
    return raw_to_enum<InputProperty>(raw_input_property);
  }

}

bool operator==(evdevw::InputProperty code1, evdevw::InputProperty code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_INPUTPROPERTY_HPP
