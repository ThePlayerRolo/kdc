#ifndef DONUT_SCN_STEP_ENEMY_ENEMY_HPP
#define DONUT_SCN_STEP_ENEMY_ENEMY_HPP

#include "scn/step/Component.hpp"
#include "scn/step/enemy/IState.hpp"
#include "util/StateChanger.hpp"

// clang-format off

namespace gobj {
    class FootState;
}

namespace scn { namespace step {
    namespace chara {
        class Model;
    }

    namespace enemy {

    class Enemy {
    public:
        ~Enemy();

        step::chara::Model* model();
        gobj::FootState* footState();
        util::StateChanger<scn::step::enemy::IState, 256>* stateChanger();

    public:
        Component *mComponent; 
    };

}}};

// clang-format on

#endif
