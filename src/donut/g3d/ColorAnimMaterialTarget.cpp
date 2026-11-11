#include "g3d/ColorAnimMaterialTarget.hpp"


namespace g3d {
    namespace {
        const GXTevColorArg T_TEV_REG_ID_2_TEV_COLOR_ARG[GX_MAX_TEVREG] = {
            GX_CC_CPREV,
            GX_CC_C0,
            GX_CC_C1,
            GX_CC_C2
        };

       const GXTevColorArg T_TEV_REG_ID_2_TEV_COLOR_ARG_ALPHA[GX_MAX_TEVREG] = {
            GX_CC_APREV,
            GX_CC_A0,
            GX_CC_A1,
            GX_CC_A2
        };
    }

    ColorAnimMaterialTarget::ColorAnimMaterialTarget()
        : m_0(0)
        , mTevStageID(GX_MAX_TEVSTAGE)
        , mTevRegID(GX_MAX_TEVREG)
        , m_C(4)
    { }

    ColorAnimMaterialTarget::ColorAnimMaterialTarget(GXTevStageID tevStageID, GXTevRegID tevRegID)
        : m_0(1)
        , mTevStageID(tevStageID)
        , mTevRegID(tevRegID)
        , m_C(4)
    { }

    GXTevColorArg ColorAnimMaterialTarget::tevRegId2GXTevColorArg() const {
        return T_TEV_REG_ID_2_TEV_COLOR_ARG[mTevRegID];
    }

    GXTevColorArg ColorAnimMaterialTarget::tevRegId2GXTevColorArgAlpha() const {
        return T_TEV_REG_ID_2_TEV_COLOR_ARG_ALPHA[mTevRegID];
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    GXTevStageID ColorAnimMaterialTarget::tevStageID() const {
        return mTevStageID;
    }

    GXTevRegID ColorAnimMaterialTarget::tevRegID() const {
        return mTevRegID;
    }
}
