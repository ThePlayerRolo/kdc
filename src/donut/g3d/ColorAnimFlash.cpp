#include "g3d/ColorAnimFlash.hpp"
#include "g3d/ColorAnimMaterialTarget.hpp"
#include "g3d/ColorAnimTevManager.hpp"
#include "g3d/MaterialAccessor.hpp"


namespace g3d {
    ColorAnimMaterialTarget ColorAnimFlash::CreateMaterialTarget(ColorAnimTevManager& rManager) {
        GXTevRegID tevRegID = rManager.findFreeTevReg();
        rManager.incStageNum();
        GXTevStageID tevStageId = rManager.lastStage();
        return ColorAnimMaterialTarget(tevStageId, tevRegID);
    }

    ColorAnimFlash::ColorAnimFlash() {
        mColor.r = 255;
        mColor.g = 255;
        mColor.b = 255;
        mColor.a = 255;
        mOperation = COLOR_ANIM_FLASH_OP_0;
    }

    // TODO: Could relate to hel::common::Color
    void ColorAnimFlash::setColor(const GXColor& rColor) {
        u8 g = rColor.g;
        u8 b = rColor.b;
        u8 a = rColor.a;
        mColor.r = rColor.r;
        mColor.g = g;
        mColor.b = b;
        mColor.a = a;
    }

    // https://decomp.me/scratch/apZ9O
    void ColorAnimFlash::reflectToMaterial(const MaterialAccessor& rMatAccessor, const ColorAnimMaterialTarget& rTarget) const {
        nw4r::g3d::ResTev resTev = rMatAccessor.obj()->GetResTev(false);
        nw4r::g3d::ResMatTevColor resTevColor = rMatAccessor.obj()->GetResMatTevColor(false);
        resTevColor.GXSetTevColor(rTarget.tevRegID(), mColor);

        GXTevStageID tevStageId = rTarget.tevStageID();
        GXTevColorArg tevRegIdColorArg = rTarget.tevRegId2GXTevColorArg();
        GXTevColorArg tevRegIdAlphaArg = rTarget.tevRegId2GXTevColorArgAlpha();
        switch (mOperation) {
            case COLOR_ANIM_FLASH_OP_0:
                resTev.GXSetTevColorOp(tevStageId, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);
                resTev.GXSetTevColorIn(tevStageId, GX_CC_CPREV, tevRegIdColorArg, tevRegIdAlphaArg, GX_CC_ZERO);
                break;
            case COLOR_ANIM_FLASH_OP_1:
                resTev.GXSetTevColorOp(tevStageId, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);
                resTev.GXSetTevColorIn(tevStageId, GX_CC_ZERO, tevRegIdColorArg, tevRegIdAlphaArg, GX_CC_CPREV);
                break;
            case COLOR_ANIM_FLASH_OP_2:
                resTev.GXSetTevColorOp(tevStageId, GX_TEV_SUB, GX_TB_ZERO, GX_CS_SCALE_1, 1, GX_TEVPREV);
                resTev.GXSetTevColorIn(tevStageId, GX_CC_ZERO, tevRegIdColorArg, tevRegIdAlphaArg, GX_CC_CPREV);
                break;
        }
        resTev.GXSetTevOrder(tevStageId, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR_NULL);
        resTev.GXSetTevDirect(tevStageId);
        resTev.GXSetTevAlphaOp(tevStageId, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, 0, GX_TEVPREV);
        resTev.GXSetTevAlphaIn(tevStageId, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_APREV);
        resTev.GXSetTevKColorSel(tevStageId, GX_TEV_KCSEL_1);
        resTev.GXSetTevKAlphaSel(tevStageId, GX_TEV_KASEL_1);
        resTev.GXSetTevSwapMode(tevStageId, GX_TEV_SWAP0, GX_TEV_SWAP0);
    }
}
