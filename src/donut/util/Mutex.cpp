#pragma peephole off
#include <donut/util/Mutex.hpp>

using util::Mutex;
using util::ScopedMutex;

Mutex::Mutex() {
    OSInitMutex(this);
}

void Mutex::lock() {
    OSLockMutex(this);
}

void Mutex::unlock() {
    OSUnlockMutex(this);
}

ScopedMutex::ScopedMutex(Mutex& rMutex)
    : mMutex(&rMutex)
{
    mMutex->lock();
}

ScopedMutex::~ScopedMutex() {
    mMutex->unlock();
}
