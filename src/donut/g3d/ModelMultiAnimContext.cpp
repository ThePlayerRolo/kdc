#pragma peephole off

#include "g3d/ModelMultiAnimContext.hpp"

namespace g3d {

    hel::common::FixedString<32> ModelMultiAnimContext::DefaultHeapNamePrefix() {
        return hel::common::FixedString<32>(hel::common::FixedString<32>::FromFormat("%s", "MdlAnm"));
    }

    u32 ModelMultiAnimContext::DefaultOneAnimSlotWorkMemSize() {
        return 0x2000;
    }

    ModelMultiAnimContext::ModelMultiAnimContext(const ResModelContext &rModelCtx, u32 animSlotNum, u32 oneAnimSlotSlotWorkMemSize,
        const hel::common::FixedString<32>& rHeapNamePrefix, mem::IAllocator& rAllocator)
    : ResModelContext(rModelCtx)
    , mOneAnimSlotSlotWorkMemSize(oneAnimSlotSlotWorkMemSize)
    , mAnimSlotNum(animSlotNum)
    , mHeapNamePrefix(rHeapNamePrefix)
    , mAllocator(rAllocator)
    { }

    u32 ModelMultiAnimContext::DefaultAnimSlotNum() {
        return 2;
    }
}
