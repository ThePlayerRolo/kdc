#ifndef DONUT_G3D_NODE_LOCAL_MTX_ACCESSOR_HPP
#define DONUT_G3D_NODE_LOCAL_MTX_ACCESSOR_HPP

#include "g3d/NodeLocalMtx.hpp"

namespace g3d {
    class NodeLocalMtxAccessor {
    public:
        //NOTE: Merged into nw4r::g3d::LightObj::LightObj()
        NodeLocalMtxAccessor();
        //NOTE: Merged into nw4r::g3d::Camera::Camera(nw4r::g3d::CameraData*)
        NodeLocalMtxAccessor(NodeLocalMtx&);

        //NOTE: Is merged into nrel::mem::ExpHeapBlockIterator::hasNext() const
        bool isValid() const;

        void reset() const;
        bool isEnable() const; // UNUSED in this game but used in Return To Dreamland
        void setRTMtx(const hel::math::Matrix34& rRTMtx) const;
        void scale() const; // UNUSED in this game but used in Return To Dreamland
        void setScale(const hel::math::Vector3& rScale) const;
        void setCalcOp(NodeLocalMtxCalcOp calcOp) const;
        hel::math::Matrix34 rtMtx() const;

    private:
        /* 0x00 */ NodeLocalMtx* mLocalMtx;
    };
}

#endif
