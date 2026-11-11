#include "g3d/ColorAnimTevManager.hpp"

namespace g3d {
    // https://decomp.me/scratch/GwjNQ
    ColorAnimTevManager::ColorAnimTevManager(const nw4r::g3d::ResTev& rResTev)
    : m_0(0)
    , mCurrentStageNum()
    , mTevRegUsers()
    , mKonstRegUsers()
    {
        m_0 = rResTev.ref().nStages;
        mCurrentStageNum = (GXTevStageID)m_0;

        for (u32 i = 0; i < 4; i++) {
            mTevRegUsers[i].m_0 = 0;
        }
        for (u32 i = 0; i < 4; i++) {
            mKonstRegUsers[i].m_0 = 0;
        }

        for (u32 i = 0; i < m_0; i++) {
            GXTevStageID id = (GXTevStageID)i;

            GXTevColorArg colorArgA, colorArgB, colorArgC, colorArgD;
            GXTevOp colorOp;
            GXTevBias colorBias;
            GXTevScale colorScale;
            u8 colorTmp;
            GXTevRegID colorRegID;

            rResTev.GXGetTevColorIn(id, &colorArgA, &colorArgB, &colorArgC, &colorArgD);
            reserveWithTevColorArg(rResTev, id, colorArgA);
            reserveWithTevColorArg(rResTev, id, colorArgB);
            reserveWithTevColorArg(rResTev, id, colorArgC);
            reserveWithTevColorArg(rResTev, id, colorArgD);
            rResTev.GXGetTevColorOp(id, &colorOp, &colorBias, &colorScale, &colorTmp, &colorRegID);
            reserveWithTevRegID(colorRegID);

            GXTevAlphaArg alphaArgA, alphaArgB, alphaArgC, alphaArgD;
            GXTevOp alphaOp;
            GXTevBias alphaBias;
            GXTevScale alphaScale;
            u8 alphaTmp;
            GXTevRegID alphaRegID;

            rResTev.GXGetTevAlphaIn(id, &alphaArgA, &alphaArgB, &alphaArgC, &alphaArgD);
            reserveWithTevAlphaArg(rResTev, id, alphaArgA);
            reserveWithTevAlphaArg(rResTev, id, alphaArgB);
            reserveWithTevAlphaArg(rResTev, id, alphaArgC);
            reserveWithTevAlphaArg(rResTev, id, alphaArgD);
            rResTev.GXGetTevAlphaOp(id, &alphaOp, &alphaBias, &alphaScale, &alphaTmp, &alphaRegID);
            reserveWithTevRegID(alphaRegID);
        }
    }

    GXTevStageID ColorAnimTevManager::lastStage() const {
        return (GXTevStageID)(mCurrentStageNum - 1);
    }

    void ColorAnimTevManager::incStageNum() {
        u32 newVal = mCurrentStageNum + 1;
        if (newVal >= GX_MAX_TEVSTAGE) return;

        mCurrentStageNum = (GXTevStageID)newVal;
    }

    bool ColorAnimTevManager::isUsedTevReg(GXTevRegID tevRegId) const {
        return mTevRegUsers[tevRegId].m_0 != 0;
    }

    GXTevRegID ColorAnimTevManager::findFreeTevReg() const {
        for (u32 i = 0; i < GX_MAX_TEVREG; i++) {
            GXTevRegID id = (GXTevRegID)i;
            if (!isUsedTevReg(id)) {
                return id;
            }
        }
        return GX_MAX_TEVREG;
    }
    // https://decomp.me/scratch/x8vT5
    void ColorAnimTevManager::reserveWithTevColorArg(const nw4r::g3d::ResTev& rResTev, GXTevStageID tevStageId, GXTevColorArg tevColorArg) {
        switch (tevColorArg) {
            case GX_CC_CPREV:
            case GX_CC_APREV:
                mTevRegUsers[0].m_0 = 1;
                break;
            case GX_CC_C0:
            case GX_CC_A0:
                mTevRegUsers[1].m_0 = 1;
                break;
            case GX_CC_C1:
            case GX_CC_A1:
                mTevRegUsers[2].m_0 = 1;
                break;
            case GX_CC_C2:
            case GX_CC_A2:
                mTevRegUsers[3].m_0 = 1;
                break;
            case GX_CC_KONST:
                GXTevKColorSel colorSel = GX_TEV_KCSEL_1;
                rResTev.GXGetTevKColorSel(tevStageId, &colorSel);
                reserveWithTevKColorSel(colorSel);


        }
    }
    // https://decomp.me/scratch/EJgK8
    void ColorAnimTevManager::reserveWithTevKColorSel(GXTevKColorSel tevKColorSel) {
        switch (tevKColorSel) {
        case GX_TEV_KCSEL_K0:
        case GX_TEV_KCSEL_K0_R:
        case GX_TEV_KCSEL_K0_G:
        case GX_TEV_KCSEL_K0_B:
        case GX_TEV_KCSEL_K0_A:
            mKonstRegUsers[0].m_0 = 1;
            break;
        case GX_TEV_KCSEL_K1:
        case GX_TEV_KCSEL_K1_R:
        case GX_TEV_KCSEL_K1_G:
        case GX_TEV_KCSEL_K1_B:
        case GX_TEV_KCSEL_K1_A:
            mKonstRegUsers[1].m_0 = 1;
            break;
        case GX_TEV_KCSEL_K2:
        case GX_TEV_KCSEL_K2_R:
        case GX_TEV_KCSEL_K2_G:
        case GX_TEV_KCSEL_K2_B:
        case GX_TEV_KCSEL_K2_A:
            mKonstRegUsers[2].m_0 = 1;
            break;
        case GX_TEV_KCSEL_K3:
        case GX_TEV_KCSEL_K3_R:
        case GX_TEV_KCSEL_K3_G:
        case GX_TEV_KCSEL_K3_B:
        case GX_TEV_KCSEL_K3_A:
            mKonstRegUsers[3].m_0 = 1;
            break;
        }
    }

    // https://decomp.me/scratch/erxCK
    void ColorAnimTevManager::reserveWithTevAlphaArg(const nw4r::g3d::ResTev& rResTev, GXTevStageID tevStageId, GXTevAlphaArg tevAlphaArg) {
        switch (tevAlphaArg) {
            case GX_CA_APREV:
                mTevRegUsers[0].m_0 = 1;
                break;
            case GX_CA_A0:
                mTevRegUsers[1].m_0 = 1;
                break;
            case GX_CA_A1:
                mTevRegUsers[2].m_0 = 1;
                break;
            case GX_CA_A2:
                mTevRegUsers[3].m_0 = 1;
                break;
            case GX_CA_KONST:
                GXTevKAlphaSel alphaSel = GX_TEV_KASEL_1;
                rResTev.GXGetTevKAlphaSel(tevStageId, &alphaSel);
                reserveWithTevKAlphaSel(alphaSel);


        }
    }
    // https://decomp.me/scratch/LMOSB
    void ColorAnimTevManager::reserveWithTevKAlphaSel(GXTevKAlphaSel tevKAlphaSel) {
        switch (tevKAlphaSel) {
        case GX_TEV_KASEL_K0_R:
        case GX_TEV_KASEL_K0_G:
        case GX_TEV_KASEL_K0_B:
        case GX_TEV_KASEL_K0_A:
            mKonstRegUsers[0].m_0 = 1;
            break;
        case GX_TEV_KASEL_K1_R:
        case GX_TEV_KASEL_K1_G:
        case GX_TEV_KASEL_K1_B:
        case GX_TEV_KASEL_K1_A:
            mKonstRegUsers[1].m_0 = 1;
            break;
        case GX_TEV_KASEL_K2_R:
        case GX_TEV_KASEL_K2_G:
        case GX_TEV_KASEL_K2_B:
        case GX_TEV_KASEL_K2_A:
            mKonstRegUsers[2].m_0 = 1;
            break;
        case GX_TEV_KASEL_K3_R:
        case GX_TEV_KASEL_K3_G:
        case GX_TEV_KASEL_K3_B:
        case GX_TEV_KASEL_K3_A:
            mKonstRegUsers[3].m_0 = 1;
            break;
        }
    }

    void ColorAnimTevManager::reserveWithTevRegID(GXTevRegID tevRegId) {
        mTevRegUsers[tevRegId].m_0 = 1;
    }
}
