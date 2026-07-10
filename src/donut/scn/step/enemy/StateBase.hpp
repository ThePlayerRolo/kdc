#ifndef DONUT_ENEMY_STATE_BASE_HPP
#define DONUT_ENEMY_STATE_BASE_HPP

#include "scn/step/enemy/IState.hpp"

namespace scn { namespace step { namespace enemy {
    class Enemy;
    class StateBase : public util::IState {
    public:
        StateBase(Enemy* pObj);

        /* 0x08 */ virtual ~StateBase();
        /* 0x0C */ virtual void procAnim();
        /* 0x10 */ virtual void procMove();
        /* 0x14 */ virtual void procConstraint();
        /* 0x18 */ virtual void procFixPos();
        /* 0x1C */ virtual void procObjCollReact();

        //NOTE: Merged into nw4r::snd::detail::AxManager::GetZeroBufferAddress()
        Enemy& obj() const;
        //NOTE: Merged into nw4r::snd::detail::AxManager::GetZeroBufferAddress()
        Enemy& obj();
        //NOTE: Merged into nw4r::snd::detail::AxManager::GetZeroBufferAddress()
        Enemy* objPtr();
    public:
        /* 0x04 */ Enemy& mObj;
    };
}}}

#endif
