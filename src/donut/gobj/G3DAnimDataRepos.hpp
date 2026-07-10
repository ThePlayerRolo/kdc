#ifndef DONUT_GOBJ_G3D_ANIM_DATA_REPOS
#define DONUT_GOBJ_G3D_ANIM_DATA_REPOS

#include "gobj/G3DAnimDataReposDesc.hpp"
#include "mem/IAllocator.hpp"

namespace gobj {
    class G3DAnimDataRepos {
    public:
        G3DAnimDataRepos(const G3DAnimDataReposDesc& rDesc, mem::IAllocator&);
    public:
        /* 0x00 */ G3DAnimDataReposDesc& mDesc;
        STRUCT_FILL(0x18);
    };
};

#endif
