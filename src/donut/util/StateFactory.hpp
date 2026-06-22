#ifndef DONUT_UTIL_STATE_FACTORY_HPP
#define DONUT_UTIL_STATE_FACTORY_HPP

#include <types.h>

namespace util {
     //TODO: This is absolute pain and the worst part is, ITS USED THROUGHOUT ALL OF THE SCN CODE
    template <typename T>
    class StateFactory {
    public:
        StateFactory(void* pState) : mState((T*)pState) { }
        //NOTE: Merged into scn::IScene::`IScene()
        /* 0x08 */ virtual ~StateFactory() { }
        /* 0x0C */ virtual T* create() { }
    public:
        /* 0x04 */ T* mState;
    };

    //TODO: This is absolute pain and the worst part is, ITS USED THROUGHOUT ALL OF THE SCN CODE
    template <typename T, typename S, typename O>
    class StateFactoryArg1 : public StateFactory<T> {
    public:
        StateFactoryArg1(void* pState) : StateFactory<T>(pState) {

        }
        virtual ~StateFactoryArg1() { }
        virtual T* create() {
            if (mState != nullptr) {
                new S(_8);
            }

        }
    public:
        /* 0x08 */ O _8;
    };
}

#endif
