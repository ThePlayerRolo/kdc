#pragma peephole off
#include "gobj/MoveParamAccel.hpp"
#include <hel/math/Vector3.hpp>

using gobj::MoveParamAccel;

void MoveParamAccel::Zero() {
    Create(0.0f, 0.0f, 0.0f);
}

//https://decomp.me/scratch/kNizQ
void MoveParamAccel::Create(f32 param_1, f32 param_2, f32 param_3) {
    hel::math::Vector3 vector(param_1, param_2, param_3);

    _0 = vector.x;
    _4 = vector.y;
    _8 = vector.z;
}
