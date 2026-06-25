#pragma peephole off
#include "g3d/RootContext.hpp"

namespace g3d {
    RootContext::RootContext(mem::IAllocator& rAllocator, u32 maxNumChildren, u32 maxNumScnObj, u32 numLightObj, u32 numLightSet)
    : mAllocator(rAllocator)
    , mMaxChildrenNum(maxNumChildren)
    , mMaxScnObjNum(maxNumScnObj)
    , mLightObjNum(numLightObj)
    , mLightSetNum(numLightSet)
    {}

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    mem::IAllocator& RootContext::DefaultAllocator() {
        return mem::Memory::Instance->sceneHeap();
    }

    u32 RootContext::DefaultMaxNumChildren() {
        return 32;
    }

    u32 RootContext::DefaultMaxScnObj() {
        return 32;
    }

    u32 RootContext::DefaultNumLightObj() {
        return 8;
    }

    u32 RootContext::DefaultNumLightSet() {
        return 1;
    }
}
