#include "g3d/ColorAnimContext.hpp"


namespace g3d {

    // https://decomp.me/scratch/u4Luv
    ColorAnimContext::ColorAnimContext(const MaterialAccessor& rMatAccessor, bool useFlash)
    : mMatAccessor(rMatAccessor)
    , mUseFlash(useFlash)
    { }

    //NOTE: All functions below are code merged into others. Refer to the header for more details
    bool ColorAnimContext::DefaultUseFlash() {
        return true;
    }
}
