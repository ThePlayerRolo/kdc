#ifndef DONUT_ENEMY_INTERFACE_STATE_HPP
#define DONUT_ENEMY_INTERFACE_STATE_HPP

#include "util/IState.hpp"

namespace scn { namespace step { namespace enemy {
    class IState : public util::IState {
    public:
        //NOTE: Merged into scn::step::boss::IState::~IState()
        virtual ~IState();
    };
}}}

#endif
