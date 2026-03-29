#pragma peephole once
#include <donut/util/Thread.hpp>

using util::Thread;

s32 Thread::GetCurrentThreadPriority() {
    OSThread* curThread = OSGetCurrentThread();
    return OSGetThreadPriority(curThread);
}
