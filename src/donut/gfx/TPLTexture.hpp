#ifndef DONUT_GFX_TPL_TEXTURE_HPP
#define DONUT_GFX_TPL_TEXTURE_HPP

#include <donut/gfx/TextureObj.hpp>
#include <donut/util/PlacementNew.hpp>
#include <donut/file/FileAccessor.hpp>

namespace gfx {
    class TPLTexture : TextureObj {
    public:
        TPLTexture(void*);
        /* 0x0 */ virtual ~TPLTexture();
        void init(void*);


        /* 0x24 */ util::PlacementNew<file::FileAccessor> mFileAccessor;
    };
}

#endif
