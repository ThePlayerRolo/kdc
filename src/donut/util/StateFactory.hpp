#ifndef DONUT_UTIL_STATE_FACTORY_HPP
#define DONUT_UTIL_STATE_FACTORY_HPP

#include <types.h>

namespace util {
    template <typename T>
    class StateFactory {
    public:
        StateFactory(void* pState) : mState(pState) { }
        //NOTE: Merged into scn::IScene::`IScene()
        /* 0x08 */ virtual ~StateFactory() { }
        /* 0x0C */ virtual T* create() = 0;
    public:
        /* 0x04 */ T* mState;
    };
}

#endif
