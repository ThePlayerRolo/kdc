#ifndef DONUT_SCN_STEP_HERO_GUARD_HPP
#define DONUT_SCN_STEP_HERO_GUARD_HPP

#include <GX/GXTypes.h>
#include <types.h>

#include "scn/step/hero/Hero.hpp"

/* clang-format off */
namespace scn { namespace step { namespace hero {

const u32 T_ALPHA_TABLE[20] = {
    0xC0,
    0xC0,
    0xA0,
    0x90,
    0x80,
    0x60,
    0x40,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00,
    0x40,
    0x60,
    0x40,
    0x20,
    0x00,
    0x00,
    0x00,
    0x00
};

class Guard
{
public:
    Guard(Hero &hero);
    void update();
    void setGuard(bool flag);
    _GXColor getColor() const;
private:
    /* 0x00 */ Hero *mHero;
    /* 0x04 */ bool mEnableGuardState;
    /* 0x05 */ bool mEnableGuardFlash;
    /* 0x08 */ u32 mGuardFlashCycle;
};

}}}

#endif
