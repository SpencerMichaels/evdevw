#ifndef EVDEVW_CLOCKID_HPP
#define EVDEVW_CLOCKID_HPP

#include <time.h>

#include "Enum.hpp"

namespace evdevw {

  enum class ClockId {
    Monotonic = CLOCK_MONOTONIC,
    Realtime = CLOCK_REALTIME,
  };

  template <>
  int enum_to_raw<int, ClockId>(ClockId code) {
    using UT = std::underlying_type_t<ClockId>;
    return static_cast<UT>(code);
  }

  template <>
  ClockId raw_to_enum<ClockId, int>(int code) {
    return static_cast<ClockId>(code);
  }

}

bool operator==(evdevw::ClockId code1, evdevw::ClockId code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_CLOCKID_HPP
