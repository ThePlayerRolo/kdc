#pragma peephole off
#include <donut/hid/LibInitializer.hpp>
#include <donut/mem/Memory.hpp>
#include <revolution/WPAD.h>
#include <revolution/KPAD.h>
#include <revolution/PAD.h>
#include <revolution/OS.h>

using hid::LibInitializer;

namespace {
    void* t_wpadAlloc(u32 size) {
        return mem::Memory::Instance->mem2FixHeap().alloc(size);
    }

    int t_wpadFree(void* pWPADData) {
        mem::Memory::Instance->mem2FixHeap().free(pWPADData);
        return 1;
    }
}

LibInitializer::LibInitializer() : hel::common::PrivateSingleton<LibInitializer>() {
    WPADRegisterAllocator(t_wpadAlloc, t_wpadFree);
    KPADInit();
    KPADReset();

    for (s32 chan = 0; chan < 4; chan++) {
        KPADSetPosParam(chan, 0.1f, 0.5f);
        KPADSetBtnRepeat(chan, 0.2f, 0.1f);
        KPADSetAccParam(chan, 0.07f,  1.0f);
        KPADSetDistParam(chan, 0.07f,  1.0f);
        KPADEnableAimingMode(chan);
    }
    PADInit();
    s64 val = OS_MSEC_TO_TICKS(1);
    OSSleepTicks(val * 5);
}

LibInitializer::~LibInitializer() {
    KPADShutdown();
}
