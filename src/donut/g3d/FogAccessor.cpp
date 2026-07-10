#pragma peephole off
#include "g3d/FogAccessor.hpp"

namespace g3d {
    FogAccessor::FogAccessor(const nw4r::g3d::Fog& rFog) : nw4r::g3d::Fog(rFog), _4(true) { }

    void FogAccessor::setFogType(GXFogType fogType) {
        SetFogType(fogType);
    }

    void FogAccessor::setZ(f32 startZ, f32 endZ) {
        SetZ(startZ, endZ);
    }

    void FogAccessor::setFogColor(GXColor fogColor) {
        SetFogColor(fogColor);
    }

    void FogAccessor::setFogRangeAdj(bool enable) {
        SetFogRangeAdj(enable);
    }
};
