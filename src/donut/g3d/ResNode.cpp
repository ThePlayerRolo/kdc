#pragma peephole off
#include "g3d/ResNode.hpp"

namespace g3d {
    ResNode::ResNode() : nw4r::g3d::ResNode(nullptr) { }

    bool ResNode::isRoot() const { return id() == 0; }

    // https://decomp.me/scratch/SU7Mc
    s32 ResNode::id() const {
        return GetID();
    }

    // https://decomp.me/scratch/0sofx
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

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    ResNode::ResNode(const nw4r::g3d::ResNode& rOther) : nw4r::g3d::ResNode(rOther) { }

    bool ResNode::isValid() const {
        return IsValid();
    }

    nw4r::g3d::ResNode* ResNode::obj() const {
        return (nw4r::g3d::ResNode*)this->ptr();
    }
}
