#ifndef DONUT_UTIL_INTERFACE_STATE_CHANGER_HPP
#define DONUT_UTIL_INTERFACE_STATE_CHANGER_HPP

#include <types.h>

namespace util {
    class IStateChanger {
    public:
        //NOTE: Merged into scn::IScene::`IScene()
        virtual ~IStateChanger();
    };
}

#endif
