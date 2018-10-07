#ifndef EVDEVW_READSTATUS_HPP
#define EVDEVW_READSTATUS_HPP

#include "Enum.hpp"

namespace evdevw {

  enum class ReadStatus {
    Success = LIBEVDEV_READ_STATUS_SUCCESS,
    Sync = LIBEVDEV_READ_STATUS_SYNC,
  };

  template <>
  int enum_to_raw<int, ReadStatus>(ReadStatus code) {
    using UT = std::underlying_type_t<ReadStatus>;
    return static_cast<UT>(code);
  }

  template <>
  ReadStatus raw_to_enum<ReadStatus, int>(int code) {
    return static_cast<ReadStatus>(code);
  }

}

#endif //EVDEVW_READSTATUS_HPP
