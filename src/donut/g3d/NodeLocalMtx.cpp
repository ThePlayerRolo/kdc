#pragma peephole off

#include "g3d/NodeLocalMtx.hpp"

using g3d::NodeLocalMtx;

NodeLocalMtx::NodeLocalMtx()
    : mScale(0.0f)
    , mEnabled(false)
    , mCalcOp(g3d::MTX_CALC_OP_NONE)
{
    reset();
}

void NodeLocalMtx::reset() {
    mEnabled = false;
    hel::math::Matrix34 identityMtx;
    mRTMtx = identityMtx;
    mScale = hel::math::Vector3::ALL_ONE;
    mCalcOp = g3d::MTX_CALC_OP_NONE;
}

bool NodeLocalMtx::isEnable() const {
    return mEnabled;
}

void NodeLocalMtx::setRTMtx(const hel::math::Matrix34& rRTMtx) {
    mRTMtx = rRTMtx;
    mEnabled = true;
}

//https://decomp.me/scratch/llrKO
void NodeLocalMtx::scale() const {
    hel::math::Matrix34* mtxTemp = (hel::math::Matrix34*)&mRTMtx;

    mtxTemp->mBaseMtx[0][0] = mScale.x;
    mtxTemp->mBaseMtx[0][1] = mScale.y;
    mtxTemp->mBaseMtx[0][2] = mScale.z;
}

void NodeLocalMtx::setScale(const hel::math::Vector3& rScale) {
    mScale = rScale;
    mEnabled = true;
}

void NodeLocalMtx::setCalcOp(g3d::NodeLocalMtxCalcOp calcOp) {
    mCalcOp = calcOp;
}

//NOTE: All functions below are code merged into others. Refer to the header for more details

hel::math::Matrix34 NodeLocalMtx::rtMtx() const {
    return hel::math::Matrix34(mRTMtx.mBaseMtx);
}

g3d::NodeLocalMtxCalcOp NodeLocalMtx::getCalcOp() const {
    return mCalcOp;
}
