#include "scn/step/chara/Invincible.hpp"
#include "scn/step/enemy/SuperStop.hpp"

using namespace scn::step::chara;
using namespace scn::step::enemy;

Invincible::Invincible()
{
    mInvincibleFrames = 0;
    mFlashCycle = 0;
    mUsingIntangibleMove = 0;
    mIsCandyActive = 0;
}

void Invincible::update(void)
{
    u32 nextFlash;
    if (isInvincible())
    {
        updateFrame();
        nextFlash = mFlashCycle + 1;
        mFlashCycle = nextFlash;
        if (nextFlash == 0x14)
        {
            mFlashCycle = 0x10;
        }
    }
}

bool Invincible::isInvincible(void) const
{
    bool result = false;
    if ((mUsingIntangibleMove != false) || (mIsCandyActive != false) || (mInvincibleFrames != 0))
    {
        result = true;
    }

    return result;
}

void Invincible::set(u32 frames)
{
    if (mInvincibleFrames < frames)
    {
        mInvincibleFrames = frames;
    }

    mFlashCycle = 0;
    return;
}

void Invincible::clear(void)
{
    mInvincibleFrames = 0;
    // TODO: Investigate scn::step::enemy::onSuperStopStarted(const Manager &);
}

void Invincible::setPerm()
{
    mUsingIntangibleMove = true;
    mFlashCycle = 0;
}

void Invincible::unsetMighty()
{
    mIsCandyActive = false;
}

bool Invincible::isMighty() const
{
    return mIsCandyActive;
}

#pragma peephole off
u32 Invincible::getFlashAlpha() const
{
    bool result = isInvincible();
    u32 alpha;

    if (result)
    {
        alpha = T_ALPHA_ANIM_TABLE[mFlashCycle / 2];
    }
    else
    {
        alpha = 0;
    }

    return alpha;
}

void Invincible::updateFrame(void)
{
    u32 currentFrames = mInvincibleFrames;
    if (currentFrames != 0)
    {
        mInvincibleFrames = currentFrames - 1;
    }
}
