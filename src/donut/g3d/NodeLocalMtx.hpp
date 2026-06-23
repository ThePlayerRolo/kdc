#ifndef DONUT_G3D_NODE_LOCAL_MTX_HPP
#define DONUT_G3D_NODE_LOCAL_MTX_HPP

#include <hel/math/Matrix34.hpp>
#include <hel/math/Vector3.hpp>

namespace g3d {
    enum NodeLocalMtxCalcOp {
        MTX_CALC_OP_NONE,
        MTX_CALC_OP_1,
    };

    class NodeLocalMtx {
    public:
        NodeLocalMtx();

        void reset();
        bool isEnable() const;
        void setRTMtx(const hel::math::Matrix34& rRTMtx);
        void scale() const;
        void setScale(const hel::math::Vector3& rScale);
        void setCalcOp(NodeLocalMtxCalcOp calcOp);

        //NOTE: Is merged into effect::detail::DrawInfo::viewMtx() const
        hel::math::Matrix34 rtMtx() const;
        //NOTE: Is merged into nw4r::lyt::Material::GetTexMapAry() const
        NodeLocalMtxCalcOp getCalcOp() const;
    public:
        /* 0x00 */ hel::math::Matrix34 mRTMtx;
        /* 0x30 */ hel::math::Vector3 mScale;
        /* 0x3C */ bool mEnabled;
        /* 0x40 */ NodeLocalMtxCalcOp mCalcOp;
    };
}

#endif
