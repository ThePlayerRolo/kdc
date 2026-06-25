#pragma peephole off
#include "g3d/ResFileAccessor.hpp"
#include <hel/common/FixedStringIN.hpp>

namespace g3d {

    bool ResFileAccessor::bind(const ResFileAccessor& rAccessor, bool param_2) const {
        if (this->ptr() == nullptr) return false;

        if (rAccessor.ptr() != nullptr) {
            return const_cast<ResFileAccessor*>(this)->Bind(rAccessor);
        } else {
            return const_cast<ResFileAccessor*>(this)->Bind();
        }
    }

    nw4r::g3d::ResMdl* ResFileAccessor::model(const char* pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResMdl(pName);
    }

    nw4r::g3d::ResAnmChr* ResFileAccessor::animChara(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmChr(pName);
    }

    nw4r::g3d::ResAnmClr* ResFileAccessor::animColor(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmClr(pName);
    }

    nw4r::g3d::ResAnmShp* ResFileAccessor::animShape(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmShp(pName);
    }

    nw4r::g3d::ResAnmScn* ResFileAccessor::animScene(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmScn(pName);
    }

    nw4r::g3d::ResAnmTexPat* ResFileAccessor::animTexPattern(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmTexPat(pName);
    }

    nw4r::g3d::ResAnmTexSrt* ResFileAccessor::animTexSRT(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmTexSrt(pName);
    }

    nw4r::g3d::ResAnmVis* ResFileAccessor::animVisible(const char *pName) const {
        if (this->ptr() == nullptr) return nullptr;

        return &GetResAnmVis(pName);
    }

    ResAnmAutoReq ResFileAccessor::animAutoReq(const char* pName) const {
        if (this->ptr() == nullptr) return ResAnmAutoReq();

        hel::common::FixedStringIN<char, 40> fileName;
        fileName =  hel::common::FixedStringIN<char, 40>::FromFormat("%s.autoreq", pName);

        return ResAnmAutoReq(GetExternalData(fileName.str()));
    }

    u32 ResFileAccessor::modelCount() const {
        return GetResMdlNumEntries();
    }

    nw4r::g3d::ResMdl ResFileAccessor::modelAtIndex(u32 idx) const {
        return GetResMdl(idx);
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
