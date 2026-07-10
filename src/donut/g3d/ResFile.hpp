#ifndef DONUT_G3D_RES_FILE_HPP
#define DONUT_G3D_RES_FILE_HPP

#include "file/FileAccessor.hpp"
#include "g3d/ResFileAccessor.hpp"

namespace g3d {
    class ResFile {
    public:
        ResFile(const char* pFileName, bool);
        ~ResFile();

        //NOTE: Is merged into GetZeroBufferAddress__Q44nw4r3snd6detail9AxManagerFv
        ResFileAccessor& accessor() const;
    public:
        /* 0x00 */ file::FileAccessor mFileAccessor;
        /* 0x04 */ ResFileAccessor mResAccessor;
    };
}

#endif
