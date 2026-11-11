#ifndef DONUT_G3D_MODEL_ANIM_HPP
#define DONUT_G3D_MODEL_ANIM_HPP

#include "g3d/ResModel.hpp"
#include "util/AnimController.hpp"
#include "mem/SDKAllocator.hpp"

namespace g3d {
    class ModelAnim {
    public:


    public:
        /* 0x00 */ ResModel mResModel;
        /* 0x08 */ util::AnimController mController;
        /* 0x18 */ mem::SDKAllocator mCharaAllocator;
        /* 0x30 */ mem::SDKAllocator mColorAllocator;
        /* 0x48 */ mem::SDKAllocator mShapeAllocator;
    };
}

#endif
