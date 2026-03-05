#ifndef DONUT_OCOLL_ATTACKROOT_HPP
#define DONUT_OCOLL_ATTACKROOT_HPP

#include <types.h>
#include "ocoll/Manager.hpp"

namespace ocoll {

struct AttackNode { };

class AttackRoot {
public:
    u32 ownerUid() const;
    u32 uid() const;
    AttackNode& node(u32 index);
    u32 nodeCount() const; // weak
    void setType(u32 type);
private:
friend class Gimmick;
    /* 0x00 */ Manager* mManager;
    /* 0x04 */ u32 mNodeCount;
    /* 0x08 */ STRUCT_FILL(0x30);
    /* 0x38 */ u32 mType;
};

}

#endif
