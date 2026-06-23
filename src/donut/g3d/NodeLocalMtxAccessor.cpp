#pragma peephole off

#include "g3d/NodeLocalMtxAccessor.hpp"

namespace g3d {

    void NodeLocalMtxAccessor::reset() const {
        const_cast<NodeLocalMtx*>(mLocalMtx)->reset();
    }

    hel::math::Matrix34 NodeLocalMtxAccessor::rtMtx() const {
        return mLocalMtx->rtMtx();
    }

    void NodeLocalMtxAccessor::setRTMtx(const hel::math::Matrix34& rRTMtx) const {
        const_cast<NodeLocalMtx*>(mLocalMtx)->setRTMtx(rRTMtx);
    }

    void NodeLocalMtxAccessor::setScale(const hel::math::Vector3& rScale) const {
        const_cast<NodeLocalMtx*>(mLocalMtx)->setScale(rScale);
    }

    void NodeLocalMtxAccessor::setCalcOp(NodeLocalMtxCalcOp calcOp) const {
        const_cast<NodeLocalMtx*>(mLocalMtx)->setCalcOp(calcOp);
    }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    NodeLocalMtxAccessor::NodeLocalMtxAccessor() : mLocalMtx(nullptr) { }

    NodeLocalMtxAccessor::NodeLocalMtxAccessor(NodeLocalMtx& rMtx) : mLocalMtx(&rMtx) { }

    bool NodeLocalMtxAccessor::isValid() const { return mLocalMtx != nullptr; }
}
