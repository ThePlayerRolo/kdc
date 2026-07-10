#ifndef DONUT_G3D_MATERIAL_ACCESSOR_HPP
#define DONUT_G3D_MATERIAL_ACCESSOR_HPP

#include <nw4r/g3d/g3d_scnmdl.h>

namespace g3d {
    class MaterialAccessor : public nw4r::g3d::ScnMdl::CopiedMatAccess {
    public:
        MaterialAccessor();
        MaterialAccessor(nw4r::g3d::ScnMdl& rMdl, u32 id);

        void matTevColorGXSetTevColor(GXTevRegID id, const GXColor& color) const;
        void matTevColorEndEdit() const;
        void matPixGXSetDstAlpha(bool enable, u8 alpha) const;
        void matPixEndEdit() const;
        void matMiscSetLightSetIdx(u32 idx) const;
        void matMiscEndEdit() const;
    public:
        /* 0x4 */ bool _4;
    };

}

#endif
