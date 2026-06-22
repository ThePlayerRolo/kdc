#ifndef DONUT_UTIL_INTERFACE_STATE_CALLBACK_HPP
#define DONUT_UTIL_INTERFACE_STATE_CALLBACK_HPP

#include <types.h>

namespace util {
    class IStateChanger;

    class IStateCallback {
    public:
        //NOTE: Merged into scn::IScene::`IScene()
        /* 0x08 */ virtual ~IStateCallback();
        /* 0x0C */ virtual void onStateChanged(const IStateChanger&) = 0;
    };
}

#endif
