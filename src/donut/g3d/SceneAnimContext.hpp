#ifndef DONUT_G3D_SCENE_ANIM_CONTEXT_HPP
#define DONUT_G3D_SCENE_ANIM_CONTEXT_HPP

#include "mem/IAllocator.hpp"

namespace g3d {
    class ResFileAccessor;

    class SceneAnimContext {
    public:
        //NOTE: Merged into nw4r::g3d::Camera::Camera(nw4r::g3d::CameraData*)
        SceneAnimContext(mem::IAllocator& rAllocator);
    public:
        /* 0x00 */ mem::IAllocator mAllocator;
    };
}

#endif
