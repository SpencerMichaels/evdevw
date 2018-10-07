#ifndef EVDEVW_BUSTYPE_HPP
#define EVDEVW_BUSTYPE_HPP

#include <stdexcept>
#include <type_traits>

#include <linux/input.h>

#include "Enum.hpp"

namespace evdevw {

  enum class BusType {
    Pci = BUS_PCI,
    Isapnp = BUS_ISAPNP,
    Usb = BUS_USB,
    Hil = BUS_HIL,
    Bluetooth = BUS_BLUETOOTH,
    Virtual = BUS_VIRTUAL,
    Isa = BUS_ISA,
    I8042 = BUS_I8042,
    Xtkbd = BUS_XTKBD,
    Rs232 = BUS_RS232,
    Gameport = BUS_GAMEPORT,
    Parport = BUS_PARPORT,
    Amiga = BUS_AMIGA,
    Adb = BUS_ADB,
    I2c = BUS_I2C,
    Host = BUS_HOST,
    Gsc = BUS_GSC,
    Atari = BUS_ATARI,
    Spi = BUS_SPI,
    Rmi = BUS_RMI,
    Cec = BUS_CEC,
    IntelIshtp = BUS_INTEL_ISHTP,
  };

  template <>
  int enum_to_raw<int, BusType>(BusType code) {
    using UT = std::underlying_type_t<BusType>;
    return static_cast<UT>(code);
  }

  template <>
  BusType raw_to_enum<BusType, int>(int code) {
    if (code <= BUS_INTEL_ISHTP)
      return static_cast<BusType>(code);
    throw std::runtime_error("Invalid value for enum type!");
  }

}

bool operator==(evdevw::BusType code1, evdevw::BusType code2) {
  return evdevw::enum_to_raw<int>(code1) == evdevw::enum_to_raw<int>(code2);
}

#endif //EVDEVW_BUSTYPE_HPP
