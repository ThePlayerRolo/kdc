#ifndef DONUT_SCN_STEP_ENEMY_HPP
#define DONUT_SCN_STEP_ENEMY_HPP

#include "mem/ExplicitScopedPtr.hpp"
#include "scn/step/Component.hpp"

/* clang-format off */
namespace scn { namespace step { namespace enemy {

class Enemy
{
public:
    // Enemy(scn::step::Component &rComponent);
    ~Enemy();

    void objStop();
public:
    /* 0x0 */ Component *mComponent;
    /* 0x4 */ u8 _4[0xAC - 0x4];
    /* 0x8 */ mem::ExplicitScopedPtr<u32> mObjStop;
};

}}}

#endif
