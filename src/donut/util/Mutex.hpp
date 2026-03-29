#ifndef DONUT_UTIL_MUTEX_HPP
#define DONUT_UTIL_MUTEX_HPP

#include <revolution/OS.h>

namespace util {
    //Struct Inheritance is required for matching lol
    class Mutex : public OSMutex {
    public:
        Mutex();

        void lock();
        void unlock();
    };

    class ScopedMutex {
    public:
        ScopedMutex(Mutex& rMutex);
        ~ScopedMutex();

        /* 0x0 */ Mutex* mMutex;
    };
}

#endif
