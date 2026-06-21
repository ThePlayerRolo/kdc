#ifndef DONUT_SCN_STEP_CHARA_MODEL_DESC_HPP
#define DONUT_SCN_STEP_CHARA_MODEL_DESC_HPP

#include <types.h>
#include "gobj/ModelDesc.hpp"

namespace scn { namespace step { namespace chara {

    class ModelDesc {
    public:
        ModelDesc();

    public:
        /* 0x00 */ s32 _0;
        /* 0x04 */ s32 _4;
        /* 0x08 */ s32 _8;
        /* 0x0C */ f32 _C; // Todo: could be Vec3
        /* 0x10 */ f32 _10;
        /* 0x14 */ f32 _14;
        /* 0x18 */ gobj::ModelDesc _18;
        /* 0x70 */ s32 _70;
        /* 0x74 */ s32 _74;
        /* 0x78 */ s32 _78;
        /* 0x7C */ s32 _7C;
    };

}}};

#endif
