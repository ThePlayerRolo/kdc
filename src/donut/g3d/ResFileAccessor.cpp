#include "hel/common/FixedStringIN.hpp"
#pragma peephole off

#include "g3d/ResFileAccessor.hpp"

namespace g3d {

    bool ResFileAccessor::bind(const ResFileAccessor& rAccessor, bool param_2) const {
        if (mFile == nullptr) return false;

        if (rAccessor.mFile != nullptr) {
            return const_cast<nw4r::g3d::ResFile*>(mFile)->Bind(*rAccessor.mFile);
        } else {
            return const_cast<nw4r::g3d::ResFile*>(mFile)->Bind();
        }
    }

    nw4r::g3d::ResMdl* ResFileAccessor::model(const char* pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResMdl(pName);
    }

    nw4r::g3d::ResAnmChr* ResFileAccessor::animChara(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmChr(pName);
    }

    nw4r::g3d::ResAnmClr* ResFileAccessor::animColor(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmClr(pName);
    }

    nw4r::g3d::ResAnmShp* ResFileAccessor::animShape(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmShp(pName);
    }

    nw4r::g3d::ResAnmScn* ResFileAccessor::animScene(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmScn(pName);
    }

    nw4r::g3d::ResAnmTexPat* ResFileAccessor::animTexPattern(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmTexPat(pName);
    }

    nw4r::g3d::ResAnmTexSrt* ResFileAccessor::animTexSRT(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmTexSrt(pName);
    }

    nw4r::g3d::ResAnmVis* ResFileAccessor::animVisible(const char *pName) const {
        if (mFile == nullptr) return nullptr;

        return &mFile->GetResAnmVis(pName);
    }

    ResAnmAutoReq ResFileAccessor::animAutoReq(const char* pName) const {
        if (mFile == nullptr) return ResAnmAutoReq();

        hel::common::FixedStringIN<char, 40> fileName;
        fileName =  hel::common::FixedStringIN<char, 40>::FromFormat("%s.autoreq", pName);

        return ResAnmAutoReq(mFile->GetExternalData(fileName.str()));
    }

    u32 ResFileAccessor::modelCount() const {
        return mFile->GetResMdlNumEntries();
    }

    nw4r::g3d::ResMdl ResFileAccessor::modelAtIndex(u32 idx) const {
        return mFile->GetResMdl(idx);
    }

    bool ResFileAccessor::isExistAnyAnim(const char* pName) const {
        bool animExist = true;
        bool animVisibleExist = true;
        bool animTexSRTExist = true;
        bool animTexPatternExist = true;
        bool animShapeExist = true;
        bool animSceneExist = true;
        bool animColorExist = true;

        if (animChara(pName) == nullptr && animColor(pName) == nullptr) {
            animColorExist = false;
        }
        if (!animColorExist && animScene(pName) == nullptr) {
            animSceneExist = false;
        }
        if (!animSceneExist && animShape(pName) == nullptr) {
            animShapeExist = false;
        }
        if (!animShapeExist && animTexPattern(pName) == nullptr) {
            animTexPatternExist = false;
        }
        if (!animTexPatternExist && animTexSRT(pName) == nullptr) {
            animTexSRTExist = false;
        }
        if (!animTexSRTExist && animVisible(pName) == nullptr) {
            animVisibleExist = false;
        }

        if (!animVisibleExist) {
            ResAnmAutoReq autoReq = animAutoReq(pName);
            if (!autoReq.isValid())
                animExist = false;
        }
        return animExist;
    }
}
