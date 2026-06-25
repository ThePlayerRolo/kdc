#ifndef DONUT_G3D_FOG_ACCESSOR_HPP
#define DONUT_G3D_FOG_ACCESSOR_HPP

#include <nw4r/g3d/g3d_fog.h>

namespace g3d {
    class FogAccessor : public nw4r::g3d::Fog {
    public:
        FogAccessor(const nw4r::g3d::Fog& rFog);

        void setFogType(GXFogType fogType);
        void setZ(f32 startZ, f32 endZ);
        void setFogColor(GXColor fogColor);
        void setFogRangeAdj(bool enable);
    public:
        /* 0x4 */ bool _4;
    };

}

#endif
