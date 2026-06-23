#ifndef DONUT_G3D_RES_FILE_ACCESSOR_HPP
#define DONUT_G3D_RES_FILE_ACCESSOR_HPP

#include <nw4r/g3d/res/g3d_resfile.h>
#include <types.h>
#include "g3d/ResAnmAutoReq.hpp"

namespace g3d {
    class ResFileAccessor {
    public:
        //NOTE: Merged into nw4r::g3d::LightObj::LightObj()
        ResFileAccessor();

        //NOTE: Merged into nw4r::ut::Color::Color(const nw4r::ut::Color&)
        ResFileAccessor(const nw4r::g3d::ResFile&);

        //NOTE: Merged into nrel::mem::ExpHeapBlockIterator::hasNext() const
        bool isValid() const;

        //NOTE: Merged into nw4r::ut::Color::Color(const nw4r::ut::Color&)
        void operator=(const ResFileAccessor& rOther) DONT_INLINE {
            mFile = rOther.mFile;
        }

        bool bind(const ResFileAccessor&, bool) const;
        //TODO: These returns act like pointers in  isExistAnyAnim and  ModelAnim::createWithEntryName but are required to be not for  a closer match
        //ALSO according to the .map file the constructor assert strings are generated for these types  (but unused) which means they need to not return Pointers??????
        nw4r::g3d::ResMdl* model(const char* pName) const;
        nw4r::g3d::ResAnmChr* animChara(const char *pName) const;
        nw4r::g3d::ResAnmClr* animColor(const char *pName) const;
        nw4r::g3d::ResAnmShp* animShape(const char *pName) const;
        nw4r::g3d::ResAnmScn* animScene(const char *pName) const;
        nw4r::g3d::ResAnmTexPat* animTexPattern(const char *pName) const;
        nw4r::g3d::ResAnmTexSrt* animTexSRT(const char *pName) const;
        nw4r::g3d::ResAnmVis* animVisible(const char *pName) const;

        ResAnmAutoReq animAutoReq(const char* pName) const;
        u32 modelCount() const;
        nw4r::g3d::ResMdl modelAtIndex(u32 idx) const;
        bool isExistAnyAnim(const char* pName) const;

    private:
        /* 0x00 */ const nw4r::g3d::ResFile* mFile;
    };
}

#endif
