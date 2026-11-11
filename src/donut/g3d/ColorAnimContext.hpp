#ifndef DONUT_G3D_COLOR_ANIM_CONTEXT_HPP
#define DONUT_G3D_COLOR_ANIM_CONTEXT_HPP

#include "g3d/MaterialAccessor.hpp"

namespace g3d {
    class ColorAnimContext {
    public:
        ColorAnimContext(const MaterialAccessor& rMatAccessor, bool useFlash);

        // NOTE: Is merged into nw4r::ut::DvdFileStream::CanCancel() const
        static bool DefaultUseFlash();
    public:
        /* 0x00 */ MaterialAccessor mMatAccessor;
        /* 0x38 */ bool mUseFlash;
    };

}

#endif
