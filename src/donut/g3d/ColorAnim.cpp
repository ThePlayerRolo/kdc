#include "g3d/ColorAnim.hpp"
#include "g3d/ColorAnimFlash.hpp"

namespace g3d {
    // https://decomp.me/scratch/4T8PI
    ColorAnim::ColorAnim(const g3d::ColorAnimContext& rContext)
        : mMatAccessor(rContext.mMatAccessor)
        , mTevMgr(mMatAccessor.obj()->GetResTevEx())
        , mMatTarget()
    {
        if (rContext.mUseFlash) {
            mMatTarget = ColorAnimFlash::CreateMaterialTarget(mTevMgr);
        }
    }
    void ColorAnim::updateBegin() {
        u8 tevStageID = mTevMgr.currentStageNum();
        mMatAccessor.obj()->GetResTev(false).SetNumTevStages(tevStageID);
        mMatAccessor.obj()->GetResGenMode(false).GXSetNumTevStages(tevStageID);
    }

     void ColorAnim::updateEnd() {
        mMatAccessor.obj()->GetResTev(false).DCStore(false);
        mMatAccessor.obj()->GetResGenMode(false); // something was stripped here in both this and RTDL
        mMatAccessor.obj()->GetResMatTevColor(false).DCStore(false);
    }

     void ColorAnim::updateFlash(const ColorAnimFlash& rFlash) {
        rFlash.reflectToMaterial(mMatAccessor, mMatTarget);
     }
}
