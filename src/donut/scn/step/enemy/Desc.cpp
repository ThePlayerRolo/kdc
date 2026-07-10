#pragma peephole off

#include "scn/step/enemy/Desc.hpp"

using scn::step::enemy::Desc;

Desc::Desc()
    : mKind(map::BIN_ENEMY_KIND_0)
    , mVariation(map::BIN_ENEMY_VARIATION_0)
    , _8(0)
    , mDirType(map::BIN_ENEMY_DIR_TYPE_0)
    , mSize(map::BIN_ENEMY_SIZE_0)
    , _14(false)
    , _15(false)
    , _18(hel::math::Vector2::ZERO)
    , _20(hel::math::Vector2::ZERO)
    , _28(0)
    , _29(0)
    , _2C(0)
    , _30(0)
    , _31(0)
    , _32(0)
{ }

Desc::Desc(map::BinEnemyKind kind, map::BinEnemyVariation variation, u32 param_3,
            map::BinEnemyDirType dirType, map::BinEnemySize size, bool param_6, bool param_7, const hel::math::Vector2& rVec)
    : mKind(kind)
    , mVariation(variation)
    , _8(param_3)
    , mDirType(dirType)
    , mSize(size)
    , _14(param_6)
    , _15(param_7)
    , _18(rVec)
    , _20(rVec)
    , _28(0)
    , _29(0)
    , _2C(0)
    , _30(0)
    , _31(0)
    , _32(1)
{ }
