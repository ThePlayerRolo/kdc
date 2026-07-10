#ifndef DONUT_MINTVM_IALLOCATOR_HPP
#define DONUT_MINTVM_IALLOCATOR_HPP

#include <types.h>

namespace mintvm {
    class IAllocator {
    public:
        // NOTE: Is replaced by a branch to IScene due to code merging
        /* 0x08 */ virtual ~IAllocator() { }
        /* 0x0C */ virtual void* mintAlloc(u32 size) = 0;
        /* 0x10 */ virtual void mintFree(void* pPtr) = 0;
    };
}

#endif
