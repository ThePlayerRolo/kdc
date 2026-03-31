#ifndef DONUT_GFX_TEXTURE_OBJECT_HPP
#define DONUT_GFX_TEXTURE_OBJECT_HPP

#include <types.h>
#include <revolution/GX.h>

namespace gfx {
    class TextureObj {
    public:
        TextureObj();
        /* 0x0 */ virtual ~TextureObj();

        GXTexObj* texObj() const;

        /* 0x4 */ GXTexObj mGXTexObj;
    };
}

#endif
