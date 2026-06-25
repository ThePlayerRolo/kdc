#pragma peephole off
#include "g3d/ResModelContext.hpp"

namespace g3d {
    const char* ResModelContext::DefaultEntryName() {
        return "Model";
    }

    ResModelContext::ResModelContext(const ResFileAccessor& rResFile, const char* pModelName)
    : mResFile(rResFile)
    , mModelName(hel::common::FixedStringIN<char, 40>::FromFormat("%s", pModelName))
    { }
}
