#ifndef DONUT_BOSS_INTERFACE_STATE_HPP
#define DONUT_BOSS_INTERFACE_STATE_HPP

#include "util/IState.hpp"

namespace scn { namespace step { namespace boss {
    class IState : public util::IState {
    public:
        /* 0x08 */ virtual ~IState();
    };
}}}

#endif
