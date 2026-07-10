#ifndef DONUT_G3D_LIGHT_SET_ACCESSOR_HPP
#define DONUT_G3D_LIGHT_SET_ACCESSOR_HPP

#include <nw4r/g3d/g3d_light.h>

namespace g3d {
    class LightSetAccessor : public nw4r::g3d::LightSet {
    public:
        //NOTE Is Merged into OSCreateAlarm
        LightSetAccessor();
        // NOTE: Is Merged into nw4r::ut::Link::operator=(const nw4r::ut::Link&)
        LightSetAccessor(const nw4r::g3d::LightSet& rLightSet);

        bool isValid() const;
        void enableLightObj(u32 lightIdx, u32 lightObjIdx) const;
        void disableLightObj(u32 lightIdx) const;
        void disableLightObjAll() const;

        void enableAmbientLightObj(u32 lightObjIdx) const;
        void disableAmbientLightObj() const;

        void setLightObj(u32 lightIdx, const nw4r::g3d::LightObj& rLightObj) const;
        void setAmbientLightObj(const nw4r::g3d::AmbLightObj& rAmbObj) const;
    };

}

#endif
