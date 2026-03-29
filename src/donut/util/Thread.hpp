#ifndef DONUT_UTIL_THREAD_HPP
#define DONUT_UTIL_THREAD_HPP

#include <revolution/OS.h>
#include <donut/mem/DataBlock.hpp>

namespace util {
    class Thread : public mem::DataBlock {
        Thread(mem::IAllocator&, u32, s32, OSThreadFunc, void*);
        ~Thread();

        s32 GetCurrentThreadPriority();

        /* 0x8 */ s32 m_8;
        /* 0xC */ s32 m_C;
        /* 0x10 */ OSThread* mThread;
    };
}

#endif
