#ifndef DONUT_GOBJ_MOVE_PARAM_ACCEL_HPP
#define DONUT_GOBJ_MOVE_PARAM_ACCEL_HPP

#include <types.h>

namespace gobj {

    struct MoveParamAccel {
         void Create(f32 param_1, f32 param_2, f32 param_3);
         void Zero();
    public:
        /* 0x0 */ f32 _0;
        /* 0x4 */ f32 _4;
        /* 0x8 */ f32 _8;
    };
}

#endif
