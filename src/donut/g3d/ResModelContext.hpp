#ifndef DONUT_G3D_RES_MODEL_CONTEXT_HPP
#define DONUT_G3D_RES_MODEL_CONTEXT_HPP

#include "g3d/ResFileAccessor.hpp"
#include <hel/common/FixedStringIN.hpp>

namespace g3d {
    class ResFileAccessor;

    class ResModelContext {
    public:
        ResModelContext(const ResFileAccessor& rResFile, const char* pModelName);
        static const char* DefaultEntryName();

    public:
        /* 0x00 */ ResFileAccessor mResFile;
        /* 0x04 */ hel::common::FixedStringIN<char, 40> mModelName;
    };
}

#endif
