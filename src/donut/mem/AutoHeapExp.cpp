#pragma peephole off

#include "mem/AutoHeapExp.hpp"

namespace mem {
    AutoHeapExp::AutoHeapExp(IAllocator& rAllocator, u32 size, const char* pHeapName)
    : DataBlock(size, 4, rAllocator)
    , mObj(hel::common::FixedString<32>(pHeapName), block(), 0, 0)
    { }

    //NOTE: All functions below are code merged into others. Refer to the header for more details

    HeapExp& AutoHeapExp::obj() {
        return mObj;
    }
}
