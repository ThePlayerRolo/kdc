#ifndef DONUT_SCN_STEP_ENEMY_DESC_HPP
#define DONUT_SCN_STEP_ENEMY_DESC_HPP

#include <hel/math/Vector2.hpp>
#include "scn/step/map/BinEnemy.hpp"

namespace scn { namespace step {
    namespace enemy {
    class Desc {
    public:
        Desc();
        Desc(map::BinEnemyKind kind, map::BinEnemyVariation variation, u32,
            map::BinEnemyDirType dirType, map::BinEnemySize size, bool, bool, const hel::math::Vector2&);
    public:
        /* 0x00 */ map::BinEnemyKind mKind;
        /* 0x04 */ map::BinEnemyVariation mVariation;
        /* 0x08 */ u32 _8;
        /* 0x0C */ map::BinEnemyDirType mDirType;
        /* 0x10 */ map::BinEnemySize mSize;
        /* 0x14 */ bool _14;
        /* 0x15 */ bool _15;
        /* 0x18 */ hel::math::Vector2 _18;
        /* 0x20 */ hel::math::Vector2 _20;
        /* 0x28 */ u8 _28;
        /* 0x29 */ u8 _29;
        /* 0x2C */ s32 _2C;
        /* 0x30 */ u8 _30;
        /* 0x31 */ u8 _31;
        /* 0x32 */ u8 _32;
    };

}}};

#endif
