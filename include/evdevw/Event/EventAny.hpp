#ifndef EVDEVW_EVENTANY_HPP
#define EVDEVW_EVENTANY_HPP

#include <variant>

#include "AbsoluteEvent.hpp"
#include "ForceFeedbackEvent.hpp"
#include "ForceFeedbackStatusEvent.hpp"
#include "KeyEvent.hpp"
#include "LedEvent.hpp"
#include "MiscEvent.hpp"
#include "PowerEvent.hpp"
#include "RelativeEvent.hpp"
#include "RepeatEvent.hpp"
#include "SoundEvent.hpp"
#include "SwitchEvent.hpp"
#include "SynchronizeEvent.hpp"

namespace evdevw {

  using EventAny = std::variant<
    AbsoluteEvent,
    ForceFeedbackEvent,
    ForceFeedbackStatusEvent,
    KeyEvent,
    LedEvent,
    MiscEvent,
    PowerEvent,
    RelativeEvent,
    RepeatEvent,
    SoundEvent,
    SwitchEvent,
    SynchronizeEvent>;

}

#endif //EVDEVW_EVENTANY_HPP
