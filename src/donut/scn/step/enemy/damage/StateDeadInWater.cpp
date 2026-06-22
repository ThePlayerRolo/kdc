#pragma peephole off
#include "scn/step/enemy/Enemy.hpp"
#include "gobj/FootState.hpp"
#include "scn/step/chara/Model.hpp"
#include "scn/step/enemy/damage/StateDeadInWater.hpp"

namespace scn { namespace step { namespace enemy { namespace damage {
    StateDeadInWater::StateDeadInWater(Enemy* pObj)
    : StateBase(pObj)
    , _8(0)
    , _C(true)
    , _10(pObj->model()->anim()->frameRate())
    , _14(0.0f)
    , _18(0.0f)
    , _1C(1.0f)
    {
        obj().footState()->setAir();
        // More...
    }

    StateDeadInWater::~StateDeadInWater() { }
}}}}
