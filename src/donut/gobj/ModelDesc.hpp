#ifndef DONUT_GOBJ_MODEL_DESC_HPP
#define DONUT_GOBJ_MODEL_DESC_HPP

#include <types.h>

namespace gobj {

class ModelDesc {
public:
    ModelDesc();

public:
    STRUCT_FILL(0x40);
    /* 0x40 */ s32 _40;
    STRUCT_FILL(0x14);
};
}

#endif
