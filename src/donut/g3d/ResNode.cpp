#pragma peephole off
#include "g3d/ResNode.hpp"

namespace g3d {
    ResNode::ResNode() : nw4r::g3d::ResNode(nullptr) { }

    bool ResNode::isRoot() const { return id() == 0; }

    // GetID() doesn't get inlined here
    s32 ResNode::id() const {
        return GetID();
    }

    // GetMtxID() doesn't get inlined here
    s32 ResNode::mtxId() const {
        return GetMtxID();
    }

    nw4r::g3d::ResNode ResNode::parent() const {
        return GetParentNode();
    }

    hel::math::Vector3 ResNode::translate() const {
        return hel::math::Vector3(GetTranslate());
    }
    hel::math::Vector3 ResNode::rotate() const {
        return hel::math::Vector3(GetRotate());
    }
}
