#pragma peephole off
#include "g3d/ResModel.hpp"

namespace g3d {

    ResModel::ResModel(const ResModelContext& rCtx)
    : mFile(rCtx.mResFile)
    , mObj(nullptr)
    {
        mObj = mFile.model(rCtx.mModelName.str());
    }

    s32 ResModel::nodeCount() const {
        return mObj.GetResNodeNumEntries();
    }

    ResNode ResModel::nodeByIndex(u32 idx) const {
        return ResNode(mObj.GetResNode(idx));
    }

    ResNode ResModel::nodeByName(const char* pName) const {
        return ResNode(mObj.GetResNode(pName));
    }
}
