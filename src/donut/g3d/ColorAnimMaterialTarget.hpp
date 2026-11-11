#ifndef DONUT_G3D_COLOR_ANIM_MATERIAL_TARGET_HPP
#define DONUT_G3D_COLOR_ANIM_MATERIAL_TARGET_HPP

#include <revolution/GX.h>

namespace g3d {
    class ColorAnimMaterialTarget {
    public:
        ColorAnimMaterialTarget();
        ColorAnimMaterialTarget(GXTevStageID tevStageID, GXTevRegID tevRegID);

        GXTevColorArg tevRegId2GXTevColorArg() const;
        GXTevColorArg tevRegId2GXTevColorArgAlpha() const;
        // NOTE: Is merged into nw4r::snd::detail::AxManager::GetZeroBufferAddress()
        GXTevStageID tevStageID() const;
        // NOTE: Is merged into ARCGetLength
        GXTevRegID tevRegID() const;
    public:
        /* 0x00 */ s32 m_0;
        /* 0x04 */ GXTevStageID mTevStageID;
        /* 0x08 */ GXTevRegID mTevRegID;
        /* 0x0C */ s32 m_C;
    };

}

#endif
