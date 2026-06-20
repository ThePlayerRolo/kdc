#ifndef DONUT_GOBJ_G3D_ANIM_DATA_REPOS_DESC
#define DONUT_GOBJ_G3D_ANIM_DATA_REPOS_DESC

#include <types.h>

namespace gobj {
    namespace G3DAnimDataReposDesc {
        struct Entry {
            /* 0x0 */ const char* mName;
            /* 0x4 */ s32 _4;
        };
    };

};

#define ANIM_ENTRIES_START(size) const gobj::G3DAnimDataReposDesc::Entry T_ANIM_ENTRIES[size] = {
#define ANIM_ENTRY(name, _4) { name, _4 },
#define ANIM_ENTRIES_END };

#endif
