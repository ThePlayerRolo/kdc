#ifndef DONUT_G3D_MODEL_MULTI_ANIM_CONTEXT_HPP
#define DONUT_G3D_MODEL_MULTI_ANIM_CONTEXT_HPP

#include "g3d/ResModelContext.hpp"
#include "g3d/ModelBufferOption.hpp"
#include "mem/Memory.hpp"

namespace g3d {
    // TODO: mAnimSlotNum and mOneAnimSlotSlotWorkMemSize may need to be swapped later down the line
    class ModelMultiAnimContext : public ResModelContext {
    public:
      ModelMultiAnimContext(const ResModelContext &rModelCtx, u32 animSlotNum, u32 oneAnimSlotSlotWorkMemSize,
        const hel::common::FixedString<32>& rHeapNamePrefix, mem::IAllocator& rAllocator);

        hel::common::FixedString<32> DefaultHeapNamePrefix();
        u32 DefaultOneAnimSlotWorkMemSize(); //Thats a name alright

        //NOTE: Is merged into nw4r::ut::detail::ResFontBase::GetType() const
        static u32 DefaultAnimSlotNum();
    public:
        /* 0x2C */ u32 mAnimSlotNum;
        /* 0x30 */ u32 mOneAnimSlotSlotWorkMemSize; //Thats a name alright
        /* 0x34 */ hel::common::FixedString<32> mHeapNamePrefix;
        /* 0x54 */ mem::IAllocator& mAllocator;
    };
}

#endif
