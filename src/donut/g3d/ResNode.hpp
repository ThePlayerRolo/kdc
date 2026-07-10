#ifndef DONUT_G3D_RES_NODE_HPP
#define DONUT_G3D_RES_NODE_HPP

#include <nw4r/g3d/res/g3d_resnode.h>
#include <hel/math/Vector3.hpp>

namespace g3d {
    class ResNode : public nw4r::g3d::ResNode {
    public:
        ResNode();
        //NOTE Is Merged into nw4r::ut::Color::Color(const nw4r::ut::Color&)
        ResNode(const nw4r::g3d::ResNode& rResNode);

        bool isRoot() const;
        s32 id() const;
        s32 mtxId() const;
        nw4r::g3d::ResNode parent() const;
        hel::math::Vector3 translate() const;
        hel::math::Vector3 rotate() const;
        //NOTE: Is merged into nrel::mem::ExpHeapBlockIterator::hasNext() const
        bool isValid() const;
        //NOTE: Is Merged into GKI_getfirst
        nw4r::g3d::ResNode* obj() const;
    public:
    };
}

#endif
