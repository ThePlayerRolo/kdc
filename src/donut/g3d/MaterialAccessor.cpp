#pragma peephole off
#include "g3d/MaterialAccessor.hpp"

namespace g3d {
    MaterialAccessor::MaterialAccessor()
    : nw4r::g3d::ScnMdl::CopiedMatAccess(nullptr, nullptr)
    , _4(false)
    { }

    void MaterialAccessor::matTevColorGXSetTevColor(GXTevRegID id, const GXColor& color) const {
        const_cast<MaterialAccessor*>(this)->GetResMatTevColor(false).GXSetTevColor(id, color);
    }

    void MaterialAccessor::matTevColorEndEdit() const {
        const_cast<MaterialAccessor*>(this)->GetResMatTevColor(false).EndEdit();
    }

    void MaterialAccessor::matPixGXSetDstAlpha(bool enable, u8 alpha) const {
        const_cast<MaterialAccessor*>(this)->GetResMatPix(false).GXSetDstAlpha(enable, alpha);
    }

    void MaterialAccessor::matPixEndEdit() const {
        const_cast<MaterialAccessor*>(this)->GetResMatPix(false).EndEdit();
    }

    void MaterialAccessor::matMiscSetLightSetIdx(u32 idx) const {
        const_cast<MaterialAccessor*>(this)->GetResMatMisc(false).SetLightSetIdx(idx);
    }

    void MaterialAccessor::matMiscEndEdit() const {
        const_cast<MaterialAccessor*>(this)->GetResMatMisc(false).EndEdit();
    }
}
