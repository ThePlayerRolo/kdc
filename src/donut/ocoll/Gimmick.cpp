#include <types.h>
#include "ocoll/Gimmick.hpp"

using namespace ocoll;

Gimmick::Gimmick(Manager& rManager)
    : mManager(rManager)
    , mBlockAttackArg(nullptr)
{ }

void Gimmick::chkCollide(AttackRoot& rAttackRoot, AttackResultGimmick& rAttackResultGimmick) {
    // not decompiled
}

bool Gimmick::mfIsBreakFire(const AttackData& rAttackData) const {
    u8 elem = rAttackData.mType.mElement;

    if (elem == 10) {
        return true;
    } else if (elem == 3) {
        return true;
    } else if (elem == 20) {
        return true;
    }

    return elem == 21;
}

bool Gimmick::mfIsBreakFireWeak(const AttackData& rAttackData) const {
    return rAttackData.mType.mElement == 11;
}

bool Gimmick::mfIsBreakHard(const AttackData& rAttackData) const {
    return rAttackData.mOption.mBlockBreakLv1 ? 1 : 0;
}

bool Gimmick::mfIsBreakIce(const AttackData& rAttackData) const {
    if (rAttackData.mType.mElement == 2) {
        return true;
    }

    return rAttackData.mType.mElement == 19;
}

bool Gimmick::mfIsBreakGold(const AttackData& rAttackData) const {
    return rAttackData.mOption.mBlockBreakLv2 ? 1 : 0;
}
