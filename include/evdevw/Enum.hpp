#ifndef EVDEVW_ENUMCONVERTERS_HPP
#define EVDEVW_ENUMCONVERTERS_HPP

namespace evdevw {

  template <typename Enum, typename Raw, Raw _max>
  struct _convert_enum_impl {
    using RawType = Raw;

    static Enum from_raw(Raw code) {
      if (_max > 0 && code < _max)
        return static_cast<Enum>(code);
      throw std::runtime_error("Invalid value for enum type!");
    }

    static Raw to_raw(Enum code) {
      using UT = std::underlying_type_t<Enum>;
      return (Raw)static_cast<UT>(code);
    }
  };

  template <typename Enum>
  struct convert_enum {};

  template <typename Enum>
  typename convert_enum<Enum>::RawType enum_to_raw(Enum code) {
    return convert_enum<Enum>::to_raw(code);
  }

  template <typename Enum>
  Enum raw_to_enum(typename convert_enum<Enum>::RawType code) {
    return convert_enum<Enum>::from_raw(code);
  }

  template <typename Code>
  struct event_from_event_code {
  };

}

#endif //EVDEVW_ENUMCONVERTERS_HPP
