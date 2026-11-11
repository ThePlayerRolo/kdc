#ifndef DONUT_G3D_COLOR_ANIM_TEV_MANAGER_HPP
#define DONUT_G3D_COLOR_ANIM_TEV_MANAGER_HPP

#include <hel/common/Array.hpp>
#include <nw4r/g3d/res/g3d_restev.h>

namespace g3d {
    class ColorAnimTevManager {
    public:
        struct TevRegUser {
            /* 0x0 */ s32 m_0;
        };

        struct KonstRegUser {
            /* 0x0 */ s32 m_0;
        };

        ColorAnimTevManager(const nw4r::g3d::ResTev& rResTev);
        GXTevStageID lastStage() const;
        void incStageNum();
        bool isUsedTevReg(GXTevRegID tevRegId) const DONT_INLINE; // TODO: Remove DONT_INLINE
        GXTevRegID findFreeTevReg() const;
        void reserveWithTevColorArg(const nw4r::g3d::ResTev& rResTev, GXTevStageID tevStageId, GXTevColorArg tevColorArg);
        void reserveWithTevKColorSel(GXTevKColorSel tevKColorSel);
        void reserveWithTevAlphaArg(const nw4r::g3d::ResTev& rResTev, GXTevStageID tevStageId, GXTevAlphaArg tevColorArg);
        void reserveWithTevKAlphaSel(GXTevKAlphaSel tevKAlphaSel);
        void reserveWithTevRegID(GXTevRegID tevRegId);

        // NOTE: Is merged into nw4r::snd::detail::AxManager::GetZeroBufferAddress()
        GXTevStageID currentStageNum() const;
    public:
        /* 0x00 */ s32 m_0;
        /* 0x04 */ GXTevStageID mCurrentStageNum;
        /* 0x08 */ hel::common::Array<TevRegUser, 4> mTevRegUsers;
        /* 0x18 */ hel::common::Array<KonstRegUser, 4> mKonstRegUsers;
    };

}

#endif
