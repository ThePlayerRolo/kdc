#pragma peephole off
#include <hel/math/Vector3.hpp>
#include <hel/math/Matrix44.hpp>

using hel::math::Matrix44;
using hel::math::Vector3;

Matrix44 Matrix44::CreatePerspective(f32 FOV, f32 aspectRatio, f32 nearClip, f32 farClip) {
    nw4r::math::MTX44 mtx;
    C_MTXPerspective(mtx, FOV, aspectRatio, nearClip, farClip);
    return Matrix44(mtx);
}

Matrix44 Matrix44::CreateOrtho(f32 top, f32 bottom, f32 left, f32 right, f32 nearClip, f32 farClip) {
    nw4r::math::MTX44 mtx;
    C_MTXOrtho(mtx, top, bottom, left, right, nearClip, farClip);
    return Matrix44(mtx);
}

Matrix44::Matrix44() {
    nw4r::math::MTX44Identity(&mBaseMtx);
}

Matrix44::Matrix44(const nw4r::math::MTX44& rMtx) {
    nw4r::math::MTX44Copy(&mBaseMtx, &rMtx);
}

//https://decomp.me/scratch/qlQ2y
 nw4r::math::MTX44 Matrix44::mulMtx(const Matrix44& rOther) const {
    nw4r::math::MTX44 newVec;
    nw4r::math::MTX44Identity(&newVec);
    PSMTX44Concat(mBaseMtx, rOther.mBaseMtx, newVec);
    return newVec;
}

//https://decomp.me/scratch/eZhPd
Vector3 Matrix44::mulVec(const Vector3& rVector) const {
    Vector3 newVec;
    PSMTX44MultVec(mBaseMtx, (Vec*)&rVector, (Vec*)&newVec);
    return newVec;
}
