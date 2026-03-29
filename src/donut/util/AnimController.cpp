#pragma peephole off
#include <donut/util/AnimController.hpp>

using util::AnimController;

AnimController::AnimController(f32 arg1)
    : mTotalFrame(arg1)
    , mFrame(0.0f)
    , mFrameRate(1.0f)
    , mDoLoop(false)
    , mIsAnimating(false)
    , mLooped(false)
{}

void AnimController::setFrameToHead() {
    mFrame = 0.0f;
}

void AnimController::setFrameToTail() {
    setFrame(mTotalFrame);
}

void AnimController::updateFrame() {
    if (!mIsAnimating) {
        return;
    }
    f32 mTotalFrameVal;
    f32 nextFrame = mFrame + mFrameRate;
    mLooped = false;

    if (mDoLoop &&  mFrameRate != 0.0f) {
        mTotalFrameVal = mTotalFrame;
        if (0.0f < mFrameRate) {
            if (mTotalFrameVal <= nextFrame) {
                mLooped = true;
                while (mTotalFrameVal <= nextFrame) {
                nextFrame -= mTotalFrameVal;
                }
            }
        }
        else if (nextFrame < 0.0f) {
            mLooped = true;
            while (nextFrame < 0.0f) {
                nextFrame += mTotalFrameVal;
            }
        }
    }
    mFrame = nextFrame;
    checkAnimEnd();
}

void AnimController::start(bool arg1) {
    mDoLoop = arg1;
    mIsAnimating = true;
    mLooped = false;
    checkAnimEnd();
}

void AnimController::stop() {
    if (!mIsAnimating) {
        return;
    }
    mIsAnimating = false;
}

bool AnimController::isAnimEnd() const {
    if (mDoLoop) {
        return false;
    }
    if (0.0f < mFrameRate) {
        return mTotalFrame <= mFrame;
    }
    if (mFrameRate < 0.0f) {
        return mFrame <= 0.0f;
    }
    return false;
}

void AnimController::checkAnimEnd() {
    if (isAnimEnd()) {
        mIsAnimating = false;
    }
}

//Note: All functions below are merged into other ones in the final binary. Refer to the header for more info
f32 AnimController::frame() const {
    return mFrame;
}

f32 AnimController::totalFrame() const {
    return mTotalFrame;
}

void AnimController::setFrame(f32 frame) {
    mFrame = frame;
}

void AnimController::changeTotalFrame(f32 totalFrame) {
    mTotalFrame = totalFrame;
}

f32 AnimController::frameRate() const {
    return mFrameRate;
}

void AnimController::setFrameRate(f32 frameRate) {
    mFrame = frameRate;
}

bool AnimController::isAnimating() const {
    return mIsAnimating;
}

bool AnimController::isLooped() const {
    return mLooped;
}

void AnimController::changeDoLoop(bool arg1) {
    mDoLoop = arg1;
}
