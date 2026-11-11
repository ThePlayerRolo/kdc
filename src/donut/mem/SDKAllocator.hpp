#ifndef DONUT_MEM_SDKALLOCATOR_HPP
#define DONUT_MEM_SDKALLOCATOR_HPP

#include <revolution/MEM.h>

struct IAllocator;

namespace mem {

class SDKAllocator {
public:
    SDKAllocator(IAllocator& rAllocator, int);
    void Alloc(MEMAllocator* pAllocator, size_t size);
    void Free(MEMAllocator* pAllocator, void* pPtr);
private:
    /* 0x00 */ int m_0;
    /* 0x04 */ IAllocator& mAllocator;
    /* 0x08 */ void* mAllocatorFuncs;
    /* 0x0C */ int m_C;
    /* 0x10 */ s32 m_10;
    /* 0x14 */ s32 m_14;
};
}

#endif
