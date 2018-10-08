#ifndef EVDEVW_ENUMCONVERTERS_HPP
#define EVDEVW_ENUMCONVERTERS_HPP

namespace evdevw {

  template <typename Raw, typename Enum>
  Raw enum_to_raw(Enum code);

  template <typename Enum, typename Raw>
  Enum raw_to_enum(Raw raw);

  template <typename Code>
  struct event_from_event_code {
  };

}

#endif //EVDEVW_ENUMCONVERTERS_HPP
