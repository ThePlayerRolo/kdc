#ifndef DONUT_GOBJ_SCRIPT_DESC
#define DONUT_GOBJ_SCRIPT_DESC

#include <types.h>

namespace gobj {
    class ScriptDesc {
    public:
        struct Entry {
            public:
            /* 0x00 */ const char* mLoopFn;
            /* 0x04 */ s32 _4;
            /* 0x08 */ s32 _8;
            /* 0x0C */ s32 _C;
            /* 0x10 */ s32 _10;
        };
    public:
        STRUCT_FILL(0xC);
    };

};

#define SCRIPT_ENTRIES_START(size) const gobj::ScriptDesc::Entry T_SCRIPT_ENTRIES[size] = {
#define SCRIPT_ENTRY(loopType, _4, _8, _C, _10) { loopType, _4, _8, _C, _10 },
#define SCRIPT_ENTRIES_END };

#endif
