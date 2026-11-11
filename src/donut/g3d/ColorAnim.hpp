#ifndef DONUT_G3D_COLOR_ANIM_HPP
#define DONUT_G3D_COLOR_ANIM_HPP

#include "g3d/ColorAnimContext.hpp"
#include "g3d/ColorAnimMaterialTarget.hpp"
#include "g3d/ColorAnimTevManager.hpp"

namespace g3d {
    class ColorAnimFlash;

    class ColorAnim {
    public:
        ColorAnim(const g3d::ColorAnimContext& rContext);

        void updateBegin();
        void updateEnd();
        void updateFlash(const ColorAnimFlash& rFlash);
    public:
        /* 0x00 */ MaterialAccessor mMatAccessor;
        /* 0x38 */ ColorAnimTevManager mTevMgr;
        /* 0x60 */ ColorAnimMaterialTarget mMatTarget;
    };

}

#endif
