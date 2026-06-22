#ifndef DONUT_UTIL_STATE_CHANGER_HPP
#define DONUT_UTIL_STATE_CHANGER_HPP

#include "util/IStateChanger.hpp"
#include "util/StateFactory.hpp"
#include "util/IState.hpp"

namespace util {
    class IStateCallback;

    class StateChangerBase : public IStateChanger {
    public:
        StateChangerBase(IStateCallback& rCallback);

        /* 0x08 */ virtual ~StateChangerBase();

        void changeState();
        void changeStateIfPossible();
        void onSetNextStateFactory();
        void releaseCurrentState();
        void releaseNextStateFactory();
        void reset();
        // NOTE: Merged into file::FileTree::wasSetParent() const
        bool hasNextState() const;
        // NOTE: Merged into ARCGetLength
        IState& currentStateRef();
    public:
        /* 0x04 */ IStateCallback& mCallback;
        /* 0x08 */ IState* mCurrentState;
        /* 0x0C */ StateFactory<IState>* mStateFactory;
    };
}

#endif

/*
--> hasNextState__Q24util16StateChangerBaseCFv is duplicated by wasSetParent__Q24file8FileTreeCFv, size = 16

--> currentStateRef__Q24util16StateChangerBaseFv is duplicated by ARCGetLength, size = 8
*/
