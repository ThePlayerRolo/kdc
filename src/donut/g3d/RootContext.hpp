#ifndef DONUT_G3D_ROOT_CONTEXT_HPP
#define DONUT_G3D_ROOT_CONTEXT_HPP

#include "mem/Memory.hpp"

namespace g3d {
    class RootContext {
    public:
        RootContext(mem::IAllocator& rAllocator, u32 maxNumChildren, u32 maxNumScnObj, u32 numLightObj, u32 numLightSet);
        //NOTE: Merged into g3d::ModelContext::DefaultAllocator()
        static mem::IAllocator& DefaultAllocator();
        //NOTE: Merged into nw4r::ut::DvdFileStream::GetBufferAlign() const
        static u32 DefaultMaxNumChildren();
        //NOTE: Merged into nw4r::ut::DvdFileStream::GetBufferAlign() const
        static u32 DefaultMaxScnObj();
        // NOTE: Merged into scn::challengefileselect::StaffCredit::kind() const
        static u32 DefaultNumLightObj();
        //NOTE: Merged into nw4r::ut::DvdFileStream::CanCancel() const
        static u32 DefaultNumLightSet();

    public:
        /* 0x00 */ mem::IAllocator& mAllocator;
        /* 0x04 */ u32 mMaxChildrenNum;
        /* 0x08 */ u32 mMaxScnObjNum;
        /* 0x0C */ u32 mLightObjNum;
        /* 0x10 */ u32 mLightSetNum;
    };
}

#endif
