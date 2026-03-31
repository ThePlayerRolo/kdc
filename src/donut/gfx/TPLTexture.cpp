#pragma peephole off
#include <donut/gfx/TPLTexture.hpp>
#include <revolution/TPL.h>

using gfx::TextureObj;
using gfx::TPLTexture;
TextureObj::TextureObj() {

}

GXTexObj* TextureObj::texObj() const {
    GXTexObj* texObj;
    for (int i = 4; i != 0; i--) {

        texObj->dummy[2] = mGXTexObj.dummy[2];
    }
    return texObj;
}

TPLTexture::TPLTexture(void* pArg1)
    : mFileAccessor()
{
    init(pArg1);
}

void TPLTexture::init(void* pArg1) {
    if ((int)(pArg1) + 0x8 < 0x80000000) {
        TPLBind((TPLPalette *)pArg1);
    }
    TPLGetGXTexObjFromPalette((TPLPalette *)pArg1, &mGXTexObj, 0);
}
