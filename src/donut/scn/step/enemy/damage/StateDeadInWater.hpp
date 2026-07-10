#ifndef DONUT_ENEMY_DAMAGE_STATE_DEAD_IN_WATER_HPP
#define DONUT_ENEMY_DAMAGE_STATE_DEAD_IN_WATER_HPP

#include "scn/step/enemy/StateBase.hpp"

namespace scn { namespace step { namespace enemy { namespace damage {
    class StateDeadInWater : public StateBase {
    public:
        StateDeadInWater(Enemy* pObj);

        /* 0x08 */ virtual ~StateDeadInWater();
        /* 0x0C */ virtual void procAnim();
        /* 0x10 */ virtual void procMove();
        /* 0x18 */ virtual void procFixPos();

        void deadFlash();
    public:
        /* 0x08 */ s32 _8;
        /* 0x0C */ bool _C;
        /* 0x10 */ f32 _10;
        /* 0x14 */ f32 _14;
        /* 0x18 */ f32 _18;
        /* 0x1C */ f32 _1C;
    };
}}}}

#endif
