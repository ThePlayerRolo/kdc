#include "scn/step/enemy/Enemy.hpp"
#pragma peephole off
#include "util/IStateCallback.hpp"
#include "util/StateChanger.hpp"

namespace util {

    StateChangerBase::StateChangerBase(IStateCallback& rCallback)
        : mCallback(rCallback)
        , mCurrentState(nullptr)
        , mStateFactory(nullptr)
    { }

    StateChangerBase::~StateChangerBase() {
        reset();
    }

    void StateChangerBase::changeStateIfPossible() {
        if (hasNextState()) {
            changeState();
        }
    }

    void StateChangerBase::changeState() {
        if (mCurrentState != nullptr) {
            releaseCurrentState();
        }
        mCallback.onStateChanged(*this);
        mCurrentState = mStateFactory->create();
        releaseNextStateFactory();
    }

    void StateChangerBase::reset() {
        if (mStateFactory != nullptr) {
            releaseNextStateFactory();
        }
        if (mCurrentState != nullptr) {
            releaseCurrentState();
        }
    }

    void StateChangerBase::releaseCurrentState() {
        mCurrentState->~IState();
        mCurrentState = nullptr;
    }

    void StateChangerBase::releaseNextStateFactory() {
        mStateFactory->~StateFactory<IState>();
        mStateFactory = nullptr;
    }

    void StateChangerBase::onSetNextStateFactory() {
        if (mStateFactory == nullptr) return;

        releaseNextStateFactory();
    }
}
