#ifndef DONUT_GOBJ_MODEL_DESC_HPP
#define DONUT_GOBJ_MODEL_DESC_HPP

#include <types.h>

namespace gobj {

class ModelDesc {
public:
    ModelDesc();

public:
    /* 0x00 */ char _0[24];
    /* 0x18 */ char _18[40];
    /* 0x40 */ s32 _40;
    /* 0x48 */ s32 _48;
    /* 0x4C */ u8 _4C;
    /* 0x4D */ u8 _4D;
    /* 0x50 */ s32 _50;
    /* 0x54 */ s32 _54;
    /* 0x58 */ s32 _58;
};
}

#endif
