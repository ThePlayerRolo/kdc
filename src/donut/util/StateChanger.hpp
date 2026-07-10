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

    //TODO: This is absolute pain and the worst part is, ITS USED THROUGHOUT ALL OF THE SCN CODE
    template <typename T, int S>
    class StateChanger : public StateChangerBase {
    public:
        /* 0x08 */ virtual ~StateChanger() { }

        template <typename St, typename B>
        void setNextState(B) {
            onSetNextStateFactory();

            if (&_10 != nullptr) {
                _10 = StateFactoryArg1<IState, St, B>(_90);
            }
            mStateFactory = &_10;
        }

        template <typename St, typename B, typename P>
        void setNextState(B, P);
    public:
        StateFactory<IState> _10;
        void* _90;
    };
}

#endif
