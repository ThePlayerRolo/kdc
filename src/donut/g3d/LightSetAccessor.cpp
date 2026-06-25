#include "g3d/g3d_light.h"
#pragma peephole off
#include "g3d/LightSetAccessor.hpp"

namespace g3d {
    bool LightSetAccessor::isValid() const {
        return IsValid();
    }

    void LightSetAccessor::enableLightObj(u32 lightIdx, u32 lightObjIdx) const {
        const_cast<LightSetAccessor*>(this)->SelectLightObj(lightIdx, lightObjIdx);
    }

    void LightSetAccessor::disableLightObj(u32 lightIdx) const {
        const_cast<LightSetAccessor*>(this)->SelectLightObj(lightIdx, -1);
    }

    void LightSetAccessor::disableLightObjAll() const {
        for (u32 i = 0; i < 8; i++) {
            disableLightObj(i);
        }
    }

    void LightSetAccessor::enableAmbientLightObj(u32 lightObjIdx) const {
        const_cast<LightSetAccessor*>(this)->SelectAmbLightObj(lightObjIdx);
    }

    void LightSetAccessor::disableAmbientLightObj() const {
        const_cast<LightSetAccessor*>(this)->SelectAmbLightObj(-1);
    }

    void LightSetAccessor::setLightObj(u32 lightIdx, const nw4r::g3d::LightObj& rLightObj) const {
        *const_cast<LightSetAccessor*>(this)->GetLightObj(lightIdx) = rLightObj;
    }

    void LightSetAccessor::setAmbientLightObj(const nw4r::g3d::AmbLightObj& rAmbObj) const {
        *const_cast<LightSetAccessor*>(this)->GetAmbLightObj() = rAmbObj;
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    LightSetAccessor::LightSetAccessor() : nw4r::g3d::LightSet() { }

    LightSetAccessor::LightSetAccessor(const nw4r::g3d::LightSet& rLightSet) : nw4r::g3d::LightSet(rLightSet) { }
}
