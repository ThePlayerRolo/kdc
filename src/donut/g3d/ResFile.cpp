#include "g3d/ResFileAccessor.hpp"
#pragma peephole off

#include "g3d/ResFile.hpp"
#include <hel/common/FixedStringIN.hpp>

namespace g3d {
    ResFile::ResFile(const char* pFileName, bool param_2)
        : mFileAccessor(hel::common::FixedStringIN<char, 80>::FromFormat("g3d/%s.brres.cmp", pFileName).str(), true)
        , mResAccessor()
    {
        if (mFileAccessor.isLoaded()) {
            nw4r::g3d::ResFile file(mFileAccessor.block().startAddress());
            file.CheckRevision();
            file.Init();

            mResAccessor = ResFileAccessor(file);

            if (!mResAccessor.bind(ResFileAccessor(), param_2) && !param_2) {
                mResAccessor = ResFileAccessor();
                return;
            }
        }
    }

    ResFile::~ResFile() {
        if (mResAccessor.isValid()) {
            nw4r::g3d::ResFile file(mFileAccessor.block().startAddress());
            file.Release();
            file.Terminate();
        }
    }

    //TODO: This uses addi instead of lwz
    ResFileAccessor& ResFile::accessor() const {
        return (ResFileAccessor&)mResAccessor;
    }
}
