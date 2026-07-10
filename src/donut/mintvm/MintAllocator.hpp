#ifndef DONUT_MINTVM_MINT_ALLOCATOR_HPP
#define DONUT_MINTVM_MINT_ALLOCATOR_HPP

#include "mintvm/IAllocator.hpp"

namespace mintvm {
    class MintAllocator : public IAllocator {
    public:
        typedef void* (*allocFunction)(u32 size);
        typedef void (*freeFunction)(void* pPtr);
    public:
        MintAllocator();

        /* 0x08 */ virtual ~MintAllocator();
        /* 0x0C */ virtual void* mintAlloc(u32 size);
        /* 0x10 */ virtual void mintFree(void* pPtr);
    public:
        /* 0x04 */ allocFunction mAllocFn;
        /* 0x08 */ freeFunction mFreeFn;
    };
}

#endif
