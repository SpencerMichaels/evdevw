#ifndef EVDEVW_LOGPRIORITY_HPP
#define EVDEVW_LOGPRIORITY_HPP

#include "Enum.hpp"

namespace evdevw {

  enum class LogPriority {
    Error = LIBEVDEV_LOG_ERROR,
    Info = LIBEVDEV_LOG_INFO,
    Debug = LIBEVDEV_LOG_DEBUG,
  };

  template <>
  int enum_to_raw<int, LogPriority>(LogPriority code) {
    using UT = std::underlying_type_t<LogPriority>;
    return static_cast<UT>(code);
  }

  template <>
  LogPriority raw_to_enum<LogPriority, int>(int code) {
    return static_cast<LogPriority>(code);
  }

}

bool operator==(evdevw::LogPriority code1, evdevw::LogPriority code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_LOGPRIORITY_HPP
