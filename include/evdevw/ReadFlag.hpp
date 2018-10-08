#ifndef EVDEVW_READFLAG_HPP
#define EVDEVW_READFLAG_HPP

#include <cstdint>

#include "Enum.hpp"

namespace evdevw {

  enum class ReadFlag {
    Sync = LIBEVDEV_READ_FLAG_SYNC,
    Normal = LIBEVDEV_READ_FLAG_NORMAL,
    ForceSync = LIBEVDEV_READ_FLAG_FORCE_SYNC,
    Blocking = LIBEVDEV_READ_FLAG_BLOCKING,
  };

  template <>
  uint16_t enum_to_raw<uint16_t, ReadFlag>(ReadFlag code) {
    using UT = std::underlying_type_t<ReadFlag>;
    return static_cast<UT>(code);
  }

  template <>
  ReadFlag raw_to_enum<ReadFlag, uint16_t>(uint16_t code) {
    return static_cast<ReadFlag>(code);
  }

}

#endif //EVDEVW_READFLAG_HPP
