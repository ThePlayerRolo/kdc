#pragma peephole off
#include "g3d/ModelAnimContext.hpp"

namespace g3d {
      ModelAnimContext::ModelAnimContext(const ResModelContext& rModelCtx, mem::IAllocator& rCharaAllocator,
        mem::IAllocator& rColorAllocator, mem::IAllocator& rShapeAllocator, mem::IAllocator& rTexPatternAllocator,
        mem::IAllocator& rTexSRTAllocator, mem::IAllocator& rVisibleAllocator)
    : ResModelContext(rModelCtx)
    , mCharaAllocator(rCharaAllocator)
    , mColorAllocator(rColorAllocator)
    , mShapeAllocator(rShapeAllocator)
    , mTexPatternAllocator(rTexPatternAllocator)
    , mTexSRTAllocator(rTexSRTAllocator)
    , mVisibleAllocator(rVisibleAllocator)
    { }
}
