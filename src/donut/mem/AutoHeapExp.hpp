#ifndef DONUT_MEM_AUTO_HEAP_EXP_BLOCK_HPP
#define DONUT_MEM_AUTO_HEAP_EXP_BLOCK_HPP

#include "mem/DataBlock.hpp"
#include "mem/HeapExp.hpp"

namespace mem {
    class AutoHeapExp : public DataBlock {
    public:
        AutoHeapExp(IAllocator& rAllocator, u32 size, const char* pHeapName);

        // NOTE: Is merged into app::RomFontWrapper::font()
        HeapExp& obj();
    public:
        /* 0xC */ HeapExp mObj;
    };
}

#endif
