#pragma peephole off
#include "g3d/ResFileAccessor.hpp"
#include <hel/common/FixedString.hpp>

namespace g3d {

    bool ResFileAccessor::bind(const ResFileAccessor& rAccessor, bool param_2) const {
        if (this->ptr() == nullptr) return false;

        if (rAccessor.ptr() != nullptr) {
            return const_cast<ResFileAccessor*>(this)->Bind(rAccessor);
        } else {
            return const_cast<ResFileAccessor*>(this)->Bind();
        }
    }

    // https://decomp.me/scratch/5h9mM
    nw4r::g3d::ResMdl ResFileAccessor::model(const char* pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResMdl(nullptr);

        return GetResMdl(pName);
    }

    nw4r::g3d::ResAnmChr ResFileAccessor::animChara(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmChr(nullptr);

        return GetResAnmChr(pName);
    }

    nw4r::g3d::ResAnmClr ResFileAccessor::animColor(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmClr(nullptr);

        return GetResAnmClr(pName);
    }

    nw4r::g3d::ResAnmShp ResFileAccessor::animShape(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmShp(nullptr);

        return GetResAnmShp(pName);
    }

    nw4r::g3d::ResAnmScn ResFileAccessor::animScene(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmScn(nullptr);

        return GetResAnmScn(pName);
    }

    nw4r::g3d::ResAnmTexPat ResFileAccessor::animTexPattern(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmTexPat(nullptr);

        return GetResAnmTexPat(pName);
    }

    nw4r::g3d::ResAnmTexSrt ResFileAccessor::animTexSRT(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmTexSrt(nullptr);

        return GetResAnmTexSrt(pName);
    }

    nw4r::g3d::ResAnmVis ResFileAccessor::animVisible(const char *pName) const {
        if (this->ptr() == nullptr) return nw4r::g3d::ResAnmVis(nullptr);

        return GetResAnmVis(pName);
    }

    ResAnmAutoReq ResFileAccessor::animAutoReq(const char* pName) const {
        if (this->ptr() == nullptr) return ResAnmAutoReq();

        hel::common::FixedString<40> fileName(hel::common::FixedString<40>::FromFormat("%s.autoreq", pName));
        return ResAnmAutoReq(GetExternalData(fileName.str()));
    }

    u32 ResFileAccessor::modelCount() const {
        return GetResMdlNumEntries();
    }

    nw4r::g3d::ResMdl ResFileAccessor::modelAtIndex(u32 idx) const {
        return GetResMdl(idx);
    }

    bool ResFileAccessor::isExistAnyAnim(const char* pName) const {
        return animChara(pName).ptr() != nullptr || animColor(pName).ptr() != nullptr || animScene(pName).ptr() != nullptr
            || animShape(pName).ptr() != nullptr || animTexPattern(pName).ptr() != nullptr || animTexSRT(pName).ptr() != nullptr
            || animVisible(pName).ptr() != nullptr || animAutoReq(pName).isValid();
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    // TODO: Consturctor problems
    ResFileAccessor::ResFileAccessor() : nw4r::g3d::ResFile(nullptr) { }

    ResFileAccessor::ResFileAccessor(const nw4r::g3d::ResFile& rOther) : nw4r::g3d::ResFile(rOther) { }

    bool ResFileAccessor::isValid() const {
        return IsValid();
    }
}
