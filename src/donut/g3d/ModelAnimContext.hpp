#ifndef DONUT_G3D_MODEL_ANIM_CONTEXT_HPP
#define DONUT_G3D_MODEL_ANIM_CONTEXT_HPP

#include "g3d/ResModelContext.hpp"
#include "mem/IAllocator.hpp"

namespace g3d {
    class ModelAnimContext : public ResModelContext {
    public:
      ModelAnimContext(const ResModelContext& rModelCtx, mem::IAllocator& rCharaAllocator,
        mem::IAllocator& rColorAllocator, mem::IAllocator& rShapeAllocator, mem::IAllocator& rTexPatternAllocator,
        mem::IAllocator& rTexSRTAllocator, mem::IAllocator& rVisibleAllocator);

    public:
        /* 0x2C */ mem::IAllocator& mCharaAllocator;
        /* 0x30 */ mem::IAllocator& mColorAllocator;
        /* 0x34 */ mem::IAllocator& mShapeAllocator;
        /* 0x38 */ mem::IAllocator& mTexPatternAllocator;
        /* 0x3C */ mem::IAllocator& mTexSRTAllocator;
        /* 0x40 */ mem::IAllocator& mVisibleAllocator;
    };
}

#endif
